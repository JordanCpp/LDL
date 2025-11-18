// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Shared/Graphics/Renders/OpenGL/Util.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL3/TextureImplOpenGL3.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL3/TextureBatcherImplOpenGL3.hpp>

using namespace LDL;

SpriteBatcherImplOpenGL3::SpriteBatcherImplOpenGL3(ITexture* texture, size_t count) :
	_texture(((TextureImplOpenGL3*)texture)->Id()),
	_textureSize(texture->Quad().x)
{
	_quads.reserve(count);
}

void SpriteBatcherImplOpenGL3::Draw(const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
	Quad quad;

	float ps = 1.0f / (float)_textureSize;

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

	_quads.push_back(quad);
}

void SpriteBatcherImplOpenGL3::Clear()
{
	_quads.clear();
}

size_t SpriteBatcherImplOpenGL3::TextureId()
{
	return _texture;
}

size_t SpriteBatcherImplOpenGL3::Count()
{
	return _quads.size();
}

Quad* SpriteBatcherImplOpenGL3::Content()
{
	return &_quads[0];
}
