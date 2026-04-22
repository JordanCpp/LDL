
#ifndef LDL_StrSpan_H
#define LDL_StrSpan_H

typedef struct LDL_StringSpan
{
	char*  Data;
	size_t Capacity;
} LDL_StringSpan;

LDL_StringSpan LDL_GetStringSpan(char* data, size_t capacity);
void LDL_StringSpanCopy(LDL_StringSpan* span, const char* source);

#endif
