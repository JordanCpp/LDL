// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_FpsLimit_hpp
#define LDL_FpsLimit_hpp

#include <LDL/Config.hpp>
#include <LDL/Types.hpp>

class LDL_LIBRARY LDL_FpsLimiter
{
public:
	LDL_FpsLimiter(size_t fps = 60);
	void Mark();
	void Throttle() const;
private:
	size_t _fps;
	size_t _startTime;
};

#endif    
