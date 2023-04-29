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
	unsigned char b, g, r, a;
};

inline bool in_palette(ArtColor col)
{
	return (col.a | col.b | col.g | col.r) != 0;
}

struct ArtTable
{
	ArtColor colors[256];
};

using bytevec = std::vector<unsigned char>;
using bytemap = std::vector<bytevec>;

struct ArtHeader
{
	unsigned long    h0[3]; //1,8,8,WTF
	ArtColor stupid_color[4];

	unsigned long    frame_num_low;
	unsigned long    frame_num;

	ArtColor palette_data1[8];
	ArtColor palette_data2[8];
	ArtColor palette_data3[8];
};

struct ArtFrameHeader
{
	unsigned long width;
	unsigned long height;
	unsigned long size;
	int c_x;
	int c_y;
	int d_x;
	int d_y;
};

struct ArtFrame
{
	ArtFrameHeader header;
	char*          data;
	bytemap        pixels;
	int px, py;

	bool Inc();
	void Dec();
	void Reset();
	bool EOD();

	ArtFrameHeader& GetHeader() { return header; }
	void LoadHeader(std::ifstream& source);
	void SaveHeader(std::ofstream& dest);

	void Load(std::ifstream& source);
	void Save(std::ofstream& source);

	unsigned char GetValue(int x, int y);
	unsigned char GetValueI(int x, int y);
	void SetValue(int x, int y, unsigned char ch);
	void SetSize(int w, int h);

	void Encode();
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
	void SaveArt(const std::string &fname);
};

#endif