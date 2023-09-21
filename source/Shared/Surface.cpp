#include <LDL/Low/SoftSurf.hpp>
#include <string.h>

LDL_SoftwareSurface::LDL_SoftwareSurface(const LDL_Point2u& size, uint8_t bpp) :
	_Bpp(bpp),
	_Pixels(NULL),
	_Size(size)
{
	_Pixels = (uint8_t LDL_FAR*)LDL_MALLOC(_Size.x * _Size.y * _Bpp);
}

LDL_SoftwareSurface::LDL_SoftwareSurface(const LDL_Point2u& size, uint8_t LDL_FAR* bytes, uint8_t bpp) :
	_Bpp(bpp),
	_Pixels(bytes),
	_Size(size)
{
	size_t count = _Size.x * _Size.y * _Bpp;

	_Pixels = (uint8_t LDL_FAR*)LDL_MALLOC(_Size.x * _Size.y * _Bpp);
	memcpy(_Pixels, bytes, count);
}

LDL_SoftwareSurface::~LDL_SoftwareSurface()
{
	LDL_FREE(_Pixels);
}

uint8_t LDL_FAR* LDL_SoftwareSurface::Pixels()
{
	return _Pixels;
}

uint8_t LDL_SoftwareSurface::Bpp()
{
	return _Bpp;
}

const LDL_Point2u& LDL_SoftwareSurface::Size()
{
	return _Size;
}
