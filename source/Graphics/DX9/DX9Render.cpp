#include <LDL/Graphics/DX9/DX9Render.hpp>
#include <LDL/Core/RuntimeError.hpp>

LDL::Graphics::DX9Render::DX9Render(LDL::Graphics::DX9Window* window) :
	_Window(window),
	_BaseRender(_Window->Size())
{
    Initialization();

    Mode2D();
}

LDL::Graphics::DX9Render::~DX9Render()
{
    Deinitialization();
}

void LDL::Graphics::DX9Render::Mode2D()
{
    D3DXMATRIX projection;
    D3DXMatrixOrthoLH(&projection, (FLOAT)_Window->Size().PosX(), (FLOAT)_Window->Size().PosY(), 0.0f, 0.0f);

    _Direct3DDevice->SetTransform(D3DTS_PROJECTION, &projection);
}

void LDL::Graphics::DX9Render::Begin()
{
    HRESULT result = _Direct3DDevice->TestCooperativeLevel();

    if (result == D3DERR_DEVICELOST)
        throw LDL::Core::RuntimeError("TestCooperativeLevel failed");

    _Direct3DDevice->BeginScene();
}

void LDL::Graphics::DX9Render::End()
{
    _Direct3DDevice->EndScene();
    _Direct3DDevice->Present(NULL, NULL, NULL, NULL);
}

const LDL::Graphics::Point2u& LDL::Graphics::DX9Render::Size()
{
	return _BaseRender.Size();
}

const LDL::Graphics::Color& LDL::Graphics::DX9Render::Color()
{
	return _BaseRender.Color();
}

void LDL::Graphics::DX9Render::Clear()
{
    _Direct3DDevice->Clear(0L, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(_BaseRender.Color().Red(), _BaseRender.Color().Green(), _BaseRender.Color().Blue()), 1.0f, 0L);
}

void LDL::Graphics::DX9Render::Color(const LDL::Graphics::Color& color)
{
	_BaseRender.Color(color);
}

void LDL::Graphics::DX9Render::Pixel(const LDL::Graphics::Point2u& pos)
{
}

void LDL::Graphics::DX9Render::Line(const LDL::Graphics::Point2u& pos1, const LDL::Graphics::Point2u& pos2)
{
    D3DXVECTOR2 vec[] = { D3DXVECTOR2((float)pos1.PosX(), (float)pos1.PosY()), D3DXVECTOR2((float)pos2.PosX(), (float)pos2.PosY()) };

    _Line->Draw(vec, 2, D3DCOLOR_XRGB(_BaseRender.Color().Red(), _BaseRender.Color().Green(), _BaseRender.Color().Blue()));
}

void LDL::Graphics::DX9Render::Fill(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size)
{
}

void LDL::Graphics::DX9Render::Draw(LDL::Graphics::DX9Image* image, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size)
{
}

void LDL::Graphics::DX9Render::Draw(LDL::Graphics::DX9Image* image, const LDL::Graphics::Point2u& pos)
{
	Draw(image, pos, image->Size());
}

void LDL::Graphics::DX9Render::Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size)
{

}

void LDL::Graphics::DX9Render::Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos)
{

}

void LDL::Graphics::DX9Render::Initialization()
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

    parameters.hDeviceWindow = _Window->Hwnd();
    parameters.Windowed = true;
    parameters.BackBufferWidth = _Window->Size().PosX();
    parameters.BackBufferHeight = _Window->Size().PosY();
    parameters.BackBufferCount = 1;
    parameters.EnableAutoDepthStencil = true;
    parameters.AutoDepthStencilFormat = D3DFMT_D16;
    parameters.SwapEffect = D3DSWAPEFFECT_FLIP;
    parameters.BackBufferFormat = displayMode.Format;

    result = _Direct3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, _Window->Hwnd(), D3DCREATE_HARDWARE_VERTEXPROCESSING, &parameters, &_Direct3DDevice);

    if (FAILED(result))
        throw LDL::Core::RuntimeError("CreateDevice failed");

    result = D3DXCreateLine(_Direct3DDevice, &_Line);

    if (FAILED(result))
        throw LDL::Core::RuntimeError("D3DXCreateLine failed");
}

void LDL::Graphics::DX9Render::Deinitialization()
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