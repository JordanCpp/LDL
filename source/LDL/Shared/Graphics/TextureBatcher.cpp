#include <LDL/Graphics/TextureBatcher.hpp>
#include "Creators/TextureBatcherImplCreator.hpp"

using namespace LDL::Math;
using namespace LDL::Graphics;
using namespace LDL::Graphics::Creators;

TextureBatcher::TextureBatcher(RenderContext* renderContext, Texture* texture, size_t count)
{
	TextureBatcherImplCreator creator;

	_impl = creator.Create(renderContext, texture, count);
}

TextureBatcher::~TextureBatcher()
{
	delete _impl;
}

TextureBatcherImpl* TextureBatcher::GetTextureBatcherImpl()
{
	return _impl;
}

void TextureBatcher::Draw(const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
	_impl->Draw(dstPos, dstSize, srcPos, srcSize);
}

void TextureBatcher::Clear()
{
	_impl->Clear();
}
