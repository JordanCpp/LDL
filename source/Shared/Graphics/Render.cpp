#include <LDL/Graphics/Render.hpp>
#include "Creators/RenderImplCreator.hpp"

using namespace LDL::Math;
using namespace LDL::Graphics;
using namespace LDL::Graphics::Creators;

Render::Render(RenderContext* renderContext, Window* window)
{
	RenderImplCreator creator;

	_impl = creator.Create(renderContext, window);
}

Render::~Render()
{
	delete _impl;
}

RenderImpl* Render::GetRenderImpl()
{
	return _impl;
}


void Render::Buffer(uint8_t* dst)
{
	_impl->Buffer(dst);
}

void Render::Begin()
{
	_impl->Begin();
}

void Render::End()
{
	_impl->End();
}

const Vec2u& Render::Size()
{
	return _impl->Size();
}

const Color& Render::Color()
{
	return _impl->Color();
}

void Render::Clear()
{
	_impl->Clear();
}

void Render::Color(const LDL::Graphics::Color& color)
{
	_impl->Color(color);
}

void Render::Pixel(const Vec2u& pos)
{
	_impl->Pixel(pos);
}

void Render::Fill(const Vec2u& pos, const Vec2u& size)
{
	_impl->Fill(pos, size);
}

void Render::Line(const Vec2u& pos1, const Vec2u& pos2)
{
	_impl->Line(pos1, pos2);
}

void Render::Draw(Texture* image, const Vec2u& pos)
{
	_impl->Draw(image, pos);
}

void Render::Draw(Texture* image, const Vec2u& pos, const Vec2u& size)
{
	_impl->Draw(image, pos, size);
}

void Render::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
	_impl->Draw(image, dstPos, srcPos, srcSize);
}

void Render::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
	_impl->Draw(image, dstPos, dstSize, srcPos, srcSize);
}

void Render::Draw(Surface* image, const Vec2u& pos)
{
	_impl->Draw(image, pos);
}

void Render::Draw(Surface* image, const Vec2u& pos, const Vec2u& size)
{
	_impl->Draw(image, pos, size);
}

void Render::Draw(Surface* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
	_impl->Draw(image, dstPos, srcPos, srcSize);
}

void Render::Draw(Surface* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
	_impl->Draw(image, dstPos, dstSize, srcPos, srcSize);
}

void Render::Draw(TextureBatcher* textureBatcher)
{
	_impl->Draw(textureBatcher);
}
