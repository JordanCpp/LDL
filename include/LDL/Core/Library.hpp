#ifndef LDL_Core_Library_hpp
#define LDL_Core_Library_hpp

#include <LDL/Core/FastPimpl.hpp>
#include <string>

namespace LDL
{
	namespace Core
	{
		class LibraryImpl;

		class Library : public FastPimpl
		{
		public:
			Library(const std::string& path);
			~Library();
			void* Function(const std::string& name);
		private:
			LibraryImpl* _LibraryImpl;
		};
	}
}

#endif    