#ifndef LDL_Graphics_GL1Screenshoter_hpp
#define LDL_Graphics_GL1Screenshoter_hpp

#include <LDL/Graphics/IGpuScreenshoter.hpp>
#include <LDL/Graphics/IGpuRender.hpp>
#include <LDL/Graphics/Base/BaseScreenshoter.hpp>

namespace LDL
{
	namespace Graphics
	{
		class GL1Screenshoter: public LDL::Graphics::IGpuScreenshoter
		{
		public:
			GL1Screenshoter(const std::string& path, const std::string& name, LDL::Graphics::IGpuRender* render, LDL::Graphics::CpuImage* image);
			void Shot();
		private:
			LDL::Graphics::BaseScreenshoter _BaseScreenshoter;
			std::string _ShortPath;
			std::string _Name;
			std::string _FullPath;
			LDL::Graphics::IGpuRender* _Render;
			LDL::Graphics::CpuImage* _Image;
		};
	}
}

#endif  