// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

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