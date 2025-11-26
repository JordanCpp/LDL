// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Managers_ScriptManager_hpp
#define Arcanum_Managers_ScriptManager_hpp

#include <string>
#include <vector>
#include <Arcanum/Objects/CritterScript.hpp>

namespace Arcanum
{
	class ScriptManager
	{
	public:
		~ScriptManager();
		CritterScript* GetCritterScript(const std::string& path);
	private:
		std::vector<Script*> _scripts;
	};
}

#endif    
