// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdlib.h>
#include <LDL/LDL.hpp>
#include <LDL/OpenGL/GL1_2.hpp>

float theta = 0.0f;

void Identity()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void LDL_Display()
{
	Identity();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glRotatef(theta, 0.0f, 0.0f, 1.0f);

	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f, 1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f, -0.5f);
	glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);

	glEnd();

	glPopMatrix();

	theta += 1.0f;
}

int main()
{
	LDL_MemoryManager::Instance().Functions(malloc, NULL, NULL, free);

	LDL_Result result;
	LDL_RenderContext renderContext(LDL_RenderMode::OpenGL1);

	LDL_IWindow* window = LDL_CreateWindow(result, renderContext, LDL_Vec2u(0, 0), LDL_Vec2u(800, 600), __FILE__, 0);
	LDL_IRender* render = LDL_CreateRender(result, renderContext, window);

	LDL_Event      report;
	LDL_FpsCounter fpsCounter;
	LDL_Convert    convert;
	LDL_FpsLimiter fpsLimiter;

	while (window->Running())
	{
		fpsLimiter.Mark();
		fpsCounter.Start();

		while (window->GetEvent(report))
		{
			if (report.Type == IsQuit)
			{
				window->StopEvent();
			}

			if (report.IsKeyPressed(LDL_KeyboardKey::Escape))
			{
				window->StopEvent();
			}
		}

		render->Begin();

		LDL_Display();

		render->End();

		fpsLimiter.Throttle();

		if (fpsCounter.Calc())
		{
			window->Title(convert.ToString(fpsCounter.Fps()));
		}
	}

	return 0;
}
