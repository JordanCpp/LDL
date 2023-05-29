#include "TextureBatcherImpl.hpp"
#include "TextureImpl.hpp"
#include "../OpenGL/Util.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

TextureBatcherImpl::TextureBatcherImpl(Texture* texture, size_t count) :
	_Texture(texture->GetTextureImpl()->Id()),
	_TextureSize(texture->GetTextureImpl()->Quad().x)
{
	_Quads.reserve(count);
}

void TextureBatcherImpl::Draw(const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
	Util::Quad quad;

	Util::CalcQuad(quad, (uint16_t)dstPos.x, (uint16_t)dstPos.y, (uint16_t)dstSize.x, (uint16_t)dstSize.y, (uint16_t)srcPos.x, (uint16_t)srcPos.y, (uint16_t)srcSize.x, (uint16_t)srcSize.y, _TextureSize);

	_Quads.push_back(quad);
}

void TextureBatcherImpl::Clear()
{
	_Quads.clear();
}

size_t TextureBatcherImpl::TextureId()
{
	return _Texture;
}

size_t TextureBatcherImpl::Count()
{
	return _Quads.size();
}

Util::Quad* TextureBatcherImpl::Content()
{
	return &_Quads[0];
}