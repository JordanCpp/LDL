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

#include <LDL/ErrorMsg.h>

static const char LDL_ErrorMessageOutOfMemory[]     = "LDL error: Out of memory\n";
static const char LDL_ErrorMessageInvalidArgument[] = "LDL error: Invalid Argument %s.\n";

const char* LDL_ErrorOutOfMemory()
{
	return LDL_ErrorMessageOutOfMemory;
}

const char* LDL_ErrorInvalidArgument()
{
	return LDL_ErrorMessageInvalidArgument;
}
