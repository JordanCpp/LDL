#ifndef LDL_Graphics_Direct3D6_ScreenshoterImpl_hpp
#define LDL_Graphics_Direct3D6_ScreenshoterImpl_hpp

#include <LDL/Graphics/Render.hpp>
#include "../../Base/BaseScreenshoter.hpp"
#include <LDL/Graphics/ImageWritter.hpp>
#include "../../Impls/ScreenshoterImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class ScreenshoterImplDirect3D6: public ScreenshoterImpl
		{
		public:
			ScreenshoterImplDirect3D6(const std::string& path, const std::string& name, Render* render, Surface* image);
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
