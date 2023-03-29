//-----------------------------------------------------------------------------
// File: Textures.cpp
//
// Desc: Better than just lights and materials, 3D objects look much more
//       convincing when texture-mapped. Textures can be thought of as a sort
//       of wallpaper, that is shrinkwrapped to fit a texture. Textures are
//       typically loaded from image files, and D3DX provides a utility to
//       function to do this for us. Like a vertex buffer, textures have
//       Lock() and Unlock() functions to access (read or write) the image
//       data. Textures have a width, height, miplevel, and pixel format. The
//       miplevel is for "mipmapped" textures, an advanced performance-
//       enhancing feature which uses lower resolutions of the texture for
//       objects in the distance where detail is less noticeable. The pixel
//       format determines how the colors are stored in a texel. The most
//       common formats are the 16-bit R5G6B5 format (5 bits of red, 6-bits of
//       green and 5 bits of blue) and the 32-bit A8R8G8B8 format (8 bits each
//       of alpha, red, green, and blue).
//
//       Textures are associated with geometry through texture coordinates.
//       Each vertex has one or more sets of texture coordinates, which are
//       named tu and tv and range from 0.0 to 1.0. Texture coordinates can be
//       supplied by the geometry, or can be automatically generated using
//       Direct3D texture coordinate generation (which is an advanced feature).
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
LPDIRECT3D9             g_pD3D       = NULL; // Used to create the D3DDevice
LPDIRECT3DDEVICE9       g_pd3dDevice = NULL; // Our rendering device
LPDIRECT3DVERTEXBUFFER9 g_pVB        = NULL; // Buffer to hold vertices
LPDIRECT3DTEXTURE9      g_pTexture   = NULL; // Our texture

// A structure for our custom vertex type. We added texture coordinates
struct CUSTOMVERTEX
{
    D3DXVECTOR3 position; // The position
    D3DCOLOR    color;    // The color
#ifndef SHOW_HOW_TO_USE_TCI
    FLOAT       tu, tv;   // The texture coordinates
#endif
};

// Our custom FVF, which describes our custom vertex structure
#ifdef SHOW_HOW_TO_USE_TCI
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE)
#else
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE|D3DFVF_TEX1)
#endif



//-----------------------------------------------------------------------------
// Name: InitD3D()
// Desc: Initializes Direct3D
//-----------------------------------------------------------------------------
HRESULT InitD3D()
{
    // Turn off culling
    g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );

    // Turn off D3D lighting
    g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );

    // Turn on the zbuffer
    g_pd3dDevice->SetRenderState( D3DRS_ZENABLE, TRUE );

    return S_OK;
}




//-----------------------------------------------------------------------------
// Name: InitGeometry()
// Desc: Create the textures and vertex buffers
//-----------------------------------------------------------------------------
HRESULT InitGeometry()
{
    // Use D3DX to create a texture from a file based image
    if( FAILED( D3DXCreateTextureFromFile( g_pd3dDevice, "banana.bmp", &g_pTexture ) ) )
    {
        // If texture is not in current folder, try parent folder
        if( FAILED( D3DXCreateTextureFromFile( g_pd3dDevice, "..\\banana.bmp", &g_pTexture ) ) )
        {
            MessageBox(NULL, "Could not find banana.bmp", "Textures.exe", MB_OK);
            return E_FAIL;
        }
    }

    // Create the vertex buffer.
    if( FAILED( g_pd3dDevice->CreateVertexBuffer( 50*2*sizeof(CUSTOMVERTEX),
                                                  0, D3DFVF_CUSTOMVERTEX,
                                                  D3DPOOL_DEFAULT, &g_pVB, NULL ) ) )
    {
        return E_FAIL;
    }

    // Fill the vertex buffer. We are setting the tu and tv texture
    // coordinates, which range from 0.0 to 1.0
    CUSTOMVERTEX* pVertices;
    if( FAILED( g_pVB->Lock( 0, 0, (void**)&pVertices, 0 ) ) )
        return E_FAIL;
    for( DWORD i=0; i<50; i++ )
    {
        FLOAT theta = (2*D3DX_PI*i)/(50-1);

        pVertices[2*i+0].position = D3DXVECTOR3( sinf(theta),-1.0f, cosf(theta) );
        pVertices[2*i+0].color    = 0xffffffff;
#ifndef SHOW_HOW_TO_USE_TCI
        pVertices[2*i+0].tu       = ((FLOAT)i)/(50-1);
        pVertices[2*i+0].tv       = 1.0f;
#endif

        pVertices[2*i+1].position = D3DXVECTOR3( sinf(theta), 1.0f, cosf(theta) );
        pVertices[2*i+1].color    = 0xff808080;
#ifndef SHOW_HOW_TO_USE_TCI
        pVertices[2*i+1].tu       = ((FLOAT)i)/(50-1);
        pVertices[2*i+1].tv       = 0.0f;
#endif
    }
    g_pVB->Unlock();

    return S_OK;
}




//-----------------------------------------------------------------------------
// Name: Cleanup()
// Desc: Releases all previously initialized objects
//-----------------------------------------------------------------------------
VOID Cleanup()
{
    if( g_pTexture != NULL )
        g_pTexture->Release();

    if( g_pVB != NULL )
        g_pVB->Release();
}



//-----------------------------------------------------------------------------
// Name: SetupMatrices()
// Desc: Sets up the world, view, and projection transform matrices.
//-----------------------------------------------------------------------------
VOID SetupMatrices()
{
    // For our world matrix, we will just leave it as the identity
    D3DXMATRIXA16 matWorld;
    D3DXMatrixIdentity( &matWorld );
    D3DXMatrixRotationX( &matWorld, Ticks()/1000.0f );
    g_pd3dDevice->SetTransform( D3DTS_WORLD, &matWorld );

    // Set up our view matrix. A view matrix can be defined given an eye point,
    // a point to lookat, and a direction for which way is up. Here, we set the
    // eye five units back along the z-axis and up three units, look at the
    // origin, and define "up" to be in the y-direction.
    D3DXVECTOR3 vEyePt( 0.0f, 3.0f,-5.0f );
    D3DXVECTOR3 vLookatPt( 0.0f, 0.0f, 0.0f );
    D3DXVECTOR3 vUpVec( 0.0f, 1.0f, 0.0f );
    D3DXMATRIXA16 matView;
    D3DXMatrixLookAtLH( &matView, &vEyePt, &vLookatPt, &vUpVec );
    g_pd3dDevice->SetTransform( D3DTS_VIEW, &matView );

    // For the projection matrix, we set up a perspective transform (which
    // transforms geometry from 3D view space to 2D viewport space, with
    // a perspective divide making objects smaller in the distance). To build
    // a perpsective transform, we need the field of view (1/4 pi is common),
    // the aspect ratio, and the near and far clipping planes (which define at
    // what distances geometry should be no longer be rendered).
    D3DXMATRIXA16 matProj;
    D3DXMatrixPerspectiveFovLH( &matProj, D3DX_PI/4, 1.0f, 1.0f, 100.0f );
    g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &matProj );
}




//-----------------------------------------------------------------------------
// Name: Render()
// Desc: Draws the scene
//-----------------------------------------------------------------------------
void Rendering()
{
    // Clear the backbuffer and the zbuffer
    g_pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER,
                         D3DCOLOR_XRGB(0,0,255), 1.0f, 0 );

    // Begin the scene
    if( SUCCEEDED( g_pd3dDevice->BeginScene() ) )
    {
        // Setup the world, view, and projection matrices
        SetupMatrices();

        // Setup our texture. Using textures introduces the texture stage states,
        // which govern how textures get blended together (in the case of multiple
        // textures) and lighting information. In this case, we are modulating
        // (blending) our texture with the diffuse color of the vertices.
        g_pd3dDevice->SetTexture( 0, g_pTexture );
        g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,   D3DTOP_MODULATE );
        g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
        g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG2, D3DTA_DIFFUSE );
        g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP,   D3DTOP_DISABLE );

    #ifdef SHOW_HOW_TO_USE_TCI
        // Note: to use D3D texture coordinate generation, use the stage state
        // D3DTSS_TEXCOORDINDEX, as shown below. In this example, we are using
        // the position of the vertex in camera space to generate texture
        // coordinates. The tex coord index (TCI) parameters are passed into a
        // texture transform, which is a 4x4 matrix which transforms the x,y,z
        // TCI coordinates into tu, tv texture coordinates.

        // In this example, the texture matrix is setup to 
        // transform the texture from (-1,+1) position coordinates to (0,1) 
        // texture coordinate space:
        //    tu =  0.5*x + 0.5
        //    tv = -0.5*y + 0.5
        D3DXMATRIXA16 mat;
        mat._11 = 0.25f; mat._12 = 0.00f; mat._13 = 0.00f; mat._14 = 0.00f;
        mat._21 = 0.00f; mat._22 =-0.25f; mat._23 = 0.00f; mat._24 = 0.00f;
        mat._31 = 0.00f; mat._32 = 0.00f; mat._33 = 1.00f; mat._34 = 0.00f;
        mat._41 = 0.50f; mat._42 = 0.50f; mat._43 = 0.00f; mat._44 = 1.00f;

        g_pd3dDevice->SetTransform( D3DTS_TEXTURE0, &mat );
        g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_COUNT2 );
        g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXCOORDINDEX, D3DTSS_TCI_CAMERASPACEPOSITION );
    #endif

        // Render the vertex buffer contents
        g_pd3dDevice->SetStreamSource( 0, g_pVB, 0, sizeof(CUSTOMVERTEX) );
        g_pd3dDevice->SetFVF( D3DFVF_CUSTOMVERTEX );
        g_pd3dDevice->DrawPrimitive( D3DPT_TRIANGLESTRIP, 0, 2*50-2 );

        // End the scene
        g_pd3dDevice->EndScene();
    }

    // Present the backbuffer contents to the display
    g_pd3dDevice->Present( NULL, NULL, NULL, NULL );
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