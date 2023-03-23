#ifndef LDL_Core_FastPimpl_hpp
#define LDL_Core_FastPimpl_hpp

#include <LDL/Config.hpp>
#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Core
	{
		class LDL_EXPORT FastPimpl
		{
		public:
			void* operator new(size_t bytes);
			void  operator delete(void* ptr);
		private:
		};
	}
}

#endif    