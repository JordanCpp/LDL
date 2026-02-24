// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Software_CameraImpl_hpp
#define LDL_Graphics_Software_CameraImpl_hpp

#include <LDL/Shared/Graphics/Impls/CameraImpl.hpp>
#include <LDL/Shared/Graphics/Renders/Software/RenderImplSoftware.hpp>

namespace LDL
{
	class CameraImplSoftware : public CameraImpl
	{
	public:
		CameraImplSoftware(RenderImpl* renderImpl, const Vec2u& pos, const Vec2u& size);
		const Vec2u& Pos();
		const Vec2u& Size();
		void Pos(const Vec2u& pos);
		void Size(const Vec2u& size);
	private:
		RenderImpl* _impl;
		Vec2u       _pos;
		Vec2u       _size;
	};
}

#endif    
