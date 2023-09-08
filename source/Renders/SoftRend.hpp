#ifndef LDL_SoftRend_hpp
#define LDL_SoftRend_hpp

#include <LDL/Low/Abstract.hpp>
#include <LDL/Low/BaseRend.hpp>
#include <LDL/Low/PixPaint.hpp>
#include <LDL/Low/PixCopy.hpp>

class LDL_SoftRender: public LDL_IRender
{
public:
	LDL_SoftRender(LDL_IRenderContext* context, LDL_IWindow* window);
	void SetColor(const LDL_Color& color);
	void Line(const LDL_Point2u& first, const LDL_Point2u& last);
	void Fill(const LDL_Point2u& pos, const LDL_Point2u& size);
	void Clear();
	void End();
	void Draw(LDL_Surface& surface, const LDL_Point2u& pos);
private:
	LDL_IRenderContext* _RenderContext;
	LDL_IWindow*        _Window;
	LDL_BaseRender      _BaseRender;
	LDL_Surface         _Surface;
	LDL_PixelPainter    _PixelPainter;
	LDL_PixelCopier     _PixelCopier;
};

#endif
