#include "TextureBatcherImplOpenGL3.hpp"
#include "TextureImplOpenGL3.hpp"
#include "../OpenGL/Util.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

TextureBatcherImplOpenGL3::TextureBatcherImplOpenGL3(Texture* texture, size_t count) :
	_Texture(((TextureImplOpenGL3*)texture->GetTextureImpl())->Id()),
	_TextureSize(texture->GetTextureImpl()->Quad().x)
{
	_Quads.reserve(count);
}

void TextureBatcherImplOpenGL3::Draw(const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
	Quad quad;

	float ps = 1.0f / (float)_TextureSize;

	quad.data[0] = (float)dstPos.x;
	quad.data[1] = float(dstSize.y + dstPos.y);
	quad.data[2] = 0.0f;
	quad.data[3] = ps * srcPos.x;
	quad.data[4] = ps * (srcSize.y + srcPos.y);

	quad.data[5] = float(dstSize.x + dstPos.x);
	quad.data[6] = float(dstSize.y + dstPos.y);
	quad.data[7] = 0.0f;
	quad.data[8] = ps * (srcSize.x + srcPos.x);
	quad.data[9] = ps * (srcSize.y + srcPos.y);

	quad.data[10] = (float)dstPos.x;
	quad.data[11] = (float)dstPos.y;
	quad.data[12] = 0.0f;
	quad.data[13] = ps * srcPos.x;
	quad.data[14] = ps * srcPos.y;

	quad.data[15] = float(dstSize.x + dstPos.x);
	quad.data[16] = float(dstSize.y + dstPos.y);
	quad.data[17] = 0.0f;
	quad.data[18] = ps * (srcSize.x + srcPos.x);
	quad.data[19] = ps * (srcSize.y + srcPos.y);

	quad.data[20] = float(dstSize.x + dstPos.x);
	quad.data[21] = (float)dstPos.y;
	quad.data[22] = 0.0f;
	quad.data[23] = ps * (srcSize.x + srcPos.x);
	quad.data[24] = ps * srcPos.y;

	quad.data[25] = (float)dstPos.x;
	quad.data[26] = (float)dstPos.y;
	quad.data[27] = 0.0f;
	quad.data[28] = ps * srcPos.x;
	quad.data[29] = ps * srcPos.y;

	_Quads.push_back(quad);
}

void TextureBatcherImplOpenGL3::Clear()
{
	_Quads.clear();
}

size_t TextureBatcherImplOpenGL3::TextureId()
{
	return _Texture;
}

size_t TextureBatcherImplOpenGL3::Count()
{
	return _Quads.size();
}

Quad* TextureBatcherImplOpenGL3::Content()
{
	return &_Quads[0];
}