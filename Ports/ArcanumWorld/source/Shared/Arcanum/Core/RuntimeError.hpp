#ifndef Arcanum_Core_RuntimeError_hpp
#define Arcanum_Core_RuntimeError_hpp

#include <stdexcept>

namespace Arcanum
{
	class RuntimeError
	{
	public:
		RuntimeError(const std::string& message);
		const char* what() const;
	private:
		std::runtime_error _runtime_error;
	};
}

#endif