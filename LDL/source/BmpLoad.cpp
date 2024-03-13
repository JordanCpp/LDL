/*
Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include <LDL/BmpLoad.hpp>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

LDL_BmpLoader::LDL_BmpLoader(LDL_Result* result) :
	_Result(result),
	_Pixels(NULL),
	_Input(NULL),
	_Bpp(0)
{
	memset(&_FileHeader, 0, sizeof(_FileHeader));
	memset(&_InfoHeader, 0, sizeof(_InfoHeader));
}

LDL_BmpLoader::~LDL_BmpLoader()
{
	if (_Pixels)
	{
		delete _Pixels;
	}
}

bool LDL_BmpLoader::Load(const char* path)
{
	if (CheckOpen(path))
	{
		if (CheckFileHeader())
		{
			if (CheckInfoHeader())
			{
				if (ReadBytes())
				{
					BgrToRgb();

					return true;
				}
			}
		}

		fclose(_Input);
	}

	return false;
}

const LDL_Vec2i& LDL_BmpLoader::Size()
{
	return _Size;
}

uint8_t LDL_BmpLoader::Bpp()
{
	return _Bpp;
}

uint8_t* LDL_BmpLoader::Pixels()
{
	return _Pixels;
}

void LDL_BmpLoader::BgrToRgb()
{
	size_t count = Size().x * Size().y * Bpp();

	for (size_t i = 0; i < count; i += 3)
	{
		uint8_t b = _Pixels[i];
		uint8_t r = _Pixels[i + 2];

		_Pixels[i] = r;
		_Pixels[i + 2] = b;
	}
}

bool LDL_BmpLoader::CheckOpen(const char* path)
{
	_Input = fopen(path, "rb");

	if (_Input == NULL)
	{
		_Result->Message("Not found file: ", path);
	}

	return _Result->Ok();
}

bool LDL_BmpLoader::CheckFileHeader()
{
	fread(&_FileHeader.bfType, sizeof(_FileHeader.bfType), 1, _Input);
	if (_FileHeader.bfType != 0x4D42)
		_Result->Message("bfType is invalid");

	fread(&_FileHeader.bfSize, sizeof(_FileHeader.bfSize), 1, _Input);
	if (_FileHeader.bfSize == 0)
		_Result->Message("bfSize is invalid");

	fread(&_FileHeader.bfReserved1, sizeof(_FileHeader.bfReserved1), 1, _Input);
	if (_FileHeader.bfReserved1 != 0)
		_Result->Message("bfReserved1 is invalid");

	fread(&_FileHeader.bfReserved2, sizeof(_FileHeader.bfReserved2), 1, _Input);
	if (_FileHeader.bfReserved2 != 0)
		_Result->Message("bfReserved2 is invalid");

	fread(&_FileHeader.bfOffBits, sizeof(_FileHeader.bfOffBits), 1, _Input);
	if (_FileHeader.bfType == 0)
		_Result->Message("bfOffBits is invalid");

	return _Result->Ok();
}

bool LDL_BmpLoader::CheckInfoHeader()
{
	fread(&_InfoHeader.biSize, sizeof(_InfoHeader.biSize), 1, _Input);
	if (_InfoHeader.biSize == 0)
		_Result->Message("biSize is invalid");

	fread(&_InfoHeader.biWidth, sizeof(_InfoHeader.biWidth), 1, _Input);
	if (_InfoHeader.biWidth == 0)
		_Result->Message("biWidth is invalid");

	fread(&_InfoHeader.biHeight, sizeof(_InfoHeader.biHeight), 1, _Input);
	if (_InfoHeader.biHeight == 0)
		_Result->Message("biHeight is invalid");

	fread(&_InfoHeader.biPlanes, sizeof(_InfoHeader.biPlanes), 1, _Input);
	fread(&_InfoHeader.biBitCount, sizeof(_InfoHeader.biBitCount), 1, _Input);
	fread(&_InfoHeader.biCompression, sizeof(_InfoHeader.biCompression), 1, _Input);
	fread(&_InfoHeader.biSizeImage, sizeof(_InfoHeader.biSizeImage), 1, _Input);
	fread(&_InfoHeader.biXPelsPerMeter, sizeof(_InfoHeader.biXPelsPerMeter), 1, _Input);
	fread(&_InfoHeader.biYPelsPerMeter, sizeof(_InfoHeader.biYPelsPerMeter), 1, _Input);
	fread(&_InfoHeader.biClrUsed, sizeof(_InfoHeader.biClrUsed), 1, _Input);
	fread(&_InfoHeader.biClrImportant, sizeof(_InfoHeader.biClrImportant), 1, _Input);

	_Size = LDL_Vec2i(_InfoHeader.biWidth, _InfoHeader.biHeight);
	_Bpp = _InfoHeader.biBitCount / 8;

	return _Result->Ok();
}

bool LDL_BmpLoader::ReadBytes()
{
	size_t bytes = _Bpp * _Size.x * abs(_InfoHeader.biHeight);

	_Pixels = new uint8_t[bytes];

	assert(_Pixels != NULL);

	size_t result = fread(_Pixels, bytes, 1, _Input);

	if (result != 1)
	{
		_Result->Message("Not enough byte data");
	}

	return _Result->Ok();
}