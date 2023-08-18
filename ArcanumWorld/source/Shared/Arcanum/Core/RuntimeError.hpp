#ifndef Arcanum_Core_RuntimeError_hpp
#define Arcanum_Core_RuntimeError_hpp

#include <LDL/Core/RuntimeError.hpp>

namespace Arcanum
{
	namespace Core
	{
		class RuntimeError 
		{
		public:
			RuntimeError(const std::string& message);
			const char* what() const;
		private:
			LDL::Core::RuntimeError _RuntimeError;
		};
	}
}

#endif