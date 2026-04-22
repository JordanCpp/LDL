
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
