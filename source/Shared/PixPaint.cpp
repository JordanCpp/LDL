#include <LDL/Low/PixPaint.hpp>
#include <math.h>

#define sgn(x) ((x<0)?-1:((x>0)?1:0))

void LDL_PixelPainter::Clear(LDL_Surface& surface, const LDL_Color& color)
{
	size_t count = surface.Size().x * surface.Size().y * surface.Bpp();
	uint8_t LDL_FAR* pixels = surface.Pixels();

    if (surface.Bpp() == 1)
    {
        for (size_t i = 0; i < count; i++)
        {
            pixels[i] = color.r;
        }
    }
    else if (surface.Bpp() == 3)
    {
        for (size_t i = 0; i < count; i+=3)
        {
#ifdef LDL_COLOR_RGBA
            pixels[i] = color.r;
            pixels[i + 1] = color.g;
            pixels[i + 2] = color.b;
#else
            pixels[i] = color.b;
            pixels[i + 1] = color.g;
            pixels[i + 2] = color.r;
#endif  
        }
    }
}


void LDL_PixelPainter::Line(LDL_Surface& surface, const LDL_Point2u& first, const LDL_Point2u& last, const LDL_Color& color)
{
    uint8_t LDL_FAR* pixels = surface.Pixels();
    LDL_Point2u size = surface.Size();
    uint8_t bpp = surface.Bpp();
    size_t index = 0;

    int i, dx, dy, sdx, sdy, dxabs, dyabs, x, y, px, py;

    dx = int(last.x - first.x);      /* the horizontal distance of the line */
    dy = int(last.y - first.y);      /* the vertical distance of the line */
    dxabs = abs(dx);
    dyabs = abs(dy);
    sdx = sgn(dx);
    sdy = sgn(dy);
    x = dyabs >> 1;
    y = dxabs >> 1;
    px = (int)first.x;
    py = (int)first.y;

    if (bpp == 3)
    {
        index = (py * size.x + px) * bpp;

#ifdef LDL_COLOR_RGBA
        pixels[index] = color.r;
        pixels[index + 1] = color.g;
        pixels[index + 2] = color.b;
#else
        pixels[index] = color.b;
        pixels[index + 1] = color.g;
        pixels[index + 2] = color.r;
#endif  

    }
    else
    {
        pixels[py * size.x + px] = color.r;
    }

    if (dxabs >= dyabs) /* the line is more horizontal than vertical */
    {
        for (i = 0; i < dxabs; i++)
        {
            y += dyabs;
            if (y >= dxabs)
            {
                y -= dxabs;
                py += sdy;
            }
            px += sdx;

            if (bpp == 3)
            {
                index = (py * size.x + px) * bpp;

#ifdef LDL_COLOR_RGBA
                pixels[index] = color.r;
                pixels[index + 1] = color.g;
                pixels[index + 2] = color.b;
#else
                pixels[index] = color.b;
                pixels[index + 1] = color.g;
                pixels[index + 2] = color.r;
#endif  

            }
            else
            {
                pixels[py * size.x + px] = color.r;
            }
        }
    }
    else /* the line is more vertical than horizontal */
    {
        for (i = 0; i < dyabs; i++)
        {
            x += dxabs;
            if (x >= dyabs)
            {
                x -= dyabs;
                px += sdx;
            }
            py += sdy;

            if (bpp == 3)
            {
                index = (py * size.x + px) * bpp;

#ifdef LDL_COLOR_RGBA
                pixels[index] = color.r;
                pixels[index + 1] = color.g;
                pixels[index + 2] = color.b;
#else
                pixels[index] = color.b;
                pixels[index + 1] = color.g;
                pixels[index + 2] = color.r;
#endif  

            }
            else
            {
                pixels[py * size.x + px] = color.r;
            }
        }
    }
}

void LDL_PixelPainter::Fill(LDL_Surface& surface, const LDL_Point2u& pos, const LDL_Point2u& size, const LDL_Color& color)
{
    size_t x        = pos.x;
    size_t y        = pos.y;
    size_t index    = 0;
    uint8_t LDL_FAR* pixels = surface.Pixels();
    uint8_t bpp     = surface.Bpp();
    size_t width    = surface.Size().x;

    if (bpp == 3)
    {
        for (size_t i = 0; i < size.x; i++)
        {
            for (size_t j = 0; j < size.y; j++)
            {
                index = (width * (y + j) + (x + i)) * bpp;

#ifdef LDL_COLOR_RGBA
                pixels[index] = color.r;
                pixels[index + 1] = color.g;
                pixels[index + 2] = color.b;
#else
                pixels[index] = color.b;
                pixels[index + 1] = color.g;
                pixels[index + 2] = color.r;
#endif  

            }
        }
    }
    else
    {
        for (size_t i = 0; i < size.x; i++)
        {
            for (size_t j = 0; j < size.y; j++)
            {
                pixels[width * (y + j) + (x + i)] = color.r;
            }
        }
    }
}