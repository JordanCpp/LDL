#include <iostream>
#include <Arcanum/Game/Engine.hpp>
#include <Arcanum/Loaders/SettingsLoader.hpp>
#include <LDL/Core/CommandLineParser.hpp>

using namespace LDL::Math;
using namespace LDL::Core;
using namespace Arcanum::Core;
using namespace Arcanum::Game;
using namespace Arcanum::Loaders;
using namespace Arcanum::Readers;

int main(int argc, char* argv[])
{
	try
	{
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