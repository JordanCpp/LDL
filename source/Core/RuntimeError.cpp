#include <LDL/Core/RuntimeError.hpp>

LDL::Core::RuntimeError::RuntimeError(const std::string& message) :
	_Message(message)
{
}

const char* LDL::Core::RuntimeError::what() const
{
	return _Message.c_str();
}