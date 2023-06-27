#include "TextureBatcherImplDirect3D9.hpp"
#include "TextureImplDirect3D9.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

TextureBatcherImplDirect3D9::TextureBatcherImplDirect3D9(Texture* texture, size_t count) :
	_TextureSize(texture->GetTextureImpl()->Quad().x)
{
}

void TextureBatcherImplDirect3D9::Draw(const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void TextureBatcherImplDirect3D9::Clear()
{
}

size_t TextureBatcherImplDirect3D9::TextureId()
{
	return _Texture;
}

size_t TextureBatcherImplDirect3D9::Count()
{
	return 0;
}