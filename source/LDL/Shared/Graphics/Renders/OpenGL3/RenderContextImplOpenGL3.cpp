// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "RenderContextImplOpenGL3.hpp"

using namespace LDL::Graphics;

RenderContextImplOpenGL3::RenderContextImplOpenGL3(size_t mode) :
	_mode(mode)
{
}

size_t RenderContextImplOpenGL3::Mode()
{
	return _mode;
}
