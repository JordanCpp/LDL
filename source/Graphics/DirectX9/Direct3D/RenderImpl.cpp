#include "RenderImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include "../../../Platforms/Windows/Graphics/DirectX9/Direct3D/WindowImpl.hpp"
#include "TextureImpl.hpp"
#include "RenderContextImpl.hpp"

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

RenderImpl::RenderImpl(RenderContextImpl* renderContextImpl, Window* window) :
	_Window(window),
	_BaseRender(_Window->Size()),
    _Line(NULL),
    _RenderContextImpl(renderContextImpl),
    _VertexBuffer(NULL)
{
    Initialization();

    HRESULT result = _RenderContextImpl->Context.Device->CreateVertexBuffer(sizeof(QuadType), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &_VertexBuffer, NULL);

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
    D3DXMatrixOrthoLH(&projection, (FLOAT)_Window->Size().x, (FLOAT)_Window->Size().y, 0.0f, 0.0f);

    HRESULT result = _RenderContextImpl->Context.Device->SetTransform(D3DTS_PROJECTION, &projection);

    if (FAILED(result))
        throw LDL::Core::RuntimeError("SetTransform failed");
}

void RenderImpl::Begin()
{
    HRESULT result = _RenderContextImpl->Context.Device->TestCooperativeLevel();

    if (result == D3DERR_DEVICELOST)
        throw LDL::Core::RuntimeError("TestCooperativeLevel failed");

    result = _RenderContextImpl->Context.Device->BeginScene();

    if (FAILED(result))
        throw LDL::Core::RuntimeError("BeginScene failed");
}

void RenderImpl::End()
{
    HRESULT result;

    result = _RenderContextImpl->Context.Device->EndScene();
    if (FAILED(result))
        throw LDL::Core::RuntimeError("EndScene failed");

    result = _RenderContextImpl->Context.Device->Present(NULL, NULL, NULL, NULL);
    if (FAILED(result))
        throw LDL::Core::RuntimeError("Present failed");
}

const Vec2u& RenderImpl::Size()
{
	return _BaseRender.Size();
}

const Color& LDL::Graphics::RenderImpl::Color()
{
	return _BaseRender.Color();
}

void RenderImpl::Clear()
{
    _RenderContextImpl->Context.Device->Clear(0L, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(_BaseRender.Color().Red(), _BaseRender.Color().Green(), _BaseRender.Color().Blue()), 1.0f, 0L);
}

void RenderImpl::Color(const LDL::Graphics::Color& color)
{
	_BaseRender.Color(color);
}

void RenderImpl::Pixel(const Vec2u& pos)
{
}

void RenderImpl::Line(const Vec2u& pos1, const Vec2u& pos2)
{
    D3DXVECTOR2 vec[] = { D3DXVECTOR2((float)pos1.x, (float)pos1.y), D3DXVECTOR2((float)pos2.x, (float)pos2.y) };

    _Line->Draw(vec, 2, D3DCOLOR_XRGB(_BaseRender.Color().Red(), _BaseRender.Color().Green(), _BaseRender.Color().Blue()));
}

void RenderImpl::Fill(const Vec2u& pos, const Vec2u& size)
{
}

void RenderImpl::Draw(Texture* image, const Vec2u& pos, const Vec2u& size)
{
    QuadType q;

    q.v1.x   = (FLOAT)pos.x;
    q.v1.y   = (FLOAT)size.y + (FLOAT)pos.y;
    q.v1.z   = 0.0f;
    q.v1.rhw = 1.0f;
    q.v1.tu  = 0.0f;
    q.v1.tv  = 1.0f;

    q.v2.x   = (FLOAT)pos.x;
    q.v2.y   = (FLOAT)pos.y;
    q.v2.z   = 0.0f;
    q.v2.rhw = 1.0f;
    q.v2.tu  = 0.0f;
    q.v2.tv  = 0.0f;

    q.v3.x = (FLOAT)size.x + (FLOAT)pos.x;;
    q.v3.y = (FLOAT)size.y + (FLOAT)pos.y;;
    q.v3.z = 0.0f;
    q.v3.rhw = 1.0f;
    q.v3.tu = 1.0f;
    q.v3.tv = 1.0f;

    q.v4.x = (FLOAT)size.x + (FLOAT)pos.x;;
    q.v4.y = (FLOAT)pos.y;
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

    _RenderContextImpl->Context.Device->SetStreamSource(0, _VertexBuffer, 0, sizeof(VertexType));
    _RenderContextImpl->Context.Device->SetFVF(D3DFVF_CUSTOMVERTEX);

    _RenderContextImpl->Context.Device->SetTexture(0, (LPDIRECT3DBASETEXTURE9)image->GetTextureImpl()->Texture());
    _RenderContextImpl->Context.Device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
    _RenderContextImpl->Context.Device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
    _RenderContextImpl->Context.Device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
    _RenderContextImpl->Context.Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
    _RenderContextImpl->Context.Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
    _RenderContextImpl->Context.Device->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

void RenderImpl::Draw(Texture* image, const Vec2u& pos)
{
	Draw(image, pos, image->Size());
}

void RenderImpl::Draw(Surface* image, const Vec2u& pos, const Vec2u& size)
{
}

void RenderImpl::Draw(Surface* image, const Vec2u& pos)
{
}

void RenderImpl::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImpl::Initialization()
{
    _RenderContextImpl->Context.Direct = Direct3DCreate9(D3D_SDK_VERSION);

    if (_RenderContextImpl->Context.Direct == NULL)
        throw LDL::Core::RuntimeError("Direct3DCreate9 failed");

    HRESULT result = NULL;

    D3DDISPLAYMODE displayMode = { 0 };

    result = _RenderContextImpl->Context.Direct->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &displayMode);

    if (FAILED(result))
        throw LDL::Core::RuntimeError("GetAdapterDisplayMode failed");

    D3DPRESENT_PARAMETERS parameters;

    ZeroMemory(&parameters, sizeof(parameters));

    parameters.hDeviceWindow = _Window->GetWindowImpl()->Hwnd();
    parameters.Windowed = true;
    parameters.BackBufferWidth = (UINT)_Window->Size().x;
    parameters.BackBufferHeight = (UINT)_Window->Size().y;
    parameters.BackBufferCount = 1;
    parameters.EnableAutoDepthStencil = true;
    parameters.AutoDepthStencilFormat = D3DFMT_D16;
    parameters.SwapEffect = D3DSWAPEFFECT_FLIP;
    parameters.BackBufferFormat = displayMode.Format;
    parameters.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
    parameters.FullScreen_RefreshRateInHz = 0;

    result = _RenderContextImpl->Context.Direct->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, _Window->GetWindowImpl()->Hwnd(), D3DCREATE_HARDWARE_VERTEXPROCESSING, &parameters, &_RenderContextImpl->Context.Device);

    if (FAILED(result))
        throw LDL::Core::RuntimeError("CreateDevice failed");

    result = D3DXCreateLine(_RenderContextImpl->Context.Device, &_Line);

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

    if (_RenderContextImpl->Context.Device != NULL)
    {
        _RenderContextImpl->Context.Device->Release();
        _RenderContextImpl->Context.Device = NULL;
    }

    if (_RenderContextImpl->Context.Direct != NULL)
    {
        _RenderContextImpl->Context.Direct->Release();
        _RenderContextImpl->Context.Direct = NULL;
    }
}