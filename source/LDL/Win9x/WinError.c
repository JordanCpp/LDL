
#include <string.h>
#include <LDL/StrSpan.h>
#include <LDL/Win9x/WinX.h>
#include <LDL/Win9x/WinError.h>

void LDL_WindowErrorClear(LDL_WindowError* windowError)
{
	memset(windowError->Message, 0, LDL_WindowErrorMax);
}

void LDL_WindowErrorInit(LDL_WindowError* windowError)
{
	LDL_WindowErrorClear(windowError);
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
