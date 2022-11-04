#include <LDL/Graphics/TextRasterizer.hpp>

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