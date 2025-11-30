// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdlib.h>
#include <LDL/LDL.hpp>
#include <LDL/OpenGL/GL3_3.hpp>
#include <LDL/OpenGL/GLLoader.hpp>

const LDL_Vec2u WindowSize = LDL_Vec2u(800, 600);

int main()
{
	LDL_MemoryManager::Instance().Functions(malloc, NULL, NULL, free);

	LDL_Result        result;
	LDL_RenderContext context(LDL_RenderMode::OpenGL3);
	LDL_IWindow*      window = LDL_CreateWindow(result, context, LDL_Vec2u(0, 0), WindowSize, __FILE__, LDL_WindowMode::Resized);

	LDL_OpenGLLoader loader(result);
	loader.Init(3, 3);

	LDL_Event report;

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

			if (report.Type == IsResize)
			{
				glViewport(0, 0, (GLsizei)report.Resize.Width, (GLsizei)report.Resize.Height);
			}

			if (report.IsKeyPressed(LDL_KeyboardKey::Escape))
			{
				window->StopEvent();
			}
		}

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		window->Present();

		fpsLimiter.Throttle();

		if (fpsCounter.Calc())
		{
			window->Title(convert.ToString(fpsCounter.Fps()));		
		}
	}

	return 0;
}
