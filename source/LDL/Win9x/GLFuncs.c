
#include <LDL/Win9x/GLFuncs.h>
#include <LDL/Win9x/WinX.h>

void LDL_OpenGLFunctionsInit(LDL_OpenGLFunctions* openGLFunctions, LDL_Result* result)
{
	if (openGLFunctions)
	{
		openGLFunctions->Result  = result;
		openGLFunctions->Library = LDL_LibraryNew(result);

		if (LDL_ResultIsOk(result))
		{
			if (!LDL_LibraryOpen(openGLFunctions->Library, "OpenGL32.dll"))
			{
				LDL_OpenGLFunctionsDeinit(openGLFunctions);
			}
		}
	}
}

void LDL_OpenGLFunctionsDeinit(LDL_OpenGLFunctions* openGLFunctions)
{
	if (openGLFunctions)
	{
		if (openGLFunctions->Library)
		{
			LDL_LibraryFree(openGLFunctions->Library);
		}

		free(openGLFunctions);
	}
}

bool IsValid(LDL_VoidFuncPtr ptr)
{
	return (ptr == 0 || (ptr == (LDL_VoidFuncPtr)0x1) || (ptr == (LDL_VoidFuncPtr)0x2) || (ptr == (LDL_VoidFuncPtr)0x3) || (ptr == (LDL_VoidFuncPtr)-1));
}

LDL_VoidFuncPtr LDL_OpenGLFunctionsGetFunction(LDL_OpenGLFunctions* openGLFunctions, const char* name)
{
	LDL_VoidFuncPtr result = (LDL_VoidFuncPtr)wglGetProcAddress(name);

	if (IsValid(result))
	{
		result = LDL_LibraryGetFunction(openGLFunctions->Library, name);
	}

	return result;
}
