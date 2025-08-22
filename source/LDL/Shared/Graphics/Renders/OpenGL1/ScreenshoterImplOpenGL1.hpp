#ifndef LDL_Graphics_OpenGL1_ScreenShotterImpl_hpp
#define LDL_Graphics_OpenGL1_ScreenShotterImpl_hpp

#include <LDL/Graphics/Render.hpp>
#include "../../Base/BaseScreenshoter.hpp"
#include <LDL/Graphics/ImageWritter.hpp>
#include "../../Impls/ScreenshoterImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class ScreenShotterImplOpenGL1: public ScreenShotterImpl
		{
		public:
			ScreenShotterImplOpenGL1(const std::string& path, const std::string& name, Render* render, Surface* image);
			void Shot();
		private:
			ImageWriter      _imageWriter;
			BaseScreenShotter _baseScreenShotter;
			std::string      _ShortPath;
			std::string      _Name;
			std::string      _FullPath;
			Render*          _Render;
			Surface*         _Image;
		};
	}
}

#endif  
