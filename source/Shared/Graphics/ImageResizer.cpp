#include <LDL/Graphics/ImageResizer.hpp>

#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "../../../dependencies/stb/stb_image_resize.h"

using namespace LDL::Graphics;
using namespace LDL::Math;

ImageResizer::ImageResizer(const Vec2u& size) :
	_surface(size, 4)
{
}

Surface* ImageResizer::Resize(const Vec2u& size, Surface* surface)
{
    assert(_surface.Capacity().x >= size.x);
    assert(_surface.Capacity().y >= size.y);

    _surface.Resize(size);

    stbir_resize(surface->Pixels(), (int)surface->Size().x, (int)surface->Size().y, 0, _surface.Pixels(), (int)size.x, (int)size.y, 0, STBIR_TYPE_UINT8, surface->BytesPerPixel(), STBIR_ALPHA_CHANNEL_NONE, 0,
        STBIR_EDGE_CLAMP, STBIR_EDGE_CLAMP,
        STBIR_FILTER_BOX, STBIR_FILTER_BOX,
        STBIR_COLORSPACE_SRGB, NULL);

    return &_surface;
}
