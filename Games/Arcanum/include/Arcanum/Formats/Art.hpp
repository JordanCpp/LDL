/* ArtConverter by Alexey Stremov https://github.com/AxelStrem/ArtConverter/blob/master/artconverter.cpp
   Refactored for OpenArcanum https://github.com/OpenArcanum/artviewer */

#ifndef Arcanum_Formats_Art_hpp
#define Arcanum_Formats_Art_hpp

#include <string>
#include <vector>
#include <fstream>

struct MissingFile
{
	std::string filename;
};

struct ArtColor
{
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
	uint32_t h0[3]; //1,8,8,WTF
	ArtColor stupid_color[4];

	uint32_t frame_num_low;
	uint32_t frame_num;

	ArtColor palette_data1[8];
	ArtColor palette_data2[8];
	ArtColor palette_data3[8];
};

struct ArtFrameHeader
{
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
	int px, py;

	bool Inc();
	void Dec();
	void Reset();
	bool EOD();

	size_t Index(int x, int y);

	ArtFrameHeader& GetHeader() { return header; }
	void LoadHeader(std::ifstream& source);
	void SaveHeader(std::ofstream& dest);

	void Load(std::ifstream& source);

	uint8_t GetValue(int x, int y);
	void SetValue(int x, int y, uint8_t ch);
	void SetSize(int w, int h);
	void Decode();
};

struct ArtFile
{
	ArtHeader header;
	std::vector<ArtFrame> frame_data;
	std::vector<ArtTable> palette_data;

	int palettes;
	int frames;
	int key_frame;
	bool animated;

	void Reset();
	void LoadArt(const std::string &fname);
};

#endif