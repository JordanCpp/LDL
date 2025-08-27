// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <assert.h>
#include <Arcanum/Managers/ScriptManager.hpp>
#include <Arcanum/Scripts/PlayerScript.hpp>

using namespace Arcanum;

ScriptManager::~ScriptManager()
{
	for (size_t i = 0; i < _scripts.size(); i++)
	{
		delete _scripts[i];
	}
}

CritterScript* ScriptManager::GetCritterScript(const std::string& path)
{
	CritterScript* result = NULL;

	if (path == "PlayerScript")
	{
		result = new PlayerScript;
	}

	assert(result != NULL);

	_scripts.push_back(result);

	return result;
}
