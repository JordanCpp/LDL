#include <LDL/Graphics/Render.hpp>

#ifdef LDL_RENDER_SOFTWARE
#include "Software/RenderImpl.hpp"
#elif LDL_RENDER_OPENGL1
#include "OpenGL1/RenderImpl.hpp"
#elif LDL_GPU_SUPPORT_DIRECTX1
#include "../DirectDraw1/GpuRenderImpl.hpp"
#endif

using namespace LDL::Graphics;

Render::Render(Window* window) :
	_GpuRenderImpl(new RenderImpl(window))
{
}

Render::~Render()
{
	delete _GpuRenderImpl;
}

void Render::Buffer(uint8_t* dst)
{
	_GpuRenderImpl->Buffer(dst);
}

void Render::Begin()
{
	_GpuRenderImpl->Begin();
}

void Render::End()
{
	_GpuRenderImpl->End();
}

const Point2u& Render::Size()
{
	return _GpuRenderImpl->Size();
}

const Color& Render::Color()
{
	return _GpuRenderImpl->Color();
}

void Render::Clear()
{
	_GpuRenderImpl->Clear();
}

void Render::Color(const LDL::Graphics::Color& color)
{
	_GpuRenderImpl->Color(color);
}

void Render::Pixel(const Point2u& pos)
{
	_GpuRenderImpl->Pixel(pos);
}

void Render::Fill(const Point2u& pos, const Point2u& size)
{
	_GpuRenderImpl->Fill(pos, size);
}

void Render::Line(const Point2u& pos1, const Point2u& pos2)
{
	_GpuRenderImpl->Line(pos1, pos2);
}

void Render::Draw(Texture* image, const Point2u& pos, const Point2u& size)
{
	_GpuRenderImpl->Draw(image, pos, size);
}

void Render::Draw(Texture* image, const Point2u& pos)
{
	_GpuRenderImpl->Draw(image, pos);
}

void Render::Draw(Surface* image, const Point2u& pos, const Point2u& size)
{
	_GpuRenderImpl->Draw(image, pos, size);
}

void Render::Draw(Surface* image, const Point2u& pos)
{
	_GpuRenderImpl->Draw(image, pos);
}

void Render::Draw(Texture* image, const Point2u& dstPos, const Point2u& srcPos, const Point2u& srcSize)
{
	_GpuRenderImpl->Draw(image, dstPos, srcPos, srcSize);
}