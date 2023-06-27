#ifndef LDL_Graphics_Direct3D9_ScreenshoterImplDirect3D9_hpp
#define LDL_Graphics_Direct3D9_ScreenshoterImplDirect3D9_hpp

#include <LDL/Graphics/Render.hpp>
#include <LDL/Graphics/Base/BaseScreenshoter.hpp>
#include <LDL/Graphics/ImageWritter.hpp>
#include "../ScreenshoterImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class ScreenshoterImplDirect3D9 : public ScreenshoterImpl
		{
		public:
			ScreenshoterImplDirect3D9(const std::string& path, const std::string& name, Render* render, Surface* image);
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