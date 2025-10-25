// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdio.h>
#include <stdlib.h>
#include <LDL/LDL.hpp>
#include <LDL/APIs/OpenGL/OpenGL1_2.hpp>

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
	LDL::MemoryManager::Instance().Functions(malloc, NULL, NULL, free);

	LDL::Result result;
	LDL::RenderContext renderContext(LDL::RenderMode::OpenGL1);

	LDL::Window window(result, renderContext, LDL::Vec2u(0, 0), LDL::Vec2u(800, 600), __FILE__);
	LDL::Render render(result, renderContext, &window);

	LDL::Event report;

	LDL::FpsCounter fpsCounter;
	LDL::Convert convert;
	LDL::FpsLimiter fpsLimiter;

	while (window.Running())
	{
		fpsLimiter.Mark();
		fpsCounter.Start();

		while (window.GetEvent(report))
		{
			if (report.Type == LDL::IsQuit)
			{
				window.StopEvent();
			}

			if (report.IsKeyPressed(LDL::KeyboardKey::Escape))
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
