#ifndef LDL_Graphics_GpuScreenshoterImpl_hpp
#define LDL_Graphics_GpuScreenshoterImpl_hpp

#include <LDL/Graphics/Gpu/GpuRender.hpp>
#include <LDL/Graphics/Base/BaseScreenshoter.hpp>
#include <LDL/Graphics/ImageWritter.hpp>

namespace LDL
{
	namespace Graphics
	{
		class GpuScreenshoterImpl
		{
		public:
			GpuScreenshoterImpl(const std::string& path, const std::string& name, LDL::Graphics::GpuRender* render, LDL::Graphics::CpuImage* image);
			void Shot();
		private:
			LDL::Graphics::ImageWritter _ImageWritter;
			LDL::Graphics::BaseScreenshoter _BaseScreenshoter;
			std::string _ShortPath;
			std::string _Name;
			std::string _FullPath;
			LDL::Graphics::GpuRender* _Render;
			LDL::Graphics::CpuImage* _Image;
		};
	}
}

#endif  