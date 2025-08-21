#ifndef LDL_Graphics_ScreenShotter_hpp
#define LDL_Graphics_ScreenShotter_hpp

#include <LDL/Graphics/Render.hpp>

namespace LDL
{
	namespace Graphics
	{
		class ScreenShotterImpl;

		class ScreenShotter
		{
		public:
			ScreenShotter(const std::string& path, const std::string& name, Render* render, Surface* image);
			~ScreenShotter();
			void Shot();
		private:
			ScreenShotterImpl* _impl;
		};
	}
}

#endif  
