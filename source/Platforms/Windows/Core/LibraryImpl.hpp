#ifndef LDL_Platforms_Windows_Core_LibraryImpl_hpp
#define LDL_Platforms_Windows_Core_LibraryImpl_hpp

#include "../Windows.hpp"
#include <string>

namespace LDL
{
	namespace Core
	{
		class LibraryImpl
		{
		public:
			LibraryImpl(const std::string& path);
			~LibraryImpl();
			void* Function(const std::string& name);
		private:
			HMODULE _HMODULE;
		};
	}
}

#endif    