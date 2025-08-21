#ifndef LDL_Platforms_Windows_Core_ConsoleImpl_hpp
#define LDL_Platforms_Windows_Core_ConsoleImpl_hpp

#include "../Windows.hpp"
#include <string>

namespace LDL
{
	namespace Core
	{
		class ConsoleImpl
		{
		public:
			ConsoleImpl();
			void Write(const std::string& text);
		private:
			HANDLE _output;
		};
	}
}

#endif    
