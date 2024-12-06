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
			ImageWritter _ImageWritter;
			BaseScreenshoter _BaseScreenshoter;
			std::string _ShortPath;
			std::string _Name;
			std::string _FullPath;
			Render* _Render;
			Surface* _Image;
		};
	}
}

#endif  
