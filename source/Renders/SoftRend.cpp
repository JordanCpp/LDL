#include "SoftRend.hpp"

#if defined(_WIN32_)
#include "../Windows/SoftWin.hpp"
#elif defined(__unix__)
#include "../Linux/SoftWin.hpp"
#endif

LDL_SoftRender::LDL_SoftRender(LDL_IRenderContext* context, LDL_IWindow* window) :
	_RenderContext(context),
	_Window(window),
	_BaseRender(_Window->Size()),
	_Surface(_BaseRender.Size(), 3)
{
}

void LDL_SoftRender::SetColor(const LDL_Color& color)
{
	_BaseRender.SetColor(color);
}

void LDL_SoftRender::Line(const LDL_Point2u& first, const LDL_Point2u& last)
{
	_PixelPainter.Line(_Surface, first, last, _BaseRender.Color());
}

void LDL_SoftRender::Fill(const LDL_Point2u& pos, const LDL_Point2u& size)
{
	_PixelPainter.Fill(_Surface, pos, size, _BaseRender.Color());
}

void LDL_SoftRender::Clear()
{
	_PixelPainter.Clear(_Surface, _BaseRender.Color());
}

void LDL_SoftRender::End()
{
	LDL_SoftWindow* p = (LDL_SoftWindow*)_Window;

	p->Present(_Surface.Pixels(), _Surface.Bpp());
}

void LDL_SoftRender::Draw(LDL_Surface& surface, const LDL_Point2u& pos)
{
	_PixelCopier.Draw(_Surface, pos, surface);
}
