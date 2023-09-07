#include "Render.hpp"
#include <string.h>

LDL_ImpRender::LDL_ImpRender(LDL_IRenderContext* context, LDL_IWindow* window) :
	_Context(context),
	_Window(window),
	_Screen(NULL),
	_BaseRender(_Window->Size()),
	_ScreenBuffer(_BaseRender.Size(), 1)
{
	_Screen = (uint8_t LDL_FAR*)0xA0000000L;

	union REGS regs;

	regs.h.ah = 0x00;
	regs.h.al = 0x13;
	int86(0x10, &regs, &regs);
}

void LDL_ImpRender::SetColor(const LDL_Color& color)
{
	_BaseRender.SetColor(color);
}

void LDL_ImpRender::Line(const LDL_Point2u& first, const LDL_Point2u& last)
{
	_PixelPainter.Line(_ScreenBuffer, first, last, _BaseRender.Color());
}

void LDL_ImpRender::Fill(const LDL_Point2u& pos, const LDL_Point2u& size)
{
	_PixelPainter.Fill(_ScreenBuffer, pos, size, _BaseRender.Color());
}

void LDL_ImpRender::Clear()
{
	_PixelPainter.Clear(_ScreenBuffer, _BaseRender.Color());
}

void LDL_ImpRender::End()
{
	size_t count = _BaseRender.Size().x * _BaseRender.Size().y;
	uint8_t LDL_FAR* pixels = _ScreenBuffer.Pixels();

	for (size_t i = 0; i < count; i++)
	{
		_Screen[i] = pixels[i];
	}
}

void LDL_ImpRender::Draw(LDL_Surface& surface, const LDL_Point2u& pos)
{
	_PixelCopier.Draw(_ScreenBuffer, pos, surface);
}
