// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "MainWindow.hpp"
#include <LDL/Enums/KeyboardKey.hpp>

using namespace LDL::Math;
using namespace LDL::Enums;
using namespace LDL::Graphics;

const size_t eventMask =
      PointerMotionMask 
    | ButtonMotionMask 
    | ButtonPressMask
    | ButtonReleaseMask
    | KeyPressMask
    | KeyReleaseMask;

size_t MainWindow::ConvertKey(size_t key)
{
    switch (key)
    {
    case XK_Meta_L:
    case XK_Super_L:
        return KeyboardKey::LSystem;
    case XK_Meta_R:
    case XK_Super_R:
        return KeyboardKey::RSystem;
    case XK_Menu:
        return KeyboardKey::Menu;
    case XK_semicolon:
        return KeyboardKey::Semicolon;
    case XK_slash:
        return KeyboardKey::Slash;
    case XK_equal:
        return KeyboardKey::Equal;
    case XK_hyphen:
        return KeyboardKey::Hyphen;
    case XK_bracketleft:
        return KeyboardKey::LBracket;
    case XK_bracketright:
        return KeyboardKey::RBracket;
    case XK_comma:
        return KeyboardKey::Comma;
    case XK_period:
        return KeyboardKey::Period;
    case XK_backslash:
        return KeyboardKey::Backslash;
    case XK_Escape:
        return KeyboardKey::Escape;
    case XK_space:
        return KeyboardKey::Space;
    case XK_Return:
        return KeyboardKey::Enter;
    case XK_BackSpace:
        return KeyboardKey::Backspace;
    case XK_Tab:
        return KeyboardKey::Tab;
    case XK_Page_Up:
        return KeyboardKey::PageUp;
    case XK_Page_Down:
        return KeyboardKey::PageDown;
    case XK_End:
        return KeyboardKey::End;
    case XK_Home:
        return KeyboardKey::Home;
    case XK_Insert:
        return KeyboardKey::Insert;
    case XK_Clear:
        return KeyboardKey::Delete;
    case XK_KP_Add:
        return KeyboardKey::Add;
    case XK_KP_Subtract:
        return KeyboardKey::Subtract;
    case XK_KP_Multiply:
        return KeyboardKey::Multiply;
    case XK_KP_Divide:
        return KeyboardKey::Divide;
    case XK_Break:
        return KeyboardKey::Pause;
    case XK_F1:
        return KeyboardKey::F1;
    case XK_F2:
        return KeyboardKey::F2;
    case XK_F3:
        return KeyboardKey::F3;
    case XK_F4:
        return KeyboardKey::F4;
    case XK_F5:
        return KeyboardKey::F5;
    case XK_F6:
        return KeyboardKey::F6;
    case XK_F7:
        return KeyboardKey::F7;
    case XK_F8:
        return KeyboardKey::F8;
    case XK_F9:
        return KeyboardKey::F9;
    case XK_F10:
        return KeyboardKey::F10;
    case XK_F11:
        return KeyboardKey::F11;
    case XK_F12:
        return KeyboardKey::F12;
    case XK_F13:
        return KeyboardKey::F13;
    case XK_F14:
        return KeyboardKey::F14;
    case XK_F15:
        return KeyboardKey::F15;
    case XK_Left:
        return KeyboardKey::Left;
    case XK_Right:
        return KeyboardKey::Right;
    case XK_Up:
        return KeyboardKey::Up;
    case XK_Down:
        return KeyboardKey::Down;
    case XK_KP_0:
        return KeyboardKey::Numpad0;
    case XK_KP_1:
        return KeyboardKey::Numpad1;
    case XK_KP_2:
        return KeyboardKey::Numpad2;
    case XK_KP_3:
        return KeyboardKey::Numpad3;
    case XK_KP_4:
        return KeyboardKey::Numpad4;
    case XK_KP_5:
        return KeyboardKey::Numpad5;
    case XK_KP_6:
        return KeyboardKey::Numpad6;
    case XK_KP_7:
        return KeyboardKey::Numpad7;
    case XK_KP_8:
        return KeyboardKey::Numpad8;
    case XK_KP_9:
        return KeyboardKey::Numpad9;
    case XK_a:
    case XK_A:
        return KeyboardKey::A;
    case XK_z:
    case XK_Z:
        return KeyboardKey::Z;
    case XK_e:
    case XK_E:
        return KeyboardKey::E;
    case XK_r:
    case XK_R:
        return KeyboardKey::R;
    case XK_t:
    case XK_T:
        return KeyboardKey::T;
    case XK_y:
    case XK_Y:
        return KeyboardKey::Y;
    case XK_u:
    case XK_U:
        return KeyboardKey::U;
    case XK_i:
    case XK_I:
        return KeyboardKey::I;
    case XK_o:
    case XK_O:
        return KeyboardKey::O;
    case XK_p:
    case XK_P:
        return KeyboardKey::P;
    case XK_q:
    case XK_Q:
        return KeyboardKey::Q;
    case XK_s:
    case XK_S:
        return KeyboardKey::S;
    case XK_d:
    case XK_D:
        return KeyboardKey::D;
    case XK_f:
    case XK_F:
        return KeyboardKey::F;
    case XK_g:
    case XK_G:
        return KeyboardKey::G;
    case XK_h:
    case XK_H:
        return KeyboardKey::H;
    case XK_j:
    case XK_J:
        return KeyboardKey::J;
    case XK_k:
    case XK_K:
        return KeyboardKey::K;
    case XK_l:
    case XK_L:
        return KeyboardKey::L;
    case XK_m:
    case XK_M:
        return KeyboardKey::M;
    case XK_w:
    case XK_W:
        return KeyboardKey::W;
    case XK_x:
    case XK_X:
        return KeyboardKey::X;
    case XK_c:
    case XK_C:
        return KeyboardKey::C;
    case XK_v:
    case XK_V:
        return KeyboardKey::V;
    case XK_b:
    case XK_B:
        return KeyboardKey::B;
    case XK_n:
    case XK_N:
        return KeyboardKey::N;
    case XK_0:
        return KeyboardKey::Num0;
    case XK_1:
        return KeyboardKey::Num1;
    case XK_2:
        return KeyboardKey::Num2;
    case XK_3:
        return KeyboardKey::Num3;
    case XK_4:
        return KeyboardKey::Num4;
    case XK_5:
        return KeyboardKey::Num5;
    case XK_6:
        return KeyboardKey::Num6;
    case XK_7:
        return KeyboardKey::Num7;
    case XK_8:
        return KeyboardKey::Num8;
    case XK_9:
        return KeyboardKey::Num9;
    case XK_Shift_L:
        return KeyboardKey::Leftshift;
    case XK_Shift_R:
        return KeyboardKey::RightShift;
    case XK_Control_L:
        return KeyboardKey::LeftControl;
    case XK_Control_R:
        return KeyboardKey::RightControl;
    }

    return KeyboardKey::Unknown;
}

MainWindow::MainWindow(const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode) :
    _BaseWindow(pos, size, title),
    _EventMask(eventMask)
{
    _Display = XOpenDisplay(NULL);
    
    //if (_Display == NULL)
    //    throw RuntimeError("XOpenDisplay failed");

    _Screen = DefaultScreen(_Display);
    _Root   = RootWindow(_Display, _Screen);
}

MainWindow::~MainWindow()
{
	XCloseDisplay(_Display);
}

bool MainWindow::Running()
{
    return _Eventer.Running();
}

void MainWindow::PollEvents()
{
    XEvent event;
    Events::Event report;
    size_t key  = 0;

    while (XPending(_Display))
    {
        XNextEvent(_Display, &event);

        switch (event.type)
        {
        case KeyPress:
            report.Type = LDL::Events::IsKeyboard;
            report.Keyboard.State = ButtonState::Pressed;
            key = ConvertKey(XKeycodeToKeysym(_Display, event.xkey.keycode, 0));
            report.Keyboard.Key = key;
            _Eventer.Push(report);
            break;

        case KeyRelease:
            report.Type = LDL::Events::IsKeyboard;
            report.Keyboard.State = ButtonState::Released;
            key = ConvertKey(XKeycodeToKeysym(_Display, event.xkey.keycode, 0));
            report.Keyboard.Key = key;
            _Eventer.Push(report);
            break;

        case MotionNotify:
            report.Type = Events::IsMouseMove;
            report.Mouse.PosX = event.xmotion.x;
            report.Mouse.PosY = event.xmotion.y;
            _Eventer.Push(report);
            break;

        case ButtonPress:
            report.Type = Events::IsMouseClick;
            report.Mouse.State = LDL::Enums::ButtonState::Pressed;

            size_t button = 0;

            switch (event.xbutton.button)
            {
            case 1:
                button = LDL::Enums::MouseButton::Left;
                break;
            case 2:
                button = LDL::Enums::MouseButton::Right;
                break;
            case 3:
                button = LDL::Enums::MouseButton::Middle;
                break;
            }

            report.Mouse.Button = button;
            report.Mouse.PosX = event.xbutton.x;
            report.Mouse.PosY = event.xbutton.y;
            _Eventer.Push(report);
            break;
        }
    }
}

bool MainWindow::GetEvent(LDL::Events::Event& event)
{
    if (!_Eventer.Empty())
    {
        _Eventer.Pop(event);

        return true;
    }

    return false;
}

bool MainWindow::WaitEvent(LDL::Events::Event& event)
{
    return _Eventer.Running();
}

void MainWindow::StopEvent()
{
    _Eventer.Stop();
}

void MainWindow::Title(const std::string& title)
{
    _BaseWindow.Title(title);

    XStoreName(_Display, _Window, _BaseWindow.Title().c_str());
}

const std::string& MainWindow::Title()
{
    return _BaseWindow.Title();
}

const Vec2u& MainWindow::Size()
{
    XWindowAttributes attributes;
    XGetWindowAttributes(_Display, _Window, &attributes);

    _BaseWindow.Size(Vec2u(attributes.width, attributes.height));

    return _BaseWindow.Size();
}

const Vec2u& MainWindow::Pos()
{
    return _BaseWindow.Pos();
}

void MainWindow::Show()
{
    XClearWindow(_Display, _Window);
	XMapRaised(_Display, _Window); 
}