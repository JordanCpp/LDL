#ifndef LDL_Surface_hpp
#define LDL_Surface_hpp

#include <LDL/Low/Point2u.hpp>

class LDL_Surface
{
public:
	LDL_Surface(const LDL_Point2u& size, uint8_t bpp);
	LDL_Surface(const LDL_Point2u& size, uint8_t LDL_FAR* bytes, uint8_t bpp);
	~LDL_Surface();
	uint8_t LDL_FAR* Pixels();
	uint8_t Bpp();
	const LDL_Point2u& Size();
private:
	uint8_t LDL_FAR* _Pixels;
	uint8_t _Bpp;
	LDL_Point2u _Size;
};

#endif
