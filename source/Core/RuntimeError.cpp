#include <LDL/Core/RuntimeError.hpp>

LDL::Core::RuntimeError::RuntimeError(const std::string& message) :
	std::runtime_error(message)
{
}