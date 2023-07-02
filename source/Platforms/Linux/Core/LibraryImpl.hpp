#ifndef LDL_Platforms_Windows_Core_LibraryImpl_hpp
#define LDL_Platforms_Windows_Core_LibraryImpl_hpp

#include <LDL/Core/Types.hpp>
#include <LDL/Core/Library.hpp>
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
			LDL::VoidFuncPtr Function(const std::string& name);
		private:
		    void* _Library;
		};
	}
}

#endif    