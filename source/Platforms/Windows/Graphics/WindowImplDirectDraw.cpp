#include "WindowImplDirectDraw.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Core/Library.hpp>

using namespace LDL::Core;
using namespace LDL::Math;
using namespace LDL::Graphics;

WindowImplDirectDraw::WindowImplDirectDraw(const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode) :
    _DirectDraw(NULL),
    _Window(pos, size, title, mode)
{
    Library library("ddraw.dll");

    DirectDrawCreate = (PFNDirectDrawCreate)library.Function("DirectDrawCreate");

    HRESULT result = DirectDrawCreate(NULL, &_DirectDraw, NULL);

    if (FAILED(result))
        throw RuntimeError("DirectDrawCreate failed");

    result = _DirectDraw->SetCooperativeLevel(_Window._HWND, DDSCL_NORMAL);

    if (FAILED(result))
        throw RuntimeError("SetCooperativeLevel failed");

    result = _DirectDraw->SetDisplayMode(size.x, size.y, 24);

    if (FAILED(result))
        throw RuntimeError("SetDisplayMode failed");

    DDSURFACEDESC ddsd;

    ZeroMemory(&ddsd, sizeof(DDSURFACEDESC));

    ddsd.dwSize = sizeof(ddsd);
    ddsd.dwFlags = DDSD_CAPS;
    ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;

    result = _DirectDraw->CreateSurface(&ddsd, &_Primary, NULL);

    if (FAILED(result))
        throw RuntimeError("CreateSurface failed");

    ddsd.ddsCaps.dwCaps = DDSCAPS_BACKBUFFER;

    result = _DirectDraw->CreateSurface(&ddsd, &_Screen, NULL);

    if (FAILED(result))
        throw RuntimeError("CreateSurface failed");

    result = _DirectDraw->CreateClipper(0, &_Clipper, NULL);

    if (FAILED(result))
        throw RuntimeError("CreateClipper failed");

    result = _Clipper->SetHWnd(0, _Window._HWND);

    if (FAILED(result))
        throw RuntimeError("SetHWnd failed");

    result = _Primary->SetClipper(_Clipper);

    if (FAILED(result))
        throw RuntimeError("SetClipper failed");
}

WindowImplDirectDraw::~WindowImplDirectDraw()
{
    if (_Primary != NULL)
    {
        _Primary->Release();
        _Primary = NULL;
    }

    if (_Screen != NULL)
    {
        _Screen->Release();
        _Screen = NULL;
    }

    if (_DirectDraw != NULL)
    {
        _DirectDraw->Release();
        _DirectDraw = NULL;
    }

    ReleaseDC(_Window._HWND, _Window._HDC);
}

bool WindowImplDirectDraw::Running()
{
    return _Window.Running();
}

void WindowImplDirectDraw::Present()
{
}

void WindowImplDirectDraw::PollEvents()
{
    _Window.PollEvents();
}

const Vec2u& WindowImplDirectDraw::Size()
{
    return _Window.Size();
}

const Vec2u& WindowImplDirectDraw::Pos()
{
    return _Window.Pos();
}

bool WindowImplDirectDraw::GetEvent(LDL::Events::Event& event)
{
    return _Window.GetEvent(event);
}

bool WindowImplDirectDraw::WaitEvent(LDL::Events::Event& event)
{
    return _Window.WaitEvent(event);
}

void WindowImplDirectDraw::StopEvent()
{
    _Window.StopEvent();
}

const std::string& WindowImplDirectDraw::Title()
{
    return _Window.Title();
}

void WindowImplDirectDraw::Title(const std::string& title)
{
    _Window.Title(title);
}

void* WindowImplDirectDraw::NativeHandle()
{
    return _Window._HWND;
}
