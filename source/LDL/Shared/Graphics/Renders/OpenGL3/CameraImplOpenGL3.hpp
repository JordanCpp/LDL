// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_OpenGL3_CameraImpl_hpp
#define LDL_Graphics_OpenGL3_CameraImpl_hpp

#include "RenderImplOpenGL3.hpp"
#include "../../Impls/CameraImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class CameraImplOpenGL3 : public CameraImpl
		{
		public:
			CameraImplOpenGL3(RenderImpl* renderImpl, const Vec2u& pos, const Vec2u& size);
			const Vec2u& Pos();
			const Vec2u& Size();
			void Pos(const Vec2u& pos);
			void Size(const Vec2u& size);
		private:
			RenderImpl* _renderImpl;
			Vec2u _pos;
			Vec2u _size;
		};
	}
}

#endif   
