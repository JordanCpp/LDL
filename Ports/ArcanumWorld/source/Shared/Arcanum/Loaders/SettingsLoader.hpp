#ifndef Arcanum_Loaders_SettingsLoader_hpp
#define Arcanum_Loaders_SettingsLoader_hpp

#include <Arcanum/Readers/XmlReader.hpp>
#include <Arcanum/Game/Settings.hpp>

namespace Arcanum
{
	namespace Loaders
	{
		class SettingsLoader
		{
		public:
			SettingsLoader(Readers::XmlReader* xmlReader);
			bool Reset(const std::string& path, Game::Settings& settings);
		private:
			Readers::XmlReader* _xmlReader;
		};
	}
}

#endif    