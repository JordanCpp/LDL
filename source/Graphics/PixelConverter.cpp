#include <LDL/Graphics/PixelConverter.hpp>

void LDL::Graphics::PixelConverter::RgbToBgr(uint8_t* pixels, const LDL::Graphics::Point2u& size, uint8_t bytesPerPixel)
{
	size_t bytes = size.PosX() * size.PosY() * bytesPerPixel;

	for (size_t i = 0; i < bytes; i += 4)
	{
		uint8_t temp = pixels[i + 2];
		pixels[i + 2] = pixels[i + 0];
		pixels[i + 0] = temp;
	}
}

void LDL::Graphics::PixelConverter::BgrToRgb(uint8_t* pixels, const LDL::Graphics::Point2u& size, uint8_t bytesPerPixel)
{
	size_t bytes = size.PosX() * size.PosY() * bytesPerPixel;

	for (size_t i = 0; i < bytes; i += 4)
	{
		uint8_t temp = pixels[i + 0];
		pixels[i + 0] = pixels[i + 2];
		pixels[i + 2] = temp;
	}
}