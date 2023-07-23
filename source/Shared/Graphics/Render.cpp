#include <LDL/Graphics/Render.hpp>
#include "Creators/RenderImplCreator.hpp"
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Core;
using namespace LDL::Math;
using namespace LDL::Graphics;
using namespace LDL::Graphics::Creators;

Render::Render(RenderContext* renderContext, Window* window)
{
	RenderImplCreator creator;

	_RenderImpl = creator.Create(renderContext, window);
}

Render::~Render()
{
	delete _RenderImpl;
}

RenderImpl* Render::GetRenderImpl()
{
	return _RenderImpl;
}


void Render::Buffer(uint8_t* dst)
{
	_RenderImpl->Buffer(dst);
}

void Render::Begin()
{
	_RenderImpl->Begin();
}

void Render::End()
{
	_RenderImpl->End();
}

const Vec2u& Render::Size()
{
	return _RenderImpl->Size();
}

const Color& Render::Color()
{
	return _RenderImpl->Color();
}

void Render::Clear()
{
	_RenderImpl->Clear();
}

void Render::Color(const LDL::Graphics::Color& color)
{
	_RenderImpl->Color(color);
}

void Render::Pixel(const Vec2u& pos)
{
	_RenderImpl->Pixel(pos);
}

void Render::Fill(const Vec2u& pos, const Vec2u& size)
{
	_RenderImpl->Fill(pos, size);
}

void Render::Line(const Vec2u& pos1, const Vec2u& pos2)
{
	_RenderImpl->Line(pos1, pos2);
}

void Render::Draw(Texture* image, const Vec2u& pos)
{
	_RenderImpl->Draw(image, pos);
}

void Render::Draw(Texture* image, const Vec2u& pos, const Vec2u& size)
{
	_RenderImpl->Draw(image, pos, size);
}

void Render::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
	_RenderImpl->Draw(image, dstPos, srcPos, srcSize);
}

void Render::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
	_RenderImpl->Draw(image, dstPos, dstSize, srcPos, srcSize);
}

void Render::Draw(Surface* image, const Vec2u& pos)
{
	_RenderImpl->Draw(image, pos);
}

void Render::Draw(Surface* image, const Vec2u& pos, const Vec2u& size)
{
	_RenderImpl->Draw(image, pos, size);
}

void Render::Draw(Surface* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
	_RenderImpl->Draw(image, dstPos, srcPos, srcSize);
}

void Render::Draw(Surface* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
	_RenderImpl->Draw(image, dstPos, dstSize, srcPos, srcSize);
}

void Render::Draw(TextureBatcher* textureBatcher)
{
	_RenderImpl->Draw(textureBatcher);
}
