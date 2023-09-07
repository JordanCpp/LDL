#ifndef LDL_PixPaint_hpp
#define LDL_PixPaint_hpp

#include <LDL/Low/Surface.hpp>
#include <LDL/Low/Color.hpp>

class LDL_PixelPainter
{
public:
	void Clear(LDL_Surface& surface, const LDL_Color& color);
	void Line(LDL_Surface& surface, const LDL_Point2u& first, const LDL_Point2u& last, const LDL_Color& color);
	void Fill(LDL_Surface& surface, const LDL_Point2u& pos, const LDL_Point2u& size, const LDL_Color& color);
private:
};

#endif
