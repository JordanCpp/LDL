/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#ifndef Fallout_Camera_hpp
#define Fallout_Camera_hpp

#include <vector>
#include <LDL/C++98/LDL.hpp>

namespace Fallout
{
	class Camera
	{
	public:
		void Up();
		void Down();
		void Left();
		void Right();
		const LDL::Vec2i& GetPos();
	private:
		LDL::Vec2i _pos;
	};
}

#endif
