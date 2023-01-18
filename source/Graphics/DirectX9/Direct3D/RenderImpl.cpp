#include "RenderImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include "../../../Platforms/Windows/Graphics/DirectX9/Direct3D/WindowImpl.hpp"

using namespace LDL::Graphics;

RenderImpl::RenderImpl(Window* window) :
	_Window(window),
	_BaseRender(_Window->Size())
{
    Initialization();

    Mode2D();
}

RenderImpl::~RenderImpl()
{
    Deinitialization();
}

void RenderImpl::Buffer(uint8_t* dst)
{

}

void RenderImpl::Mode2D()
{
    D3DXMATRIX projection;
    D3DXMatrixOrthoLH(&projection, (FLOAT)_Window->Size().PosX(), (FLOAT)_Window->Size().PosY(), 0.0f, 0.0f);

    _Direct3DDevice->SetTransform(D3DTS_PROJECTION, &projection);
}

void RenderImpl::Begin()
{
    HRESULT result = _Direct3DDevice->TestCooperativeLevel();

    if (result == D3DERR_DEVICELOST)
        throw LDL::Core::RuntimeError("TestCooperativeLevel failed");

    _Direct3DDevice->BeginScene();
}

void RenderImpl::End()
{
    _Direct3DDevice->EndScene();
    _Direct3DDevice->Present(NULL, NULL, NULL, NULL);
}

const Point2u& RenderImpl::Size()
{
	return _BaseRender.Size();
}

const Color& LDL::Graphics::RenderImpl::Color()
{
	return _BaseRender.Color();
}

void RenderImpl::Clear()
{
    _Direct3DDevice->Clear(0L, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(_BaseRender.Color().Red(), _BaseRender.Color().Green(), _BaseRender.Color().Blue()), 1.0f, 0L);
}

void RenderImpl::Color(const LDL::Graphics::Color& color)
{
	_BaseRender.Color(color);
}

void RenderImpl::Pixel(const Point2u& pos)
{
}

void RenderImpl::Line(const Point2u& pos1, const Point2u& pos2)
{
    D3DXVECTOR2 vec[] = { D3DXVECTOR2((float)pos1.PosX(), (float)pos1.PosY()), D3DXVECTOR2((float)pos2.PosX(), (float)pos2.PosY()) };

    _Line->Draw(vec, 2, D3DCOLOR_XRGB(_BaseRender.Color().Red(), _BaseRender.Color().Green(), _BaseRender.Color().Blue()));
}

void RenderImpl::Fill(const Point2u& pos, const Point2u& size)
{
}

void RenderImpl::Draw(Texture* image, const Point2u& pos, const Point2u& size)
{
}

void RenderImpl::Draw(Texture* image, const Point2u& pos)
{
	Draw(image, pos, image->Size());
}

void RenderImpl::Draw(Surface* image, const Point2u& pos, const Point2u& size)
{
}

void RenderImpl::Draw(Surface* image, const Point2u& pos)
{
}

void RenderImpl::Draw(Texture* image, const Point2u& dstPos, const Point2u& srcPos, const Point2u& srcSize)
{
}

void RenderImpl::Initialization()
{
    _Direct3D = Direct3DCreate9(D3D_SDK_VERSION);

    if (_Direct3D == NULL)
        throw LDL::Core::RuntimeError("Direct3DCreate9 failed");

    HRESULT result = NULL;

    D3DDISPLAYMODE displayMode = { 0 };

    result = _Direct3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &displayMode);

    if (FAILED(result))
        throw LDL::Core::RuntimeError("GetAdapterDisplayMode failed");

    D3DPRESENT_PARAMETERS parameters = { 0 };

    parameters.hDeviceWindow = _Window->GetWindowImpl()->Hwnd();
    parameters.Windowed = true;
    parameters.BackBufferWidth = (UINT)_Window->Size().PosX();
    parameters.BackBufferHeight = (UINT)_Window->Size().PosY();
    parameters.BackBufferCount = 1;
    parameters.EnableAutoDepthStencil = true;
    parameters.AutoDepthStencilFormat = D3DFMT_D16;
    parameters.SwapEffect = D3DSWAPEFFECT_FLIP;
    parameters.BackBufferFormat = displayMode.Format;
    parameters.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
    parameters.FullScreen_RefreshRateInHz = 0;

    result = _Direct3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, _Window->GetWindowImpl()->Hwnd(), D3DCREATE_HARDWARE_VERTEXPROCESSING, &parameters, &_Direct3DDevice);

    if (FAILED(result))
        throw LDL::Core::RuntimeError("CreateDevice failed");

    result = D3DXCreateLine(_Direct3DDevice, &_Line);

    if (FAILED(result))
        throw LDL::Core::RuntimeError("D3DXCreateLine failed");
}

void RenderImpl::Deinitialization()
{
    if (_Line != NULL)
    {
        _Line->Release();
        _Line = NULL;
    }

    if (_Direct3DDevice != NULL)
    {
        _Direct3DDevice->Release();
        _Direct3DDevice = NULL;
    }

    if (_Direct3D != NULL)
    {
        _Direct3D->Release();
        _Direct3D = NULL;
    }
}