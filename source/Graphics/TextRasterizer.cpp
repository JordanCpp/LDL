#include <LDL/Graphics/TextRasterizer.hpp>
#include <LDL/Core/RuntimeError.hpp>

static LDL::Allocators::Allocator* StbTrueTypeAllocator;

#define STBTT_malloc(x,u)  ((void)(u),StbTrueTypeAllocator->Allocate(x))
#define STBTT_free(x,u)    ((void)(u),StbTrueTypeAllocator->Deallocate(x))

#define STB_TRUETYPE_IMPLEMENTATION 
#include "../dependencies/stb/stb_truetype.h"

LDL::Graphics::TextRasterizer::TextRasterizer(LDL::Allocators::Allocator* allocator) :
	_Allocator(allocator),
	_Result(nullptr),
	_Bitmap(nullptr)
{
	StbTrueTypeAllocator = _Allocator;
}

LDL::Graphics::TextRasterizer::~TextRasterizer()
{
}

LDL::Graphics::CpuImage* LDL::Graphics::TextRasterizer::Result()
{
	return _Result;
}

void LDL::Graphics::TextRasterizer::Create(LDL::Loaders::FontBufferLoader* fontBufferLoader, size_t size, const std::string& text)
{
	stbtt_fontinfo info;

	if (!stbtt_InitFont(&info, fontBufferLoader->Font(), 0))
		throw LDL::Core::RuntimeError("stbtt_InitFont failed");
}