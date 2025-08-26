// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

/* ArtConverter by Alexey Stremov https://github.com/AxelStrem/ArtConverter/blob/master/artconverter.cpp
   Refactored for OpenArcanum https://github.com/OpenArcanum/artviewer */

#ifndef Arcanum_Formats_Art_hpp
#define Arcanum_Formats_Art_hpp

#include <string>
#include <vector>
#include <fstream>

#include <Arcanum/Readers/MemoryReader.hpp>

namespace Arcanum
{
	namespace Formats
	{
		struct MissingFile
		{
			std::string filename;
		};

		struct ArtColor
		{
			ArtColor();
			uint8_t b;
			uint8_t	g;
			uint8_t	r;
			uint8_t	a;
		};

		inline bool in_palette(ArtColor col)
		{
			return (col.a | col.b | col.g | col.r) != 0;
		}

		struct ArtTable
		{
			ArtColor colors[256];
		};

		struct ArtHeader
		{
			uint32_t h0[3] = { 0 };
			ArtColor stupid_color[4];

			uint32_t frame_num_low = 0;
			uint32_t frame_num     = 0;

			ArtColor palette_data1[8];
			ArtColor palette_data2[8];
			ArtColor palette_data3[8];
		};

		struct ArtFrameHeader
		{
			ArtFrameHeader();
			uint32_t width;
			uint32_t height;
			uint32_t size;
			int c_x;
			int c_y;
			int d_x;
			int d_y;
		};

		struct ArtFrame
		{
			ArtFrameHeader header;
			std::vector<char> data;
			std::vector<uint8_t> pixels;
			int px = 0;
			int py = 0;

			bool Inc();
			void Dec();
			void Reset();
			bool EOD();

			size_t Index(size_t x, size_t y);

			ArtFrameHeader& GetHeader() { return header; }
			void LoadHeader(Readers::MemoryReader& source);
			void SaveHeader(std::ofstream& dest);

			void Load(Readers::MemoryReader& source);

			uint8_t GetValue(size_t x, size_t y);
			void SetValue(size_t x, size_t y, uint8_t ch);
			void SetSize(size_t w, size_t h);
			void Decode();
		};

		struct ArtFile
		{
			ArtHeader header;
			std::vector<ArtFrame> frame_data;
			std::vector<ArtTable> palette_data;

			int palettes  = { 0 };
			int frames    = { 0 };
			int key_frame = { 0 };
			bool animated = { 0 };

			void Reset();
			void LoadArt(Readers::MemoryReader& source);
		};
	}
}

#endif