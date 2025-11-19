// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdlib.h>
#include <iostream>
#include <LDL/LDL.hpp>
#include <Arcanum/Game/Engine.hpp>
#include <Arcanum/Loaders/SettingsLoader.hpp>

using namespace Arcanum;

int main(int argc, char* argv[])
{
	try
	{
		LDL_MemoryManager::Instance().Functions(malloc, NULL, NULL, free);

		CommandLineParser parser(argc, argv);
		Settings settings;
		XmlReader xmlReader;
		SettingsLoader settingsLoader(&xmlReader);

		settingsLoader.Reset("Config.xml", settings);

		Engine engine(&parser, &settings);
		engine.Run();
	}
	catch (const RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}
