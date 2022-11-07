#ifndef LDL_Graphics_BaseScreenshoter_hpp
#define LDL_Graphics_BaseScreenshoter_hpp

#include <string>

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
		};
	}
}

#endif    