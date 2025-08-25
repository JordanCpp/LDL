// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Loaders/BmpLoader.hpp>

using namespace LDL::Math;
using namespace LDL::Loaders;

#pragma pack(push, 1)
typedef struct
{
    uint16_t file_type;
    uint32_t file_size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset_data;
} BMPFileHeader;

typedef struct
{
    uint32_t size;
    int32_t  width;
    int32_t  height;
    uint16_t planes;
    uint16_t bit_count;
    uint32_t compression;
    uint32_t size_image;
    int32_t  x_pixels_per_meter;
    int32_t  y_pixels_per_meter;
    uint32_t colors_used;
    uint32_t colors_important;
} BMPInfoHeader;
#pragma pack(pop) 

BmpLoader::BmpLoader(Core::Result& result) :
    _bpp(0),
	_result(result)
{
}

bool BmpLoader::Load(const char* path)
{
    FILE* file = fopen(path, "rb");

    if (!file)
    {
        _result.Message("Can't open file: ", path);
        return false;
    }

    BMPFileHeader file_header;
    BMPInfoHeader info_header;

    if (fread(&file_header, sizeof(BMPFileHeader), 1, file) != 1 ||
        fread(&info_header, sizeof(BMPInfoHeader), 1, file) != 1)
    {
        fclose(file);
        _result.Message("Failed to read BMP headers: ", path);

        return false;
    }

    if (file_header.file_type != 0x4D42)
    {
        fclose(file);
        _result.Message("Not a BMP file: ", path);

        return false;
    }

    if (info_header.bit_count != 8 && info_header.bit_count != 24 && info_header.bit_count != 32)
    {
        fclose(file);
        _result.Message("Unsupported BMP format (only 8, 24, and 32-bit supported): ", path);

        return false;
    }

    if (info_header.compression != 0)
    {
        fclose(file);
        _result.Message("Only uncompressed BMP supported: ", path);

        return false;
    }

    _size = Vec2u(info_header.width, info_header.height);
    _bpp  = info_header.bit_count / 8;

    if (_bpp == 0)
    {
        _bpp = 1;
    }

    const uint32_t row_stride = (_size.x * info_header.bit_count + 31) / 32 * 4;
    const uint32_t pixel_data_size = row_stride * _size.y;

    _pixels.resize(pixel_data_size);

    fseek(file, file_header.offset_data, SEEK_SET);

    for (int y = _size.y - 1; y >= 0; --y)
    {
        if (fread(_pixels.data() + y * row_stride, 1, row_stride, file) != row_stride)
        {
            fclose(file);
            _result.Message("Failed to read pixel data: ", path);

            return false;
        }
    }

    fclose(file);

    if (info_header.bit_count >= 24)
    {
        const int channels = info_header.bit_count / 8;

        for (size_t y = 0; y < _size.y; ++y)
        {
            uint8_t* row = _pixels.data() + y * row_stride;

            for (size_t x = 0; x < _size.x; ++x)
            {
                uint8_t* pixel = row + x * channels;
                uint8_t tmp    = pixel[0];
                pixel[0]       = pixel[2];
                pixel[2]       = tmp;
            }
        }
    }

    return _result.Ok();
}

const Vec2u& BmpLoader::Size()
{
    return _size;
}

uint8_t BmpLoader::Bpp()
{
    return _bpp;
}

uint8_t* BmpLoader::Pixels()
{
    return _pixels.data();
}
