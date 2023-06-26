#include "TextureBatcherImplOpenGL1.hpp"
#include "TextureImplOpenGL1.hpp"
#include "../OpenGL/Util.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

TextureBatcherImplOpenGL1::TextureBatcherImplOpenGL1(Texture* texture, size_t count) :
	_Texture(((TextureImplOpenGL1*)texture->GetTextureImpl())->Id()),
	_TextureSize(texture->GetTextureImpl()->Quad().x)
{
	_Quads.reserve(count);
}

void TextureBatcherImplOpenGL1::Draw(const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
	Util::Quad quad;

	Util::CalcQuad(quad, (uint16_t)dstPos.x, (uint16_t)dstPos.y, (uint16_t)dstSize.x, (uint16_t)dstSize.y, (uint16_t)srcPos.x, (uint16_t)srcPos.y, (uint16_t)srcSize.x, (uint16_t)srcSize.y, _TextureSize);

	_Quads.push_back(quad);
}

void TextureBatcherImplOpenGL1::Clear()
{
	_Quads.clear();
}

size_t TextureBatcherImplOpenGL1::TextureId()
{
	return _Texture;
}

size_t TextureBatcherImplOpenGL1::Count()
{
	return _Quads.size();
}

Util::Quad* TextureBatcherImplOpenGL1::Content()
{
	return &_Quads[0];
}