#include <LDL/Low/Errors.hpp>
#include <LDL/Low/EHandler.hpp>

static LDL_ErrorHandler _ErrorHandler;

bool LDL_IsError()
{
	return _ErrorHandler.Ok() != true;
}

const char* LDL_GetError()
{
	return _ErrorHandler.Message();
}

void LDL_AddError(const char* error)
{
	_ErrorHandler.Message(error);
}

void LDL_AddError(const char* error, const char* detail)
{
	_ErrorHandler.Message(error, detail);
}
