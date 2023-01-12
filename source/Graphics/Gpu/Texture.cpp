#include <LDL/Graphics/Texture.hpp>

#ifdef LDL_GPU_SUPPORT_OPENGL1
#include "../GL1/TextureImpl.hpp"
#elif LDL_GPU_SUPPORT_DIRECTX1
#include "../DirectDraw1/GpuImageImpl.hpp"
#endif

using namespace LDL::Graphics;

Texture::Texture(const Point2u& size, size_t bytesPerPixel, uint8_t* pixels) :
	_TextureImpl(new TextureImpl(size, bytesPerPixel, pixels))
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

size_t Texture::Id()
{
	return _TextureImpl->Id();
}