#include <LDL/Graphics/Texture.hpp>

#ifdef LDL_RENDER_SOFTWARE
#include "Software/TextureImpl.hpp"
#elif LDL_RENDER_GDI
#include "GDI/TextureImpl.hpp"
#elif LDL_RENDER_OPENGL1
#include "OpenGL1/TextureImpl.hpp"
#elif LDL_RENDER_OPENGL3
#include "OpenGL3/TextureImpl.hpp"
#elif LDL_RENDER_DIRECT_DRAW
#include "DirectDraw/TextureImpl.hpp"
#elif LDL_RENDER_DIRECTX5
#include "DirectX5/Direct3D/TextureImpl.hpp"
#elif LDL_RENDER_DIRECTX9
#include "DirectX9/Direct3D/TextureImpl.hpp"
#elif LDL_RENDER_DIRECTX10
#include "DirectX10/Direct3D/TextureImpl.hpp"
#endif

using namespace LDL::Graphics;
using namespace LDL::Math;

Texture::Texture(RenderContext* renderContext, const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel) :
	_TextureImpl(new TextureImpl(renderContext->GetRenderContextImpl(), size, pixels, bytesPerPixel))
{
}

Texture::Texture(RenderContext* renderContext, const Vec2u& size, uint8_t bytesPerPixel) :
	_TextureImpl(new TextureImpl(renderContext->GetRenderContextImpl(), size, bytesPerPixel))
{
}

Texture::~Texture()
{
	delete _TextureImpl;
}

void Texture::Copy(const Vec2u& dstPos, const Vec2u& srcSize, uint8_t* pixels, size_t bytesPerPixel)
{
	_TextureImpl->Copy(dstPos, srcSize, pixels, bytesPerPixel);
}

void Texture::Copy(const Vec2u& dstPos, Surface* surface, const Vec2u& srcSize)
{
	_TextureImpl->Copy(dstPos, surface, srcSize);
}

const Vec2u& Texture::Size()
{
	return _TextureImpl->Size();
}

TextureImpl* Texture::GetTextureImpl()
{
	return _TextureImpl;
}