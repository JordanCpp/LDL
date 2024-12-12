#ifndef LDL_Core_Console_hpp
#define LDL_Core_Console_hpp

#include <LDL/Core/Types.hpp>
#include <string>

namespace LDL
{
    namespace Core
    {
		class ConsoleImpl;

		class LDL_LIBRARY Console
		{
		public:
			Console();
			~Console();
			void Write(const std::string& text);
		private:
			ConsoleImpl* _impl;
		};
    }
}

#endif
