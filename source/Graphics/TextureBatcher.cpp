#include <LDL/Graphics/TextureBatcher.hpp>

#ifdef LDL_RENDER_OPENGL1
#include "OpenGL1/TextureBatcherImpl.hpp"
#endif

using namespace LDL::Graphics;

TextureBatcher::TextureBatcher(Texture* texture, size_t count) :
	_TextureBatcherImpl(new TextureBatcherImpl(texture, count))
{
}

TextureBatcher::~TextureBatcher()
{
	delete _TextureBatcherImpl;
}

TextureBatcherImpl* TextureBatcher::GetTextureBatcherImpl()
{
	return _TextureBatcherImpl;
}

void TextureBatcher::Draw(const Point2u& dstPos, const Point2u& dstSize, const Point2u& srcPos, const Point2u& srcSize)
{
	_TextureBatcherImpl->Draw(dstPos, dstSize, srcPos, srcSize);
}

void TextureBatcher::Clear()
{
	_TextureBatcherImpl->Clear();
}