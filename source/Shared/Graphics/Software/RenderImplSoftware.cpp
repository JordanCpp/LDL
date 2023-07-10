#include "RenderImplSoftware.hpp"

#if defined(_WIN32)
#include "../source/Platforms/Windows/Graphics/Software/WindowImplSoftware.hpp"
#elif defined(__unix__)
#include "../../Platforms/Linux/Graphics/Software/WindowImplSoftware.hpp"
#endif

using namespace LDL::Graphics;
using namespace LDL::Math;

RenderImplSoftware::RenderImplSoftware(RenderContextImpl* renderContextImpl, Window* window) :
	_Window(window),
	_Canvas(_Window->Size(), 3),
	_ImageResizer(_Window->Size())
{
	_PixelPainter.Bind(&_Canvas);
}

void RenderImplSoftware::Buffer(uint8_t* dst)
{
}

void RenderImplSoftware::Begin()
{
}

void RenderImplSoftware::End()
{
	WindowImplSoftware* windowImpl = (WindowImplSoftware*)_Window->GetWindowImpl();

	windowImpl->Present(_Canvas.Pixels(), _Canvas.BytesPerPixel());
}

const Vec2u& RenderImplSoftware::Size()
{
	return _Window->Size();
}

const Color& RenderImplSoftware::Color()
{
	return _PixelPainter.Color();
}

void RenderImplSoftware::Clear()
{
	_PixelPainter.Clear();
}

void RenderImplSoftware::Color(const LDL::Graphics::Color& color)
{
	_PixelPainter.Color(color);
}

void RenderImplSoftware::Pixel(const Vec2u& pos)
{
	_PixelPainter.Pixel(pos);
}

void RenderImplSoftware::Line(const Vec2u& pos1, const Vec2u& pos2)
{
	_PixelPainter.Line(pos1, pos2);
}

void RenderImplSoftware::Fill(const Vec2u& pos, const Vec2u& size)
{
	_PixelPainter.Fill(pos, size);
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
		Surface* result = _ImageResizer.Resize(size, image);
		_PixelCopier.Copy(result, &_Canvas, pos);
	}
	else
	{
		_PixelCopier.Copy(image, &_Canvas, pos);
	}
}

void RenderImplSoftware::Draw(Surface* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImplSoftware::Draw(Surface* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImplSoftware::Draw(Surface* image, const Vec2u& pos)
{
	Draw(image, pos, image->Size());
}

void RenderImplSoftware::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImplSoftware::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImplSoftware::Draw(TextureBatcher* textureBatcher)
{
}