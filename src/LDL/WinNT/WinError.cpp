// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/WinNT/Windows.hpp>
#include <LDL/WinNT/WinError.hpp>

WindowError::WindowError()
{
    Clear();
}

void WindowError::Clear()
{
    _formatter.Clear();
}

const char* WindowError::GetErrorMessage()
{
    Clear();

    DWORD lastError = GetLastError();

    if (lastError == 0)
    {
        return _formatter.Format("No error");
    }

    DWORD size = FormatMessageA(
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        lastError,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        _formatter.Data(),
        (DWORD)LDL_Formatter::Max,
        NULL
    );

    if (size == 0)
    {
        _formatter.Format("Unknown error");
    }

    return _formatter.Data();
}
