#include <LDL/Graphics/TextureBatcher.hpp>

#ifdef LDL_RENDER_SOFTWARE
#include "Software/TextureBatcherImpl.hpp"
#elif LDL_RENDER_GDI
#include "GDI/TextureBatcherImpl.hpp"
#elif LDL_RENDER_OPENGL1
#include "OpenGL1/TextureBatcherImpl.hpp"
#elif LDL_RENDER_OPENGL3
#include "OpenGL3/TextureBatcherImpl.hpp"
#elif LDL_RENDER_DIRECT_DRAW
#include "DirectDraw/TextureBatcherImpl.hpp"
#elif LDL_RENDER_DIRECTX5
#include "DirectX5/Direct3D/TextureBatcherImpl.hpp"
#elif LDL_RENDER_DIRECTX9
#include "DirectX9/Direct3D/TextureBatcherImpl.hpp"
#elif LDL_RENDER_DIRECTX10
#include "DirectX10/Direct3D/TextureBatcherImpl.hpp"
#endif

using namespace LDL::Graphics;
using namespace LDL::Math;

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

void TextureBatcher::Draw(const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
	_TextureBatcherImpl->Draw(dstPos, dstSize, srcPos, srcSize);
}

void TextureBatcher::Clear()
{
	_TextureBatcherImpl->Clear();
}