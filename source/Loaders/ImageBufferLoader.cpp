#include <LDL/Loaders/ImageBufferLoader.hpp>
#include <LDL/Core/RuntimeError.hpp>

static LDL::Allocators::Allocator* StbImageAllocator;

#define STBI_MALLOC(sz)        StbImageAllocator->Allocate(sz);
#define STBI_REALLOC(p,newsz)  StbImageAllocator->Reallocate(p,newsz)
#define STBI_FREE(p)           StbImageAllocator->Deallocate(p) 

#define STB_IMAGE_IMPLEMENTATION
#define STBI_NO_THREAD_LOCALS
#include "../dependencies/stb/stb_image.h"  

LDL::Loaders::ImageBufferLoader::ImageBufferLoader(LDL::Allocators::Allocator* allocator) :
	_Allocator(allocator),
	_BytesPerPixel(0),
	_Pixels(nullptr)
{
	assert(allocator != nullptr);

	StbImageAllocator = _Allocator;
}

LDL::Loaders::ImageBufferLoader::~ImageBufferLoader()
{
	Clear();
}

void LDL::Loaders::ImageBufferLoader::Clear()
{
	_Allocator->Reset();
	_Pixels = nullptr;
	_Size = LDL::Graphics::Point2u(0, 0);
	_BytesPerPixel = 0;
}

const LDL::Graphics::Point2u& LDL::Loaders::ImageBufferLoader::Size()
{
	return _Size;
}

size_t LDL::Loaders::ImageBufferLoader::BytesPerPixel()
{
	return _BytesPerPixel;
}

uint8_t* LDL::Loaders::ImageBufferLoader::Pixels()
{
	return _Pixels;
}

void LDL::Loaders::ImageBufferLoader::Load(const std::string& path)
{
	if (path.empty())
		throw LDL::Core::RuntimeError("Argument path is empty");

	Clear();

	int width         = 0;
	int height        = 0;
	int bytesPerPixel = 0;

	stbi_set_flip_vertically_on_load(true);

	_Pixels = stbi_load(path.c_str(), &width, &height, &bytesPerPixel, 0);

	if (width <= 0)
		throw LDL::Core::RuntimeError("Width image <= 0");

	if (height <= 0)
		throw LDL::Core::RuntimeError("Height image <= 0");

	if (bytesPerPixel <= 0)
		throw LDL::Core::RuntimeError("Bytes per pixel image <= 0");

	if (_Pixels == nullptr)
		throw LDL::Core::RuntimeError("Pixels image not load");

	_Size = LDL::Graphics::Point2u(width, height);
	_BytesPerPixel = bytesPerPixel;
}