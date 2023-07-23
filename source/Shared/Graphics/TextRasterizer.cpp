#include <LDL/Graphics/TextRasterizer.hpp>
#include <LDL/Core/RuntimeError.hpp>

static LDL::Allocators::Allocator* StbTrueTypeAllocator;

#define STBTT_malloc(x,u)  ((void)(u),StbTrueTypeAllocator->Allocate(x))
#define STBTT_free(x,u)    ((void)(u),StbTrueTypeAllocator->Deallocate(x))

#define STB_TRUETYPE_IMPLEMENTATION 
#include "../../../dependencies/stb/stb_truetype.h"

using namespace LDL::Graphics;

TextRasterizer::TextRasterizer(LDL::Allocators::Allocator* allocator) :
	_Allocator(allocator)
{
	assert(_Allocator != NULL);

	StbTrueTypeAllocator = _Allocator;
}

TextRasterizer::~TextRasterizer()
{
}
