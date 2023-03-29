//-----------------------------------------------------------------------------
// File: CreateDevice.cpp
//
// Desc: This is the first tutorial for using Direct3D. In this tutorial, all
//       we are doing is creating a Direct3D device and using it to clear the
//       window.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//-----------------------------------------------------------------------------
#include <iostream>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Contexts/Direct3D9.hpp>
#include <d3dx9math.h>

using namespace LDL::Graphics;
using namespace LDL::Contexts;




//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------
LPDIRECT3D9             g_pD3D = NULL; // Used to create the D3DDevice
LPDIRECT3DDEVICE9       g_pd3dDevice = NULL; // Our rendering device




//-----------------------------------------------------------------------------
// Name: InitD3D()
// Desc: Initializes Direct3D
//-----------------------------------------------------------------------------
HRESULT InitD3D()
{
    return S_OK;
}




//-----------------------------------------------------------------------------
// Name: Cleanup()
// Desc: Releases all previously initialized objects
//-----------------------------------------------------------------------------
void Cleanup()
{
}




//-----------------------------------------------------------------------------
// Name: Render()
// Desc: Draws the scene
//-----------------------------------------------------------------------------
void Rendering()
{
    if (NULL == g_pd3dDevice)
        return;

    // Clear the backbuffer to a blue color
    g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

    // Begin the scene
    if (SUCCEEDED(g_pd3dDevice->BeginScene()))
    {
        // Rendering of scene objects can happen here

        // End the scene
        g_pd3dDevice->EndScene();
    }

    // Present the backbuffer contents to the display
    g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}




//-----------------------------------------------------------------------------
// Name: WinMain()
// Desc: The application's entry point
//-----------------------------------------------------------------------------
int main()
{
    try
    {
        Window window(Point2u(0, 0), Point2u(800, 600), "D3D Tutorial");

        RenderContext renderContext;
        Render render(&renderContext, &window);

        Direct3D9* direct3D9 = (Direct3D9*)renderContext.Context();
        g_pD3D = direct3D9->Direct;
        g_pd3dDevice = direct3D9->Device;

        LDL::Events::Event report;

        // Initialize Direct3D
        if (SUCCEEDED(InitD3D()))
        {
            while (window.GetEvent(report))
            {
                Rendering();

                if (report.Type == LDL::Events::IsQuit)
                {
                    window.StopEvent();
                }
            }
        }

        Cleanup();
    }
    catch (const LDL::Core::RuntimeError& error)
    {
        std::cout << error.what() << '\n';
    }

    return 0;
}