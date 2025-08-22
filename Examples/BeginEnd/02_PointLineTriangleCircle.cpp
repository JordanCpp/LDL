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
using namespace LDL::Loaders;
using namespace LDL::Math;

float theta = 0.0f;

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

	glClearColor(0.7f, 1.0f, 0.7f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(10);
	glBegin(GL_POINTS);
	glColor3f(0, 0, 0);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();

	glLineWidth(5);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();

	theta += 1.0f;
}

int main()
{
	RenderContext renderContext(RenderMode::OpenGL1);

	Window window(renderContext, Vec2u(0, 0), Vec2u(800, 600), "Window!");
	Render render(renderContext, &window);

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
			fpsCounter.Clear();
		}

		window.PollEvents();
	}

	return 0;
}
