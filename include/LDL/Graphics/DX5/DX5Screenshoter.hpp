#ifndef LDL_Graphics_DX5Screenshoter_hpp
#define LDL_Graphics_DX5Screenshoter_hpp

#include <LDL/Graphics/DX5/DX5Render.hpp>
#include <LDL/Graphics/Base/BaseScreenshoter.hpp>

namespace LDL
{
	namespace Graphics
	{
		class DX5Screenshoter
		{
		public:
			DX5Screenshoter(const std::string& path, const std::string& name, LDL::Graphics::DX5Render* render, LDL::Graphics::CpuImage* image);
			void Shot();
		private:
			LDL::Graphics::BaseScreenshoter _BaseScreenshoter;
			std::string _ShortPath;
			std::string _Name;
			std::string _FullPath;
			LDL::Graphics::DX5Render* _Render;
			LDL::Graphics::CpuImage* _Image;
		};
	}
}

#endif  