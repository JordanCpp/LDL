#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Core/Assert.hpp>
#include <LDL/APIs/DirectX6/DirectX6Loader.hpp>
#include <string.h>
#include <time.h>

using namespace LDL::Graphics;
using namespace LDL::Enums;
using namespace LDL::Events;
using namespace LDL::Core;
using namespace LDL::Allocators;
using namespace LDL::Loaders;
using namespace LDL::Math;
using namespace LDL::DirectX6;

void ZeroMemory(void* dst, size_t size)
{
	memset(dst, 0, size);
}

//-----------------------------------------------------------------------------
// Local variables for the DirectDraw and Direct3D interface.
//
// Note: A real programmer would not use global variables for these objects,
// and use encapsulation instead. As it turns out, after initialization, any
// Direct3D app can make do with only a LPDIRECT3DDEVICE3 parameter, and deduct
// all other interfaces from that.
//-----------------------------------------------------------------------------
LPDIRECTDRAW         g_pDD1 = NULL;
LPDIRECTDRAW4        g_pDD4 = NULL;
LPDIRECTDRAWSURFACE4 g_pddsPrimary = NULL;
LPDIRECTDRAWSURFACE4 g_pddsBackBuffer = NULL;
LPDIRECT3D3          g_pD3D = NULL;
LPDIRECT3DDEVICE3    g_pd3dDevice = NULL;
LPDIRECT3DVIEWPORT3  g_pvViewport = NULL;
RECT                 g_rcScreenRect;
RECT                 g_rcViewportRect;
//-----------------------------------------------------------------------------
// Defines, constants, and global variables
//-----------------------------------------------------------------------------
LPDIRECT3DMATERIAL3 g_pmtrlObjectMtrl = NULL;
D3DVERTEX           g_pvTriangleVertices[6];

//-----------------------------------------------------------------------------
// Name: App_InitDeviceObjects()
// Desc: Initialize scene objects. This function is called after all the
//       DirectDraw and Direct3D objects have been initialized. It makes sense
//       to structure code this way, separating the DDraw/D3D initialization
//       code from the app-specific intialization code.
//-----------------------------------------------------------------------------
HRESULT App_InitDeviceObjects(LPDIRECT3DDEVICE3 pd3dDevice, LPDIRECT3DVIEWPORT3 pvViewport)
{
	// Data for the geometry of the triangle. Note that this tutorial only
	// uses ambient lighting, so the vertices' normals are not actually used.
	D3DVECTOR p1(0.0f, 3.0f, 0.0f);
	D3DVECTOR p2(3.0f, -3.0f, 0.0f);
	D3DVECTOR p3(-3.0f, -3.0f, 0.0f);
	D3DVECTOR vNormal(0.0f, 0.0f, 1.0f);

	// Initialize the 3 vertices for the front of the triangle
	g_pvTriangleVertices[0] = D3DVERTEX(p1, vNormal, 0, 0);
	g_pvTriangleVertices[1] = D3DVERTEX(p2, vNormal, 0, 0);
	g_pvTriangleVertices[2] = D3DVERTEX(p3, vNormal, 0, 0);

	// Initialize the 3 vertices for the back of the triangle
	g_pvTriangleVertices[3] = D3DVERTEX(p1, -vNormal, 0, 0);
	g_pvTriangleVertices[4] = D3DVERTEX(p3, -vNormal, 0, 0);
	g_pvTriangleVertices[5] = D3DVERTEX(p2, -vNormal, 0, 0);

	// Get a ptr to the ID3D object to create materials and/or lights. Note:
	// the Release() call just serves to decrease the ref count.
	LPDIRECT3D3 pD3D;
	if (FAILED(pd3dDevice->GetDirect3D(&pD3D)))
		return E_FAIL;
	pD3D->Release();

	// Create the object material. This material will be used to draw the
	// triangle. Note: that when we use textures, the object material is
	// usually omitted or left as white.
	if (FAILED(pD3D->CreateMaterial(&g_pmtrlObjectMtrl, NULL)))
		return E_FAIL;

	// Set the object material as yellow. We're setting the ambient color here
	// since this tutorial only uses ambient lighting. For apps that use real
	// lights, the diffuse and specular values should be set. (In addition, the
	// polygons' vertices need normals for true lighting.)
	D3DMATERIAL       mtrl;
	D3DMATERIALHANDLE hmtrl;
	ZeroMemory(&mtrl, sizeof(D3DMATERIAL));
	mtrl.dwSize = sizeof(D3DMATERIAL);
	mtrl.dcvAmbient.r = 1.0f;
	mtrl.dcvAmbient.g = 1.0f;
	mtrl.dcvAmbient.b = 0.0f;
	g_pmtrlObjectMtrl->SetMaterial(&mtrl);

	// Put the object material into effect. Direct3D is a state machine, and
	// calls like this set the current state. After this call, any polygons
	// rendered will be drawn using this material.
	g_pmtrlObjectMtrl->GetHandle(pd3dDevice, &hmtrl);
	pd3dDevice->SetLightState(D3DLIGHTSTATE_MATERIAL, hmtrl);

	// The ambient lighting value is another state to set. Here, we are turning
	// ambient lighting on to full white.
	pd3dDevice->SetLightState(D3DLIGHTSTATE_AMBIENT, 0xffffffff);

	// Set the transform matrices. Direct3D uses three independant matrices:
	// the world matrix, the view matrix, and the projection matrix. For
	// convienence, we are first setting up an identity matrix.
	D3DMATRIX mat;
	mat._11 = mat._22 = mat._33 = mat._44 = 1.0f;
	mat._12 = mat._13 = mat._14 = mat._41 = 0.0f;
	mat._21 = mat._23 = mat._24 = mat._42 = 0.0f;
	mat._31 = mat._32 = mat._34 = mat._43 = 0.0f;

	// The world matrix controls the position and orientation of the polygons
	// in world space. We'll use it later to spin the triangle.
	D3DMATRIX matWorld = mat;
	pd3dDevice->SetTransform(D3DTRANSFORMSTATE_WORLD, &matWorld);

	// The view matrix defines the position and orientation of the camera.
	// Here, we are just moving it back along the z-axis by 10 units.
	D3DMATRIX matView = mat;
	matView._43 = 10.0f;
	pd3dDevice->SetTransform(D3DTRANSFORMSTATE_VIEW, &matView);

	// The projection matrix defines how the 3D scene is "projected" onto the
	// 2D render target (the backbuffer surface). Refer to the docs for more
	// info about projection matrices.
	D3DMATRIX matProj = mat;
	matProj._11 = 2.0f;
	matProj._22 = 2.0f;
	matProj._34 = 1.0f;
	matProj._43 = -1.0f;
	matProj._44 = 0.0f;
	pd3dDevice->SetTransform(D3DTRANSFORMSTATE_PROJECTION, &matProj);

	return S_OK;
}

//-----------------------------------------------------------------------------
// Name: App_FrameMove()
// Desc: Called once per frame, the call is used for animating the scene. The
//       device is used for changing various render states, and the timekey is
//       used for timing of the dynamics of the scene.
//-----------------------------------------------------------------------------
HRESULT App_FrameMove(LPDIRECT3DDEVICE3 pd3dDevice, FLOAT fTimeKey)
{
	// For this simple tutorial, we are rotating the triangle about the y-axis.
	// To do this, just set up a 4x4 matrix defining the rotation, and set it
	// as the new world transform.
	D3DMATRIX matSpin;
	matSpin._11 = matSpin._22 = matSpin._33 = matSpin._44 = 1.0f;
	matSpin._12 = matSpin._13 = matSpin._14 = matSpin._41 = 0.0f;
	matSpin._21 = matSpin._23 = matSpin._24 = matSpin._42 = 0.0f;
	matSpin._32 = matSpin._32 = matSpin._34 = matSpin._43 = 0.0f;

	matSpin._11 = (FLOAT)cos(fTimeKey);
	matSpin._33 = (FLOAT)cos(fTimeKey);
	matSpin._13 = (FLOAT)sin(fTimeKey);
	matSpin._31 = (FLOAT)sin(fTimeKey);

	pd3dDevice->SetTransform(D3DTRANSFORMSTATE_WORLD, &matSpin);

	return S_OK;
}

//-----------------------------------------------------------------------------
// Name: App_Render()
// Desc: Called once per frame, the function is called to render the scene.
//       Rendering consists of the following:
//       (1) Clear the viewport
//       (2) Call BeginScene()
//       (3) Draw the polygons (primitives) and change the state as needed
//       (4) Call EndScene()
//
//       After this call completes, the device's render target (the backbuffer
//       surface) will contain the rendered image of the scene. All that is
//       left is to copy the contents of the backbuffer to the primary.
//-----------------------------------------------------------------------------
HRESULT App_Render(LPDIRECT3DDEVICE3 pd3dDevice,
	LPDIRECT3DVIEWPORT3 pvViewport,
	D3DRECT* prcViewportRect)
{
	// Clear the viewport to a blue color (dwColor = 0x000000ff). For apps with
	// z-buffers, this call can also clear the z-buffer (if present) as well.
	pvViewport->Clear2(1UL, prcViewportRect, D3DCLEAR_TARGET, 0x000000ff,
		0L, 0L);

	// Begin the scene
	if (FAILED(pd3dDevice->BeginScene()))
		return E_FAIL;

	// Draw the triangle using a DrawPrimitive() call. Subsequent
	// tutorials will go into more detail on the various calls for
	// drawing polygons.
	pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, D3DFVF_VERTEX, g_pvTriangleVertices, 6, NULL);

	// End the scene.
	pd3dDevice->EndScene();

	return S_OK;
}

//-----------------------------------------------------------------------------
// Name: App_DeleteDeviceObjects()
// Desc: Called when the device is being deleted, this function deletes any
//       device dependant objects.
//-----------------------------------------------------------------------------
void App_DeleteDeviceObjects(LPDIRECT3DDEVICE3 pd3dDevice, LPDIRECT3DVIEWPORT3 pvViewport)
{
	// Release the material that was created earlier.
	if (g_pmtrlObjectMtrl)
		g_pmtrlObjectMtrl->Release();
	g_pmtrlObjectMtrl = NULL;
}

//-----------------------------------------------------------------------------
// Name: Initialize3DEnvironment()
// Desc: 
//-----------------------------------------------------------------------------
HRESULT Initialize3DEnvironment(Window& window)
{
	HRESULT hr;

	//-------------------------------------------------------------------------
	// Step 1: Create DirectDraw and set the coop level
	//-------------------------------------------------------------------------

	// Create the IDirectDraw interface. The first parameter is the GUID,
	// which is allowed to be NULL. If there are more than one DirectDraw
	// drivers on the system, a NULL guid requests the primary driver. For 
	// non-GDI hardware cards like the 3DFX and PowerVR, the guid would need
	// to be explicity specified . (Note: these guids are normally obtained
	// from enumeration, which is convered in a subsequent tutorial.)
	hr = DirectDrawCreate(NULL, &g_pDD1, NULL);
	if (FAILED(hr))
		return hr;

	// Get a ptr to an IDirectDraw4 interface. This interface to DirectDraw
	// represents the DX6 version of the API.
	hr = g_pDD1->QueryInterface(IID_IDirectDraw4, (void**)&g_pDD4);
	if (FAILED(hr))
		return hr;

	// Set the Windows cooperative level. This is where we tell the system
	// whether wew will be rendering in fullscreen mode or in a window. Note
	// that some hardware (non-GDI) may not be able to render into a window.
	// The flag DDSCL_NORMAL specifies windowed mode. Using fullscreen mode
	// is the topic of a subsequent tutorial. The DDSCL_FPUSETUP flag is a 
	// hint to DirectX to optomize floating points calculations. See the docs
	// for more info on this. Note: this call could fail if another application
	// already controls a fullscreen, exclusive mode.
	hr = g_pDD4->SetCooperativeLevel(window.NativeHandle(), DDSCL_NORMAL);
	if (FAILED(hr))
		return hr;

	//-------------------------------------------------------------------------
	// Step 2: Create DirectDraw surfaces used for rendering
	//-------------------------------------------------------------------------

	// Initialize a surface description structure for the primary surface. The
	// primary surface represents the entire display, with dimensions and a
	// pixel format of the display. Therefore, none of that information needs
	// to be specified in order to create the primary surface.
	DDSURFACEDESC2 ddsd;
	ZeroMemory(&ddsd, sizeof(DDSURFACEDESC2));
	ddsd.dwSize = sizeof(DDSURFACEDESC2);
	ddsd.dwFlags = DDSD_CAPS;
	ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;

	// Create the primary surface.
	hr = g_pDD4->CreateSurface(&ddsd, &g_pddsPrimary, NULL);
	if (FAILED(hr))
		return hr;

	// Setup a surface description to create a backbuffer. This is an
	// offscreen plain surface with dimensions equal to our window size.
	// The DDSCAPS_3DDEVICE is needed so we can later query this surface
	// for an IDirect3DDevice interface.
	ddsd.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;
	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_3DDEVICE;

	// Set the dimensions of the backbuffer. Note that if our window changes
	// size, we need to destroy this surface and create a new one.
	ddsd.dwWidth  = window.Size().x;
	ddsd.dwHeight = window.Size().y;

	// Create the backbuffer. The most likely reason for failure is running
	// out of video memory. (A more sophisticated app should handle this.)
	hr = g_pDD4->CreateSurface(&ddsd, &g_pddsBackBuffer, NULL);
	if (FAILED(hr))
		return hr;

	// Note: if using a z-buffer, the zbuffer surface creation would go around
	// here. However, z-buffer usage is the topic of a subsequent tutorial.

	// Create a clipper object which handles all our clipping for cases when
	// our window is partially obscured by other windows. This is not needed
	// for apps running in fullscreen mode.
	LPDIRECTDRAWCLIPPER pcClipper;
	hr = g_pDD4->CreateClipper(0, &pcClipper, NULL);
	if (FAILED(hr))
		return hr;

	// Associate the clipper with our window. Note that, afterwards, the
	// clipper is internally referenced by the primary surface, so it is safe
	// to release our local reference to it.
	pcClipper->SetHWnd(0, window.NativeHandle());
	g_pddsPrimary->SetClipper(pcClipper);
	pcClipper->Release();

	//-------------------------------------------------------------------------
	// Step 3: Create the Direct3D interfaces
	//-------------------------------------------------------------------------

	// Query DirectDraw for access to Direct3D
	g_pDD4->QueryInterface(IID_IDirect3D3, (void**)&g_pD3D);
	if (FAILED(hr))
		return hr;

	// Before creating the device, check that we are NOT in a palettized
	// display. That case will cause CreateDevice() to fail, since this simple 
	// tutorial does not bother with palettes.
	ddsd.dwSize = sizeof(DDSURFACEDESC2);
	g_pDD4->GetDisplayMode(&ddsd);
	if (ddsd.ddpfPixelFormat.dwRGBBitCount <= 8)
		return DDERR_INVALIDMODE;

	// Create the device. The GUID is hardcoded for now, but should come from
	// device enumeration, which is the topic of a future tutorial. The device
	// is created off of our back buffer, which becomes the render target for
	// the newly created device.
	hr = g_pD3D->CreateDevice(IID_IDirect3DHALDevice, g_pddsBackBuffer, &g_pd3dDevice, NULL);
	if (FAILED(hr))
	{
		// This call could fail for many reasons. The most likely cause is
		// that we specifically requested a hardware device, without knowing
		// whether there is even a 3D card installed in the system. Another
		// possibility is the hardware is incompatible with the current display
		// mode (once again, the correct implementation would use enumeration
		// to check that). In any case, let's simply try again with the RGB
		// software rasterizer.
		hr = g_pD3D->CreateDevice(IID_IDirect3DRGBDevice, g_pddsBackBuffer, &g_pd3dDevice, NULL);
		if (FAILED(hr))
			return hr;
	}

	//-------------------------------------------------------------------------
	// Step 4: Create the viewport
	//-------------------------------------------------------------------------

	// Set up the viewport data parameters
	D3DVIEWPORT2 vdData;
	ZeroMemory(&vdData, sizeof(D3DVIEWPORT2));
	vdData.dwSize = sizeof(D3DVIEWPORT2);
	vdData.dwWidth = window.Size().x;
	vdData.dwHeight = window.Size().y;
	vdData.dvClipX = -1.0f;
	vdData.dvClipWidth = 2.0f;
	vdData.dvClipY = 1.0f;
	vdData.dvClipHeight = 2.0f;
	vdData.dvMaxZ = 1.0f;

	// Create the viewport
	hr = g_pD3D->CreateViewport(&g_pvViewport, NULL);
	if (FAILED(hr))
		return hr;

	// Associate the viewport with the D3DDEVICE object
	g_pd3dDevice->AddViewport(g_pvViewport);

	// Set the parameters to the new viewport
	g_pvViewport->SetViewport2(&vdData);

	// Set the viewport as current for the device
	g_pd3dDevice->SetCurrentViewport(g_pvViewport);

	//-------------------------------------------------------------------------
	// Step 5: We're done and ready to set up our scene
	//-------------------------------------------------------------------------

	return App_InitDeviceObjects(g_pd3dDevice, g_pvViewport);
}

//-----------------------------------------------------------------------------
// Name: Cleanup3DEnvironment()
// Desc: Releases all the resources used by the app. Note the check for
//       reference counts when releasing the D3DDevice and DDraw objects. If
//       these ref counts are non-zero, then something was not cleaned up
//       correctly.
//-----------------------------------------------------------------------------
HRESULT Cleanup3DEnvironment()
{
	// Cleanup any objects created for the scene
	App_DeleteDeviceObjects(g_pd3dDevice, g_pvViewport);

	// Release the DDraw and D3D objects used by the app
	if (g_pvViewport)     g_pvViewport->Release();
	if (g_pD3D)           g_pD3D->Release();
	if (g_pddsBackBuffer) g_pddsBackBuffer->Release();
	if (g_pddsPrimary)    g_pddsPrimary->Release();
	if (g_pDD4)           g_pDD4->Release();

	// Do a safe check for releasing the D3DDEVICE. RefCount should be zero.
	if (g_pd3dDevice)
		if (0 < g_pd3dDevice->Release())
			return E_FAIL;

	// Do a safe check for releasing DDRAW. RefCount should be zero.
	if (g_pDD1)
		if (0 < g_pDD1->Release())
			return E_FAIL;

	g_pvViewport = NULL;
	g_pd3dDevice = NULL;
	g_pD3D = NULL;
	g_pddsBackBuffer = NULL;
	g_pddsPrimary = NULL;
	g_pDD4 = NULL;
	g_pDD1 = NULL;

	return S_OK;
}

//-----------------------------------------------------------------------------
// Name: ShowFrame()
// Desc: Show the frame on the primary surface
//-----------------------------------------------------------------------------
HRESULT ShowFrame()
{
	if (g_pddsPrimary == NULL)
		return E_FAIL;

	// We are in windowed mode, so perform a blit from the backbuffer to the
	// correct position on the primary surface
	return g_pddsPrimary->Blt(&g_rcScreenRect, g_pddsBackBuffer, &g_rcViewportRect, DDBLT_WAIT, NULL);
}

//-----------------------------------------------------------------------------
// Name: RestoreSurfaces()
// Desc: Checks for lost surfaces and restores them if lost.
//-----------------------------------------------------------------------------
HRESULT RestoreSurfaces()
{
	// Check/restore the primary surface
	if (g_pddsPrimary)
		if (g_pddsPrimary->IsLost())
			g_pddsPrimary->Restore();

	// Check/restore the back buffer
	if (g_pddsBackBuffer)
		if (g_pddsBackBuffer->IsLost())
			g_pddsBackBuffer->Restore();

	return S_OK;
}

//-----------------------------------------------------------------------------
// Name: Render3DEnvironment()
// Desc: Draws the scene. There are three steps here:
//       (1) Animate the scene
//       (2) Render the scene
//       (3) Show the frame (copy backbuffer contents to the primary).
//-----------------------------------------------------------------------------
HRESULT Render3DEnvironment()
{
	// Call the app specific function to framemove (animate) the scene
	App_FrameMove(g_pd3dDevice, ((FLOAT)clock()) / CLOCKS_PER_SEC);

	// Call the app specific function to render the scene
	App_Render(g_pd3dDevice, g_pvViewport, (D3DRECT*)&g_rcViewportRect);

	// Show the frame on the primary surface. Note: this is the best place to
	// check for "lost" surfaces. Surfaces can be lost if something caused
	// them to temporary lose their video memory. "Lost" surfaces simply
	// need to be restored before continuing.
	if (DDERR_SURFACELOST == ShowFrame())
	{
		RestoreSurfaces();
	}

	return S_OK;
}

int main()
{
		DirectX6Loader directXLoader;
		RenderContext renderContext(RenderMode::Direct3D6);

		Window window(&renderContext, Vec2u(0, 0), Vec2u(800, 600), "DirectX6Loader.cpp");

		Event report;

		g_rcScreenRect.left   = (LONG)window.Pos().x;
		g_rcScreenRect.top    = (LONG)window.Pos().y;
		g_rcScreenRect.right  = (LONG)window.Size().x;
		g_rcScreenRect.bottom = (LONG)window.Size().y;
		  
		g_rcViewportRect.left   = (LONG)window.Pos().x;
		g_rcViewportRect.top    = (LONG)window.Pos().y;
		g_rcViewportRect.right  = (LONG)window.Size().x;
		g_rcViewportRect.bottom = (LONG)window.Size().y;

		HRESULT result = Initialize3DEnvironment(window);
		LDL_ASSERT_DETAIL(!FAILED(result), "Initialize3DEnvironment failed");

		while (window.Running())
		{
			while (window.GetEvent(report))
			{
				if (report.Type == IsQuit)
				{
					window.StopEvent();
				}

				if (report.IsKeyPressed(KeyboardKey::Escape))
					window.StopEvent();
			}

			result = Render3DEnvironment();
			LDL_ASSERT_DETAIL(!FAILED(result), "Initialize3DEnvironment failed");

			window.PollEvents();
		}

		Cleanup3DEnvironment();

	return 0;
}
