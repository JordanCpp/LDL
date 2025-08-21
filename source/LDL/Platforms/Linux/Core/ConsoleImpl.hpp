#ifndef LDL_Platforms_Linux_Core_ConsoleImpl_hpp
#define LDL_Platforms_Linux_Core_ConsoleImpl_hpp

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
		};
	}
}

#endif    
