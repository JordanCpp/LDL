// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Software_CameraImpl_hpp
#define LDL_Graphics_Software_CameraImpl_hpp

#include <LDL/Math/Vec2.hpp>
#include <LDL/Shared/Graphics/Impls/CameraImpl.hpp>
#include <LDL/Shared/Graphics/Renders/Software/RenderImplSoftware.hpp>

namespace LDL
{
	namespace Graphics
	{
		class CameraImplSoftware : public CameraImpl
		{
		public:
			CameraImplSoftware(RenderImpl* renderImpl, const Math::Vec2u& pos, const Math::Vec2u& size);
			const Math::Vec2u& Pos();
			const Math::Vec2u& Size();
			void Pos(const Math::Vec2u& pos);
			void Size(const Math::Vec2u& size);
		private:
			RenderImpl* _impl;
			Math::Vec2u _pos;
			Math::Vec2u _size;
		};
	}
}

#endif    
