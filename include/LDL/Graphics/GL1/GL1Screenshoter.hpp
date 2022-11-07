#ifndef LDL_Graphics_GL1Screenshoter_hpp
#define LDL_Graphics_GL1Screenshoter_hpp

#include <LDL/Graphics/GL1/GL1Render.hpp>
#include <LDL/Graphics/Base/BaseScreenshoter.hpp>

namespace LDL
{
	namespace Graphics
	{
		class GL1Screenshoter
		{
		public:
			GL1Screenshoter(const std::string& path, const std::string& name, LDL::Graphics::GL1Render* render, LDL::Graphics::CpuImage* image);
			void Shot();
		private:
			LDL::Graphics::BaseScreenshoter _BaseScreenshoter;
			std::string _ShortPath;
			std::string _Name;
			std::string _FullPath;
			LDL::Graphics::GL1Render* _Render;
			LDL::Graphics::CpuImage* _Image;
		};
	}
}

#endif  