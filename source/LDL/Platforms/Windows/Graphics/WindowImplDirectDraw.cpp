// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Core/Library.hpp>
#include <LDL/Platforms/Windows/Graphics/WindowImplDirectDraw.hpp>

using namespace LDL::Core;
using namespace LDL::Math;
using namespace LDL::Graphics;

WindowImplDirectDraw::WindowImplDirectDraw(Result& result, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode) :
    _directDraw(NULL),
    _result(result),
    _window(_result, pos, size, title, mode)
{
    Library library("ddraw.dll");

    DirectDrawCreate = (PFNDirectDrawCreate)library.Function("DirectDrawCreate");

    if (FAILED(DirectDrawCreate(NULL, &_directDraw, NULL))) _result.Message("DirectDrawCreate failed");
    if (FAILED(_directDraw->SetCooperativeLevel(_window._hwnd, DDSCL_NORMAL))) _result.Message("SetCooperativeLevel failed");
    if (FAILED(_directDraw->SetDisplayMode(size.x, size.y, 24))) _result.Message("SetDisplayMode failed");

    DDSURFACEDESC ddsd;

    ZeroMemory(&ddsd, sizeof(DDSURFACEDESC));

    ddsd.dwSize = sizeof(ddsd);
    ddsd.dwFlags = DDSD_CAPS;
    ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;

    if (FAILED(_directDraw->CreateSurface(&ddsd, &_primary, NULL))) 
        _result.Message("CreateSurface failed");

    ddsd.ddsCaps.dwCaps = DDSCAPS_BACKBUFFER;

    if (FAILED(_directDraw->CreateSurface(&ddsd, &_screen, NULL))) 
        _result.Message("CreateSurface failed");

    if (FAILED(_directDraw->CreateClipper(0, &_clipper, NULL))) 
        _result.Message("CreateClipper failed");

    if (FAILED(_clipper->SetHWnd(0, _window._hwnd)))
        _result.Message("SetHWnd failed");

    if (FAILED(_primary->SetClipper(_clipper)))
        _result.Message("SetClipper failed");
}

WindowImplDirectDraw::~WindowImplDirectDraw()
{
    if (_primary != NULL)
    {
        _primary->Release();
        _primary = NULL;
    }

    if (_screen != NULL)
    {
        _screen->Release();
        _screen = NULL;
    }

    if (_directDraw != NULL)
    {
        _directDraw->Release();
        _directDraw = NULL;
    }

    ReleaseDC(_window._hwnd, _window._hdc);
}

bool WindowImplDirectDraw::Running()
{
    return _window.Running();
}

void WindowImplDirectDraw::Present()
{
}

void WindowImplDirectDraw::PollEvents()
{
    _window.PollEvents();
}

const Vec2u& WindowImplDirectDraw::Size()
{
    return _window.Size();
}

const Vec2u& WindowImplDirectDraw::Pos()
{
    return _window.Pos();
}

bool WindowImplDirectDraw::GetEvent(LDL::Events::Event& event)
{
    return _window.GetEvent(event);
}

bool WindowImplDirectDraw::WaitEvent(LDL::Events::Event& event)
{
    return _window.WaitEvent(event);
}

void WindowImplDirectDraw::StopEvent()
{
    _window.StopEvent();
}

const char* WindowImplDirectDraw::Title()
{
    return _window.Title();
}

void WindowImplDirectDraw::Title(const char* title)
{
    _window.Title(title);
}

void* WindowImplDirectDraw::NativeHandle()
{
    return _window._hwnd;
}
