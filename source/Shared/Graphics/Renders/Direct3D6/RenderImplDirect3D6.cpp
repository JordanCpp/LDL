#include "RenderImplDirect3D6.hpp"
#include "TextureImplDirect3D6.hpp"
#include <LDL/Math/Funcs.hpp>
#include <LDL/Core/RuntimeError.hpp>

#if defined(_WIN32)
#include "../source/Platforms/Windows/Graphics/WindowImplOpenGL1.hpp"
#include "../source/Platforms/Windows/Graphics/WindowImplDirect3D6.hpp"
#elif defined(__unix__)
#include "../DirectX.hpp"
#include "../source/Platforms/Linux/Graphics/OpenGL1/WindowImplOpenGL1.hpp"
#endif

#undef FAILED

using namespace LDL::Core;
using namespace LDL::Graphics;
using namespace LDL::Math;
using namespace LDL::DirectX6;

void RenderImplDirect3D6::InitDirectDraw()
{
	LDL::DirectX6::HRESULT result = 0;

	result = DirectDrawCreate(NULL, &g_pDD1, NULL);
	if (FAILED(result))
		throw RuntimeError("DirectDrawCreate failed");

	result = g_pDD1->QueryInterface(IID_IDirectDraw4, (void**)&g_pDD4);
	if (FAILED(result))
		throw RuntimeError("QueryInterface failed");

	result = g_pDD4->SetCooperativeLevel(_Window->NativeHandle(), DDSCL_NORMAL);
	if (FAILED(result))
		throw RuntimeError("SetCooperativeLevel failed");
}

void RenderImplDirect3D6::InitSurfaces()
{
	LDL::DirectX6::HRESULT result = 0;

	DDSURFACEDESC2 ddsd;
	ZeroMemory(&ddsd, sizeof(DDSURFACEDESC2));
	ddsd.dwSize = sizeof(DDSURFACEDESC2);
	ddsd.dwFlags = DDSD_CAPS;
	ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;

	result = g_pDD4->CreateSurface(&ddsd, &g_pddsPrimary, NULL);
	if (FAILED(result))
		throw RuntimeError("CreateSurface failed");

	ddsd.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;
	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_3DDEVICE;
	ddsd.dwWidth = _Window->Size().x;
	ddsd.dwHeight = _Window->Size().y;

	result = g_pDD4->CreateSurface(&ddsd, &g_pddsBackBuffer, NULL);
	if (FAILED(result))
		throw RuntimeError("CreateSurface failed");

	LPDIRECTDRAWCLIPPER pcClipper;
	result = g_pDD4->CreateClipper(0, &pcClipper, NULL);
	if (FAILED(result))
		throw RuntimeError("CreateClipper failed");

	pcClipper->SetHWnd(0, _Window->NativeHandle());
	g_pddsPrimary->SetClipper(pcClipper);
	pcClipper->Release();
}

void RenderImplDirect3D6::InitDirect3D()
{
	LDL::DirectX6::HRESULT result = 0;

	g_pDD4->QueryInterface(IID_IDirect3D3, (void**)&g_pD3D);
	if (FAILED(result))
		throw RuntimeError("QueryInterface failed");

	result = g_pD3D->CreateDevice(IID_IDirect3DHALDevice, g_pddsBackBuffer, &g_pd3dDevice, NULL);

	if (FAILED(result))
	{
		result = g_pD3D->CreateDevice(IID_IDirect3DRGBDevice, g_pddsBackBuffer, &g_pd3dDevice, NULL);
		if (FAILED(result))
			throw RuntimeError("CreateDevice failed");
	}
}

void RenderImplDirect3D6::InitViewport()
{
	LDL::DirectX6::HRESULT result = 0;

	D3DVIEWPORT2 vdData;
	ZeroMemory(&vdData, sizeof(D3DVIEWPORT2));
	vdData.dwSize = sizeof(D3DVIEWPORT2);
	vdData.dwWidth = _Window->Size().x;
	vdData.dwHeight = _Window->Size().y;
	vdData.dvClipX = -1.0f;
	vdData.dvClipWidth = 2.0f;
	vdData.dvClipY = 1.0f;
	vdData.dvClipHeight = 2.0f;
	vdData.dvMaxZ = 1.0f;

	result = g_pD3D->CreateViewport(&g_pvViewport, NULL);
	if (FAILED(result))
		throw RuntimeError("CreateDevice failed");

	g_pd3dDevice->AddViewport(g_pvViewport);
	if (FAILED(result))
		throw RuntimeError("AddViewport failed");

	g_pvViewport->SetViewport2(&vdData);
	if (FAILED(result))
		throw RuntimeError("SetViewport2 failed");

	g_pd3dDevice->SetCurrentViewport(g_pvViewport);
	if (FAILED(result))
		throw RuntimeError("SetCurrentViewport failed");
}

RenderImplDirect3D6::RenderImplDirect3D6(RenderContextImpl* renderContextImpl, Window* window) :
	_Window(window),
	_RenderContextImpl(renderContextImpl),
	g_pDD1(NULL),
	g_pDD4(NULL),
	g_pddsPrimary(NULL),
	g_pddsBackBuffer(NULL),
	g_pD3D(NULL),
	g_pd3dDevice(NULL),
	g_pvViewport(NULL)
{
	InitDirectDraw();
	InitSurfaces();
	InitDirect3D();
	InitViewport();
}

void RenderImplDirect3D6::Buffer(uint8_t* dst)
{
}

void RenderImplDirect3D6::Begin()
{
}

void RenderImplDirect3D6::End()
{
}

const Vec2u& RenderImplDirect3D6::Size()
{
	return _Window->Size();
}

const Color& RenderImplDirect3D6::Color()
{
	return _Color;
}

void RenderImplDirect3D6::Clear()
{
}

void RenderImplDirect3D6::Color(const LDL::Graphics::Color& color)
{
	_Color = color;
}

void RenderImplDirect3D6::Pixel(const Vec2u& pos)
{
}

void RenderImplDirect3D6::Line(const Vec2u& pos1, const Vec2u& pos2)
{
}

void RenderImplDirect3D6::Fill(const Vec2u& pos, const Vec2u& size)
{
}

void RenderImplDirect3D6::Draw(Surface* image, const Vec2u& pos)
{
}

void RenderImplDirect3D6::Draw(Surface* image, const Vec2u& pos, const Vec2u& size)
{
}

void RenderImplDirect3D6::Draw(Surface* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImplDirect3D6::Draw(Surface* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImplDirect3D6::Draw(Texture* image, const Vec2u& pos)
{
	Draw(image, pos, image->Size(), Vec2u(0, 0), image->Size());
}

void RenderImplDirect3D6::Draw(Texture* image, const Vec2u& pos, const Vec2u& size)
{
	Draw(image, pos, size, Vec2u(0, 0), image->Size());
}

void RenderImplDirect3D6::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
	Draw(image, dstPos, srcSize, srcPos, srcSize);
}

void RenderImplDirect3D6::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImplDirect3D6::Draw(TextureBatcher* textureBatcher)
{
}
