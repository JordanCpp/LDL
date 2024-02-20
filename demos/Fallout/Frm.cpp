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

#include "Frm.hpp"

FrmReader::FrmReader(ByteReader* reader) :
	_Reader(reader)
{
}

FrmReader::~FrmReader()
{
}

bool FrmReader::Open(const char* path)
{
	return _Reader->Open(path, ByteReader::LittleEndian);
}

void FrmReader::ReadFrmFile(FrmFile* dest)
{
	dest->version              = _Reader->u32();
	dest->frames_per_second    = _Reader->u16();
	dest->action_frame         = _Reader->u16();
	dest->frames_per_direction = _Reader->u16();

	ReadShiftX(dest);
	ReadShiftY(dest);
	ReadOffsets(dest);

	dest->dirs = 1;

	for (size_t i = 1; i < FrmFile::Max; i++)
	{
		if (dest->offset[i] != 0)
		{
			dest->dirs++;
		}
	}

	dest->size = _Reader->u32();
}

void FrmReader::ReadFrmFrame(FrmFrame* dest)
{
	dest->width  = _Reader->u16();
	dest->height = _Reader->u16();

	_Reader->u32();
	_Reader->u16();
	_Reader->u16();

	for (size_t i = 0; i < dest->width * dest->height; i++)
	{
		dest->indexes[i] = _Reader->u8();
	}
}

void FrmReader::ReadShiftX(FrmFile* dest)
{
	for (size_t i = 0; i < FrmFile::Max; i++)
	{
		dest->shift_x[i] = _Reader->u16();
	}
}

void FrmReader::ReadShiftY(FrmFile* dest)
{
	for (size_t i = 0; i < FrmFile::Max; i++)
	{
		dest->shift_y[i] = _Reader->u16();
	}
}

void FrmReader::ReadOffsets(FrmFile* dest)
{
	for (size_t i = 0; i < FrmFile::Max; i++)
	{
		dest->offset[i] = _Reader->u32();
	}
}
