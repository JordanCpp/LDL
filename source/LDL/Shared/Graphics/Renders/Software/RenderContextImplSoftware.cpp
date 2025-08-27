// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Shared/Graphics/Renders/Software/RenderContextImplSoftware.hpp>

using namespace LDL;

RenderContextImplSoftware::RenderContextImplSoftware(size_t mode) :
	_mode(mode)
{
}

size_t RenderContextImplSoftware::Mode()
{
	return _mode;
}
