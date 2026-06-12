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

#ifndef Fallout_Sprite_hpp
#define Fallout_Sprite_hpp

#include <vector>
#include <LDL/C++98/LDL.hpp>

namespace Fallout
{
	class Sprite
	{
	public:
		enum
		{
			DirMax = 6
		};
		Sprite();
		void Append(size_t dir, LDL::Texture* texture);
		LDL::Texture* Single();
	private:
		std::vector<std::vector<LDL::Texture*>>_dirs;
	};
}

#endif
