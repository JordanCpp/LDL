#include <LDL/Graphics/TextRasterizer.hpp>
#include <LDL/Core/RuntimeError.hpp>

static LDL::Allocators::Allocator* StbTrueTypeAllocator;

#define STBTT_malloc(x,u)  ((void)(u),StbTrueTypeAllocator->Allocate(x))
#define STBTT_free(x,u)    ((void)(u),StbTrueTypeAllocator->Deallocate(x))

#define STB_TRUETYPE_IMPLEMENTATION 
#include "../dependencies/stb/stb_truetype.h"

using namespace LDL::Graphics;

TextRasterizer::TextRasterizer(LDL::Allocators::Allocator* allocator) :
	_Allocator(allocator),
	_Result(NULL),
	_Bitmap(NULL)
{
	assert(_Allocator != NULL);

	StbTrueTypeAllocator = _Allocator;
}

TextRasterizer::~TextRasterizer()
{
}

Surface* TextRasterizer::Result()
{
	return _Result;
}

void TextRasterizer::Create(LDL::Loaders::FontLoader* fontBufferLoader, size_t size, const std::string& text)
{
	stbtt_fontinfo info;

	if (!stbtt_InitFont(&info, fontBufferLoader->Font(), 0))
		throw LDL::Core::RuntimeError("stbtt_InitFont failed");
}