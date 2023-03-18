#include "TextureImpl.hpp"
#include <assert.h>

using namespace LDL::Graphics;

TextureImpl::TextureImpl(RenderImpl* renderImpl, const Point2u& size, uint8_t* pixels, size_t bytesPerPixel) :
	_Texture(NULL)
{
	assert(size.PosX() > 0);
	assert(size.PosY() > 0);
	assert(pixels != NULL);
	assert(bytesPerPixel >= 1 && bytesPerPixel <= 4);

	D3DXCreateTexture(renderImpl->_Direct3DDevice, size.PosX(), size.PosY(), 1, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &_Texture);
}

TextureImpl::~TextureImpl()
{
}

const Point2u& TextureImpl::Size()
{
	return _Size;
}

const size_t TextureImpl::Id()
{
	return 0;
}