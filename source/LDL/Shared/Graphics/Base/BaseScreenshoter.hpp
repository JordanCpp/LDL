#ifndef LDL_Graphics_BaseScreenShotter_hpp
#define LDL_Graphics_BaseScreenShotter_hpp

#include <LDL/Core/Convert.hpp>
#include <string>

namespace LDL
{
	namespace Graphics
	{
		class LDL_LIBRARY BaseScreenShotter
		{
		public:
			const std::string Prefix();
		private:
			std::string   _prefix;
			Core::Convert _converter;
		};
	}
}

#endif    
