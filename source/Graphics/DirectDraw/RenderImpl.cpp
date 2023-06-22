#include "RenderImpl.hpp"
#include "RenderContextImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include "../source/Platforms/Windows/Graphics/DirectDraw/WindowImpl.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;
using namespace LDL::Core;

RenderImpl::RenderImpl(RenderContextImpl* renderContextImpl, Window* window) :
	_Window(window),
	_BaseRender(_Window->Size()),
    _RenderContextImpl(renderContextImpl)
{
    HRESULT result = DirectDrawCreate(NULL, &_RenderContextImpl->Context._DirectDraw, NULL);

    if (result != DD_OK)
        throw RuntimeError("DirectDrawCreate failed");

    result = _RenderContextImpl->Context._DirectDraw->SetCooperativeLevel(window->GetWindowImpl()->Hwnd(), DDSCL_NORMAL);

    if (result != DD_OK)
        throw RuntimeError("SetCooperativeLevel failed");

    ZeroMemory(&_RenderContextImpl->Context._SurfaceDesc, sizeof(_RenderContextImpl->Context._SurfaceDesc));

    _RenderContextImpl->Context._SurfaceDesc.dwSize = sizeof(_RenderContextImpl->Context._SurfaceDesc);
    _RenderContextImpl->Context._SurfaceDesc.dwFlags = DDSD_CAPS;
    _RenderContextImpl->Context._SurfaceDesc.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
    _RenderContextImpl->Context._SurfaceDesc.dwWidth = _BaseRender.Size().x;
    _RenderContextImpl->Context._SurfaceDesc.dwHeight = _BaseRender.Size().y;

    result = _RenderContextImpl->Context._DirectDraw->CreateSurface(&_RenderContextImpl->Context._SurfaceDesc, &_RenderContextImpl->Context._Primary, NULL);

    if (result != DD_OK)
        throw RuntimeError("CreateSurface failed");

    result = _RenderContextImpl->Context._DirectDraw->CreateClipper(0, &_RenderContextImpl->Context._DirectDrawClipper, NULL);

    if (result != DD_OK)
        throw RuntimeError("CreateClipper failed");

    result = _RenderContextImpl->Context._DirectDrawClipper->SetHWnd(0, window->GetWindowImpl()->Hwnd());

    if (result != DD_OK)
        throw RuntimeError("SetHWnd failed");

    result = _RenderContextImpl->Context._Primary->SetClipper(_RenderContextImpl->Context._DirectDrawClipper);

    if (result != DD_OK)
        throw RuntimeError("SetClipper failed");

    DDSURFACEDESC       ddsd;

    ZeroMemory(&ddsd, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
    ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;
    ddsd.dwWidth = _BaseRender.Size().x;
    ddsd.dwHeight = _BaseRender.Size().y;

    result = _RenderContextImpl->Context._DirectDraw->CreateSurface(&ddsd, &_RenderContextImpl->Context._Screen, NULL);

    if (result != DD_OK)
        throw RuntimeError("CreateSurface failed");
}

LDL::Graphics::RenderImpl::~RenderImpl()
{
    if (_RenderContextImpl->Context._Screen != NULL)
    {
        _RenderContextImpl->Context._Screen->Release();
        _RenderContextImpl->Context._Screen = NULL;
    }

    if (_RenderContextImpl->Context._Primary != NULL)
    {
        _RenderContextImpl->Context._Primary->Release();
        _RenderContextImpl->Context._Primary = NULL;
    }

    if (_RenderContextImpl->Context._DirectDraw != NULL)
    {
        _RenderContextImpl->Context._DirectDraw->Release();
        _RenderContextImpl->Context._DirectDraw = NULL;
    }
}

void RenderImpl::Buffer(uint8_t* dst)
{
}

void RenderImpl::Begin()
{
    HRESULT result;

    RECT sizeRect;

    sizeRect.left   = 0;
    sizeRect.top    = 0;
    sizeRect.right  = _BaseRender.Size().x;
    sizeRect.bottom = _BaseRender.Size().y;

    while (1)
    {
        //result = _Primary->Flip(NULL, DDFLIP_WAIT);

        result = _RenderContextImpl->Context._Primary->Blt(&sizeRect, _RenderContextImpl->Context._Screen, &sizeRect, 0, NULL);

        if (result != DD_OK)
            throw RuntimeError("Blt failed");

        if (result == DD_OK)
            break;

        if (result == DDERR_SURFACELOST)
        {
            result = _RenderContextImpl->Context._Primary->Restore();

            if (result != DD_OK)
                break;
        }

        if (result != DDERR_WASSTILLDRAWING)
        {
            break;
        }
    }
}

void RenderImpl::End()
{
    /*
    HRESULT result;

    result = _Primary->Flip(NULL, DDFLIP_WAIT);

    if (result != DD_OK)
        throw LDL::Core::RuntimeError("Flip failed");
    */
}

const Vec2u& RenderImpl::Size()
{
	return _BaseRender.Size();
}

const Color& RenderImpl::Color()
{
	return _BaseRender.Color();
}

void RenderImpl::Clear()
{
    DDBLTFX bltfx;

    ZeroMemory(&bltfx, sizeof(bltfx));

    bltfx.dwSize = sizeof(bltfx);
    bltfx.dwFillColor = RGB(_BaseRender.Color().r, _BaseRender.Color().g, _BaseRender.Color().b);

    HRESULT result;

    //result = _Primary->Blt(NULL, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &bltfx);

    //if (result != DD_OK)
     //   throw LDL::Core::RuntimeError("Blt failed");
}

void RenderImpl::Color(const LDL::Graphics::Color& color)
{
	_BaseRender.Color(color);
}

void RenderImpl::Pixel(const Vec2u& pos)
{
}

void RenderImpl::Line(const Vec2u& pos1, const Vec2u& pos2)
{

}

void RenderImpl::Fill(const Vec2u& pos, const Vec2u& size)
{
    DDSURFACEDESC desc;
    ZeroMemory(&desc, sizeof(desc));
    desc.dwSize = sizeof(desc);

    HRESULT result = _RenderContextImpl->Context._Screen->Lock(0, &desc, DDLOCK_WAIT | DDLOCK_WRITEONLY, 0);

    if (result != DD_OK)
        throw RuntimeError("Lock failed");

    BYTE* pixels = (BYTE*)desc.lpSurface;

    for (size_t i = 0; i < _BaseRender.Size().x * _BaseRender.Size().y * 4; i+=4)
    {
        pixels[i] = 36;
        pixels[i + 1] = 28;
        pixels[i + 2] = 237;
    }

    result = _RenderContextImpl->Context._Screen->Unlock(0);

    if (result != DD_OK)
        throw RuntimeError("Unlock failed");
}

void RenderImpl::Draw(Texture* image, const Math::Vec2u& pos, const Math::Vec2u& size)
{
}

void RenderImpl::Draw(Texture* image, const Math::Vec2u& pos)
{
}

void RenderImpl::Draw(Surface* image, const Math::Vec2u& pos, const Math::Vec2u& size)
{
}

void RenderImpl::Draw(Surface* image, const Math::Vec2u& pos)
{
}

void RenderImpl::Draw(Texture* image, const Math::Vec2u& dstPos, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize)
{
}

void RenderImpl::Draw(Texture* image, const Math::Vec2u& dstPos, const Math::Vec2u& dstSize, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize)
{
}

void RenderImpl::Draw(TextureBatcher* textureBatcher)
{
}