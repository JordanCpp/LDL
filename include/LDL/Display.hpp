// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Display_hpp
#define LDL_Display_hpp

#include <LDL/Video.hpp>
#include <LDL/PVector.hpp>

class LDL_LIBRARY LDL_Display
{
public:
	LDL_Display();
	const LDL_PodVector<LDL_VideoMode>& Modes();
	const LDL_VideoMode& Current();
private:
	LDL_VideoMode                _videoMode;
	LDL_PodVector<LDL_VideoMode> _videoModes;
};

#endif     
