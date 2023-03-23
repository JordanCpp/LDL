#include <LDL/Graphics/Texture.hpp>

#ifdef LDL_RENDER_SOFTWARE
#include "Software/TextureImpl.hpp"
#elif LDL_RENDER_GDI
#include "GDI/TextureImpl.hpp"
#elif LDL_RENDER_OPENGL1
#include "OpenGL1/TextureImpl.hpp"
#elif LDL_RENDER_OPENGL3
#include "OpenGL3/TextureImpl.hpp"
#elif LDL_RENDER_DIRECTX1
#include "DirectDraw/TextureImpl.hpp"
#elif LDL_RENDER_DIRECTX5
#include "DirectX5/Direct3D/TextureImpl.hpp"
#elif LDL_RENDER_DIRECTX9
#include "DirectX9/Direct3D/TextureImpl.hpp"
#endif

using namespace LDL::Graphics;

Texture::Texture(Render* render, const Point2u& size, uint8_t* pixels, uint8_t bytesPerPixel) :
	_TextureImpl(new TextureImpl(render->GetRenderImpl(), size, pixels, bytesPerPixel))
{
}

Texture::~Texture()
{
	delete _TextureImpl;
}

const Point2u& Texture::Size()
{
	return _TextureImpl->Size();
}

TextureImpl* Texture::GetTextureImpl()
{
	return _TextureImpl;
}