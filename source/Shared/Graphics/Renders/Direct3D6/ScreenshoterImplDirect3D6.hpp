#ifndef LDL_Graphics_Direct3D6_ScreenshoterImpl_hpp
#define LDL_Graphics_Direct3D6_ScreenshoterImpl_hpp

#include <LDL/Graphics/Render.hpp>
#include <LDL/Graphics/Base/BaseScreenshoter.hpp>
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
