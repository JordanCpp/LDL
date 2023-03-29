//-----------------------------------------------------------------------------
// File: Meshes.cpp
//
// Desc: For advanced geometry, most apps will prefer to load pre-authored
//       meshes from a file. Fortunately, when using meshes, D3DX does most of
//       the work for this, parsing a geometry file and creating vertx buffers
//       (and index buffers) for us. This tutorial shows how to use a D3DXMESH
//       object, including loading it from a file and rendering it. One thing
//       D3DX does not handle for us is the materials and textures for a mesh,
//       so note that we have to handle those manually.
//
//       Note: one advanced (but nice) feature that we don't show here is that
//       when cloning a mesh we can specify the FVF. So, regardless of how the
//       mesh was authored, we can add/remove normals, add more texture
//       coordinate sets (for multi-texturing), etc.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//-----------------------------------------------------------------------------
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Time/Ticks.hpp>
#include <LDL/Contexts/Direct3D9.hpp>
#include <d3dx9.h>
#include <iostream>

using namespace LDL::Graphics;
using namespace LDL::Contexts;
using namespace LDL::Time;




//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------
LPDIRECT3D9         g_pD3D = NULL; // Used to create the D3DDevice
LPDIRECT3DDEVICE9   g_pd3dDevice = NULL; // Our rendering device

LPD3DXMESH          g_pMesh = NULL; // Our mesh object in sysmem
D3DMATERIAL9*       g_pMeshMaterials = NULL; // Materials for our mesh
LPDIRECT3DTEXTURE9* g_pMeshTextures = NULL; // Textures for our mesh
DWORD               g_dwNumMaterials = 0L;   // Number of mesh materials




//-----------------------------------------------------------------------------
// Name: InitD3D()
// Desc: Initializes Direct3D
//-----------------------------------------------------------------------------
HRESULT InitD3D()
{
    // Turn on the zbuffer
    g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);

    // Turn on ambient lighting 
    g_pd3dDevice->SetRenderState(D3DRS_AMBIENT, 0xffffffff);

    return S_OK;
}




//-----------------------------------------------------------------------------
// Name: InitGeometry()
// Desc: Load the mesh and build the material and texture arrays
//-----------------------------------------------------------------------------
HRESULT InitGeometry()
{
    LPD3DXBUFFER pD3DXMtrlBuffer;

    // Load the mesh from the specified file
    if (FAILED(D3DXLoadMeshFromX("Tiger.x", D3DXMESH_SYSTEMMEM, g_pd3dDevice, NULL, &pD3DXMtrlBuffer, NULL, &g_dwNumMaterials, &g_pMesh)))
    {
        // If model is not in current folder, try parent folder
        if (FAILED(D3DXLoadMeshFromX("..\\Tiger.x", D3DXMESH_SYSTEMMEM, g_pd3dDevice, NULL, &pD3DXMtrlBuffer, NULL, &g_dwNumMaterials, &g_pMesh)))
        {
            MessageBox(NULL, "Could not find tiger.x", "Meshes.exe", MB_OK);
            return E_FAIL;
        }
    }

    // We need to extract the material properties and texture names from the 
    // pD3DXMtrlBuffer
    D3DXMATERIAL* d3dxMaterials = (D3DXMATERIAL*)pD3DXMtrlBuffer->GetBufferPointer();
    g_pMeshMaterials = new D3DMATERIAL9[g_dwNumMaterials];
    g_pMeshTextures = new LPDIRECT3DTEXTURE9[g_dwNumMaterials];

    for (size_t i = 0; i < g_dwNumMaterials; i++)
    {
        // Copy the material
        g_pMeshMaterials[i] = d3dxMaterials[i].MatD3D;

        // Set the ambient color for the material (D3DX does not do this)
        g_pMeshMaterials[i].Ambient = g_pMeshMaterials[i].Diffuse;

        g_pMeshTextures[i] = NULL;
        if (d3dxMaterials[i].pTextureFilename != NULL &&
            lstrlen(d3dxMaterials[i].pTextureFilename) > 0)
        {
            // Create the texture
            if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, d3dxMaterials[i].pTextureFilename, &g_pMeshTextures[i])))
            {
                // If texture is not in current folder, try parent folder
                const std::string strPrefix = "..\\";
                std::string strTexture = strPrefix + d3dxMaterials[i].pTextureFilename;

                // If texture is not in current folder, try parent folder
                if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, strTexture.c_str(), &g_pMeshTextures[i])))
                {
                    MessageBox(NULL, "Could not find texture map", "Meshes.exe", MB_OK);
                }
            }
        }
    }

    // Done with the material buffer
    pD3DXMtrlBuffer->Release();

    return S_OK;
}




//-----------------------------------------------------------------------------
// Name: Cleanup()
// Desc: Releases all previously initialized objects
//-----------------------------------------------------------------------------
void Cleanup()
{
    if (g_pMeshMaterials != NULL)
        delete[] g_pMeshMaterials;

    if (g_pMeshTextures)
    {
        for (size_t i = 0; i < g_dwNumMaterials; i++)
        {
            if (g_pMeshTextures[i])
                g_pMeshTextures[i]->Release();
        }

        delete[] g_pMeshTextures;
    }

    if (g_pMesh != NULL)
        g_pMesh->Release();
}



//-----------------------------------------------------------------------------
// Name: SetupMatrices()
// Desc: Sets up the world, view, and projection transform matrices.
//-----------------------------------------------------------------------------
void SetupMatrices()
{
    // For our world matrix, we will just leave it as the identity
    D3DXMATRIXA16 matWorld;
    D3DXMatrixRotationY(&matWorld, Ticks() / 1000.0f);
    g_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);

    // Set up our view matrix. A view matrix can be defined given an eye point,
    // a point to lookat, and a direction for which way is up. Here, we set the
    // eye five units back along the z-axis and up three units, look at the 
    // origin, and define "up" to be in the y-direction.
    D3DXVECTOR3 vEyePt(0.0f, 3.0f, -5.0f);
    D3DXVECTOR3 vLookatPt(0.0f, 0.0f, 0.0f);
    D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);
    D3DXMATRIXA16 matView;
    D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);
    g_pd3dDevice->SetTransform(D3DTS_VIEW, &matView);

    // For the projection matrix, we set up a perspective transform (which
    // transforms geometry from 3D view space to 2D viewport space, with
    // a perspective divide making objects smaller in the distance). To build
    // a perpsective transform, we need the field of view (1/4 pi is common),
    // the aspect ratio, and the near and far clipping planes (which define at
    // what distances geometry should be no longer be rendered).
    D3DXMATRIXA16 matProj;
    D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
    g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &matProj);
}




//-----------------------------------------------------------------------------
// Name: Render()
// Desc: Draws the scene
//-----------------------------------------------------------------------------
void Rendering()
{
    // Clear the backbuffer and the zbuffer
    g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
        D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

    // Begin the scene
    if (SUCCEEDED(g_pd3dDevice->BeginScene()))
    {
        // Setup the world, view, and projection matrices
        SetupMatrices();

        // Meshes are divided into subsets, one for each material. Render them in
        // a loop
        for (DWORD i = 0; i < g_dwNumMaterials; i++)
        {
            // Set the material and texture for this subset
            g_pd3dDevice->SetMaterial(&g_pMeshMaterials[i]);
            g_pd3dDevice->SetTexture(0, g_pMeshTextures[i]);

            // Draw the mesh subset
            g_pMesh->DrawSubset(i);
        }

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
            // Create the geometry
            if (SUCCEEDED(InitGeometry()))
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
        }

        Cleanup();
    }
    catch (const LDL::Core::RuntimeError& error)
    {
        std::cout << error.what() << '\n';
    }

    return 0;
}