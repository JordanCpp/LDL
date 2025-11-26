// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/BmpLoad.hpp>

#pragma pack(push, 1)
struct BMPFileHeader
{
    uint16_t file_type;
    uint32_t file_size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset_data;
};

struct BMPInfoHeader
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
};
#pragma pack(pop) 

LDL_BmpLoader::LDL_BmpLoader(LDL_Result& result) :
    _bpp(0),
    _pixelFormat(LDL_PixelFormat::UNKNOWN),
	_result(result),
    _stream(NULL)
{
    _stream = LDL_CreateFileStream(_result);
}

LDL_BmpLoader::~LDL_BmpLoader()
{
    if (_stream)
    {
        delete _stream;
    }
}

bool LDL_BmpLoader::Load(const char* path)
{
    _stream->Open(path, LDL_IFileStream::ModeRead);

    if (!_stream->IsOpen())
    {
        _result.Message(_formatter.Format("Can't open file: %s\n", path));
        return false;
    }

    BMPFileHeader file_header;
    BMPInfoHeader info_header;

    _stream->Read(&file_header, sizeof(BMPFileHeader));
    _stream->Read(&info_header, sizeof(BMPInfoHeader));

    if (file_header.file_type != 0x4D42)
    {
        _result.Message(_formatter.Format("Not a BMP file: %s\n", path));
        return false;
    }

    if (info_header.bit_count != 8 && info_header.bit_count != 24 && info_header.bit_count != 32)
    {
        _result.Message(_formatter.Format("Unsupported BMP format (only 8, 24, and 32-bit supported): %s\n", path));
        return false;
    }

    if (info_header.compression != 0)
    {
        _result.Message(_formatter.Format("Only uncompressed BMP supported: %s\n", path));
        return false;
    }

    _size = LDL_Vec2u(info_header.width, info_header.height);
    _bpp  = info_header.bit_count / 8;

    if (_bpp == 0)
    {
        _bpp = 1;
    }

    const uint32_t row_stride      = (_size.x * info_header.bit_count + 31) / 32 * 4;
    const uint32_t pixel_data_size = row_stride * _size.y;

    _pixels.resize(pixel_data_size);

    _stream->Seek(file_header.offset_data);

    for (int y = _size.y - 1; y >= 0; --y)
    {
        if (_stream->Read(_pixels.data() + y * row_stride, row_stride) != row_stride)
        {
            _result.Message(_formatter.Format("Failed to read pixel data: %s\n", path));
            return false;
        }
    }

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

    if (info_header.bit_count == 24)
    {
        _pixelFormat = LDL_PixelFormat::RGB24;
    }
    else
    {
        _pixelFormat = LDL_PixelFormat::RGBA32;
    }

    return _result.Ok();
}

const LDL_Vec2u& LDL_BmpLoader::Size()
{
    return _size;
}

uint8_t LDL_BmpLoader::Bpp()
{
    return _bpp;
}

uint8_t* LDL_BmpLoader::Pixels()
{
    return _pixels.data();
}

size_t LDL_BmpLoader::Format()
{
    return _pixelFormat;
}
