#ifndef LDL_Low_RgbArray_hpp
#define LDL_Low_RgbArray_hpp

#include <LDL/Low/Vec2u.hpp>

class LDL_RgbArray
{
public:
	LDL_RgbArray(const LDL_Vec2u& size, uint8_t bpp, size_t capacity);
	~LDL_RgbArray();
	uint8_t LDL_FAR* Pixels();
	const LDL_Vec2u& Size();
	uint8_t Bpp();
	size_t Capacity();
	void Resize(const LDL_Vec2u& size, uint8_t bpp);
private:
	size_t _Capacity;
	uint8_t LDL_FAR* _Pixels;
	uint8_t _Bpp;
	LDL_Vec2u _Size;
};

#endif
