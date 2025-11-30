// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/WinNT/Windows.hpp>
#include <LDL/WinNT/WinError.hpp>

static const DWORD formatMessage = FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS;
static const DWORD defaultLangId = MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT);

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
    DWORD lastError = GetLastError();

    if (lastError == 0)
    {
        return _formatter.Format("No error");
    }

    Clear();

    DWORD size = FormatMessageA(formatMessage, NULL, lastError, defaultLangId, _formatter.Data(), (DWORD)LDL_Formatter::Max, NULL);

    if (size == 0)
    {
        _formatter.Format("Unknown error: 0x%08X", lastError);
    }

    return _formatter.Data();
}
