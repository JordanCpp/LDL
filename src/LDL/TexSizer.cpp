// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/TexSizer.hpp>

static const size_t _textureSizes[] = {16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536 };
static const size_t _textureCount   = sizeof(_textureSizes) / sizeof(_textureSizes[0]);

size_t LDL_PotTextureSizer::Calc(const LDL_Vec2u& size)
{
	size_t w = size.x;
	size_t h = size.y;

	for (size_t i = 0; i < _textureCount; i++)
	{
		if (w <= _textureSizes[i] && h <= _textureSizes[i])
		{
			return _textureSizes[i];
		}
	}

	return 0;
}
