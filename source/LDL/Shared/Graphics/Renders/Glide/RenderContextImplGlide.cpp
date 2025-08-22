// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "RenderContextImplGlide.hpp"

using namespace LDL::Graphics;

RenderContextImplGlide::RenderContextImplGlide(size_t mode) :
	_mode(mode)
{
}

size_t RenderContextImplGlide::Mode()
{
	return _mode;
}

