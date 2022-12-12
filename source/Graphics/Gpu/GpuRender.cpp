#include <LDL/Graphics/Gpu/GpuRender.hpp>
#include "../GL1/GpuRenderImpl.hpp"

LDL::Graphics::GpuRender::GpuRender(LDL::Graphics::GpuWindow* window) :
	_GpuRenderImpl(new LDL::Graphics::GpuRenderImpl(window))
{
}

LDL::Graphics::GpuRender::~GpuRender()
{
	delete _GpuRenderImpl;
}

void LDL::Graphics::GpuRender::Begin()
{
	_GpuRenderImpl->Begin();
}

void LDL::Graphics::GpuRender::End()
{
	_GpuRenderImpl->End();
}

const LDL::Graphics::Point2u& LDL::Graphics::GpuRender::Size()
{
	return _GpuRenderImpl->Size();
}

const LDL::Graphics::Color& LDL::Graphics::GpuRender::Color()
{
	return _GpuRenderImpl->Color();
}

void LDL::Graphics::GpuRender::Clear()
{
	_GpuRenderImpl->Clear();
}

void LDL::Graphics::GpuRender::Color(const LDL::Graphics::Color& color)
{
	_GpuRenderImpl->Color(color);
}

void LDL::Graphics::GpuRender::Pixel(const LDL::Graphics::Point2u& pos)
{
	_GpuRenderImpl->Pixel(pos);
}

void LDL::Graphics::GpuRender::Fill(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size)
{
	_GpuRenderImpl->Fill(pos, size);
}

void LDL::Graphics::GpuRender::Line(const LDL::Graphics::Point2u& pos1, const LDL::Graphics::Point2u& pos2)
{
	_GpuRenderImpl->Line(pos1, pos2);
}

void LDL::Graphics::GpuRender::Draw(LDL::Graphics::GpuImage* image, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size)
{
	_GpuRenderImpl->Draw(image, pos, size);
}

void LDL::Graphics::GpuRender::Draw(LDL::Graphics::GpuImage* image, const LDL::Graphics::Point2u& pos)
{
	_GpuRenderImpl->Draw(image, pos);
}

void LDL::Graphics::GpuRender::Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size)
{
	_GpuRenderImpl->Draw(image, pos, size);
}

void LDL::Graphics::GpuRender::Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos)
{
	_GpuRenderImpl->Draw(image, pos);
}