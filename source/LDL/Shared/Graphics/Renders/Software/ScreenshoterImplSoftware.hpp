#ifndef LDL_Graphics_Software_ScreenshoterImpl_hpp
#define LDL_Graphics_Software_ScreenshoterImpl_hpp

#include <LDL/Graphics/Render.hpp>
#include <LDL/Graphics/ImageWritter.hpp>
#include "../../Base/BaseScreenshoter.hpp"
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
			LDL::Graphics::ImageWritter     _imageWritter;
			LDL::Graphics::BaseScreenshoter _baseScreenshoter;
			std::string                     _shortPath;
			std::string                     _name;
			std::string                     _fullPath;
			LDL::Graphics::Render*          _render;
			LDL::Graphics::Surface*         _image;
		};
	}
}

#endif  
