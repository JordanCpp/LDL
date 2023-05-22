#include "TextureBatcherImpl.hpp"
#include "TextureImpl.hpp"
#include "../OpenGL/Util.hpp"

using namespace LDL::Graphics;

TextureBatcherImpl::TextureBatcherImpl(Texture* texture, size_t count) :
	_Texture(texture->GetTextureImpl()->Id()),
	_TextureSize(texture->GetTextureImpl()->Quad().PosX())
{
	_Quads.reserve(count);
}

void TextureBatcherImpl::Draw(const Point2u& dstPos, const Point2u& dstSize, const Point2u& srcPos, const Point2u& srcSize)
{
	Util::Quad quad;

	Util::CalcQuad(quad, (uint16_t)dstPos.PosX(), (uint16_t)dstPos.PosY(), (uint16_t)dstSize.PosX(), (uint16_t)dstSize.PosY(), (uint16_t)srcPos.PosX(), (uint16_t)srcPos.PosY(), (uint16_t)srcSize.PosX(), (uint16_t)srcSize.PosY(), _TextureSize);

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