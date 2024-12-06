#ifndef LDL_Graphics_Software_ScreenshoterImpl_hpp
#define LDL_Graphics_Software_ScreenshoterImpl_hpp

#include <LDL/Graphics/Render.hpp>
#include "../../Base/BaseScreenshoter.hpp"
#include <LDL/Graphics/ImageWritter.hpp>
#include "../../Impls/ScreenshoterImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class ScreenshoterImplSoftware : public ScreenshoterImpl
		{
		public:
			ScreenshoterImplSoftware(const std::string& path, const std::string& name, LDL::Graphics::Render* render, LDL::Graphics::Surface* image);
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
