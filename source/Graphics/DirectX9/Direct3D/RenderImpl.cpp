#include "RenderImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include "../../../Platforms/Windows/Graphics/DirectX9/Direct3D/WindowImpl.hpp"
#include "TextureImpl.hpp"

using namespace LDL::Graphics;

struct VertexType
{
    FLOAT x, y, z, rhw;
    FLOAT tu, tv;
};

struct QuadType 
{
    VertexType  v1;
    VertexType  v2;
    VertexType  v3;
    VertexType  v4;
};

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_TEX1)

RenderImpl::RenderImpl(Window* window) :
	_Window(window),
	_BaseRender(_Window->Size()),
    _Line(NULL),
    _Direct3D(NULL),
    _Direct3DDevice(NULL),
    _VertexBuffer(NULL)
{
    Initialization();

    HRESULT result = _Direct3DDevice->CreateVertexBuffer(sizeof(QuadType), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &_VertexBuffer, NULL);

    if (FAILED(result))
        throw LDL::Core::RuntimeError("CreateVertexBuffer failed");

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

    HRESULT result = _Direct3DDevice->SetTransform(D3DTS_PROJECTION, &projection);

    if (FAILED(result))
        throw LDL::Core::RuntimeError("SetTransform failed");
}

void RenderImpl::Begin()
{
    HRESULT result = _Direct3DDevice->TestCooperativeLevel();

    if (result == D3DERR_DEVICELOST)
        throw LDL::Core::RuntimeError("TestCooperativeLevel failed");

    result = _Direct3DDevice->BeginScene();

    if (FAILED(result))
        throw LDL::Core::RuntimeError("BeginScene failed");
}

void RenderImpl::End()
{
    HRESULT result;

    result = _Direct3DDevice->EndScene();
    if (FAILED(result))
        throw LDL::Core::RuntimeError("EndScene failed");

    result = _Direct3DDevice->Present(NULL, NULL, NULL, NULL);
    if (FAILED(result))
        throw LDL::Core::RuntimeError("Present failed");
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
    QuadType q;

    q.v1.x   = (FLOAT)pos.PosX();
    q.v1.y   = (FLOAT)size.PosY() + (FLOAT)pos.PosY();
    q.v1.z   = 0.0f;
    q.v1.rhw = 1.0f;
    q.v1.tu  = 0.0f;
    q.v1.tv  = 1.0f;

    q.v2.x   = (FLOAT)pos.PosX();
    q.v2.y   = (FLOAT)pos.PosY();
    q.v2.z   = 0.0f;
    q.v2.rhw = 1.0f;
    q.v2.tu  = 0.0f;
    q.v2.tv  = 0.0f;

    q.v3.x = (FLOAT)size.PosX() + (FLOAT)pos.PosX();;
    q.v3.y = (FLOAT)size.PosY() + (FLOAT)pos.PosY();;
    q.v3.z = 0.0f;
    q.v3.rhw = 1.0f;
    q.v3.tu = 1.0f;
    q.v3.tv = 1.0f;

    q.v4.x = (FLOAT)size.PosX() + (FLOAT)pos.PosX();;
    q.v4.y = (FLOAT)pos.PosY();
    q.v4.z = 0.0f;
    q.v4.rhw = 1.0f;
    q.v4.tu = 1.0f;
    q.v4.tv = 0.0f;

    HRESULT result;
    void* temp = NULL;

    result = _VertexBuffer->Lock(0, sizeof(QuadType), (void**)&temp, 0);
    if (FAILED(result))
        throw LDL::Core::RuntimeError("Lock failed");

    memcpy(temp, &q, sizeof(QuadType));

    result = _VertexBuffer->Unlock();
    if (FAILED(result))
        throw LDL::Core::RuntimeError("Unlock failed");

    _Direct3DDevice->SetStreamSource(0, _VertexBuffer, 0, sizeof(VertexType));
    _Direct3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

    _Direct3DDevice->SetTexture(0, (LPDIRECT3DBASETEXTURE9)image->GetTextureImpl()->Texture());
    _Direct3DDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
    _Direct3DDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
    _Direct3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
    _Direct3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
    _Direct3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
    _Direct3DDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
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