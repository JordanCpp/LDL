#include <iostream>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Contexts/Direct3D9.hpp>
#include <d3dx9math.h>
#include <d3dx9.h>

using namespace LDL::Graphics;
using namespace LDL::Contexts;

#define CUSTOMFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

struct D3DVERTEX
{
	FLOAT x, y, z, rhw;
	DWORD color;
};

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

		D3DVERTEX vertices[3];

		vertices[0].x = 50;
		vertices[0].y = 50;
		vertices[0].z = 0;
		vertices[0].rhw = 1.0f;
		vertices[0].color = 0x00ff00;

		vertices[1].x = 250;
		vertices[1].y = 50;
		vertices[1].z = 0;
		vertices[1].rhw = 1.0f;
		vertices[1].color = 0x0000ff;

		vertices[2].x = 50;
		vertices[2].y = 250;
		vertices[2].z = 0;
		vertices[2].rhw = 1.0f;
		vertices[2].color = 0xff0000;

		IDirect3DVertexBuffer9* vertexBuffer = NULL;

		direct3D9->Device->CreateVertexBuffer(3 * sizeof(D3DVERTEX), 0, CUSTOMFVF, D3DPOOL_MANAGED, &vertexBuffer, NULL);

		VOID* pVoid = NULL; 

		vertexBuffer->Lock(0, 0, (void**)&pVoid, 0);
		memcpy(pVoid, vertices, sizeof(vertices));
		vertexBuffer->Unlock();

		while (window.GetEvent(report))
		{
			direct3D9->Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

			direct3D9->Device->BeginScene();

			direct3D9->Device->SetStreamSource(0, vertexBuffer, 0, sizeof(D3DVERTEX));
			direct3D9->Device->SetFVF(CUSTOMFVF);
			direct3D9->Device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);

			direct3D9->Device->EndScene();

			direct3D9->Device->Present(NULL, NULL, NULL, NULL);

			if (report.Type == LDL::Events::IsQuit)
			{
				window.StopEvent();
			}
		}

		vertexBuffer->Release();
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}