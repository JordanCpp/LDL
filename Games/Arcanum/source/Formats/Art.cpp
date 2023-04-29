/* ArtConverter by Alexey Stremov https://github.com/AxelStrem/ArtConverter/blob/master/artconverter.cpp
   Refactored for OpenArcanum https://github.com/OpenArcanum/artviewer */

#include <Arcanum/Formats/Art.hpp>

#include <iostream>
#include <sstream>


bool ArtFrame::Inc()
{
	px++;
	if (px >= static_cast<int>(header.width))
	{
		px = 0;
		py++;
	}
	if (py >= static_cast<int>(header.height)) return false;
	if (py < 0) return false;
	return true;
}

void ArtFrame::Dec()
{
	px--;
	if (px < 0)
	{
		px = header.width - 1;
		py--;
	}
}

void ArtFrame::Reset()
{
	px = py = 0;
}

bool ArtFrame::EOD()
{
	if (py < static_cast<int>(header.height)) return false;
	return true;
}

void ArtFrame::LoadHeader(std::ifstream& source)
{
	source.read(reinterpret_cast<char*>(&header), sizeof(header));
}

void ArtFrame::SaveHeader(std::ofstream& dest)
{
	dest.write(reinterpret_cast<char*>(&header), sizeof(header));
}

void ArtFrame::Load(std::ifstream& source)
{
	data = new char[header.size];
	source.read(data, header.size);
}

void ArtFrame::Save(std::ofstream& source)
{
	source.write(data, header.size);
}

unsigned char ArtFrame::GetValue(int x, int y)
{
	return pixels[y][x];
}

unsigned char ArtFrame::GetValueI(int x, int y)
{
	return pixels[pixels.size() - 1 - y][x];
}

void ArtFrame::SetValue(int x, int y, unsigned char ch)
{
	pixels[y][x] = ch;
}

void ArtFrame::SetSize(int w, int h)
{
	header.width = w;
	header.height = h;
	pixels = bytemap(header.height, bytevec(header.width));
}

void ArtFrame::Encode()
{
	std::string data_compressed;
	std::string data_raw;

	Reset();
	do
	{
		char clones = 0;
		char val = GetValueI(px, py);
		if (!Inc())
		{
			data_compressed += static_cast<unsigned char>(0x81);
			data_compressed += val;
		}
		else
		{
			if (val == GetValueI(px, py))
			{
				clones = 2;
				while (Inc() && (val == GetValueI(px, py)) && (clones < 0x7F))
				{
					clones++;
				}
				data_compressed += clones;
				data_compressed += val;
			}
			else
			{
				clones = 2;
				data_compressed += '\0';
				data_compressed += val;
				data_compressed += GetValueI(px, py);
				while (Inc() && (GetValueI(px, py) != data_compressed.back()) && (clones < 0x7F))
				{
					data_compressed += GetValueI(px, py);
					clones++;
				}
				if ((!EOD()) && (GetValueI(px, py) == data_compressed.back()))
				{
					clones--;
					data_compressed.resize(data_compressed.size() - 1);
					Dec();
				}
				data_compressed[data_compressed.size() - clones - 1] = static_cast<unsigned char>(0x80) | static_cast<unsigned char>(clones);
			}
		}
	} while (!EOD());

	Reset();
	while (!EOD())
	{
		data_raw += GetValueI(px, py);
		Inc();
	}
	Reset();

	if (data_raw.size() <= data_compressed.size())
	{
		data = new char[data_raw.size()];
		memcpy(data, data_raw.c_str(), data_raw.size());
		header.size = static_cast<unsigned long>(data_raw.size());
	}
	else
	{
		data = new char[data_compressed.size()];
		memcpy(data, data_compressed.c_str(), data_compressed.size());
		header.size = static_cast<unsigned long>(data_compressed.size());
	}
}

void ArtFrame::Decode()
{
	pixels = bytemap(header.height, bytevec(header.width));
	Reset();
	if (header.size < (header.height*header.width))
	{
		for (int p = 0; p < static_cast<int>(header.size); p++)
		{
			unsigned char ch = static_cast<unsigned char>(data[p]);
			if (ch & 0x80)
			{
				int to_copy = ch & (0x7F);
				while (to_copy--)
				{
					p++;
					pixels[py][px] = data[p];
					Inc();
				}
			}
			else
			{
				int to_clone = ch & (0x7F);
				p++;
				unsigned char src = static_cast<unsigned char>(data[p]);
				while (to_clone--)
				{
					pixels[py][px] = src;
					Inc();
				}
			}
		}
	}
	else
	{
		for (int p = 0; p < static_cast<int>(header.size); p++)
		{
			pixels[py][px] = data[p];
			Inc();
		}
	}
}

void ArtFile::Reset()
{

}

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

void ArtFile::LoadArt(const std::string &fname)
{
	std::ifstream source;
	source.open(fname, std::ios_base::binary);

	if (!source)
		throw MissingFile{ fname };

	source.read(reinterpret_cast<char*>(&header), sizeof(header));

	animated = ((header.h0[0] & 0x1) == 0);

	palettes = 0;
	for (auto col : header.stupid_color)
	{
		if (in_palette(col)) palettes++;
	}

	frames = header.frame_num;
	key_frame = header.frame_num_low;

	if (animated) frames *= 8;

	for (int i = 0; i < palettes; i++)
	{
		palette_data.push_back(ArtTable());
		source.read(reinterpret_cast<char*>(&palette_data.back()), sizeof(ArtTable));
	}

	for (int i = 0; i < frames; i++)
	{
		frame_data.push_back(ArtFrame());
		frame_data.back().LoadHeader(source);
	}

	for (auto &af : frame_data)
	{
		af.Load(source);
		af.Decode();
	}
}

void ArtFile::SaveArt(const std::string &fname)
{
	std::ofstream source;
	source.open(fname, std::ios_base::binary);
	source.write(reinterpret_cast<char*>(&header), sizeof(header));

	for (int i = 0; i < palettes; i++)
	{
		source.write(reinterpret_cast<char*>(&palette_data[i]), sizeof(ArtTable));
	}

	for (auto &af : frame_data)
	{
		af.Encode();
		af.SaveHeader(source);
	}

	for (auto &af : frame_data)
	{
		af.Save(source);
	}

	source.close();
}