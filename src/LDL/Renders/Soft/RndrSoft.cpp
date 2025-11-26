// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Renders/Soft/RndrSoft.hpp>

#if defined(LDL_WINDOWS_NT)
    #include <LDL/WinNT/WinSoft.hpp>
#elif defined(LDL_WINDOWS_9X)
    #include <LDL/Win9X/WinSoft.hpp>
#elif defined(__unix__)
    #include <LDL/Linux/WinSoft.hpp>
#else
    #include <LDL/Null/WinSoft.hpp>
#endif

LDL_RenderSoftware::LDL_RenderSoftware(LDL_Result& result, LDL_RenderContext* renderContextImpl, LDL_IWindow* window) :
	_result(result),
	_window(window),
	_canvas(LDL_PixelFormat::BGR24, _window->Size()),
	_imageResizer(_window->Size())
{
	LDL_UNUSED(renderContextImpl);
}

void LDL_RenderSoftware::Buffer(uint8_t* dst)
{
	LDL_UNUSED(dst);
}

void LDL_RenderSoftware::Begin()
{
}

void LDL_RenderSoftware::End()
{
	LDL_WindowSoftware* windowImpl = (LDL_WindowSoftware*)_window;

	windowImpl->Present(_canvas.Pixels(), _canvas.BytesPerPixel());
}

const LDL_Vec2u& LDL_RenderSoftware::Size()
{
	return _window->Size();
}

const LDL_Color& LDL_RenderSoftware::GetColor()
{
	return _color;
}

void LDL_RenderSoftware::Clear()
{
	_pixelPainter.Clear(_canvas.Format(), _canvas.Pixels(), _canvas.Size(), _color);
}

void LDL_RenderSoftware::SetColor(const LDL_Color& color)
{
	_color = color;
}

void LDL_RenderSoftware::Pixel(const LDL_Vec2u& pos)
{
	LDL_UNUSED(pos);
}

void LDL_RenderSoftware::Line(const LDL_Vec2u& pos1, const LDL_Vec2u& pos2)
{
	_pixelPainter.Fill(_canvas.Format(), _canvas.Pixels(), _canvas.Size(), pos1, pos2, _color);
}

void LDL_RenderSoftware::Fill(const LDL_Vec2u& pos, const LDL_Vec2u& size)
{
	_pixelPainter.Fill(_canvas.Format(), _canvas.Pixels(), _canvas.Size(), pos, size, _color);
}

void LDL_RenderSoftware::Draw(LDL_ITexture* image, const LDL_Vec2u& pos, const LDL_Vec2u& size)
{
	LDL_TextureSoftware* textureImpl = (LDL_TextureSoftware*)image;

	Draw(textureImpl->GetSurface(), pos, size);
}

void LDL_RenderSoftware::Draw(LDL_ITexture* image, const LDL_Vec2u& pos)
{
	Draw(image, pos, image->Size());
}

void LDL_RenderSoftware::Draw(LDL_Surface* image, const LDL_Vec2u& pos, const LDL_Vec2u& size)
{
	if (size.x != image->Size().x || size.y != image->Size().y)
	{
		//Surface* result = _imageResizer.Resize(size, image);
		//_pixelCopier.Copy(result, &_canvas, pos);
	}
	else
	{
		_pixelCopier.Copy(image->Format(), image->Pixels(), image->Size(), image, _canvas.Format(), _canvas.Pixels(), _canvas.Size(), pos, &_canvas);
	}
}

void LDL_RenderSoftware::Draw(LDL_Surface* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize)
{
	LDL_UNUSED(image);
	LDL_UNUSED(dstPos);
	LDL_UNUSED(srcPos);
	LDL_UNUSED(srcSize);
}

void LDL_RenderSoftware::Draw(LDL_Surface* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize)
{
	LDL_UNUSED(image);
	LDL_UNUSED(dstPos);
	LDL_UNUSED(dstSize);
	LDL_UNUSED(srcPos);
	LDL_UNUSED(srcSize);
}

void LDL_RenderSoftware::Draw(LDL_Surface* image, const LDL_Vec2u& pos)
{
	Draw(image, pos, image->Size());
}

void LDL_RenderSoftware::Draw(LDL_ITexture* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize)
{
	LDL_UNUSED(image);
	LDL_UNUSED(dstPos);
	LDL_UNUSED(srcPos);
	LDL_UNUSED(srcSize);
}

void LDL_RenderSoftware::Draw(LDL_ITexture* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize)
{
	LDL_UNUSED(image);
	LDL_UNUSED(dstPos);
	LDL_UNUSED(dstSize);
	LDL_UNUSED(srcPos);
	LDL_UNUSED(srcSize);
}

void LDL_RenderSoftware::Draw(LDL_ISpriteBatcher* textureBatcher)
{
	LDL_UNUSED(textureBatcher);
}
