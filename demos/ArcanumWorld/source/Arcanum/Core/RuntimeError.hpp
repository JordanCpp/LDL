// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Core_RuntimeError_hpp
#define Arcanum_Core_RuntimeError_hpp

#include <stdexcept>

namespace Arcanum
{
	class RuntimeError
	{
	public:
		RuntimeError(const std::string& message);
		const char* what() const;
	private:
		std::runtime_error _runtime_error;
	};
}

#endif
