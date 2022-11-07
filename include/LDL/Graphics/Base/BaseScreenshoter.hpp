#ifndef LDL_Graphics_BaseScreenshoter_hpp
#define LDL_Graphics_BaseScreenshoter_hpp

#include <string>
#include <LDL/Core/IntegerToString.hpp>

namespace LDL
{
	namespace Graphics
	{
		class BaseScreenshoter
		{
		public:
			const std::string Prefix();
		private:
			std::string _Prefix;
			LDL::Core::IntegerToString _Converter;
		};
	}
}

#endif    