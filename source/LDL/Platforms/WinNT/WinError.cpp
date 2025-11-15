// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Platforms/WinNT/WinError.hpp>
#include <LDL/Platforms/WinNT/Windows.hpp>

using namespace LDL;

WindowError::WindowError()
{
    Clear();
}

void WindowError::Clear()
{
    _buffer.clear();
}

const char* WindowError::GetErrorMessage()
{
    Clear();

    DWORD lastError = GetLastError();

    if (lastError == 0)
    {
        _buffer.assign("No error");

        return _buffer.c_str();
    }

    DWORD size = FormatMessageA(
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        lastError,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        _buffer.data(),
        (DWORD)_buffer.capacity() + 1,
        NULL
    );

    if (size == 0)
    {
        _buffer.assign("Unknown error");
    }

    size_t length = _buffer.size();

    while (length > 0)
    {
        char lastChar = _buffer.c_str()[length - 1];

        if (lastChar == '\r' || lastChar == '\n')
        {
            _buffer.resize(length - 1);
            length = length - 1;
        }
        else
        {
            break;
        }
    }

    return _buffer.c_str();
}
