// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Graphics_Camera_hpp
#define Arcanum_Graphics_Camera_hpp

#include <LDL/Math/Vec2u.hpp>
#include <LDL/Math/Rectu.hpp>
#include <LDL/Events/Event.hpp>

namespace Arcanum
{
	class Camera
	{
	public:
		Camera(const LDL::Vec2u& pos, const LDL::Vec2u& size);
		const LDL::Vec2u& Pos();
		const LDL::Vec2u& Size();
		void Move(const LDL::Vec2u& pos);
		void Handle(LDL::Event& event);
	private:
		uint32_t   _step;
		LDL::Rectu _area;
	};
}

#endif    
