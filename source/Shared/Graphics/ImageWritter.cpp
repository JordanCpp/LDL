#include <LDL/Graphics/ImageWritter.hpp>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#undef __STDC_LIB_EXT1__
#include "../../Libraries/stb/stb_image_write.h"  

using namespace LDL::Graphics;
using namespace LDL::Math;

void ImageWritter::Save(const std::string& path, const Vec2u& size, size_t bytesPerPixel, uint8_t* pixels)
{
	stbi_flip_vertically_on_write(true);

	stbi_write_png(path.c_str(), (int)size.x, (int)size.y, (int)bytesPerPixel, pixels, (int)size.x * (int)bytesPerPixel);
}
