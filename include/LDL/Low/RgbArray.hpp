#ifndef LDL_RgbArray_hpp
#define LDL_RgbArray_hpp

#include <LDL/Low/Point2u.hpp>

class LDL_RgbArray
{
public:
	LDL_RgbArray(const LDL_Point2u& size, uint8_t bpp, size_t capacity);
	~LDL_RgbArray();
	uint8_t LDL_FAR* Pixels();
	const LDL_Point2u& Size();
	uint8_t Bpp();
	size_t Capacity();
	void Resize(const LDL_Point2u& size, uint8_t bpp);
private:
	size_t _Capacity;
	uint8_t LDL_FAR* _Pixels;
	uint8_t _Bpp;
	LDL_Point2u _Size;
};

#endif
