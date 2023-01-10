#include "GpuRenderImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include "../source/Platforms/Windows/Graphics/DirectDraw1/GpuWindowImpl.hpp"

using namespace LDL::Graphics;

GpuRenderImpl::GpuRenderImpl(GpuWindow* window) :
	_Window(window),
	_BaseRender(_Window->View())
{
    HRESULT result = DirectDrawCreate(NULL, &_DirectDraw, NULL);

    if (result != DD_OK)
        throw LDL::Core::RuntimeError("DirectDrawCreate failed");

    result = _DirectDraw->SetCooperativeLevel(window->GetGpuWindowImpl()->Hwnd(), DDSCL_NORMAL);

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

    result = _DirectDrawClipper->SetHWnd(0, window->GetGpuWindowImpl()->Hwnd());

    if (result != DD_OK)
        throw LDL::Core::RuntimeError("SetHWnd failed");

    result = _Primary->SetClipper(_DirectDrawClipper);

    if (result != DD_OK)
        throw LDL::Core::RuntimeError("SetClipper failed");
}

LDL::Graphics::GpuRenderImpl::~GpuRenderImpl()
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

void LDL::Graphics::GpuRenderImpl::Screen(uint8_t* dst)
{
}

void GpuRenderImpl::Begin()
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

void GpuRenderImpl::End()
{
    /*
    HRESULT result;

    result = _Primary->Flip(NULL, DDFLIP_WAIT);

    if (result != DD_OK)
        throw LDL::Core::RuntimeError("Flip failed");
    */
}

const Point2u& GpuRenderImpl::Size()
{
	return _BaseRender.Size();
}

const Color& GpuRenderImpl::Color()
{
	return _BaseRender.Color();
}

void GpuRenderImpl::Clear()
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

void GpuRenderImpl::Color(const LDL::Graphics::Color& color)
{
	_BaseRender.Color(color);
}

void GpuRenderImpl::Pixel(const Point2u& pos)
{
}

void GpuRenderImpl::Line(const Point2u& pos1, const Point2u& pos2)
{
}

void GpuRenderImpl::Fill(const Point2u& pos, const Point2u& size)
{
}

void GpuRenderImpl::Draw(GpuImage* image, const Point2u& pos, const Point2u& size)
{
}

void GpuRenderImpl::Draw(GpuImage* image, const Point2u& pos)
{

}

void GpuRenderImpl::Draw(CpuImage* image, const Point2u& pos, const Point2u& size)
{

}

void GpuRenderImpl::Draw(CpuImage* image, const Point2u& pos)
{

}

void GpuRenderImpl::Draw(GpuImage* image, const Point2u& dstPos, const Point2u& srcPos, const Point2u& srcSize)
{
}