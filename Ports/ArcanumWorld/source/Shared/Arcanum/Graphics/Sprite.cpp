// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Graphics/Sprite.hpp>

using namespace Arcanum::Graphics;

Sprite::~Sprite()
{
	for (size_t i = 0; i < _images.size(); i++)
	{
		delete _images[i];
	}
}

void Sprite::Append(Image* image)
{
	_images.push_back(image);
}

Image* Sprite::GetImage(size_t index)
{
	return _images[index];
}

Image* Sprite::Single()
{
	return GetImage(0);
}