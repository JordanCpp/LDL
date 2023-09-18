#include <LDL/Low/RgbArray.hpp>
#include <assert.h>

LDL_RgbArray::LDL_RgbArray(const LDL_Point2u& size, uint8_t bpp, size_t capacity) :
	_Capacity(capacity),
	_Pixels(NULL),
	_Bpp(bpp),
	_Size(size)
{
	assert(size.x * size.y * bpp <= capacity);

	_Pixels = (uint8_t LDL_FAR*)LDL_MALLOC(capacity);
}

LDL_RgbArray::~LDL_RgbArray()
{
	LDL_FREE(_Pixels);
}

uint8_t LDL_FAR* LDL_RgbArray::Pixels()
{
	return _Pixels;
}

const LDL_Point2u& LDL_RgbArray::Size()
{
	return _Size;
}

uint8_t LDL_RgbArray::Bpp()
{
	return _Bpp;
}

size_t LDL_RgbArray::Capacity()
{
	return _Capacity;
}

void LDL_RgbArray::Resize(const LDL_Point2u& size, uint8_t bpp)
{
	assert(size.x * size.y * bpp <= _Capacity);

	_Size = size;
	_Bpp = bpp;
}
