#include <LDL/Low/Surface.hpp>
#include <string.h>

LDL_Surface::LDL_Surface(const LDL_Point2u& size, uint8_t bpp) :
	_Pixels(NULL),
	_Size(size),
	_Bpp(bpp)
{
	_Pixels = (uint8_t LDL_FAR*)LDL_MALLOC(_Size.x * _Size.y * _Bpp);
}

LDL_Surface::LDL_Surface(const LDL_Point2u& size, uint8_t LDL_FAR* bytes, uint8_t bpp) :
	_Pixels(bytes),
	_Size(size),
	_Bpp(bpp)
{
	size_t count = _Size.x * _Size.y * _Bpp;

	_Pixels = (uint8_t LDL_FAR*)LDL_MALLOC(_Size.x * _Size.y * _Bpp);
	memcpy(_Pixels, bytes, count);
}

LDL_Surface::~LDL_Surface()
{
	LDL_FREE(_Pixels);
}

uint8_t LDL_FAR* LDL_Surface::Pixels()
{
	return _Pixels;
}

uint8_t LDL_Surface::Bpp()
{
	return _Bpp;
}

const LDL_Point2u& LDL_Surface::Size()
{
	return _Size;
}
