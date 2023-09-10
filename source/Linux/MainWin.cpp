#include "MainWin.hpp"
#include <LDL/Low/Enums.hpp>
#include <LDL/Low/Enums.hpp>

const size_t eventMask =
      PointerMotionMask 
    | ButtonMotionMask 
    | ButtonPressMask
    | ButtonReleaseMask
    | KeyPressMask
    | KeyReleaseMask;

size_t LDL_MainWinow::ConvertKey(size_t key)
{
    switch (key)
    {
    case XK_Meta_L:
    case XK_Super_L:
        return LDL_KeyboardKey::LSystem;
    case XK_Meta_R:
    case XK_Super_R:
        return LDL_KeyboardKey::RSystem;
    case XK_Menu:
        return LDL_KeyboardKey::Menu;
    case XK_semicolon:
        return LDL_KeyboardKey::Semicolon;
    case XK_slash:
        return LDL_KeyboardKey::Slash;
    case XK_equal:
        return LDL_KeyboardKey::Equal;
    case XK_hyphen:
        return LDL_KeyboardKey::Hyphen;
    case XK_bracketleft:
        return LDL_KeyboardKey::LBracket;
    case XK_bracketright:
        return LDL_KeyboardKey::RBracket;
    case XK_comma:
        return LDL_KeyboardKey::Comma;
    case XK_period:
        return LDL_KeyboardKey::Period;
    case XK_backslash:
        return LDL_KeyboardKey::Backslash;
    case XK_Escape:
        return LDL_KeyboardKey::Escape;
    case XK_space:
        return LDL_KeyboardKey::Space;
    case XK_Return:
        return LDL_KeyboardKey::Enter;
    case XK_BackSpace:
        return LDL_KeyboardKey::Backspace;
    case XK_Tab:
        return LDL_KeyboardKey::Tab;
    case XK_Page_Up:
        return LDL_KeyboardKey::PageUp;
    case XK_Page_Down:
        return LDL_KeyboardKey::PageDown;
    case XK_End:
        return LDL_KeyboardKey::End;
    case XK_Home:
        return LDL_KeyboardKey::Home;
    case XK_Insert:
        return LDL_KeyboardKey::Insert;
    case XK_Clear:
        return LDL_KeyboardKey::Delete;
    case XK_KP_Add:
        return LDL_KeyboardKey::Add;
    case XK_KP_Subtract:
        return LDL_KeyboardKey::Subtract;
    case XK_KP_Multiply:
        return LDL_KeyboardKey::Multiply;
    case XK_KP_Divide:
        return LDL_KeyboardKey::Divide;
    case XK_Break:
        return LDL_KeyboardKey::Pause;
    case XK_F1:
        return LDL_KeyboardKey::F1;
    case XK_F2:
        return LDL_KeyboardKey::F2;
    case XK_F3:
        return LDL_KeyboardKey::F3;
    case XK_F4:
        return LDL_KeyboardKey::F4;
    case XK_F5:
        return LDL_KeyboardKey::F5;
    case XK_F6:
        return LDL_KeyboardKey::F6;
    case XK_F7:
        return LDL_KeyboardKey::F7;
    case XK_F8:
        return LDL_KeyboardKey::F8;
    case XK_F9:
        return LDL_KeyboardKey::F9;
    case XK_F10:
        return LDL_KeyboardKey::F10;
    case XK_F11:
        return LDL_KeyboardKey::F11;
    case XK_F12:
        return LDL_KeyboardKey::F12;
    case XK_F13:
        return LDL_KeyboardKey::F13;
    case XK_F14:
        return LDL_KeyboardKey::F14;
    case XK_F15:
        return LDL_KeyboardKey::F15;
    case XK_Left:
        return LDL_KeyboardKey::Left;
    case XK_Right:
        return LDL_KeyboardKey::Right;
    case XK_Up:
        return LDL_KeyboardKey::Up;
    case XK_Down:
        return LDL_KeyboardKey::Down;
    case XK_KP_0:
        return LDL_KeyboardKey::Numpad0;
    case XK_KP_1:
        return LDL_KeyboardKey::Numpad1;
    case XK_KP_2:
        return LDL_KeyboardKey::Numpad2;
    case XK_KP_3:
        return LDL_KeyboardKey::Numpad3;
    case XK_KP_4:
        return LDL_KeyboardKey::Numpad4;
    case XK_KP_5:
        return LDL_KeyboardKey::Numpad5;
    case XK_KP_6:
        return LDL_KeyboardKey::Numpad6;
    case XK_KP_7:
        return LDL_KeyboardKey::Numpad7;
    case XK_KP_8:
        return LDL_KeyboardKey::Numpad8;
    case XK_KP_9:
        return LDL_KeyboardKey::Numpad9;
    case XK_a:
    case XK_A:
        return LDL_KeyboardKey::A;
    case XK_z:
    case XK_Z:
        return LDL_KeyboardKey::Z;
    case XK_e:
    case XK_E:
        return LDL_KeyboardKey::E;
    case XK_r:
    case XK_R:
        return LDL_KeyboardKey::R;
    case XK_t:
    case XK_T:
        return LDL_KeyboardKey::T;
    case XK_y:
    case XK_Y:
        return LDL_KeyboardKey::Y;
    case XK_u:
    case XK_U:
        return LDL_KeyboardKey::U;
    case XK_i:
    case XK_I:
        return LDL_KeyboardKey::I;
    case XK_o:
    case XK_O:
        return LDL_KeyboardKey::O;
    case XK_p:
    case XK_P:
        return LDL_KeyboardKey::P;
    case XK_q:
    case XK_Q:
        return LDL_KeyboardKey::Q;
    case XK_s:
    case XK_S:
        return LDL_KeyboardKey::S;
    case XK_d:
    case XK_D:
        return LDL_KeyboardKey::D;
    case XK_f:
    case XK_F:
        return LDL_KeyboardKey::F;
    case XK_g:
    case XK_G:
        return LDL_KeyboardKey::G;
    case XK_h:
    case XK_H:
        return LDL_KeyboardKey::H;
    case XK_j:
    case XK_J:
        return LDL_KeyboardKey::J;
    case XK_k:
    case XK_K:
        return LDL_KeyboardKey::K;
    case XK_l:
    case XK_L:
        return LDL_KeyboardKey::L;
    case XK_m:
    case XK_M:
        return LDL_KeyboardKey::M;
    case XK_w:
    case XK_W:
        return LDL_KeyboardKey::W;
    case XK_x:
    case XK_X:
        return LDL_KeyboardKey::X;
    case XK_c:
    case XK_C:
        return LDL_KeyboardKey::C;
    case XK_v:
    case XK_V:
        return LDL_KeyboardKey::V;
    case XK_b:
    case XK_B:
        return LDL_KeyboardKey::B;
    case XK_n:
    case XK_N:
        return LDL_KeyboardKey::N;
    case XK_0:
        return LDL_KeyboardKey::Num0;
    case XK_1:
        return LDL_KeyboardKey::Num1;
    case XK_2:
        return LDL_KeyboardKey::Num2;
    case XK_3:
        return LDL_KeyboardKey::Num3;
    case XK_4:
        return LDL_KeyboardKey::Num4;
    case XK_5:
        return LDL_KeyboardKey::Num5;
    case XK_6:
        return LDL_KeyboardKey::Num6;
    case XK_7:
        return LDL_KeyboardKey::Num7;
    case XK_8:
        return LDL_KeyboardKey::Num8;
    case XK_9:
        return LDL_KeyboardKey::Num9;
    case XK_Shift_L:
        return LDL_KeyboardKey::Leftshift;
    case XK_Shift_R:
        return LDL_KeyboardKey::RightShift;
    case XK_Control_L:
        return LDL_KeyboardKey::LeftControl;
    case XK_Control_R:
        return LDL_KeyboardKey::RightControl;
    }

    return LDL_KeyboardKey::Unknown;
}

LDL_MainWinow::LDL_MainWinow(LDL_ErrorHandler* errorHandler, const LDL_Point2u& pos, const LDL_Point2u& size, const char* title, size_t mode) :
    _BaseWindow(pos, size, title),
    _ErrorHandler(errorHandler),
    _EventMask(eventMask)
{
    _Display = XOpenDisplay(NULL);
    _Screen  = DefaultScreen(_Display);
	_Root    = RootWindow(_Display, _Screen);
	_Visual  = DefaultVisual(_Display, _Screen);

    size_t x = _BaseWindow.Pos().x;
    size_t y = _BaseWindow.Pos().y;
    size_t w = _BaseWindow.Size().x;
    size_t h = _BaseWindow.Size().y;

    _Window = XCreateSimpleWindow(_Display, _Root, x, y, w, h, 1, 0, 0);
}

LDL_MainWinow::~LDL_MainWinow()
{
    XCloseDisplay(_Display);
}

bool LDL_MainWinow::Running()
{
    return _Eventer.Running();
}

void LDL_MainWinow::PollEvents()
{
    XEvent event;
    LDL_Event report;
    size_t key  = 0;

    while (XPending(_Display))
    {
        XNextEvent(_Display, &event);

        switch (event.type)
        {
        case KeyPress:
            report.Type = LDL_Events::IsKeyboard;
            report.Keyboard.State = LDL_ButtonState::Pressed;
            key = ConvertKey(XKeycodeToKeysym(_Display, event.xkey.keycode, 0));
            report.Keyboard.Key = key;
            _Eventer.Push(report);
            break;

        case KeyRelease:
            report.Type = LDL_Events::IsKeyboard;
            report.Keyboard.State = LDL_ButtonState::Released;
            key = ConvertKey(XKeycodeToKeysym(_Display, event.xkey.keycode, 0));
            report.Keyboard.Key = key;
            _Eventer.Push(report);
            break;

        case MotionNotify:
            report.Type = LDL_Events::IsMouseMove;
            report.Mouse.PosX = event.xmotion.x;
            report.Mouse.PosY = event.xmotion.y;
            _Eventer.Push(report);
            break;

        case ButtonPress:
            report.Type = LDL_Events::IsMouseClick;
            report.Mouse.State = LDL_ButtonState::Pressed;

            size_t button = 0;

            switch (event.xbutton.button)
            {
            case 1:
                button = LDL_MouseButton::Left;
                break;
            case 2:
                button = LDL_MouseButton::Right;
                break;
            case 3:
                button = LDL_MouseButton::Middle;
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

bool LDL_MainWinow::GetEvent(LDL_Event& event)
{
    if (!_Eventer.Empty())
    {
        _Eventer.Pop(event);

        return true;
    }

    return false;
}

bool LDL_MainWinow::WaitEvent(LDL_Event& event)
{
    return _Eventer.Running();
}

void LDL_MainWinow::StopEvent()
{
    _Eventer.Stop();
}

void LDL_MainWinow::Title(const char* title)
{
    _BaseWindow.Title(title);

   XStoreName(_Display, _Window, _BaseWindow.Title());
}

const char* LDL_MainWinow::Title()
{
    return _BaseWindow.Title();
}

const LDL_Point2u& LDL_MainWinow::Size()
{
   XWindowAttributes attributes;
    XGetWindowAttributes(_Display, _Window, &attributes);

    _BaseWindow.Size(LDL_Point2u(attributes.width, attributes.height));

    return _BaseWindow.Size();
}

const LDL_Point2u& LDL_MainWinow::Pos()
{
    return _BaseWindow.Pos();
}
