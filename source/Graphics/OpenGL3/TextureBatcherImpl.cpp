#include "TextureBatcherImpl.hpp"
#include "TextureImpl.hpp"
#include "Util.hpp"

using namespace LDL::Graphics;

TextureBatcherImpl::TextureBatcherImpl(Texture* texture, size_t count) :
	_Texture(texture->GetTextureImpl()->Id()),
	_TextureSize(texture->GetTextureImpl()->Quad().PosX())
{
	_Quads.reserve(count);
}

void TextureBatcherImpl::Draw(const Point2u& dstPos, const Point2u& dstSize, const Point2u& srcPos, const Point2u& srcSize)
{
	Quad quad;

	float ps = 1.0f / (float)_TextureSize;

	quad.data[0] = dstPos.PosX();
	quad.data[1] = float(dstSize.PosY() + dstPos.PosY());
	quad.data[2] = 0.0f;
	quad.data[3] = ps * srcPos.PosX();
	quad.data[4] = ps * (srcSize.PosY() + srcPos.PosY());

	quad.data[5] = float(dstSize.PosX() + dstPos.PosX());
	quad.data[6] = float(dstSize.PosY() + dstPos.PosY());
	quad.data[7] = 0.0f;
	quad.data[8] = ps * (srcSize.PosX() + srcPos.PosX());
	quad.data[9] = ps * (srcSize.PosY() + srcPos.PosY());

	quad.data[10] = dstPos.PosX();
	quad.data[11] = dstPos.PosY();
	quad.data[12] = 0.0f;
	quad.data[13] = ps * srcPos.PosX();
	quad.data[14] = ps * srcPos.PosY();

	quad.data[15] = float(dstSize.PosX() + dstPos.PosX());
	quad.data[16] = float(dstSize.PosY() + dstPos.PosY());
	quad.data[17] = 0.0f;
	quad.data[18] = ps * (srcSize.PosX() + srcPos.PosX());
	quad.data[19] = ps * (srcSize.PosY() + srcPos.PosY());

	quad.data[20] = float(dstSize.PosX() + dstPos.PosX());
	quad.data[21] = dstPos.PosY();
	quad.data[22] = 0.0f;
	quad.data[23] = ps * (srcSize.PosX() + srcPos.PosX());
	quad.data[24] = ps * srcPos.PosY();

	quad.data[25] = dstPos.PosX();
	quad.data[26] = dstPos.PosY();
	quad.data[27] = 0.0f;
	quad.data[28] = ps * srcPos.PosX();
	quad.data[29] = ps * srcPos.PosY();

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

Quad* TextureBatcherImpl::Content()
{
	return &_Quads[0];
}