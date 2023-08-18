#include <Arcanum/Core/RuntimeError.hpp>

using namespace Arcanum::Core;

RuntimeError::RuntimeError(const std::string& message) :
	_RuntimeError(message)
{
}

const char* RuntimeError::what() const
{
	return _RuntimeError.what();
}