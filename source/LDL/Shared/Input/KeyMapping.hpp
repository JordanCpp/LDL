// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Shared_Input_KeyMapping_hpp
#define LDL_Shared_Input_KeyMapping_hpp

#include <LDL/Core/Vector.hpp>
#include <LDL/Shared/Input/KeyMap.hpp>

namespace LDL
{
	class KeyMapping
	{
	public:
		enum
		{
			DefaultCount = 256
		};
		KeyMapping();
		void Add(const KeyMap& keyMap);
		uint8_t FindKey(size_t key);
	private:
		Vector<KeyMap> _table;
	};
}

#endif   
