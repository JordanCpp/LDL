/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#include <string.h>
#include <LDL/StrSpan.h>
#include <LDL/Win9x/WinX.h>
#include <LDL/Win9x/WinError.h>

void LDL_WindowErrorClear(LDL_WindowError* windowError)
{
    if (windowError)
    {
        memset(windowError->Message, 0, LDL_WindowErrorMax);
    }
}

void LDL_WindowErrorInit(LDL_WindowError* windowError)
{
    if (windowError)
    {
        LDL_WindowErrorClear(windowError);
    }
}

const char* LDL_WindowErrorGetMessage(LDL_WindowError* windowError)
{
    DWORD flag;
    DWORD size;
    DWORD lastError;
    LDL_StringSpan message;

    LDL_WindowErrorClear(windowError);

    lastError = GetLastError();
    
    message = LDL_GetStringSpan(windowError->Message, LDL_WindowErrorMax);
    
    if (lastError == 0)
    {
        LDL_StringSpanCopy(&message, "No error");

        return windowError->Message;
    }

    flag = FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS;
    size = FormatMessageA(flag, NULL, lastError, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), windowError->Message, LDL_WindowErrorMax, NULL);

    if (size == 0)
    {
        LDL_StringSpanCopy(&message, "Unknown error");
    }

   return windowError->Message;
}
