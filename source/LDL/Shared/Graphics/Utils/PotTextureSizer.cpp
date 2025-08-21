#include "PotTextureSizer.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

const size_t _TextureCount = 13;
const size_t _TextureSizes[_TextureCount] = {16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536 };

size_t Utils::PotTextureSizer::Calc(const Vec2u& size)
{
	size_t w = size.x;
	size_t h = size.y;

	for (size_t i = 0; i < _TextureCount; i++)
	{
		if (w <= _TextureSizes[i] && h <= _TextureSizes[i])
		{
			return _TextureSizes[i];
		}
	}

	return 0;
}
