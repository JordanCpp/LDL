#include <LDL/Graphics/ImageResizer.hpp>

#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "../../dependencies/stb/stb_image_resize.h"

using namespace LDL::Graphics;

ImageResizer::ImageResizer(const Point2u& size) :
	_Surface(size, 4)
{
}

Surface* ImageResizer::Resize(const Point2u& size, Surface* surface)
{
    assert(_Surface.Capacity().PosX() >= size.PosX());
    assert(_Surface.Capacity().PosY() >= size.PosY());

    _Surface.Resize(size);

    stbir_resize(surface->Pixels(), surface->Size().PosX(), surface->Size().PosY(), 0, _Surface.Pixels(), size.PosX(), size.PosY(), 0, STBIR_TYPE_UINT8, surface->BytesPerPixel(), STBIR_ALPHA_CHANNEL_NONE, 0,
        STBIR_EDGE_CLAMP, STBIR_EDGE_CLAMP,
        STBIR_FILTER_BOX, STBIR_FILTER_BOX,
        STBIR_COLORSPACE_SRGB, NULL);

    return &_Surface;
}