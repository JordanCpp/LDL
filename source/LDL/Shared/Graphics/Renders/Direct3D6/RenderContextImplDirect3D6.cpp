// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "RenderContextImplDirect3D6.hpp"

using namespace LDL::Graphics;

RenderContextImplDirect3D6::RenderContextImplDirect3D6(size_t mode) :
	_mode(mode)
{
}

size_t RenderContextImplDirect3D6::Mode()
{
	return _mode;
}

