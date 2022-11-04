#include <LDL/Graphics/TextRasterizer.hpp>
#include <LDL/Core/RuntimeError.hpp>

#define STB_TRUETYPE_IMPLEMENTATION 
#include "../dependencies/stb/stb_truetype.h"

LDL::Graphics::TextRasterizer::TextRasterizer(LDL::Allocators::Allocator* allocator) :
	_Allocator(allocator),
	_Result(nullptr)
{
}

LDL::Graphics::TextRasterizer::~TextRasterizer()
{
}

LDL::Graphics::CpuImage* LDL::Graphics::TextRasterizer::Result()
{
	return _Result;
}

void LDL::Graphics::TextRasterizer::Create(LDL::Loaders::FontBufferLoader* fontBufferLoader, const std::string& text)
{
	stbtt_fontinfo info;

	if (!stbtt_InitFont(&info, fontBufferLoader->Font(), 0))
		throw LDL::Core::RuntimeError("stbtt_InitFont failed");
}