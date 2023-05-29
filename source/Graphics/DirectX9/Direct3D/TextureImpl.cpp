#include "TextureImpl.hpp"
#include <assert.h>
#include <LDL/Core/RuntimeError.hpp>
#include "RenderContextImpl.hpp"

using namespace LDL::Graphics;

TextureImpl::TextureImpl(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t* pixels, size_t bytesPerPixel) :
	_Texture(NULL)
{
	assert(size.x > 0);
	assert(size.y > 0);
	assert(pixels != NULL);
	assert(bytesPerPixel >= 1 && bytesPerPixel <= 4);

	_Size = size;

	HRESULT result = NULL;

	D3DFORMAT format;

	if (bytesPerPixel == 4)
		format = D3DFMT_A8R8G8B8;
	else
		format = D3DFMT_R8G8B8;
	
	result = D3DXCreateTexture(renderContextImpl->Context.Device, (UINT)size.x, (UINT)size.y, D3DX_DEFAULT, 0, format, D3DPOOL_MANAGED, &_Texture);
	if (FAILED(result))
		throw LDL::Core::RuntimeError("D3DXCreateTexture failed");

	D3DLOCKED_RECT rect;

	result = _Texture->LockRect(0, &rect, NULL, D3DLOCK_DISCARD);
	if (FAILED(result))
		throw LDL::Core::RuntimeError("LockRect failed");

	memcpy(rect.pBits, pixels, Size().x * Size().y * bytesPerPixel);
	
	result = _Texture->UnlockRect(0);
	if (FAILED(result))
		throw LDL::Core::RuntimeError("UnlockRect failed");
}

TextureImpl::~TextureImpl()
{
	if (_Texture != NULL)
	{
		_Texture->Release();
		_Texture = NULL;
	}
}

const Vec2u& TextureImpl::Size()
{
	return _Size;
}

IDirect3DTexture9* LDL::Graphics::TextureImpl::Texture()
{
	return _Texture;
}
