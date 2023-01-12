#include "RenderImpl.hpp"

using namespace LDL::Graphics;

RenderImpl::RenderImpl(Window* window) :
	_Window(window),
	_BaseRender(_Window->View())
{
}

void LDL::Graphics::RenderImpl::Buffer(uint8_t* dst)
{
}

void RenderImpl::Begin()
{
}

void RenderImpl::End()
{
	_Window->Present();
}

const Point2u& RenderImpl::Size()
{
	return _BaseRender.Size();
}

const Color& RenderImpl::Color()
{
	return _BaseRender.Color();
}

void RenderImpl::Clear()
{
}

void RenderImpl::Color(const LDL::Graphics::Color& color)
{
	_BaseRender.Color(color);
}

void RenderImpl::Pixel(const Point2u& pos)
{
}

void RenderImpl::Line(const Point2u& pos1, const Point2u& pos2)
{
}

void RenderImpl::Fill(const Point2u& pos, const Point2u& size)
{
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

}

void RenderImpl::Draw(Surface* image, const Point2u& pos)
{

}

void RenderImpl::Draw(Texture* image, const Point2u& dstPos, const Point2u& srcPos, const Point2u& srcSize)
{
}