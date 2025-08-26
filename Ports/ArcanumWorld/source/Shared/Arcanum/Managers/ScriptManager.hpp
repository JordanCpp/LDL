// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Managers_ScriptManager_hpp
#define Arcanum_Managers_ScriptManager_hpp

#include <Arcanum/Objects/CritterScript.hpp>
#include <string>
#include <vector>

namespace Arcanum
{
	namespace Managers
	{
		class ScriptManager
		{
		public:
			~ScriptManager();
			Objects::CritterScript* GetCritterScript(const std::string& path);
		private:
			std::vector<Objects::Script*> _scripts;
		};
	}
}

#endif    