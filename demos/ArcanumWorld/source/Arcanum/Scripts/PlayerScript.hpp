// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Scripts_PlayerScript_hpp
#define Arcanum_Scripts_PlayerScript_hpp

#include <Arcanum/Objects/CritterScript.hpp>

namespace Arcanum
{
	class PlayerScript : public CritterScript
	{
	public:
		void MapEnter();
		void MapUpdate();
		void MapExit();
	private:
	};
}

#endif
