// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Enums.hpp>
#include <LDL/WinNT/Windows.hpp>
#include <LDL/WinNT/KeyMapper.hpp>

KeyMapper::KeyMapper()
{
    _keyMapping.Add(LDL_KeyMap(VK_LWIN, LDL_KeyboardKey::LSystem));
    _keyMapping.Add(LDL_KeyMap(VK_RWIN, LDL_KeyboardKey::RSystem));
    _keyMapping.Add(LDL_KeyMap(VK_APPS, LDL_KeyboardKey::Menu));

    _keyMapping.Add(LDL_KeyMap(VK_OEM_1, LDL_KeyboardKey::Semicolon));
    _keyMapping.Add(LDL_KeyMap(VK_OEM_2, LDL_KeyboardKey::Slash));
    _keyMapping.Add(LDL_KeyMap(VK_OEM_PLUS, LDL_KeyboardKey::Equal));
    _keyMapping.Add(LDL_KeyMap(VK_OEM_MINUS, LDL_KeyboardKey::Hyphen));
    _keyMapping.Add(LDL_KeyMap(VK_OEM_4, LDL_KeyboardKey::LBracket));
    _keyMapping.Add(LDL_KeyMap(VK_OEM_6, LDL_KeyboardKey::RBracket));
    _keyMapping.Add(LDL_KeyMap(VK_OEM_COMMA, LDL_KeyboardKey::Comma));
    _keyMapping.Add(LDL_KeyMap(VK_OEM_PERIOD, LDL_KeyboardKey::Period));
    _keyMapping.Add(LDL_KeyMap(VK_OEM_7, LDL_KeyboardKey::Quote));
    _keyMapping.Add(LDL_KeyMap(VK_OEM_5, LDL_KeyboardKey::Backslash));
    _keyMapping.Add(LDL_KeyMap(VK_OEM_3, LDL_KeyboardKey::Tilde));

    _keyMapping.Add(LDL_KeyMap(VK_ESCAPE, LDL_KeyboardKey::Escape));
    _keyMapping.Add(LDL_KeyMap(VK_SPACE, LDL_KeyboardKey::Space));
    _keyMapping.Add(LDL_KeyMap(VK_RETURN, LDL_KeyboardKey::Enter));
    _keyMapping.Add(LDL_KeyMap(VK_BACK, LDL_KeyboardKey::Backspace));
    _keyMapping.Add(LDL_KeyMap(VK_TAB, LDL_KeyboardKey::Tab));

    _keyMapping.Add(LDL_KeyMap(VK_PRIOR, LDL_KeyboardKey::PageUp));
    _keyMapping.Add(LDL_KeyMap(VK_NEXT, LDL_KeyboardKey::PageDown));
    _keyMapping.Add(LDL_KeyMap(VK_END, LDL_KeyboardKey::End));
    _keyMapping.Add(LDL_KeyMap(VK_HOME, LDL_KeyboardKey::Home));
    _keyMapping.Add(LDL_KeyMap(VK_INSERT, LDL_KeyboardKey::Insert));
    _keyMapping.Add(LDL_KeyMap(VK_DELETE, LDL_KeyboardKey::Delete));

    _keyMapping.Add(LDL_KeyMap(VK_LEFT, LDL_KeyboardKey::Left));
    _keyMapping.Add(LDL_KeyMap(VK_RIGHT, LDL_KeyboardKey::Right));
    _keyMapping.Add(LDL_KeyMap(VK_UP, LDL_KeyboardKey::Up));
    _keyMapping.Add(LDL_KeyMap(VK_DOWN, LDL_KeyboardKey::Down));

    _keyMapping.Add(LDL_KeyMap(VK_F1, LDL_KeyboardKey::F1));
    _keyMapping.Add(LDL_KeyMap(VK_F2, LDL_KeyboardKey::F2));
    _keyMapping.Add(LDL_KeyMap(VK_F3, LDL_KeyboardKey::F3));
    _keyMapping.Add(LDL_KeyMap(VK_F4, LDL_KeyboardKey::F4));
    _keyMapping.Add(LDL_KeyMap(VK_F5, LDL_KeyboardKey::F5));
    _keyMapping.Add(LDL_KeyMap(VK_F6, LDL_KeyboardKey::F6));
    _keyMapping.Add(LDL_KeyMap(VK_F7, LDL_KeyboardKey::F7));
    _keyMapping.Add(LDL_KeyMap(VK_F8, LDL_KeyboardKey::F8));
    _keyMapping.Add(LDL_KeyMap(VK_F9, LDL_KeyboardKey::F9));
    _keyMapping.Add(LDL_KeyMap(VK_F10, LDL_KeyboardKey::F10));
    _keyMapping.Add(LDL_KeyMap(VK_F11, LDL_KeyboardKey::F11));
    _keyMapping.Add(LDL_KeyMap(VK_F12, LDL_KeyboardKey::F12));
    _keyMapping.Add(LDL_KeyMap(VK_F13, LDL_KeyboardKey::F13));
    _keyMapping.Add(LDL_KeyMap(VK_F14, LDL_KeyboardKey::F14));
    _keyMapping.Add(LDL_KeyMap(VK_F15, LDL_KeyboardKey::F15));

    _keyMapping.Add(LDL_KeyMap(VK_NUMPAD0, LDL_KeyboardKey::Numpad0));
    _keyMapping.Add(LDL_KeyMap(VK_NUMPAD1, LDL_KeyboardKey::Numpad1));
    _keyMapping.Add(LDL_KeyMap(VK_NUMPAD2, LDL_KeyboardKey::Numpad2));
    _keyMapping.Add(LDL_KeyMap(VK_NUMPAD3, LDL_KeyboardKey::Numpad3));
    _keyMapping.Add(LDL_KeyMap(VK_NUMPAD4, LDL_KeyboardKey::Numpad4));
    _keyMapping.Add(LDL_KeyMap(VK_NUMPAD5, LDL_KeyboardKey::Numpad5));
    _keyMapping.Add(LDL_KeyMap(VK_NUMPAD6, LDL_KeyboardKey::Numpad6));
    _keyMapping.Add(LDL_KeyMap(VK_NUMPAD7, LDL_KeyboardKey::Numpad7));
    _keyMapping.Add(LDL_KeyMap(VK_NUMPAD8, LDL_KeyboardKey::Numpad8));
    _keyMapping.Add(LDL_KeyMap(VK_NUMPAD9, LDL_KeyboardKey::Numpad9));

    _keyMapping.Add(LDL_KeyMap(VK_ADD, LDL_KeyboardKey::Add));
    _keyMapping.Add(LDL_KeyMap(VK_SUBTRACT, LDL_KeyboardKey::Subtract));
    _keyMapping.Add(LDL_KeyMap(VK_MULTIPLY, LDL_KeyboardKey::Multiply));
    _keyMapping.Add(LDL_KeyMap(VK_DIVIDE, LDL_KeyboardKey::Divide));

    _keyMapping.Add(LDL_KeyMap(VK_PAUSE, LDL_KeyboardKey::Pause));

    _keyMapping.Add(LDL_KeyMap('A', LDL_KeyboardKey::A));
    _keyMapping.Add(LDL_KeyMap('Z', LDL_KeyboardKey::Z));
    _keyMapping.Add(LDL_KeyMap('E', LDL_KeyboardKey::E));
    _keyMapping.Add(LDL_KeyMap('R', LDL_KeyboardKey::R));
    _keyMapping.Add(LDL_KeyMap('T', LDL_KeyboardKey::T));
    _keyMapping.Add(LDL_KeyMap('Y', LDL_KeyboardKey::Y));
    _keyMapping.Add(LDL_KeyMap('U', LDL_KeyboardKey::U));
    _keyMapping.Add(LDL_KeyMap('I', LDL_KeyboardKey::I));
    _keyMapping.Add(LDL_KeyMap('O', LDL_KeyboardKey::O));
    _keyMapping.Add(LDL_KeyMap('P', LDL_KeyboardKey::P));
    _keyMapping.Add(LDL_KeyMap('Q', LDL_KeyboardKey::Q));
    _keyMapping.Add(LDL_KeyMap('S', LDL_KeyboardKey::S));
    _keyMapping.Add(LDL_KeyMap('D', LDL_KeyboardKey::D));
    _keyMapping.Add(LDL_KeyMap('F', LDL_KeyboardKey::F));
    _keyMapping.Add(LDL_KeyMap('G', LDL_KeyboardKey::G));
    _keyMapping.Add(LDL_KeyMap('H', LDL_KeyboardKey::H));
    _keyMapping.Add(LDL_KeyMap('J', LDL_KeyboardKey::J));
    _keyMapping.Add(LDL_KeyMap('K', LDL_KeyboardKey::K));
    _keyMapping.Add(LDL_KeyMap('W', LDL_KeyboardKey::W));
}

uint8_t KeyMapper::ConvertKey(size_t key)
{
    return _keyMapping.FindKey(key);
}
