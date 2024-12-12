#include <Arcanum/Core/RuntimeError.hpp>

using namespace Arcanum::Core;

RuntimeError::RuntimeError(const std::string& message) :
	_runtime_error(message)
{
}

const char* RuntimeError::what() const
{
	return _runtime_error.what();
}