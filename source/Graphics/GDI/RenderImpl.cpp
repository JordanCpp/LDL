#include "RenderImpl.hpp"
#include "TextureImpl.hpp"
#include "../../Platforms/Windows/Graphics/GDI/WindowImpl.hpp"

using namespace LDL::Graphics;

RenderImpl::RenderImpl(RenderContextImpl* renderContextImpl, Window* window) :
	_Window(window),
	_Screen(_Window->Size())
{
}

void LDL::Graphics::RenderImpl::Buffer(uint8_t* dst)
{
}

void RenderImpl::Begin()
{
	_Window->GetWindowImpl()->Hdc(BeginPaint(_Window->GetWindowImpl()->Hwnd(), &_PaintStruct));
}

void RenderImpl::End()
{
	EndPaint(_Window->GetWindowImpl()->Hwnd(), &_PaintStruct);
}

const Vec2u& RenderImpl::Size()
{
	return _Window->Size();
}

const Color& RenderImpl::Color()
{
	return _Color;
}

void RenderImpl::Clear()
{
}

void RenderImpl::Color(const LDL::Graphics::Color& color)
{
	_Color = color;

	_Pen = CreatePen(PS_SOLID, 1, RGB(_Color.Red(), _Color.Green(), _Color.Blue()));

	SelectObject(_Window->GetWindowImpl()->Hdc(), _Pen);
}

void RenderImpl::Pixel(const Vec2u& pos)
{
}

void RenderImpl::Line(const Vec2u& pos1, const Vec2u& pos2)
{
	POINT point;

	MoveToEx(_Window->GetWindowImpl()->Hdc(), pos1.x, pos1.y, &point);
	LineTo(_Window->GetWindowImpl()->Hdc(), pos2.x, pos2.y);
}

void RenderImpl::Fill(const Vec2u& pos, const Vec2u& size)
{
	Rectangle(_Window->GetWindowImpl()->Hdc(), pos.x, pos.y, size.x, size.y);
}

void RenderImpl::Draw(Texture* image, const Vec2u& pos, const Vec2u& size)
{
}

void RenderImpl::Draw(Texture* image, const Vec2u& pos)
{
	Draw(image, pos, image->Size());
}

void RenderImpl::Draw(Surface* image, const Vec2u& pos, const Vec2u& size)
{
	_Screen.Draw(image, pos, size);
}

void RenderImpl::Draw(Surface* image, const Vec2u& pos)
{
	_Screen.Draw(image, pos);
}

void RenderImpl::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
}