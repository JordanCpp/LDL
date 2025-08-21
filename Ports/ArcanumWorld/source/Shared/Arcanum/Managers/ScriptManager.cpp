#include <Arcanum/Managers/ScriptManager.hpp>
#include <cassert>
#include <Arcanum/Scripts/PlayerScript.hpp>

using namespace Arcanum::Managers;
using namespace Arcanum::Objects;
using namespace Arcanum::Scripts;

ScriptManager::~ScriptManager()
{
	for (size_t i = 0; i < _scripts.size(); i++)
		delete _scripts[i];
}

CritterScript* ScriptManager::GetCritterScript(const std::string& path)
{
	CritterScript* result = nullptr;

	if (path == "PlayerScript")
		result = new PlayerScript;

	assert(result != nullptr);

	_scripts.push_back(result);

	return result;
}