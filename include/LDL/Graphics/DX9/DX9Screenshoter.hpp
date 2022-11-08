#ifndef LDL_Graphics_DX9Screenshoter_hpp
#define LDL_Graphics_DX9Screenshoter_hpp

#include <LDL/Graphics/DX9/DX9Render.hpp>
#include <LDL/Graphics/Base/BaseScreenshoter.hpp>

namespace LDL
{
	namespace Graphics
	{
		class DX9Screenshoter
		{
		public:
			DX9Screenshoter(const std::string& path, const std::string& name, LDL::Graphics::DX9Render* render, LDL::Graphics::CpuImage* image);
			void Shot();
		private:
			LDL::Graphics::BaseScreenshoter _BaseScreenshoter;
			std::string _ShortPath;
			std::string _Name;
			std::string _FullPath;
			LDL::Graphics::DX9Render* _Render;
			LDL::Graphics::CpuImage* _Image;
		};
	}
}

#endif  