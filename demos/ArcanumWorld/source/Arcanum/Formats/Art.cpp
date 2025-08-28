// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

/* ArtConverter by Alexey Stremov https://github.com/AxelStrem/ArtConverter/blob/master/artconverter.cpp
   Refactored for OpenArcanum https://github.com/OpenArcanum/artviewer */

#include <Arcanum/Formats/Art.hpp>

using namespace Arcanum;

bool ArtFrame::Inc()
{
	px++;

	if (px >= (int)header.width)
	{
		px = 0;
		py++;
	}

	if (py >= (int)header.height)
	{
		return false;
	}
		
	if (py < 0)
	{
		return false;
	}

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
	px = 0;
	py = 0;
}

size_t ArtFrame::Index(size_t x, size_t y)
{
	return ((header.width * y) + x);
}

bool ArtFrame::EOD()
{
	if (py < (int)(header.height))
	{
		return false;
	}
	
	return true;
}

void ArtFrame::LoadHeader(MemoryReader& source)
{
	source.Read((char*)(&header), sizeof(header));
}

void ArtFrame::SaveHeader(std::ofstream& dest)
{
	dest.write((char*)(&header), sizeof(header));
}

void ArtFrame::Load(MemoryReader& source)
{
	data.resize(header.size);
	source.Read(&data[0], header.size);
}

uint8_t ArtFrame::GetValue(size_t x, size_t y)
{
	return pixels[Index(x, y)];
}

void ArtFrame::SetValue(size_t x, size_t y, uint8_t ch)
{
	pixels[Index(x, y)] = ch;
}

void ArtFrame::SetSize(size_t w, size_t h)
{
	header.width  = (uint32_t)w;
	header.height = (uint32_t)h;

	pixels.resize(header.height * header.width);
}

void ArtFrame::Decode()
{
	pixels.resize(header.height * header.width);

	Reset();
	if (header.size < (header.height*header.width))
	{
		for (size_t p = 0; p < header.size; p++)
		{
			uint8_t ch = data[p];

			if (ch & 0x80)
			{
				uint8_t to_copy = ch & (0x7F);
				while (to_copy--)
				{
					p++;
					pixels[Index(px, py)] = data[p];
					Inc();
				}
			}
			else
			{
				uint8_t to_clone = ch & (0x7F);
				p++;
				uint8_t src = data[p];

				while (to_clone--)
				{
					pixels[Index(px, py)] = src;
					Inc();
				}
			}
		}
	}
	else
	{
		for (size_t p = 0; p < header.size; p++)
		{
			pixels[Index(px, py)] = data[p];
			Inc();
		}
	}
}

void ArtFile::LoadArt(MemoryReader& source)
{
	frame_data.clear();

	source.Read((char*)(&header), sizeof(header));

	animated = ((header.h0[0] & 0x1) == 0);

	palettes = 0;

	for (size_t i = 0; i < 4; i++)
	{
		if (in_palette(header.stupid_color[i])) palettes++;
	}

	frames    = header.frame_num;
	key_frame = header.frame_num_low;

	if (animated)
	{
		frames *= 8;
	}

	palette_data.clear();

	for (int j = 0; j < palettes; j++)
	{
		palette_data.push_back(ArtTable());
		source.Read((char*)(&palette_data.back()), sizeof(ArtTable));
	}

	for (int k = 0; k < frames; k++)
	{
		frame_data.push_back(ArtFrame());
		frame_data.back().LoadHeader(source);
	}

	for (size_t g = 0; g < frame_data.size(); g++)
	{
		frame_data[g].Load(source);
		frame_data[g].Decode();
	}

	source.Close();
}

ArtColor::ArtColor() :
	b(0),
	g(0),
	r(0),
	a(0)
{
}

ArtFrameHeader::ArtFrameHeader() :
	width(0),
	height(0),
	size(0),
	c_x(0),
	c_y(0),
	d_x(0),
	d_y(0)
{
}
