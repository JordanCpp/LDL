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
			std::vector<Objects::Script*> _Scripts;
		};
	}
}

#endif    