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

#ifndef LDL_Win9x_WinError_H
#define LDL_Win9x_WinError_H

enum
{
	LDL_WindowErrorMax = 128
};

typedef struct LDL_WindowError
{
	char Message[LDL_WindowErrorMax];
} LDL_WindowError;

void LDL_WindowErrorClear(LDL_WindowError* windowError);
void LDL_WindowErrorInit(LDL_WindowError* windowError);
const char* LDL_WindowErrorGetMessage(LDL_WindowError* windowError);

#endif
