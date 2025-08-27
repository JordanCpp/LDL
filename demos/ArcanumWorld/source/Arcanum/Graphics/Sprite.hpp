// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Graphics_Sprite_hpp
#define Arcanum_Graphics_Sprite_hpp

#include <vector>
#include <Arcanum/Graphics/Image.hpp>

namespace Arcanum
{
	class Sprite
	{
	public:
		~Sprite();
		void Append(Image* image);
		Image* GetImage(size_t index);
		Image* Single();
	private:
		std::vector<Image*> _images;
	};
}

#endif    
