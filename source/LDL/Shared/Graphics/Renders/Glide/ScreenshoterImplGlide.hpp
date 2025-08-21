#ifndef LDL_Graphics_Renders_Glide_ScreenshoterImplGlide_hpp
#define LDL_Graphics_Renders_Glide_ScreenshoterImplGlide_hpp

#include <LDL/Graphics/Render.hpp>
#include "../../Base/BaseScreenshoter.hpp"
#include <LDL/Graphics/ImageWritter.hpp>
#include "../../Impls/ScreenshoterImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class ScreenshoterImplGlide : public ScreenshoterImpl
		{
		public:
			ScreenshoterImplGlide(const std::string& path, const std::string& name, Render* render, Surface* image);
			void Shot();
		private:
			ImageWritter     _imageWritter;
			BaseScreenshoter _baseScreenshoter;
			std::string      _shortPath;
			std::string      _name;
			std::string      _fullPath;
			Render*          _render;
			Surface*         _image;
		};
	}
}

#endif  
