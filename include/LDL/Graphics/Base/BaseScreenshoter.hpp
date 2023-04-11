#ifndef LDL_Graphics_BaseScreenshoter_hpp
#define LDL_Graphics_BaseScreenshoter_hpp

#include <LDL/Config.hpp>
#include <LDL/Core/NumberToString.hpp>
#include <string>

namespace LDL
{
	namespace Graphics
	{
		class LDL_EXPORT BaseScreenshoter
		{
		public:
			const std::string Prefix();
		private:
			std::string _Prefix;
			LDL::Core::NumberToString _Converter;
		};
	}
}

#endif    