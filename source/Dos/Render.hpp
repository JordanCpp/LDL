#ifndef LDL_ImpRender_hpp
#define LDL_ImpRender_hpp

#include <LDL/Low/Abstract.hpp>
#include <LDL/Low/PixPaint.hpp>
#include <LDL/Low/PixCopy.hpp>
#include <LDL/Low/BaseRend.hpp>
#include <LDL/Low/Surface.hpp>
#include <dos.h>

class LDL_ImpRender: public LDL_IRender
{
public:
	LDL_ImpRender(LDL_IRenderContext* context, LDL_IWindow* window);
	void SetColor(const LDL_Color& color);
	void Line(const LDL_Point2u& first, const LDL_Point2u& last);
	void Fill(const LDL_Point2u& pos, const LDL_Point2u& size);
	void Clear();
	void End();
	void Draw(LDL_Surface& surface, const LDL_Point2u& pos);
private:
	LDL_PixelPainter _PixelPainter;
	LDL_PixelCopier _PixelCopier;
	LDL_IRenderContext* _Context;
	LDL_IWindow* _Window;
	uint8_t LDL_FAR* _Screen;
	LDL_BaseRender _BaseRender;
	LDL_Surface _ScreenBuffer;
};

#endif
