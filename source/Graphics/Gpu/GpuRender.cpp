#include <LDL/Graphics/Gpu/GpuRender.hpp>
#include "../GL1/GpuRenderImpl.hpp"

using namespace LDL::Graphics;

GpuRender::GpuRender(GpuWindow* window) :
	_GpuRenderImpl(new GpuRenderImpl(window))
{
}

GpuRender::~GpuRender()
{
	delete _GpuRenderImpl;
}

void GpuRender::Begin()
{
	_GpuRenderImpl->Begin();
}

void GpuRender::End()
{
	_GpuRenderImpl->End();
}

const Point2u& GpuRender::Size()
{
	return _GpuRenderImpl->Size();
}

const Color& GpuRender::Color()
{
	return _GpuRenderImpl->Color();
}

void GpuRender::Clear()
{
	_GpuRenderImpl->Clear();
}

void GpuRender::Color(const LDL::Graphics::Color& color)
{
	_GpuRenderImpl->Color(color);
}

void GpuRender::Pixel(const Point2u& pos)
{
	_GpuRenderImpl->Pixel(pos);
}

void GpuRender::Fill(const Point2u& pos, const Point2u& size)
{
	_GpuRenderImpl->Fill(pos, size);
}

void GpuRender::Line(const Point2u& pos1, const Point2u& pos2)
{
	_GpuRenderImpl->Line(pos1, pos2);
}

void GpuRender::Draw(GpuImage* image, const Point2u& pos, const Point2u& size)
{
	_GpuRenderImpl->Draw(image, pos, size);
}

void GpuRender::Draw(GpuImage* image, const Point2u& pos)
{
	_GpuRenderImpl->Draw(image, pos);
}

void GpuRender::Draw(CpuImage* image, const Point2u& pos, const Point2u& size)
{
	_GpuRenderImpl->Draw(image, pos, size);
}

void GpuRender::Draw(CpuImage* image, const Point2u& pos)
{
	_GpuRenderImpl->Draw(image, pos);
}

void GpuRender::Draw(GpuImage* image, const Point2u& dstPos, const Point2u& srcPos, const Point2u& srcSize)
{
	_GpuRenderImpl->Draw(image, dstPos, srcPos, srcSize);
}