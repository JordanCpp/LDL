#ifndef LDL_EHandler_hpp
#define LDL_EHandler_hpp

#include <LDL/Low/String.hpp>

class LDL_ErrorHandler
{
public:
	LDL_ErrorHandler();
	void Message(const char* message, const char* detail = "");
	const char* Message();
	bool Ok();
private:
	bool _IsOk;
	LDL_String _Message;
};

#endif
