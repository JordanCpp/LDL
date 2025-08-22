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

WindowImplDirectDraw::WindowImplDirectDraw(const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode) :
    _directDraw(NULL),
    _window(pos, size, title, mode)
{
    Library library("ddraw.dll");

    DirectDrawCreate = (PFNDirectDrawCreate)library.Function("DirectDrawCreate");

    HRESULT result = DirectDrawCreate(NULL, &_directDraw, NULL);
    LDL_ASSERT_DETAIL(!FAILED(result), "DirectDrawCreate failed");

    result = _directDraw->SetCooperativeLevel(_window._hwnd, DDSCL_NORMAL);
    LDL_ASSERT_DETAIL(!FAILED(result), "SetCooperativeLevel failed");

    result = _directDraw->SetDisplayMode(size.x, size.y, 24);
    LDL_ASSERT_DETAIL(!FAILED(result), "SetDisplayMode failed");

    DDSURFACEDESC ddsd;

    ZeroMemory(&ddsd, sizeof(DDSURFACEDESC));

    ddsd.dwSize = sizeof(ddsd);
    ddsd.dwFlags = DDSD_CAPS;
    ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;

    result = _directDraw->CreateSurface(&ddsd, &_primary, NULL);
    LDL_ASSERT_DETAIL(!FAILED(result), "CreateSurface failed");

    ddsd.ddsCaps.dwCaps = DDSCAPS_BACKBUFFER;

    result = _directDraw->CreateSurface(&ddsd, &_screen, NULL);
    LDL_ASSERT_DETAIL(!FAILED(result), "CreateSurface failed");

    result = _directDraw->CreateClipper(0, &_clipper, NULL);
    LDL_ASSERT_DETAIL(!FAILED(result), "CreateClipper failed");

    result = _clipper->SetHWnd(0, _window._hwnd);
    LDL_ASSERT_DETAIL(!FAILED(result), "SetHWnd failed");

    result = _primary->SetClipper(_clipper);
    LDL_ASSERT_DETAIL(!FAILED(result), "SetClipper failed");
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

const std::string& WindowImplDirectDraw::Title()
{
    return _window.Title();
}

void WindowImplDirectDraw::Title(const std::string& title)
{
    _window.Title(title);
}

void* WindowImplDirectDraw::NativeHandle()
{
    return _window._hwnd;
}
