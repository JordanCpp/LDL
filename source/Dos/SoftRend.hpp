#ifndef LDL_Dos_SoftRend_hpp
#define LDL_Dos_SoftRend_hpp

#include <LDL/Low/Abstract.hpp>
#include <LDL/Low/PixPaint.hpp>
#include <LDL/Low/PixCopy.hpp>
#include <LDL/Low/BaseRend.hpp>
#include <LDL/Low/SoftSurf.hpp>
#include <dos.h>

class LDL_SoftRender : public LDL_IRender
{
public:
	LDL_SoftRender(LDL_IRenderContext* context, LDL_IWindow* window);
	void SetColor(const LDL_Color& color);
	void Line(const LDL_Point2u& first, const LDL_Point2u& last);
	void Fill(const LDL_Point2u& pos, const LDL_Point2u& size);
	void Clear();
	void Begin();
	void End();
	void Draw(LDL_ISurface* surface, const LDL_Point2u& pos);
	void Draw(LDL_ITexture* texture, const LDL_Point2u& pos);
private:
	LDL_PixelPainter _PixelPainter;
	LDL_PixelCopier _PixelCopier;
	LDL_IRenderContext* _Context;
	LDL_IWindow* _Window;
	uint8_t LDL_FAR* _Screen;
	LDL_BaseRender _BaseRender;
	LDL_ISurface* _ScreenBuffer;
};

#endif
