#include "RenderImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include "../source/Platforms/Windows/Graphics/DirectDraw1/GpuWindowImpl.hpp"

using namespace LDL::Graphics;

RenderImpl::RenderImpl(Window* window) :
	_Window(window),
	_BaseRender(_Window->View())
{
    HRESULT result = DirectDrawCreate(NULL, &_DirectDraw, NULL);

    if (result != DD_OK)
        throw LDL::Core::RuntimeError("DirectDrawCreate failed");

    result = _DirectDraw->SetCooperativeLevel(window->GetWindowImpl()->Hwnd(), DDSCL_NORMAL);

    if (result != DD_OK)
        throw LDL::Core::RuntimeError("SetCooperativeLevel failed");

    ZeroMemory(&_SurfaceDesc, sizeof(_SurfaceDesc));

    _SurfaceDesc.dwSize = sizeof(_SurfaceDesc);
    _SurfaceDesc.dwFlags = DDSD_CAPS;
    _SurfaceDesc.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
    _SurfaceDesc.dwWidth = _BaseRender.Size().PosX();
    _SurfaceDesc.dwHeight = _BaseRender.Size().PosY();

    result = _DirectDraw->CreateSurface(&_SurfaceDesc, &_Primary, NULL);

    if (result != DD_OK)
        throw LDL::Core::RuntimeError("CreateSurface failed");

    result = _DirectDraw->CreateClipper(0, &_DirectDrawClipper, NULL);

    if (result != DD_OK)
        throw LDL::Core::RuntimeError("CreateClipper failed");

    result = _DirectDrawClipper->SetHWnd(0, window->GetWindowImpl()->Hwnd());

    if (result != DD_OK)
        throw LDL::Core::RuntimeError("SetHWnd failed");

    result = _Primary->SetClipper(_DirectDrawClipper);

    if (result != DD_OK)
        throw LDL::Core::RuntimeError("SetClipper failed");
}

LDL::Graphics::RenderImpl::~RenderImpl()
{
    if (_Primary != NULL)
    {
        _Primary->Release();
        _Primary = NULL;
    }

    if (_DirectDraw != NULL)
    {
        _DirectDraw->Release();
        _DirectDraw = NULL;
    }
}

void LDL::Graphics::RenderImpl::Buffer(uint8_t* dst)
{
}

void RenderImpl::Begin()
{
    HRESULT result;

    while (1)
    {
        result = _Primary->Flip(NULL, DDFLIP_WAIT);

        if (result == DD_OK)
            break;

        if (result == DDERR_SURFACELOST)
        {
            result = _Primary->Restore();

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

const Point2u& RenderImpl::Size()
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
    bltfx.dwFillColor = RGB(_BaseRender.Color().Red(), _BaseRender.Color().Green(), _BaseRender.Color().Blue());

    HRESULT result;

    result = _Primary->Blt(NULL, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &bltfx);

    if (result != DD_OK)
        throw LDL::Core::RuntimeError("Blt failed");
}

void RenderImpl::Color(const LDL::Graphics::Color& color)
{
	_BaseRender.Color(color);
}

void RenderImpl::Pixel(const Point2u& pos)
{
}

void RenderImpl::Line(const Point2u& pos1, const Point2u& pos2)
{
}

void RenderImpl::Fill(const Point2u& pos, const Point2u& size)
{
}

void RenderImpl::Draw(Texture* image, const Point2u& pos, const Point2u& size)
{
}

void RenderImpl::Draw(Texture* image, const Point2u& pos)
{

}

void RenderImpl::Draw(Surface* image, const Point2u& pos, const Point2u& size)
{

}

void RenderImpl::Draw(Surface* image, const Point2u& pos)
{

}

void RenderImpl::Draw(Texture* image, const Point2u& dstPos, const Point2u& srcPos, const Point2u& srcSize)
{
}