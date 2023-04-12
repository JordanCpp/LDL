#ifndef LDL_Core_Library_hpp
#define LDL_Core_Library_hpp

#include <LDL/Core/FastPimpl.hpp>
#include <string>

namespace LDL
{
	typedef void(*VoidFuncPtr)(void);

	namespace Core
	{
		class LibraryImpl;

		class LDL_EXPORT Library : public FastPimpl
		{
		public:
			Library(const std::string& path);
			~Library();
			VoidFuncPtr Function(const std::string& name);
		private:
			LibraryImpl* _LibraryImpl;
		};
	}
}

#endif    