#include <LDL/Low/BmpLoad.hpp>
#include <math.h>
#include <string.h>
#include <assert.h>

LDL_BmpLoader::LDL_BmpLoader(LDL_ErrorHandler* errorHandler) :
	_ErrorHandler(errorHandler),
	_Result(NULL),
	_Input(NULL),
	_Bpp(0)
{
	memset(&_FileHeader, 0, sizeof(_FileHeader));
	memset(&_InfoHeader, 0, sizeof(_InfoHeader));
}

LDL_BmpLoader::~LDL_BmpLoader()
{
	if (_Result)
	{
		LDL_FREE(_Result);
	}
}

void LDL_BmpLoader::Load(const char* path)
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
				}
			}
		}

		fclose(_Input);
	}
}

const LDL_Point2u& LDL_BmpLoader::Size()
{
	return _Size;
}

uint8_t LDL_BmpLoader::Bpp()
{
	return _Bpp;
}

uint8_t LDL_FAR* LDL_BmpLoader::Pixels()
{
	return _Result;
}

void LDL_BmpLoader::BgrToRgb()
{
	size_t count = Size().x * Size().y * Bpp();

	uint8_t b = 0;
	uint8_t r = 0;

	for (size_t i = 0; i < count; i += 3)
	{
		b = _Result[i];
		r = _Result[i + 2];

		_Result[i] = r;
		_Result[i + 2] = b;
	}
}

bool LDL_BmpLoader::CheckOpen(const char* path)
{
	_Input = fopen(path, "rb");

	if (_Input == NULL)
	{
		_ErrorHandler->Message("Not found file: ", path);
	}

	return _ErrorHandler->Ok();
}

bool LDL_BmpLoader::CheckFileHeader()
{
	fread(&_FileHeader.bfType, sizeof(_FileHeader.bfType), 1, _Input);
	if (_FileHeader.bfType != 0x4D42)
		_ErrorHandler->Message("bfType is invalid");

	fread(&_FileHeader.bfSize, sizeof(_FileHeader.bfSize), 1, _Input);
	if (_FileHeader.bfSize == 0)
		_ErrorHandler->Message("bfSize is invalid");

	fread(&_FileHeader.bfReserved1, sizeof(_FileHeader.bfReserved1), 1, _Input);
	if (_FileHeader.bfReserved1 != 0)
		_ErrorHandler->Message("bfReserved1 is invalid");

	fread(&_FileHeader.bfReserved2, sizeof(_FileHeader.bfReserved2), 1, _Input);
	if (_FileHeader.bfReserved2 != 0)
		_ErrorHandler->Message("bfReserved2 is invalid");

	fread(&_FileHeader.bfOffBits, sizeof(_FileHeader.bfOffBits), 1, _Input);
	if (_FileHeader.bfType == 0)
		_ErrorHandler->Message("bfOffBits is invalid");

	return _ErrorHandler->Ok();
}

bool LDL_BmpLoader::CheckInfoHeader()
{
	fread(&_InfoHeader.biSize, sizeof(_InfoHeader.biSize), 1, _Input);
	if (_InfoHeader.biSize == 0)
		_ErrorHandler->Message("biSize is invalid");

	fread(&_InfoHeader.biWidth, sizeof(_InfoHeader.biWidth), 1, _Input);
	if (_InfoHeader.biWidth == 0)
		_ErrorHandler->Message("biWidth is invalid");

	fread(&_InfoHeader.biHeight, sizeof(_InfoHeader.biHeight), 1, _Input);
	if (_InfoHeader.biHeight == 0)
		_ErrorHandler->Message("biHeight is invalid");

	fread(&_InfoHeader.biPlanes, sizeof(_InfoHeader.biPlanes), 1, _Input);
	fread(&_InfoHeader.biBitCount, sizeof(_InfoHeader.biBitCount), 1, _Input);
	fread(&_InfoHeader.biCompression, sizeof(_InfoHeader.biCompression), 1, _Input);
	fread(&_InfoHeader.biSizeImage, sizeof(_InfoHeader.biSizeImage), 1, _Input);
	fread(&_InfoHeader.biXPelsPerMeter, sizeof(_InfoHeader.biXPelsPerMeter), 1, _Input);
	fread(&_InfoHeader.biYPelsPerMeter, sizeof(_InfoHeader.biYPelsPerMeter), 1, _Input);
	fread(&_InfoHeader.biClrUsed, sizeof(_InfoHeader.biClrUsed), 1, _Input);
	fread(&_InfoHeader.biClrImportant, sizeof(_InfoHeader.biClrImportant), 1, _Input);

	_Size = LDL_Point2u(_InfoHeader.biWidth, _InfoHeader.biHeight);
	_Bpp = _InfoHeader.biBitCount / 8;

	return _ErrorHandler->Ok();
}

bool LDL_BmpLoader::ReadBytes()
{
	size_t bytes = _Bpp * _Size.x * abs(_InfoHeader.biHeight);

	_Result = (uint8_t LDL_FAR*)LDL_MALLOC(bytes);

	assert(_Result != NULL);

	size_t result = fread(_Result, bytes, 1, _Input);

	if (result != 1)
	{
		_ErrorHandler->Message("Not enough byte data");
	}

	return _ErrorHandler->Ok();
}
