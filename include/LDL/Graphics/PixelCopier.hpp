// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_PixelCopier_hpp
#define LDL_Graphics_PixelCopier_hpp

#include <LDL/Graphics/Surface.hpp>

namespace LDL
{
	class PixelCopier
	{
	public:
		void Copy(Surface* srcSurf, Surface* dstSurf, const Vec2u& pos);
		void Copy8(Surface* srcSurf, Surface* dstSurf, const Vec2u& pos);
		void Copy16(Surface* srcSurf, Surface* dstSurf, const Vec2u& pos);
		void Copy24(Surface* srcSurf, Surface* dstSurf, const Vec2u& pos);
		void Copy32(Surface* srcSurf, Surface* dstSurf, const Vec2u& pos);
	private:
	};
}

#endif 
