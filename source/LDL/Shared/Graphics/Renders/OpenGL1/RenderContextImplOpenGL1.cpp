// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "RenderContextImplOpenGL1.hpp"

using namespace LDL;

RenderContextImplOpenGL1::RenderContextImplOpenGL1(size_t mode) :
	_mode(mode)
{
}

size_t RenderContextImplOpenGL1::Mode()
{
	return _mode;
}

