#include <LDL/Low/EHandler.hpp>
#include <string.h>

LDL_ErrorHandler::LDL_ErrorHandler() :
	_IsOk(true)
{
}

void LDL_ErrorHandler::Message(const char* message, const char* detail)
{
	_IsOk = false;

	_Message.Assign(message);
	_Message.Append(detail);
}

const char* LDL_ErrorHandler::Message()
{
	return _Message.CStr();
}

bool LDL_ErrorHandler::Ok()
{
	return _IsOk;
}
