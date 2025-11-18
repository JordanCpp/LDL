// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Enums/KeyboardKey.hpp>
#include <LDL/WinNT/Windows.hpp>
#include <LDL/WinNT/Input/KeyMapper.hpp>

using namespace LDL;

KeyMapper::KeyMapper()
{
    _keyMapping.Add(KeyMap(VK_LWIN, KeyboardKey::LSystem));
    _keyMapping.Add(KeyMap(VK_RWIN, KeyboardKey::RSystem));
    _keyMapping.Add(KeyMap(VK_APPS, KeyboardKey::Menu));

    _keyMapping.Add(KeyMap(VK_OEM_1, KeyboardKey::Semicolon));
    _keyMapping.Add(KeyMap(VK_OEM_2, KeyboardKey::Slash));
    _keyMapping.Add(KeyMap(VK_OEM_PLUS, KeyboardKey::Equal));
    _keyMapping.Add(KeyMap(VK_OEM_MINUS, KeyboardKey::Hyphen));
    _keyMapping.Add(KeyMap(VK_OEM_4, KeyboardKey::LBracket));
    _keyMapping.Add(KeyMap(VK_OEM_6, KeyboardKey::RBracket));
    _keyMapping.Add(KeyMap(VK_OEM_COMMA, KeyboardKey::Comma));
    _keyMapping.Add(KeyMap(VK_OEM_PERIOD, KeyboardKey::Period));
    _keyMapping.Add(KeyMap(VK_OEM_7, KeyboardKey::Quote));
    _keyMapping.Add(KeyMap(VK_OEM_5, KeyboardKey::Backslash));
    _keyMapping.Add(KeyMap(VK_OEM_3, KeyboardKey::Tilde));

    _keyMapping.Add(KeyMap(VK_ESCAPE, KeyboardKey::Escape));
    _keyMapping.Add(KeyMap(VK_SPACE, KeyboardKey::Space));
    _keyMapping.Add(KeyMap(VK_RETURN, KeyboardKey::Enter));
    _keyMapping.Add(KeyMap(VK_BACK, KeyboardKey::Backspace));
    _keyMapping.Add(KeyMap(VK_TAB, KeyboardKey::Tab));

    _keyMapping.Add(KeyMap(VK_PRIOR, KeyboardKey::PageUp));
    _keyMapping.Add(KeyMap(VK_NEXT, KeyboardKey::PageDown));
    _keyMapping.Add(KeyMap(VK_END, KeyboardKey::End));
    _keyMapping.Add(KeyMap(VK_HOME, KeyboardKey::Home));
    _keyMapping.Add(KeyMap(VK_INSERT, KeyboardKey::Insert));
    _keyMapping.Add(KeyMap(VK_DELETE, KeyboardKey::Delete));

    _keyMapping.Add(KeyMap(VK_LEFT, KeyboardKey::Left));
    _keyMapping.Add(KeyMap(VK_RIGHT, KeyboardKey::Right));
    _keyMapping.Add(KeyMap(VK_UP, KeyboardKey::Up));
    _keyMapping.Add(KeyMap(VK_DOWN, KeyboardKey::Down));

    _keyMapping.Add(KeyMap(VK_F1, KeyboardKey::F1));
    _keyMapping.Add(KeyMap(VK_F2, KeyboardKey::F2));
    _keyMapping.Add(KeyMap(VK_F3, KeyboardKey::F3));
    _keyMapping.Add(KeyMap(VK_F4, KeyboardKey::F4));
    _keyMapping.Add(KeyMap(VK_F5, KeyboardKey::F5));
    _keyMapping.Add(KeyMap(VK_F6, KeyboardKey::F6));
    _keyMapping.Add(KeyMap(VK_F7, KeyboardKey::F7));
    _keyMapping.Add(KeyMap(VK_F8, KeyboardKey::F8));
    _keyMapping.Add(KeyMap(VK_F9, KeyboardKey::F9));
    _keyMapping.Add(KeyMap(VK_F10, KeyboardKey::F10));
    _keyMapping.Add(KeyMap(VK_F11, KeyboardKey::F11));
    _keyMapping.Add(KeyMap(VK_F12, KeyboardKey::F12));
    _keyMapping.Add(KeyMap(VK_F13, KeyboardKey::F13));
    _keyMapping.Add(KeyMap(VK_F14, KeyboardKey::F14));
    _keyMapping.Add(KeyMap(VK_F15, KeyboardKey::F15));

    _keyMapping.Add(KeyMap(VK_NUMPAD0, KeyboardKey::Numpad0));
    _keyMapping.Add(KeyMap(VK_NUMPAD1, KeyboardKey::Numpad1));
    _keyMapping.Add(KeyMap(VK_NUMPAD2, KeyboardKey::Numpad2));
    _keyMapping.Add(KeyMap(VK_NUMPAD3, KeyboardKey::Numpad3));
    _keyMapping.Add(KeyMap(VK_NUMPAD4, KeyboardKey::Numpad4));
    _keyMapping.Add(KeyMap(VK_NUMPAD5, KeyboardKey::Numpad5));
    _keyMapping.Add(KeyMap(VK_NUMPAD6, KeyboardKey::Numpad6));
    _keyMapping.Add(KeyMap(VK_NUMPAD7, KeyboardKey::Numpad7));
    _keyMapping.Add(KeyMap(VK_NUMPAD8, KeyboardKey::Numpad8));
    _keyMapping.Add(KeyMap(VK_NUMPAD9, KeyboardKey::Numpad9));

    _keyMapping.Add(KeyMap(VK_ADD, KeyboardKey::Add));
    _keyMapping.Add(KeyMap(VK_SUBTRACT, KeyboardKey::Subtract));
    _keyMapping.Add(KeyMap(VK_MULTIPLY, KeyboardKey::Multiply));
    _keyMapping.Add(KeyMap(VK_DIVIDE, KeyboardKey::Divide));

    _keyMapping.Add(KeyMap(VK_PAUSE, KeyboardKey::Pause));

    _keyMapping.Add(KeyMap('A', KeyboardKey::A));
    _keyMapping.Add(KeyMap('Z', KeyboardKey::Z));
    _keyMapping.Add(KeyMap('E', KeyboardKey::E));
    _keyMapping.Add(KeyMap('R', KeyboardKey::R));
    _keyMapping.Add(KeyMap('T', KeyboardKey::T));
    _keyMapping.Add(KeyMap('Y', KeyboardKey::Y));
    _keyMapping.Add(KeyMap('U', KeyboardKey::U));
    _keyMapping.Add(KeyMap('I', KeyboardKey::I));
    _keyMapping.Add(KeyMap('O', KeyboardKey::O));
    _keyMapping.Add(KeyMap('P', KeyboardKey::P));
    _keyMapping.Add(KeyMap('Q', KeyboardKey::Q));
    _keyMapping.Add(KeyMap('S', KeyboardKey::S));
    _keyMapping.Add(KeyMap('D', KeyboardKey::D));
    _keyMapping.Add(KeyMap('F', KeyboardKey::F));
    _keyMapping.Add(KeyMap('G', KeyboardKey::G));
    _keyMapping.Add(KeyMap('H', KeyboardKey::H));
    _keyMapping.Add(KeyMap('J', KeyboardKey::J));
    _keyMapping.Add(KeyMap('K', KeyboardKey::K));
    _keyMapping.Add(KeyMap('W', KeyboardKey::W));
}

uint8_t KeyMapper::ConvertKey(size_t key)
{
    return _keyMapping.FindKey(key);
}
