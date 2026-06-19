/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#include "Engine.hpp"
#include <iostream>

using namespace LDL;
using namespace Fallout;

int main()
{
	Config config;
	config.Size  = Vec2i(800, 600);
	config.Title = "Fallout Demo";
	config.Mode  = Window::Fixed;

	Engine engine(config);
	engine.Run();

	if (engine.GetResult().IsFail())
	{
		std::cout << "Fallout error: " << engine.GetResult().Message() << std::endl;
	}

	return 0;
}
