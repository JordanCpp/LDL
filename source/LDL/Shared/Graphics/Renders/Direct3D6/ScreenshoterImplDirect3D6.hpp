// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

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
		class ScreenShotterImplDirect3D6: public ScreenShotterImpl
		{
		public:
			ScreenShotterImplDirect3D6(const char* path, const char* name, Render* render, Surface* image);
			void Shot();
		private:
			ImageWriter       _imageWriter;
			BaseScreenShotter _baseScreenShotter;
			FileString        _shortPath;
			FileString        _name;
			FileString        _fullPath;
			Render*           _render;
			Surface*          _image;
		};
	}
}

#endif  
