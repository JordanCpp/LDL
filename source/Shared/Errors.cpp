#include <LDL/Low/Errors.hpp>
#include <LDL/Low/EHandler.hpp>

static LDL_ErrorHandler _ErrorHandler;

const char* LDL_GetError()
{
	return _ErrorHandler.Message();
}

void LDL_AddError(const char* name)
{
	_ErrorHandler.Message(name);
}