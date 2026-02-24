// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Graphics/Render.hpp>
#include <LDL/Shared/Graphics/Creators/RenderImplCreator.hpp>

using namespace LDL;

Render::Render(Result& result, RenderContext& renderContext, Window* window)
{
	RenderImplCreator creator;

	_impl = creator.Create(result, renderContext, window);
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

const Color& Render::GetColor()
{
	return _impl->GetColor();
}

void Render::Clear()
{
	_impl->Clear();
}

void Render::SetColor(const Color& color)
{
	_impl->SetColor(color);
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
