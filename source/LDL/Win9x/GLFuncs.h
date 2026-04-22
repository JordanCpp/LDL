
#ifndef LDL_Win9x_GLFuncs_H
#define LDL_Win9x_GLFuncs_H

#include <LDL/Library.h>
#include <LDL/Win9x/GLFuncs.h>

typedef struct LDL_OpenGLFunctions
{
	LDL_Result*  Result;
	LDL_Library* Library;
} LDL_OpenGLFunctions;

LDL_LIBRARY void LDL_OpenGLFunctionsInit(LDL_OpenGLFunctions* openGLFunctions, LDL_Result* result);
LDL_LIBRARY void LDL_OpenGLFunctionsDeinit(LDL_OpenGLFunctions* openGLFunctions);
LDL_LIBRARY LDL_VoidFuncPtr LDL_OpenGLFunctionsGetFunction(LDL_OpenGLFunctions* openGLFunctions, const char* name);

#endif
