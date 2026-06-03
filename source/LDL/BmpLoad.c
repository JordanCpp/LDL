/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <LDL/BmpLoad.h>
#include <LDL/ErrorMsg.h>

#pragma pack(push, 1)
typedef struct BMPFileHeader 
{
    uint16_t file_type;
    uint32_t file_size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset_data;
} BMPFileHeader;

typedef struct BMPInfoHeader 
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

struct LDL_BmpLoader 
{
    uint8_t     Bpp;
    uint8_t     Format;
    uint8_t*    Pixels;
    FILE*       File;
    LDL_Result* Result;
    LDL_Vec2i   Size;
};

LDL_BmpLoader* LDL_BmpLoaderNew(LDL_Result* result) 
{
    LDL_BmpLoader* loader = (LDL_BmpLoader*)malloc(sizeof(LDL_BmpLoader));

    if (result && loader == NULL)
    {
        LDL_ResultAddMessage(result, LDL_ErrorOutOfMemory());
    }

    if (loader && result) 
    {
        loader->File   = NULL;
        loader->Result = result;

        return loader;
    }

    if (loader)
    {
        free(loader);
    }

    return NULL;
}

void LDL_BmpLoaderFree(LDL_BmpLoader* loader) 
{
    if (loader) 
    {
        if (loader->File) 
        {
            fclose(loader->File);
        }

        if (loader->Pixels)
        {
            free(loader->Pixels);
        }

        free(loader);
    }
}

LDL_Vec2i LDL_BmpLoaderGetSize(LDL_BmpLoader* loader)
{
    if (loader)
    {
        return loader->Size;
    }

    return LDL_GetVec2i(0, 0);
}

uint8_t* LDL_BmpLoaderGetPixels(LDL_BmpLoader* loader) 
{
    if (loader)
    {
        return loader->Pixels;
    }

    return NULL;
}

uint8_t LDL_BmpLoaderGetPixelFormat(LDL_BmpLoader* loader)
{
    if (loader)
    {
        return loader->Format;
    }

    return LDL_PixelFormatUnknown;
}

uint8_t LDL_BmpLoaderGetBytesPerPixels(LDL_BmpLoader* loader)
{
    if (loader)
    {
        return loader->Bpp;
    }

    return 0;
}

bool LDL_BmpLoaderLoadFromFile(LDL_BmpLoader* loader, const char* path) 
{
    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;
    int32_t       width;
    int32_t       height;
    bool          isTopDown;
    uint32_t      row_stride;
    uint32_t      pixel_data_size;
    int           channels;
    int           y;
    int           x;
    uint8_t*      row;
    uint8_t*      pixel;
    uint8_t       tmp;

    if (loader && path) 
    {
        if (loader->File)
        {
            fclose(loader->File);
        }

        loader->File = fopen(path, "rb");

        if (!loader->File) 
        {
            LDL_ResultAddMessage(loader->Result, "Can't open file: %s\n", path);
            return false;
        }

        if (fread(&fileHeader, sizeof(BMPFileHeader), 1, loader->File) != 1)
        {
            LDL_ResultAddMessage(loader->Result, "Failed to read BMP file header: %s", path);
            return false;
        }

        if (fread(&infoHeader, sizeof(BMPInfoHeader), 1, loader->File) != 1) 
        {
            LDL_ResultAddMessage(loader->Result, "Failed to read BMP info header: %s", path);
            return false;
        }

        if (fileHeader.file_type != 0x4D42) 
        {
            LDL_ResultAddMessage(loader->Result, "Not a BMP file: %s\n", path);
            return false;
        }

        if (infoHeader.bit_count != 8 && infoHeader.bit_count != 24 && infoHeader.bit_count != 32) 
        {
            LDL_ResultAddMessage(loader->Result, "Unsupported BMP format (only 8, 24, and 32-bit supported): %s\n", path);
            return false;
        }

        if (infoHeader.compression != 0) 
        {
            LDL_ResultAddMessage(loader->Result, "Only uncompressed BMP supported: %s\n", path);
            return false;
        }

        width     = infoHeader.width;
        height    = infoHeader.height;
        isTopDown = height < 0;

        if (isTopDown) 
        {
            height = -height;
        }

        loader->Size = LDL_GetVec2i(width, height);
        loader->Bpp  = infoHeader.bit_count / 8;

        if (loader->Bpp == 0) 
        {
            loader->Bpp = 1;
        }

        row_stride      = (loader->Size.x * infoHeader.bit_count + 31) / 32 * 4;
        pixel_data_size = row_stride * loader->Size.y;

        loader->Pixels = (uint8_t*)malloc(pixel_data_size);

        if (!loader->Pixels) 
        {
            LDL_ResultAddMessage(loader->Result, "Failed to allocate memory for pixels: %s", path);
            return false;
        }

        fseek(loader->File, fileHeader.offset_data, SEEK_SET);

        if (isTopDown)
        {
            for (y = 0; y < loader->Size.y; ++y) 
            {
                if (fread(loader->Pixels + y * row_stride, row_stride, 1, loader->File) != 1)
                {
                    LDL_ResultAddMessage(loader->Result, "Failed to read pixel data: %s", path);
                    return false;
                }
            }
        }
        else 
        {
            for (y = loader->Size.y - 1; y >= 0; --y) 
            {
                if (fread(loader->Pixels + y * row_stride, row_stride, 1, loader->File) != 1) 
                {
                    LDL_ResultAddMessage(loader->Result, "Failed to read pixel data: %s", path);
                    return false;
                }
            }
        }

        if (infoHeader.bit_count >= 24)
        {
            channels = infoHeader.bit_count / 8;

            for (y = 0; y < loader->Size.y; ++y)
            {
                row = loader->Pixels + y * row_stride;

                for (x = 0; x < loader->Size.x; ++x)
                {
                    pixel = row + x * channels;
                    tmp = pixel[0];
                    pixel[0] = pixel[2];
                    pixel[2] = tmp;
                }
            }
        }

        if (infoHeader.bit_count == 24)
        {
            loader->Format = LDL_PixelFormatRGB24;
        }
        else
        {
            loader->Format = LDL_PixelFormatRGBA32;
        }

        return LDL_ResultIsOk(loader->Result);
    }

    return false;
}
