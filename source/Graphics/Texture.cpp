#include <LDL/Graphics/Texture.hpp>

#ifdef LDL_RENDER_SOFTWARE
#include "Software/TextureImpl.hpp"
#elif LDL_RENDER_OPENGL1
#include "OpenGL1/TextureImpl.hpp"
#elif LDL_GPU_SUPPORT_DIRECTX1
#include "DirectDraw/TextureImpl.hpp"
#elif LDL_GPU_SUPPORT_DIRECTX5
#include "DirectX5/Direct3D/TextureImpl.hpp"
#elif LDL_GPU_SUPPORT_DIRECTX9
#include "DirectX9/Direct3D/TextureImpl.hpp"
#endif

using namespace LDL::Graphics;

Texture::Texture(const Point2u& size, uint8_t* pixels, uint8_t bytesPerPixel) :
	_TextureImpl(new TextureImpl(size, pixels, bytesPerPixel))
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