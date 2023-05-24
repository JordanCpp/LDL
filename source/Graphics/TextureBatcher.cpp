#include <LDL/Graphics/TextureBatcher.hpp>

#ifdef LDL_RENDER_SOFTWARE
#include "Software/TextureBatcherImpl.hpp"
#elif LDL_RENDER_GDI
#include "GDI/TextureBatcherImpl.hpp"
#elif LDL_RENDER_OPENGL1
#include "OpenGL1/TextureBatcherImpl.hpp"
#elif LDL_RENDER_OPENGL3
#include "OpenGL3/TextureBatcherImpl.hpp"
#elif LDL_RENDER_DIRECTX1
#include "DirectDraw/TextureBatcherImpl.hpp"
#elif LDL_RENDER_DIRECTX5
#include "DirectX5/Direct3D/TextureBatcherImpl.hpp"
#elif LDL_RENDER_DIRECTX9
#include "DirectX9/Direct3D/TextureBatcherImpl.hpp"
#elif LDL_RENDER_DIRECTX10
#include "DirectX10/Direct3D/TextureBatcherImpl.hpp"
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