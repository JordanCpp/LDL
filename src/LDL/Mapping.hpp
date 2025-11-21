// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Shared_Input_KeyMapping_hpp
#define LDL_Shared_Input_KeyMapping_hpp

#include <LDL/PVector.hpp>
#include <LDL/KeyMap.hpp>

class LDL_KeyMapping
{
public:
	enum
	{
		DefaultCount = 256
	};
	LDL_KeyMapping();
	void Add(const LDL_KeyMap& keyMap);
	uint8_t FindKey(size_t key);
private:
	LDL_PodVector<LDL_KeyMap> _table;
};

#endif   
