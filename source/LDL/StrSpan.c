
#include <string.h>
#include <LDL/StrSpan.h>

LDL_StringSpan LDL_GetStringSpan(char* data, size_t capacity)
{
    LDL_StringSpan span;

    span.Data     = data;
    span.Capacity = capacity;

    return span;
}

void LDL_StringSpanCopy(LDL_StringSpan* span, const char* source)
{
    if (span && span->Data && source)
    {
        strncpy(span->Data, source, span->Capacity - 1);
        span->Data[span->Capacity - 1] = '\0';
    }
}
