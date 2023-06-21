#include "RenderImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include "../source/Platforms/Windows/Graphics/DirectDraw/WindowImpl.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

RenderImpl::RenderImpl(RenderContextImpl* renderContextImpl, Window* window) :
	_Window(window),
	_BaseRender(_Window->Size())
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
    _SurfaceDesc.dwWidth = _BaseRender.Size().x;
    _SurfaceDesc.dwHeight = _BaseRender.Size().y;

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

void RenderImpl::Buffer(uint8_t* dst)
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

    result = _Primary->Blt(NULL, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &bltfx);

    if (result != DD_OK)
        throw LDL::Core::RuntimeError("Blt failed");
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