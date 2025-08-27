// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Objects_Script_hpp
#define Arcanum_Objects_Script_hpp

namespace Arcanum
{
	class Script
	{
	public:
		virtual ~Script(){}
		virtual void MapEnter()  = 0;
		virtual void MapUpdate() = 0;
		virtual void MapExit()   = 0;
	private:
	};
}

#endif
