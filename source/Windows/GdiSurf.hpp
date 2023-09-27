#ifndef LDL_Windows_GdiSurf_hpp
#define LDL_Windows_GdiSurf_hpp

#include <LDL/Low/Abstract.hpp>
#include <LDL/Low/SoftSurf.hpp>
#include "GdiWin.hpp"

class LDL_GdiSurface : public LDL_ISurface
{
public:
	LDL_GdiSurface(LDL_IWindow* window, const LDL_Vec2u& size, uint8_t bpp);
	LDL_GdiSurface(LDL_IWindow* window, const LDL_Vec2u& size, uint8_t LDL_FAR* bytes, uint8_t bpp);
	~LDL_GdiSurface();
	uint8_t LDL_FAR* Pixels();
	uint8_t Bpp();
	const LDL_Vec2u& Size();
	HDC _CompatibleDC;
	HBITMAP _Bitmap;
	LDL_IWindow* _Window;
	LDL_GdiWindow* _GdiWindow;
	LDL_SoftwareSurface _Surface;

};

#endif