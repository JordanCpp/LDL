// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Core/RuntimeError.hpp>

using namespace Arcanum::Core;

RuntimeError::RuntimeError(const std::string& message) :
	_runtime_error(message)
{
}

const char* RuntimeError::what() const
{
	return _runtime_error.what();
}