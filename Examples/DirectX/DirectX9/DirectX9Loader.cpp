// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/LDL.hpp>
#include <LDL/APIs/DirectX/DirectXLoader.hpp>

using namespace LDL;
using namespace LDL::DirectX;
using namespace LDL::DirectX9;

int main()
{
	DirectXLoader directXLoader;
	IDirect3D9* direct3D9 = directXLoader.GetDirect3D();

	Result result;
	RenderContext renderContext(RenderMode::OpenGL1);

	Window window(result, renderContext, Vec2u(0, 0), Vec2u(800, 600), "DirectXLoader.cpp");
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
			if (report.Type == Event::IsQuit)
			{
				window.StopEvent();
			}

			if (report.IsKeyPressed(KeyboardKey::Escape))
			{
				window.StopEvent();
			}
		}

		render.Begin();

		render.End();

		fpsLimiter.Throttle();

		if (fpsCounter.Calc())
		{
			window.Title(convert.ToString(fpsCounter.Fps()));
		}
	}

	return 0;
}
