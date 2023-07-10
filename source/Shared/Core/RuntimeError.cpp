#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Core;

RuntimeError::RuntimeError(const std::string& message) :
	_Message(message)
{
}

const char* RuntimeError::what() const
{
	return _Message.c_str();
}