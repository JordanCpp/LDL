// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Shared/Graphics/Renders/Software/RenderImplSoftware.hpp>

#if defined(_WIN32)
    #include <LDL/Platforms/Windows/Graphics/WindowImplSoftware.hpp>
#elif defined(__unix__)
    #include <LDL/Platforms/Linux/Graphics/Software/WindowImplSoftware.hpp>
#endif

using namespace LDL;

RenderImplSoftware::RenderImplSoftware(Result& result, RenderContextImpl* renderContextImpl, Window* window) :
	_result(result),
	_window(window),
	_canvas(PixelFormat::BGR24, _window->Size()),
	_imageResizer(_window->Size())
{
	LDL_UNUSED(renderContextImpl);
}

void RenderImplSoftware::Buffer(uint8_t* dst)
{
	LDL_UNUSED(dst);
}

void RenderImplSoftware::Begin()
{
}

void RenderImplSoftware::End()
{
	WindowImplSoftware* windowImpl = (WindowImplSoftware*)_window->GetWindowImpl();

	windowImpl->Present(_canvas.Pixels(), _canvas.BytesPerPixel());
}

const Vec2u& RenderImplSoftware::Size()
{
	return _window->Size();
}

const Color& RenderImplSoftware::GetColor()
{
	return _color;
}

void RenderImplSoftware::Clear()
{
	_pixelPainter.Clear(_canvas.Format(), _canvas.Pixels(), _canvas.Size(), _color);
}

void RenderImplSoftware::SetColor(const Color& color)
{
	_color = color;
}

void RenderImplSoftware::Pixel(const Vec2u& pos)
{
}

void RenderImplSoftware::Line(const Vec2u& pos1, const Vec2u& pos2)
{
	_pixelPainter.Fill(_canvas.Format(), _canvas.Pixels(), _canvas.Size(), pos1, pos2, _color);
}

void RenderImplSoftware::Fill(const Vec2u& pos, const Vec2u& size)
{
	_pixelPainter.Fill(_canvas.Format(), _canvas.Pixels(), _canvas.Size(), pos, size, _color);
}

void RenderImplSoftware::Draw(Texture* image, const Vec2u& pos, const Vec2u& size)
{
	TextureImplSoftware* textureImpl = (TextureImplSoftware*)image->GetTextureImpl();

	Draw(textureImpl->GetSurface(), pos, size);
}

void RenderImplSoftware::Draw(Texture* image, const Vec2u& pos)
{
	Draw(image, pos, image->Size());
}

void RenderImplSoftware::Draw(Surface* image, const Vec2u& pos, const Vec2u& size)
{
	if (size.x != image->Size().x || size.y != image->Size().y)
	{
		Surface* result = _imageResizer.Resize(size, image);
		//_pixelCopier.Copy(result, &_canvas, pos);
	}
	else
	{
		_pixelCopier.Copy(image->Format(), image->Pixels(), image->Size(), image, _canvas.Format(), _canvas.Pixels(), _canvas.Size(), pos, &_canvas);
	}
}

void RenderImplSoftware::Draw(Surface* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
	LDL_UNUSED(image);
	LDL_UNUSED(dstPos);
	LDL_UNUSED(srcPos);
	LDL_UNUSED(srcSize);
}

void RenderImplSoftware::Draw(Surface* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
	LDL_UNUSED(image);
	LDL_UNUSED(dstPos);
	LDL_UNUSED(dstSize);
	LDL_UNUSED(srcPos);
	LDL_UNUSED(srcSize);
}

void RenderImplSoftware::Draw(Surface* image, const Vec2u& pos)
{
	Draw(image, pos, image->Size());
}

void RenderImplSoftware::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
	LDL_UNUSED(image);
	LDL_UNUSED(dstPos);
	LDL_UNUSED(srcPos);
	LDL_UNUSED(srcSize);
}

void RenderImplSoftware::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
	LDL_UNUSED(image);
	LDL_UNUSED(dstPos);
	LDL_UNUSED(dstSize);
	LDL_UNUSED(srcPos);
	LDL_UNUSED(srcSize);
}

void RenderImplSoftware::Draw(SpriteBatcher* textureBatcher)
{
	LDL_UNUSED(textureBatcher);
}
