#include "SoftRend.hpp"

#if defined(_WIN32)
#include "../Windows/SoftWin.hpp"
#elif defined(__unix__)
#include "../Linux/SoftWin.hpp"
#endif

LDL_SoftRender::LDL_SoftRender(LDL_IRenderContext* context, LDL_IWindow* window) :
	_RenderContext(context),
	_Window(window),
	_BaseRender(_Window->Size()),
	_Surface(new LDL_SoftwareSurface(_BaseRender.Size(), 3))
{
}

void LDL_SoftRender::SetColor(const LDL_Color& color)
{
	_BaseRender.SetColor(color);
}

void LDL_SoftRender::Line(const LDL_Vec2u& first, const LDL_Vec2u& last)
{
	_PixelPainter.Line(_Surface, first, last, _BaseRender.Color());
}

void LDL_SoftRender::Fill(const LDL_Vec2u& pos, const LDL_Vec2u& size)
{
	_PixelPainter.Fill(_Surface, pos, size, _BaseRender.Color());
}

void LDL_SoftRender::Clear()
{
	_PixelPainter.Clear(_Surface, _BaseRender.Color());
}

void LDL_SoftRender::Begin()
{
}

void LDL_SoftRender::End()
{
	LDL_SoftWindow* p = (LDL_SoftWindow*)_Window;

	p->Present(_Surface);
}

void LDL_SoftRender::Draw(LDL_ISurface* surface, const LDL_Vec2u& pos)
{
	_PixelCopier.Draw(_Surface, pos, surface);
}

void LDL_SoftRender::Draw(LDL_ITexture* texture, const LDL_Vec2u& pos)
{
}
