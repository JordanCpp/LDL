#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Core/RuntimeError.hpp>

#define STBI_NO_SIMD
#define STB_IMAGE_IMPLEMENTATION
#define STBI_NO_THREAD_LOCALS
#include "../dependencies/stb/stb_image.h"  

LDL::Loaders::ImageLoader::ImageLoader() :
	_IsKey(false),
	_BytesPerPixel(0),
	_Pixels(NULL)
{
}

LDL::Loaders::ImageLoader::~ImageLoader()
{
	Clear();
}

bool LDL::Loaders::ImageLoader::IsKey()
{
	return _IsKey;
}
const LDL::Graphics::Color& LDL::Loaders::ImageLoader::Key()
{
	return _Key;
}

void LDL::Loaders::ImageLoader::Clear()
{
	if (_Pixels != NULL)
	{
		stbi_image_free(_Pixels);
		_Pixels = NULL;
	}

	_Size = LDL::Graphics::Point2u(0, 0);
	_BytesPerPixel = 0;
	_IsKey = false;
}

const LDL::Graphics::Point2u& LDL::Loaders::ImageLoader::Size()
{
	return _Size;
}

uint8_t LDL::Loaders::ImageLoader::BytesPerPixel()
{
	return _BytesPerPixel;
}

uint8_t* LDL::Loaders::ImageLoader::Pixels()
{
	return _Pixels;
}

void LDL::Loaders::ImageLoader::Load(const std::string& path)
{
	if (path.empty())
		throw LDL::Core::RuntimeError("Argument path is empty");

	Clear();

	int width = 0;
	int height = 0;
	int bytesPerPixel = 0;

	stbi_set_flip_vertically_on_load(true);

	_Pixels = stbi_load(path.c_str(), &width, &height, &bytesPerPixel, 0);

	if (width <= 0 || height <= 0 || bytesPerPixel <= 0 || _Pixels == NULL)
		throw LDL::Core::RuntimeError("stbi_load: " + path + " failed");

	_Size = LDL::Graphics::Point2u(width, height);
	_BytesPerPixel = bytesPerPixel;
}

void LDL::Loaders::ImageLoader::Load(const LDL::Graphics::Color& color, const std::string& path)
{
	Load(path);

	_IsKey = true;
	_Key = color;
}