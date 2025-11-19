// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Graphics_Camera_hpp
#define Arcanum_Graphics_Camera_hpp

#include <LDL/Vec2u.hpp>
#include <LDL/Rectu.hpp>
#include <LDL/Event.hpp>

namespace Arcanum
{
	class Camera
	{
	public:
		Camera(const LDL_Vec2u& pos, const LDL_Vec2u& size);
		const LDL_Vec2u& Pos();
		const LDL_Vec2u& Size();
		void Move(const LDL_Vec2u& pos);
		void Handle(LDL_Event& event);
	private:
		uint32_t   _step;
		Rectu _area;
	};
}

#endif    
