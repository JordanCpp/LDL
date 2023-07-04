#include "MainWindow.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Enums/KeyboardKey.hpp>

using namespace LDL::Core;
using namespace LDL::Math;
using namespace LDL::Graphics;

Bool CheckEvent(Display*, XEvent* event, XPointer pointer)
{
    return ((XAnyEvent*)&event->xany.window == (XAnyEvent*)pointer || (event->type == ClientMessage));
}

size_t MainWindow::ConvertKey(size_t key)
{
    switch (key)
    {
    case XK_Meta_L: case XK_Super_L:      return LDL::Enums::KeyboardKey::LSystem;
    case XK_Meta_R: case XK_Super_R:      return LDL::Enums::KeyboardKey::RSystem;
    case XK_Menu:       return LDL::Enums::KeyboardKey::Menu;
    case XK_semicolon:      return LDL::Enums::KeyboardKey::Semicolon;
    case XK_slash:      return LDL::Enums::KeyboardKey::Slash;
    case XK_equal:   return LDL::Enums::KeyboardKey::Equal;
    case XK_hyphen:  return LDL::Enums::KeyboardKey::Hyphen;
    case XK_bracketleft:      return LDL::Enums::KeyboardKey::LBracket;
    case XK_bracketright:      return LDL::Enums::KeyboardKey::RBracket;
    case XK_comma:  return LDL::Enums::KeyboardKey::Comma;
    case XK_period: return LDL::Enums::KeyboardKey::Period;
    case XK_backslash:      return LDL::Enums::KeyboardKey::Backslash;
    case XK_Escape:     return LDL::Enums::KeyboardKey::Escape;
    case XK_space:      return LDL::Enums::KeyboardKey::Space;
    case XK_Return:     return LDL::Enums::KeyboardKey::Enter;
    case XK_BackSpace:       return LDL::Enums::KeyboardKey::Backspace;
    case XK_Tab:        return LDL::Enums::KeyboardKey::Tab;
    case XK_Page_Up:      return LDL::Enums::KeyboardKey::PageUp;
    case XK_Page_Down:       return LDL::Enums::KeyboardKey::PageDown;
    case XK_End:        return LDL::Enums::KeyboardKey::End;
    case XK_Home:       return LDL::Enums::KeyboardKey::Home;
    case XK_Insert:     return LDL::Enums::KeyboardKey::Insert;
    case XK_Clear:     return LDL::Enums::KeyboardKey::Delete;
    case XK_KP_Add:        return LDL::Enums::KeyboardKey::Add;
    case XK_KP_Subtract:   return LDL::Enums::KeyboardKey::Subtract;
    case XK_KP_Multiply:   return LDL::Enums::KeyboardKey::Multiply;
    case XK_KP_Divide:     return LDL::Enums::KeyboardKey::Divide;
    case XK_Break:      return LDL::Enums::KeyboardKey::Pause;
    case XK_F1:         return LDL::Enums::KeyboardKey::F1;
    case XK_F2:         return LDL::Enums::KeyboardKey::F2;
    case XK_F3:         return LDL::Enums::KeyboardKey::F3;
    case XK_F4:         return LDL::Enums::KeyboardKey::F4;
    case XK_F5:         return LDL::Enums::KeyboardKey::F5;
    case XK_F6:         return LDL::Enums::KeyboardKey::F6;
    case XK_F7:         return LDL::Enums::KeyboardKey::F7;
    case XK_F8:         return LDL::Enums::KeyboardKey::F8;
    case XK_F9:         return LDL::Enums::KeyboardKey::F9;
    case XK_F10:        return LDL::Enums::KeyboardKey::F10;
    case XK_F11:        return LDL::Enums::KeyboardKey::F11;
    case XK_F12:        return LDL::Enums::KeyboardKey::F12;
    case XK_F13:        return LDL::Enums::KeyboardKey::F13;
    case XK_F14:        return LDL::Enums::KeyboardKey::F14;
    case XK_F15:        return LDL::Enums::KeyboardKey::F15;
    case XK_Left:       return LDL::Enums::KeyboardKey::Left;
    case XK_Right:      return LDL::Enums::KeyboardKey::Right;
    case XK_Up:         return LDL::Enums::KeyboardKey::Up;
    case XK_Down:       return LDL::Enums::KeyboardKey::Down;
    case XK_KP_0:    return LDL::Enums::KeyboardKey::Numpad0;
    case XK_KP_1:    return LDL::Enums::KeyboardKey::Numpad1;
    case XK_KP_2:    return LDL::Enums::KeyboardKey::Numpad2;
    case XK_KP_3:    return LDL::Enums::KeyboardKey::Numpad3;
    case XK_KP_4:    return LDL::Enums::KeyboardKey::Numpad4;
    case XK_KP_5:    return LDL::Enums::KeyboardKey::Numpad5;
    case XK_KP_6:    return LDL::Enums::KeyboardKey::Numpad6;
    case XK_KP_7:    return LDL::Enums::KeyboardKey::Numpad7;
    case XK_KP_8:    return LDL::Enums::KeyboardKey::Numpad8;
    case XK_KP_9:    return LDL::Enums::KeyboardKey::Numpad9;
    case XK_a: case XK_A:           return LDL::Enums::KeyboardKey::A;
    case XK_z: case XK_Z:           return LDL::Enums::KeyboardKey::Z;
    case XK_e: case XK_E:           return LDL::Enums::KeyboardKey::E;
    case XK_r: case XK_R:           return LDL::Enums::KeyboardKey::R;
    case XK_t: case XK_T:           return LDL::Enums::KeyboardKey::T;
    case XK_y: case XK_Y:           return LDL::Enums::KeyboardKey::Y;
    case XK_u: case XK_U:           return LDL::Enums::KeyboardKey::U;
    case XK_i: case XK_I:           return LDL::Enums::KeyboardKey::I;
    case XK_o: case XK_O:           return LDL::Enums::KeyboardKey::O;
    case XK_p: case XK_P:           return LDL::Enums::KeyboardKey::P;
    case XK_q: case XK_Q:           return LDL::Enums::KeyboardKey::Q;
    case XK_s: case XK_S:           return LDL::Enums::KeyboardKey::S;
    case XK_d: case XK_D:           return LDL::Enums::KeyboardKey::D;
    case XK_f: case XK_F:           return LDL::Enums::KeyboardKey::F;
    case XK_g: case XK_G:           return LDL::Enums::KeyboardKey::G;
    case XK_h: case XK_H:           return LDL::Enums::KeyboardKey::H;
    case XK_j: case XK_J:           return LDL::Enums::KeyboardKey::J;
    case XK_k: case XK_K:           return LDL::Enums::KeyboardKey::K;
    case XK_l: case XK_L:           return LDL::Enums::KeyboardKey::L;
    case XK_m: case XK_M:           return LDL::Enums::KeyboardKey::M;
    case XK_w: case XK_W:           return LDL::Enums::KeyboardKey::W;
    case XK_x: case XK_X:           return LDL::Enums::KeyboardKey::X;
    case XK_c: case XK_C:           return LDL::Enums::KeyboardKey::C;
    case XK_v: case XK_V:           return LDL::Enums::KeyboardKey::V;
    case XK_b: case XK_B:           return LDL::Enums::KeyboardKey::B;
    case XK_n: case XK_N:           return LDL::Enums::KeyboardKey::N;
    case XK_0:           return LDL::Enums::KeyboardKey::Num0;
    case XK_1:           return LDL::Enums::KeyboardKey::Num1;
    case XK_2:           return LDL::Enums::KeyboardKey::Num2;
    case XK_3:           return LDL::Enums::KeyboardKey::Num3;
    case XK_4:           return LDL::Enums::KeyboardKey::Num4;
    case XK_5:           return LDL::Enums::KeyboardKey::Num5;
    case XK_6:           return LDL::Enums::KeyboardKey::Num6;
    case XK_7:           return LDL::Enums::KeyboardKey::Num7;
    case XK_8:           return LDL::Enums::KeyboardKey::Num8;
    case XK_9:           return LDL::Enums::KeyboardKey::Num9;
    case XK_Shift_L:     return LDL::Enums::KeyboardKey::Leftshift;
    case XK_Shift_R:     return LDL::Enums::KeyboardKey::RightShift;
    case XK_Control_L:   return LDL::Enums::KeyboardKey::LeftControl;
    case XK_Control_R:   return LDL::Enums::KeyboardKey::RightControl;
    }
       
    return LDL::Enums::KeyboardKey::Unknown;
}

MainWindow::MainWindow(const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode) :
    _BaseWindow(pos, size, title)
{
    _Display = XOpenDisplay(NULL);
    if (_Display == NULL)
        throw RuntimeError("XOpenDisplay failed");

    _Screen   = DefaultScreenOfDisplay(_Display);
	_ScreenId = DefaultScreen(_Display);
}

MainWindow::~MainWindow()
{
    XDestroyWindow(_Display, _Window);
	XFree(_Screen);
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

    while (XCheckMaskEvent(_Display, PointerMotionMask | ButtonMotionMask, &event))
    {
        switch (event.type)
        {
        case KeyPress:
            report.Type = LDL::Events::IsKeyboard;
            report.Keyboard.State = LDL::Enums::ButtonState::Pressed;
            report.Keyboard.Key = ConvertKey(event.xkey.keycode);
            _Eventer.Push(report);
            break;

        case MotionNotify:
            report.Type = Events::IsMouseMove;
            report.Mouse.PosX = event.xmotion.x;
            report.Mouse.PosY = event.xmotion.y;
            _Eventer.Push(report);
            break;
        }
    }

    glXSwapBuffers(_Display, _Window);
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