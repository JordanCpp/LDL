#include <Arcanum/Loaders/ArtLoader.hpp>

using namespace Arcanum::Loaders;
using namespace LDL::Graphics;

void ArtLoader::Load(const std::string& path)
{
	_File.LoadArt(path);
}

const Point2u& ArtLoader::Size()
{
	return _Size;
}

uint8_t* ArtLoader::Pixels()
{
	return &_Pixels[0];
}

size_t ArtLoader::Frames()
{
	return _File.frame_data.size();
}

void ArtLoader::Frame(size_t index)
{
	size_t w = _File.frame_data[index].header.width;
	size_t h = _File.frame_data[index].header.height;

	_Size = Point2u(w, h);

	_Pixels.resize(w * h * 4);

	for (size_t y = 0; y < h; y++)
	{
		for (size_t x = 0; x < w; x++)
		{
			size_t i = ((w * y) + x) * 4;

			ArtTable& table = _File.palette_data[0];

			uint8_t c = _File.frame_data[index].GetValue(x, y);

			uint8_t r = table.colors[c].r;
			uint8_t g = table.colors[c].g;
			uint8_t b = table.colors[c].b;

			if (c != 0)
			{
				_Pixels[i + 0] = r;
				_Pixels[i + 1] = g;
				_Pixels[i + 2] = b;
				_Pixels[i + 3] = 255;
			}
			else
			{
				_Pixels[index + 0] = 0;
				_Pixels[index + 1] = 0;
				_Pixels[index + 2] = 0;
				_Pixels[index + 3] = 0;
			}
		}
	}
}