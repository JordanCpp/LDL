#ifndef LDL_Low_PixPaint_hpp
#define LDL_Low_PixPaint_hpp

#include <LDL/Low/SoftSurf.hpp>
#include <LDL/Low/Color.hpp>

class LDL_PixelPainter
{
public:
	void Clear(LDL_ISurface* surface, const LDL_Color& color);
	void Line(LDL_ISurface* surface, const LDL_Point2u& first, const LDL_Point2u& last, const LDL_Color& color);
	void Fill(LDL_ISurface* surface, const LDL_Point2u& pos, const LDL_Point2u& size, const LDL_Color& color);
private:
};

#endif
