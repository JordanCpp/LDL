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

const Point2u& RenderImpl::Size()
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

void RenderImpl::Pixel(const Point2u& pos)
{
}

void RenderImpl::Line(const Point2u& pos1, const Point2u& pos2)
{
	POINT point;

	MoveToEx(_Window->GetWindowImpl()->Hdc(), pos1.PosX(), pos1.PosY(), &point);
	LineTo(_Window->GetWindowImpl()->Hdc(), pos2.PosX(), pos2.PosY());
}

void RenderImpl::Fill(const Point2u& pos, const Point2u& size)
{
	Rectangle(_Window->GetWindowImpl()->Hdc(), pos.PosX(), pos.PosY(), size.PosX(), size.PosY());
}

void RenderImpl::Draw(Texture* image, const Point2u& pos, const Point2u& size)
{
}

void RenderImpl::Draw(Texture* image, const Point2u& pos)
{
	Draw(image, pos, image->Size());
}

void RenderImpl::Draw(Surface* image, const Point2u& pos, const Point2u& size)
{
	_Screen.Draw(image, pos, size);
}

void RenderImpl::Draw(Surface* image, const Point2u& pos)
{
	_Screen.Draw(image, pos);
}

void RenderImpl::Draw(Texture* image, const Point2u& dstPos, const Point2u& srcPos, const Point2u& srcSize)
{
}