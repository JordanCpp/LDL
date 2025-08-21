#include <Arcanum/Loaders/ArtLoader.hpp>

using namespace LDL::Math;
using namespace Arcanum::Loaders;
using namespace Arcanum::Readers;
using namespace Arcanum::Formats;

void ArtLoader::Load(MemoryReader& memoryReader)
{
	_file.LoadArt(memoryReader);
}

const Vec2u& ArtLoader::Size()
{
	return _size;
}

const Vec2u& ArtLoader::Offset()
{
	return _offset;
}

const Vec2u& ArtLoader::Delta()
{
	return _delta;
}

uint8_t* ArtLoader::Pixels()
{
	return &_pixels[0];
}

size_t ArtLoader::Frames()
{
	return _file.frame_data.size();
}

void ArtLoader::Frame(size_t index)
{
	size_t w = _file.frame_data[index].header.width;
	size_t h = _file.frame_data[index].header.height;
	_size = Vec2u(w, h);

	size_t ow = _file.frame_data[index].header.c_x;
	size_t oh = _file.frame_data[index].header.c_y;
	_offset = Vec2u(ow, oh);

	size_t dw = _file.frame_data[index].header.d_x;
	size_t dh = _file.frame_data[index].header.d_y;
	_delta = Vec2u(dw, dh);

	_pixels.clear();
	_pixels.resize(w * h * 4);

	for (size_t y = 0; y < h; y++)
	{
		for (size_t x = 0; x < w; x++)
		{
			size_t i = ((w * y) + x) * 4;

			ArtTable& table = _file.palette_data[0];

			uint8_t c = _file.frame_data[index].GetValue(x, y);

			uint8_t r = table.colors[c].r;
			uint8_t g = table.colors[c].g;
			uint8_t b = table.colors[c].b;

			if (c != 0)
			{
				_pixels[i + 0] = r;
				_pixels[i + 1] = g;
				_pixels[i + 2] = b;
				_pixels[i + 3] = 255;
			}
			else
			{
				_pixels[index + 0] = 0;
				_pixels[index + 1] = 0;
				_pixels[index + 2] = 0;
				_pixels[index + 3] = 0;
			}
		}
	}
}