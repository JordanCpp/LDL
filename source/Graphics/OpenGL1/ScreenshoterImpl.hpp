#ifndef LDL_Graphics_GL1_ScreenshoterImpl_hpp
#define LDL_Graphics_GL1_ScreenshoterImpl_hpp

#include <LDL/Graphics/Render.hpp>
#include <LDL/Graphics/Base/BaseScreenshoter.hpp>
#include <LDL/Graphics/ImageWritter.hpp>

namespace LDL
{
	namespace Graphics
	{
		class ScreenshoterImpl
		{
		public:
			ScreenshoterImpl(const std::string& path, const std::string& name, LDL::Graphics::Render* render, LDL::Graphics::Surface* image);
			void Shot();
		private:
			LDL::Graphics::ImageWritter _ImageWritter;
			LDL::Graphics::BaseScreenshoter _BaseScreenshoter;
			std::string _ShortPath;
			std::string _Name;
			std::string _FullPath;
			LDL::Graphics::Render* _Render;
			LDL::Graphics::Surface* _Image;
		};
	}
}

#endif  