#include <iostream>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Contexts/Direct3D9.hpp>
#include <d3dx9math.h>

using namespace LDL::Graphics;
using namespace LDL::Contexts;

int main()
{
	try
	{
		Window window(Point2u(0, 0), Point2u(800, 600), "01_GetContext");

		RenderContext renderContext;

		Direct3D9* direct3D9 = (Direct3D9*)renderContext.Context();

		Render render(&renderContext, &window);

		LDL::Events::Event report;

		D3DXMATRIX projection;
		D3DXMatrixIdentity(&projection);
		direct3D9->Device->SetTransform(D3DTS_PROJECTION, &projection);

		while (window.GetEvent(report))
		{
			direct3D9->Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

			direct3D9->Device->BeginScene();

			direct3D9->Device->EndScene();

			direct3D9->Device->Present(NULL, NULL, NULL, NULL);

			if (report.Type == LDL::Events::IsQuit)
			{
				window.StopEvent();
			}
		}
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}