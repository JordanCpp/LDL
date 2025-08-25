// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/LDL.hpp>
#include <LDL/APIs/OpenGL/OpenGL1_2.hpp>

using namespace LDL::Graphics;
using namespace LDL::Enums;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Core;
using namespace LDL::Allocators;
using namespace LDL::Math;

void Identity()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Display()
{
	Identity();

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0); glVertex3f(-0.6f, -0.75f, 0.5f);
	glColor3f(0, 1, 0); glVertex3f(0.6f, -0.75f, 0.0f);
	glColor3f(0, 0, 1); glVertex3f(0.0f, 0.75f, 0.0f);
	glEnd();
}

int main()
{
	MemoryManager::Instance().Functions(malloc, NULL, NULL, free);

	Result result;
	RenderContext renderContext(RenderMode::OpenGL1);

	Window window(result, renderContext, Vec2u(0, 0), Vec2u(800, 600), "Window!");
	Render render(result, renderContext, &window);

	Event report;

	FpsCounter fpsCounter;
	Convert convert;
	FpsLimiter fpsLimiter;

	while (window.Running())
	{
		fpsLimiter.Mark();
		fpsCounter.Start();

		while (window.GetEvent(report))
		{
			if (report.Type == IsQuit)
			{
				window.StopEvent();
			}

			if (report.IsKeyPressed(KeyboardKey::Escape))
				window.StopEvent();
		}

		render.Begin();

		Display();

		render.End();

		fpsLimiter.Throttle();

		if (fpsCounter.Calc())
		{
			window.Title(convert.ToString(fpsCounter.Fps()));
			
		}

		
	}

	return 0;
}
