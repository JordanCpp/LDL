/*==========================================================================;
 *
 *  Copyright (C) 1995-1998 Microsoft Corporation.  All Rights Reserved.
 *
 *  File:   d3d.h
 *  Content:    Direct3D include file
 *
 ****************************************************************************/
#ifndef LDL_DirectX_DirectX6_d3d_hpp
#define LDL_DirectX_DirectX6_d3d_hpp

#include <LDL/APIs/DirectX6/d3dcaps.hpp>

namespace LDL
{
    namespace DirectX6
    {
        /*
         * Interface IID's
         */
       
        const GUID  IID_IDirect3D = { 0x3BBA0080, 0x2421, 0x11CF, 0xA3, 0x1A, 0x00, 0xAA, 0x00, 0xB9, 0x33, 0x56 };
        const GUID  IID_IDirect3D2 = { 0x6aae1ec1, 0x662a, 0x11d0, 0x88, 0x9d, 0x00, 0xaa, 0x00, 0xbb, 0xb7, 0x6a };
        const GUID  IID_IDirect3D3 = { 0xbb223240, 0xe72b, 0x11d0, 0xa9, 0xb4, 0x00, 0xaa, 0x00, 0xc0, 0x99, 0x3e };

        const GUID  IID_IDirect3DRampDevice = { 0xF2086B20, 0x259F, 0x11CF, 0xA3, 0x1A, 0x00, 0xAA, 0x00, 0xB9, 0x33, 0x56 };
        const GUID  IID_IDirect3DRGBDevice = { 0xA4665C60, 0x2673, 0x11CF, 0xA3, 0x1A, 0x00, 0xAA, 0x00, 0xB9, 0x33, 0x56 };
        const GUID  IID_IDirect3DHALDevice = { 0x84E63dE0, 0x46AA, 0x11CF, 0x81, 0x6F, 0x00, 0x00, 0xC0, 0x20, 0x15, 0x6E };
        const GUID  IID_IDirect3DMMXDevice = { 0x881949a1, 0xd6f3, 0x11d0, 0x89, 0xab, 0x00, 0xa0, 0xc9, 0x05, 0x41, 0x29 };

        const GUID  IID_IDirect3DRefDevice = { 0x50936643, 0x13e9, 0x11d1, 0x89, 0xaa, 0x0, 0xa0, 0xc9, 0x5, 0x41, 0x29 };
        const GUID  IID_IDirect3DNullDevice = { 0x8767df22, 0xbacc, 0x11d1, 0x89, 0x69, 0x0, 0xa0, 0xc9, 0x6, 0x29, 0xa8 };

        /*
         * Internal Guid to distinguish requested MMX from MMX being used as an RGB rasterizer
         */

        const GUID  IID_IDirect3DDevice = { 0x64108800, 0x957d, 0X11d0, 0x89, 0xab, 0x00, 0xa0, 0xc9, 0x05, 0x41, 0x29 };
        const GUID  IID_IDirect3DDevice2 = { 0x93281501, 0x8cf8, 0x11d0, 0x89, 0xab, 0x0, 0xa0, 0xc9, 0x5, 0x41, 0x29 };
        const GUID  IID_IDirect3DDevice3 = { 0xb0ab3b60, 0x33d7, 0x11d1, 0xa9, 0x81, 0x0, 0xc0, 0x4f, 0xd7, 0xb1, 0x74 };

        const GUID  IID_IDirect3DTexture = { 0x2CDCD9E0, 0x25A0, 0x11CF, 0xA3, 0x1A, 0x00, 0xAA, 0x00, 0xB9, 0x33, 0x56 };
        const GUID  IID_IDirect3DTexture2 = { 0x93281502, 0x8cf8, 0x11d0, 0x89, 0xab, 0x0, 0xa0, 0xc9, 0x5, 0x41, 0x29 };
        const GUID  IID_IDirect3DLight = { 0x4417C142, 0x33AD, 0x11CF, 0x81, 0x6F, 0x00, 0x00, 0xC0, 0x20, 0x15, 0x6E };
        const GUID  IID_IDirect3DMaterial = { 0x4417C144, 0x33AD, 0x11CF, 0x81, 0x6F, 0x00, 0x00, 0xC0, 0x20, 0x15, 0x6E };
        const GUID  IID_IDirect3DMaterial2 = { 0x93281503, 0x8cf8, 0x11d0, 0x89, 0xab, 0x0, 0xa0, 0xc9, 0x5, 0x41, 0x29 };
        const GUID  IID_IDirect3DMaterial3 = { 0xca9c46f4, 0xd3c5, 0x11d1, 0xb7, 0x5a, 0x0, 0x60, 0x8, 0x52, 0xb3, 0x12 };
        const GUID  IID_IDirect3DExecuteBuffer = { 0x4417C145, 0x33AD, 0x11CF, 0x81, 0x6F, 0x00, 0x00, 0xC0, 0x20, 0x15, 0x6E };
        const GUID  IID_IDirect3DViewport = { 0x4417C146, 0x33AD, 0x11CF, 0x81, 0x6F, 0x00, 0x00, 0xC0, 0x20, 0x15, 0x6E };
        const GUID  IID_IDirect3DViewport2 = { 0x93281500, 0x8cf8, 0x11d0, 0x89, 0xab, 0x0, 0xa0, 0xc9, 0x5, 0x41, 0x29 };
        const GUID  IID_IDirect3DViewport3 = { 0xb0ab3b61, 0x33d7, 0x11d1, 0xa9, 0x81, 0x0, 0xc0, 0x4f, 0xd7, 0xb1, 0x74 };
        const GUID  IID_IDirect3DVertexBuffer = { 0x7a503555, 0x4a83, 0x11d1, 0xa5, 0xdb, 0x0, 0xa0, 0xc9, 0x3, 0x67, 0xf8 };

         struct IDirect3D;
         struct IDirect3D2;
         struct IDirect3D3;
         struct IDirect3DDevice;
         struct IDirect3DDevice2;
         struct IDirect3DDevice3;
         struct IDirect3DExecuteBuffer;
         struct IDirect3DLight;
         struct IDirect3DMaterial;
         struct IDirect3DMaterial2;
         struct IDirect3DMaterial3;
         struct IDirect3DTexture;
         struct IDirect3DTexture2;
         struct IDirect3DViewport;
         struct IDirect3DViewport2;
         struct IDirect3DViewport3;
         struct IDirect3DVertexBuffer;
         typedef struct IDirect3D* LPDIRECT3D;
         typedef struct IDirect3D2* LPDIRECT3D2;
         typedef struct IDirect3D3* LPDIRECT3D3;
         typedef struct IDirect3DDevice* LPDIRECT3DDEVICE;
         typedef struct IDirect3DDevice2* LPDIRECT3DDEVICE2;
         typedef struct IDirect3DDevice3* LPDIRECT3DDEVICE3;
         typedef struct IDirect3DExecuteBuffer* LPDIRECT3DEXECUTEBUFFER;
         typedef struct IDirect3DLight* LPDIRECT3DLIGHT;
         typedef struct IDirect3DMaterial* LPDIRECT3DMATERIAL;
         typedef struct IDirect3DMaterial2* LPDIRECT3DMATERIAL2;
         typedef struct IDirect3DMaterial3* LPDIRECT3DMATERIAL3;
         typedef struct IDirect3DTexture* LPDIRECT3DTEXTURE;
         typedef struct IDirect3DTexture2* LPDIRECT3DTEXTURE2;
         typedef struct IDirect3DViewport* LPDIRECT3DVIEWPORT;
         typedef struct IDirect3DViewport2* LPDIRECT3DVIEWPORT2;
         typedef struct IDirect3DViewport3* LPDIRECT3DVIEWPORT3;
         typedef struct IDirect3DVertexBuffer* LPDIRECT3DVERTEXBUFFER;

         /*
          * Direct3D interfaces
          */
         struct IDirect3D: IUnknown
         {
             /*** IUnknown methods ***/
             virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
             virtual ULONG LDL_CALL AddRef() = 0;
             virtual ULONG LDL_CALL Release() = 0;

             /*** IDirect3D methods ***/
             virtual HRESULT LDL_CALL Initialize(const IID &) = 0;
             virtual HRESULT LDL_CALL EnumDevices(LPD3DENUMDEVICESCALLBACK, LPVOID) = 0;
             virtual HRESULT LDL_CALL CreateLight(LPDIRECT3DLIGHT*, IUnknown*) = 0;
             virtual HRESULT LDL_CALL CreateMaterial(LPDIRECT3DMATERIAL*, IUnknown*) = 0;
             virtual HRESULT LDL_CALL CreateViewport(LPDIRECT3DVIEWPORT*, IUnknown*) = 0;
             virtual HRESULT LDL_CALL FindDevice(LPD3DFINDDEVICESEARCH, LPD3DFINDDEVICERESULT) = 0;
};

         typedef struct IDirect3D* LPDIRECT3D;

         struct IDirect3D2: IUnknown
         {
             /*** IUnknown methods ***/
             virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
             virtual ULONG LDL_CALL AddRef() = 0;
             virtual ULONG LDL_CALL Release() = 0;

             /*** IDirect3D2 methods ***/
             virtual HRESULT LDL_CALL EnumDevices(LPD3DENUMDEVICESCALLBACK, LPVOID) = 0;
             virtual HRESULT LDL_CALL CreateLight(LPDIRECT3DLIGHT*, IUnknown*) = 0;
             virtual HRESULT LDL_CALL CreateMaterial(LPDIRECT3DMATERIAL2*, IUnknown*) = 0;
             virtual HRESULT LDL_CALL CreateViewport(LPDIRECT3DVIEWPORT2*, IUnknown*) = 0;
             virtual HRESULT LDL_CALL FindDevice(LPD3DFINDDEVICESEARCH, LPD3DFINDDEVICERESULT) = 0;
             virtual HRESULT LDL_CALL CreateDevice(const IID &, LPDIRECTDRAWSURFACE, LPDIRECT3DDEVICE2*) = 0;
};

         typedef struct IDirect3D2* LPDIRECT3D2;

         struct IDirect3D3: IUnknown
         {
             /*** IUnknown methods ***/
             virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
             virtual ULONG LDL_CALL AddRef() = 0;
             virtual ULONG LDL_CALL Release() = 0;

             /*** IDirect3D3 methods ***/
             virtual HRESULT LDL_CALL EnumDevices(LPD3DENUMDEVICESCALLBACK, LPVOID) = 0;
             virtual HRESULT LDL_CALL CreateLight(LPDIRECT3DLIGHT*, LPUNKNOWN) = 0;
             virtual HRESULT LDL_CALL CreateMaterial(LPDIRECT3DMATERIAL3*, LPUNKNOWN) = 0;
             virtual HRESULT LDL_CALL CreateViewport(LPDIRECT3DVIEWPORT3*, LPUNKNOWN) = 0;
             virtual HRESULT LDL_CALL FindDevice(LPD3DFINDDEVICESEARCH, LPD3DFINDDEVICERESULT) = 0;
             virtual HRESULT LDL_CALL CreateDevice(const IID &, LPDIRECTDRAWSURFACE4, LPDIRECT3DDEVICE3*, LPUNKNOWN) = 0;
             virtual HRESULT LDL_CALL CreateVertexBuffer(LPD3DVERTEXBUFFERDESC, LPDIRECT3DVERTEXBUFFER*, DWORD, LPUNKNOWN) = 0;
             virtual HRESULT LDL_CALL EnumZBufferFormats(const IID &, LPD3DENUMPIXELFORMATSCALLBACK, LPVOID) = 0;
             virtual HRESULT LDL_CALL EvictManagedTextures() = 0;
};

         typedef struct IDirect3D3* LPDIRECT3D3;

         /*
          * Direct3D Device interfaces
          */
         struct IDirect3DDevice: IUnknown
         {
             /*** IUnknown methods ***/
             virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
             virtual ULONG LDL_CALL AddRef() = 0;
             virtual ULONG  LDL_CALL Release() = 0;

             /*** IDirect3DDevice methods ***/
             virtual HRESULT LDL_CALL Initialize(LPDIRECT3D, LPGUID, LPD3DDEVICEDESC) = 0;
             virtual HRESULT LDL_CALL GetCaps(LPD3DDEVICEDESC, LPD3DDEVICEDESC) = 0;
             virtual HRESULT LDL_CALL SwapTextureHandles(LPDIRECT3DTEXTURE, LPDIRECT3DTEXTURE) = 0;
             virtual HRESULT LDL_CALL CreateExecuteBuffer(LPD3DEXECUTEBUFFERDESC, LPDIRECT3DEXECUTEBUFFER*, IUnknown*) = 0;
             virtual HRESULT LDL_CALL GetStats(LPD3DSTATS) = 0;
             virtual HRESULT LDL_CALL Execute(LPDIRECT3DEXECUTEBUFFER, LPDIRECT3DVIEWPORT, DWORD) = 0;
             virtual HRESULT LDL_CALL AddViewport(LPDIRECT3DVIEWPORT) = 0;
             virtual HRESULT LDL_CALL DeleteViewport(LPDIRECT3DVIEWPORT) = 0;
             virtual HRESULT LDL_CALL NextViewport(LPDIRECT3DVIEWPORT, LPDIRECT3DVIEWPORT*, DWORD) = 0;
             virtual HRESULT LDL_CALL Pick(LPDIRECT3DEXECUTEBUFFER, LPDIRECT3DVIEWPORT, DWORD, LPD3DRECT) = 0;
             virtual HRESULT LDL_CALL GetPickRecords(LPDWORD, LPD3DPICKRECORD) = 0;
             virtual HRESULT LDL_CALL EnumTextureFormats(LPD3DENUMTEXTUREFORMATSCALLBACK, LPVOID) = 0;
             virtual HRESULT LDL_CALL CreateMatrix(LPD3DMATRIXHANDLE) = 0;
             virtual HRESULT LDL_CALL SetMatrix(D3DMATRIXHANDLE, const LPD3DMATRIX) = 0;
             virtual HRESULT LDL_CALL GetMatrix(D3DMATRIXHANDLE, LPD3DMATRIX) = 0;
             virtual HRESULT LDL_CALL DeleteMatrix(D3DMATRIXHANDLE) = 0;
             virtual HRESULT LDL_CALL BeginScene() = 0;
             virtual HRESULT LDL_CALL EndScene() = 0;
             virtual HRESULT LDL_CALL GetDirect3D(LPDIRECT3D*) = 0;
};

         typedef struct IDirect3DDevice* LPDIRECT3DDEVICE;

         struct IDirect3DDevice2: IUnknown
         {
             /*** IUnknown methods ***/
             virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
             virtual ULONG LDL_CALL AddRef() = 0;
             virtual ULONG LDL_CALL Release() = 0;

             /*** IDirect3DDevice2 methods ***/
             virtual HRESULT LDL_CALL GetCaps(LPD3DDEVICEDESC, LPD3DDEVICEDESC) = 0;
             virtual HRESULT LDL_CALL SwapTextureHandles(LPDIRECT3DTEXTURE2, LPDIRECT3DTEXTURE2) = 0;
             virtual HRESULT LDL_CALL GetStats(LPD3DSTATS) = 0;
             virtual HRESULT LDL_CALL AddViewport(LPDIRECT3DVIEWPORT2) = 0;
             virtual HRESULT LDL_CALL DeleteViewport(LPDIRECT3DVIEWPORT2) = 0;
             virtual HRESULT LDL_CALL NextViewport(LPDIRECT3DVIEWPORT2, LPDIRECT3DVIEWPORT2*, DWORD) = 0;
             virtual HRESULT LDL_CALL EnumTextureFormats(LPD3DENUMTEXTUREFORMATSCALLBACK, LPVOID) = 0;
             virtual HRESULT LDL_CALL BeginScene() = 0;
             virtual HRESULT LDL_CALL EndScene() = 0;
             virtual HRESULT LDL_CALL GetDirect3D(LPDIRECT3D2*) = 0;
             virtual HRESULT LDL_CALL SetCurrentViewport(LPDIRECT3DVIEWPORT2) = 0;
             virtual HRESULT LDL_CALL GetCurrentViewport(LPDIRECT3DVIEWPORT2*) = 0;
             virtual HRESULT LDL_CALL SetRenderTarget(LPDIRECTDRAWSURFACE, DWORD) = 0;
             virtual HRESULT LDL_CALL GetRenderTarget(LPDIRECTDRAWSURFACE*) = 0;
             virtual HRESULT LDL_CALL Begin(D3DPRIMITIVETYPE, D3DVERTEXTYPE, DWORD) = 0;
             virtual HRESULT LDL_CALL BeginIndexed(D3DPRIMITIVETYPE, D3DVERTEXTYPE, LPVOID, DWORD, DWORD) = 0;
             virtual HRESULT LDL_CALL Vertex(LPVOID) = 0;
             virtual HRESULT LDL_CALL Index(WORD) = 0;
             virtual HRESULT LDL_CALL End(DWORD) = 0;
             virtual HRESULT LDL_CALL GetRenderState(D3DRENDERSTATETYPE, LPDWORD) = 0;
             virtual HRESULT LDL_CALL SetRenderState(D3DRENDERSTATETYPE, DWORD) = 0;
             virtual HRESULT LDL_CALL GetLightState(D3DLIGHTSTATETYPE, LPDWORD) = 0;
             virtual HRESULT LDL_CALL SetLightState(D3DLIGHTSTATETYPE, DWORD) = 0;
             virtual HRESULT LDL_CALL SetTransform(D3DTRANSFORMSTATETYPE, LPD3DMATRIX) = 0;
             virtual HRESULT LDL_CALL GetTransform(D3DTRANSFORMSTATETYPE, LPD3DMATRIX) = 0;
             virtual HRESULT LDL_CALL MultiplyTransform(D3DTRANSFORMSTATETYPE, LPD3DMATRIX) = 0;
             virtual HRESULT LDL_CALL DrawPrimitive(D3DPRIMITIVETYPE, D3DVERTEXTYPE, LPVOID, DWORD, DWORD) = 0;
             virtual HRESULT LDL_CALL DrawIndexedPrimitive(D3DPRIMITIVETYPE, D3DVERTEXTYPE, LPVOID, DWORD, LPWORD, DWORD, DWORD) = 0;
             virtual HRESULT LDL_CALL SetClipStatus(LPD3DCLIPSTATUS) = 0;
             virtual HRESULT LDL_CALL GetClipStatus(LPD3DCLIPSTATUS) = 0;
};

         typedef struct IDirect3DDevice2* LPDIRECT3DDEVICE2;

         struct IDirect3DDevice3: IUnknown
         {
             /*** IUnknown methods ***/
             virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
             virtual ULONG LDL_CALL AddRef() = 0;
             virtual ULONG LDL_CALL Release() = 0;

             /*** IDirect3DDevice3 methods ***/
             virtual HRESULT LDL_CALL GetCaps(LPD3DDEVICEDESC, LPD3DDEVICEDESC) = 0;
             virtual HRESULT LDL_CALL GetStats(LPD3DSTATS) = 0;
             virtual HRESULT LDL_CALL AddViewport(LPDIRECT3DVIEWPORT3) = 0;
             virtual HRESULT LDL_CALL DeleteViewport(LPDIRECT3DVIEWPORT3) = 0;
             virtual HRESULT LDL_CALL NextViewport(LPDIRECT3DVIEWPORT3, LPDIRECT3DVIEWPORT3*, DWORD) = 0;
             virtual HRESULT LDL_CALL EnumTextureFormats(LPD3DENUMPIXELFORMATSCALLBACK, LPVOID) = 0;
             virtual HRESULT LDL_CALL BeginScene() = 0;
             virtual HRESULT LDL_CALL EndScene() = 0;
             virtual HRESULT LDL_CALL GetDirect3D(LPDIRECT3D3*) = 0;
             virtual HRESULT LDL_CALL SetCurrentViewport(LPDIRECT3DVIEWPORT3) = 0;
             virtual HRESULT LDL_CALL GetCurrentViewport(LPDIRECT3DVIEWPORT3*) = 0;
             virtual HRESULT LDL_CALL SetRenderTarget(LPDIRECTDRAWSURFACE4, DWORD) = 0;
             virtual HRESULT LDL_CALL GetRenderTarget(LPDIRECTDRAWSURFACE4*) = 0;
             virtual HRESULT LDL_CALL Begin(D3DPRIMITIVETYPE, DWORD, DWORD) = 0;
             virtual HRESULT LDL_CALL BeginIndexed(D3DPRIMITIVETYPE, DWORD, LPVOID, DWORD, DWORD) = 0;
             virtual HRESULT LDL_CALL Vertex(LPVOID) = 0;
             virtual HRESULT LDL_CALL Index(WORD) = 0;
             virtual HRESULT LDL_CALL End(DWORD) = 0;
             virtual HRESULT LDL_CALL GetRenderState(D3DRENDERSTATETYPE, LPDWORD) = 0;
             virtual HRESULT LDL_CALL SetRenderState(D3DRENDERSTATETYPE, DWORD) = 0;
             virtual HRESULT LDL_CALL GetLightState(D3DLIGHTSTATETYPE, LPDWORD) = 0;
             virtual HRESULT LDL_CALL SetLightState(D3DLIGHTSTATETYPE, DWORD) = 0;
             virtual HRESULT LDL_CALL SetTransform(D3DTRANSFORMSTATETYPE, LPD3DMATRIX) = 0;
             virtual HRESULT LDL_CALL GetTransform(D3DTRANSFORMSTATETYPE, LPD3DMATRIX) = 0;
             virtual HRESULT LDL_CALL MultiplyTransform(D3DTRANSFORMSTATETYPE, LPD3DMATRIX) = 0;
             virtual HRESULT LDL_CALL DrawPrimitive(D3DPRIMITIVETYPE, DWORD, LPVOID, DWORD, DWORD) = 0;
             virtual HRESULT LDL_CALL DrawIndexedPrimitive(D3DPRIMITIVETYPE, DWORD, LPVOID, DWORD, LPWORD, DWORD, DWORD) = 0;
             virtual HRESULT LDL_CALL SetClipStatus(LPD3DCLIPSTATUS) = 0;
             virtual HRESULT LDL_CALL GetClipStatus(LPD3DCLIPSTATUS) = 0;
             virtual HRESULT LDL_CALL DrawPrimitiveStrided(D3DPRIMITIVETYPE, DWORD, LPD3DDRAWPRIMITIVESTRIDEDDATA, DWORD, DWORD) = 0;
             virtual HRESULT LDL_CALL DrawIndexedPrimitiveStrided(D3DPRIMITIVETYPE, DWORD, LPD3DDRAWPRIMITIVESTRIDEDDATA, DWORD, LPWORD, DWORD, DWORD) = 0;
             virtual HRESULT LDL_CALL DrawPrimitiveVB(D3DPRIMITIVETYPE, LPDIRECT3DVERTEXBUFFER, DWORD, DWORD, DWORD) = 0;
             virtual HRESULT LDL_CALL DrawIndexedPrimitiveVB(D3DPRIMITIVETYPE, LPDIRECT3DVERTEXBUFFER, LPWORD, DWORD, DWORD) = 0;
             virtual HRESULT LDL_CALL ComputeSphereVisibility(LPD3DVECTOR, LPD3DVALUE, DWORD, DWORD, LPDWORD) = 0;
             virtual HRESULT LDL_CALL GetTexture(DWORD, LPDIRECT3DTEXTURE2*) = 0;
             virtual HRESULT LDL_CALL SetTexture(DWORD, LPDIRECT3DTEXTURE2) = 0;
             virtual HRESULT LDL_CALL GetTextureStageState(DWORD, D3DTEXTURESTAGESTATETYPE, LPDWORD) = 0;
             virtual HRESULT LDL_CALL SetTextureStageState(DWORD, D3DTEXTURESTAGESTATETYPE, DWORD) = 0;
             virtual HRESULT LDL_CALL ValidateDevice(LPDWORD) = 0;
};

         typedef struct IDirect3DDevice3* LPDIRECT3DDEVICE3;

         /*
          * Execute Buffer interface
          */

         struct IDirect3DExecuteBuffer: IUnknown
         {
             /*** IUnknown methods ***/
             virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
             virtual ULONG LDL_CALL AddRef() = 0;
             virtual ULONG LDL_CALL Release() = 0;

             /*** IDirect3DExecuteBuffer methods ***/
             virtual HRESULT LDL_CALL Initialize(LPDIRECT3DDEVICE, LPD3DEXECUTEBUFFERDESC) = 0;
             virtual HRESULT LDL_CALL Lock(LPD3DEXECUTEBUFFERDESC) = 0;
             virtual HRESULT LDL_CALL Unlock() = 0;
             virtual HRESULT LDL_CALL SetExecuteData(LPD3DEXECUTEDATA) = 0;
             virtual HRESULT LDL_CALL GetExecuteData(LPD3DEXECUTEDATA) = 0;
             virtual HRESULT LDL_CALL Validate(LPDWORD, LPD3DVALIDATECALLBACK, LPVOID, DWORD) = 0;
             virtual HRESULT LDL_CALL Optimize(DWORD) = 0;
};

         typedef struct IDirect3DExecuteBuffer* LPDIRECT3DEXECUTEBUFFER;

         /*
          * Light interfaces
          */

         struct IDirect3DLight: IUnknown
         {
             /*** IUnknown methods ***/
             virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
             virtual ULONG LDL_CALL AddRef() = 0;
             virtual ULONG LDL_CALL Release() = 0;

             /*** IDirect3DLight methods ***/
             virtual HRESULT LDL_CALL Initialize(LPDIRECT3D) = 0;
             virtual HRESULT LDL_CALL SetLight(LPD3DLIGHT) = 0;
             virtual HRESULT LDL_CALL GetLight(LPD3DLIGHT) = 0;
};

         typedef struct IDirect3DLight* LPDIRECT3DLIGHT;

         /*
          * Material interfaces
          */
         struct IDirect3DMaterial: IUnknown
         {
             /*** IUnknown methods ***/
             virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
             virtual ULONG LDL_CALL AddRef() = 0;
             virtual ULONG LDL_CALL Release() = 0;

             /*** IDirect3DMaterial methods ***/
             virtual HRESULT LDL_CALL Initialize(LPDIRECT3D) = 0;
             virtual HRESULT LDL_CALL SetMaterial(LPD3DMATERIAL) = 0;
             virtual HRESULT LDL_CALL GetMaterial(LPD3DMATERIAL) = 0;
             virtual HRESULT LDL_CALL GetHandle(LPDIRECT3DDEVICE, LPD3DMATERIALHANDLE) = 0;
             virtual HRESULT LDL_CALL Reserve() = 0;
             virtual HRESULT LDL_CALL Unreserve() = 0;
};

         typedef struct IDirect3DMaterial* LPDIRECT3DMATERIAL;

         struct IDirect3DMaterial2: IUnknown
         {
             /*** IUnknown methods ***/
             virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
             virtual ULONG LDL_CALL AddRef() = 0;
             virtual ULONG LDL_CALL Release() = 0;

             /*** IDirect3DMaterial2 methods ***/
             virtual HRESULT LDL_CALL SetMaterial(LPD3DMATERIAL) = 0;
             virtual HRESULT LDL_CALL GetMaterial(LPD3DMATERIAL) = 0;
             virtual HRESULT LDL_CALL GetHandle(LPDIRECT3DDEVICE2, LPD3DMATERIALHANDLE) = 0;
};

         typedef struct IDirect3DMaterial2* LPDIRECT3DMATERIAL2;

         struct IDirect3DMaterial3: IUnknown
         {
             /*** IUnknown methods ***/
             virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
             virtual ULONG LDL_CALL AddRef() = 0;
             virtual ULONG LDL_CALL Release() = 0;

             /*** IDirect3DMaterial3 methods ***/
             virtual HRESULT LDL_CALL SetMaterial(LPD3DMATERIAL) = 0;
             virtual HRESULT LDL_CALL GetMaterial(LPD3DMATERIAL) = 0;
             virtual HRESULT LDL_CALL GetHandle(LPDIRECT3DDEVICE3, LPD3DMATERIALHANDLE) = 0;
};

         typedef struct IDirect3DMaterial3* LPDIRECT3DMATERIAL3;

         /*
          * Texture interfaces
          */
         struct IDirect3DTexture: IUnknown
         {
             /*** IUnknown methods ***/
             virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
             virtual ULONG LDL_CALL AddRef() = 0;
             virtual ULONG LDL_CALL Release() = 0;

             /*** IDirect3DTexture methods ***/
             virtual HRESULT LDL_CALL Initialize(LPDIRECT3DDEVICE, LPDIRECTDRAWSURFACE) = 0;
             virtual HRESULT LDL_CALL GetHandle(LPDIRECT3DDEVICE, LPD3DTEXTUREHANDLE) = 0;
             virtual HRESULT LDL_CALL PaletteChanged(DWORD, DWORD) = 0;
             virtual HRESULT LDL_CALL Load(LPDIRECT3DTEXTURE) = 0;
             virtual HRESULT LDL_CALL Unload() = 0;
};

         typedef struct IDirect3DTexture* LPDIRECT3DTEXTURE;

         struct IDirect3DTexture2: IUnknown
         {
             /*** IUnknown methods ***/
             virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
             virtual ULONG LDL_CALL AddRef() = 0;
             virtual ULONG LDL_CALL Release() = 0;

             /*** IDirect3DTexture2 methods ***/
             virtual HRESULT LDL_CALL GetHandle(LPDIRECT3DDEVICE2, LPD3DTEXTUREHANDLE) = 0;
             virtual HRESULT LDL_CALL PaletteChanged(DWORD, DWORD) = 0;
             virtual HRESULT LDL_CALL Load(LPDIRECT3DTEXTURE2) = 0;
};

         typedef struct IDirect3DTexture2* LPDIRECT3DTEXTURE2;

         /*
          * Viewport interfaces
          */
         struct IDirect3DViewport: IUnknown
         {
             /*** IUnknown methods ***/
             virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
             virtual ULONG LDL_CALL AddRef() = 0;
             virtual ULONG LDL_CALL Release() = 0;

             /*** IDirect3DViewport methods ***/
             virtual HRESULT LDL_CALL Initialize(LPDIRECT3D) = 0;
             virtual HRESULT LDL_CALL GetViewport(LPD3DVIEWPORT) = 0;
             virtual HRESULT LDL_CALL SetViewport(LPD3DVIEWPORT) = 0;
             virtual HRESULT LDL_CALL TransformVertices(DWORD, LPD3DTRANSFORMDATA, DWORD, LPDWORD) = 0;
             virtual HRESULT LDL_CALL LightElements(DWORD, LPD3DLIGHTDATA) = 0;
             virtual HRESULT LDL_CALL SetBackground(D3DMATERIALHANDLE) = 0;
             virtual HRESULT LDL_CALL GetBackground(LPD3DMATERIALHANDLE, LPBOOL) = 0;
             virtual HRESULT LDL_CALL SetBackgroundDepth(LPDIRECTDRAWSURFACE) = 0;
             virtual HRESULT LDL_CALL GetBackgroundDepth(LPDIRECTDRAWSURFACE*, LPBOOL) = 0;
             virtual HRESULT LDL_CALL Clear(DWORD, LPD3DRECT, DWORD) = 0;
             virtual HRESULT LDL_CALL AddLight(LPDIRECT3DLIGHT) = 0;
             virtual HRESULT LDL_CALL DeleteLight(LPDIRECT3DLIGHT) = 0;
             virtual HRESULT LDL_CALL NextLight(LPDIRECT3DLIGHT, LPDIRECT3DLIGHT*, DWORD) = 0;
};

         typedef struct IDirect3DViewport* LPDIRECT3DVIEWPORT;

         struct IDirect3DViewport2: IDirect3DViewport
         {
             /*** IUnknown methods ***/
             virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
             virtual ULONG LDL_CALL AddRef() = 0;
             virtual ULONG LDL_CALL Release() = 0;

             /*** IDirect3DViewport methods ***/
             virtual HRESULT LDL_CALL Initialize(LPDIRECT3D) = 0;
             virtual HRESULT LDL_CALL GetViewport(LPD3DVIEWPORT) = 0;
             virtual HRESULT LDL_CALL SetViewport(LPD3DVIEWPORT) = 0;
             virtual HRESULT LDL_CALL TransformVertices(DWORD, LPD3DTRANSFORMDATA, DWORD, LPDWORD) = 0;
             virtual HRESULT LDL_CALL LightElements(DWORD, LPD3DLIGHTDATA) = 0;
             virtual HRESULT LDL_CALL SetBackground(D3DMATERIALHANDLE) = 0;
             virtual HRESULT LDL_CALL GetBackground(LPD3DMATERIALHANDLE, LPBOOL) = 0;
             virtual HRESULT LDL_CALL SetBackgroundDepth(LPDIRECTDRAWSURFACE) = 0;
             virtual HRESULT LDL_CALL GetBackgroundDepth(LPDIRECTDRAWSURFACE*, LPBOOL) = 0;
             virtual HRESULT LDL_CALL Clear(DWORD, LPD3DRECT, DWORD) = 0;
             virtual HRESULT LDL_CALL AddLight(LPDIRECT3DLIGHT) = 0;
             virtual HRESULT LDL_CALL DeleteLight(LPDIRECT3DLIGHT) = 0;
             virtual HRESULT LDL_CALL NextLight(LPDIRECT3DLIGHT, LPDIRECT3DLIGHT*, DWORD) = 0;
             virtual HRESULT LDL_CALL GetViewport2(LPD3DVIEWPORT2) = 0;
             virtual HRESULT LDL_CALL SetViewport2(LPD3DVIEWPORT2) = 0;
};

         typedef struct IDirect3DViewport2* LPDIRECT3DVIEWPORT2;

         struct IDirect3DViewport3: IDirect3DViewport2
         {
             /*** IUnknown methods ***/
             virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
             virtual ULONG LDL_CALL AddRef() = 0;
             virtual ULONG LDL_CALL Release() = 0;

             /*** IDirect3DViewport2 methods ***/
             virtual HRESULT LDL_CALL Initialize(LPDIRECT3D) = 0;
             virtual HRESULT LDL_CALL GetViewport(LPD3DVIEWPORT) = 0;
             virtual HRESULT LDL_CALL SetViewport(LPD3DVIEWPORT) = 0;
             virtual HRESULT LDL_CALL TransformVertices(DWORD, LPD3DTRANSFORMDATA, DWORD, LPDWORD) = 0;
             virtual HRESULT LDL_CALL LightElements(DWORD, LPD3DLIGHTDATA) = 0;
             virtual HRESULT LDL_CALL SetBackground(D3DMATERIALHANDLE) = 0;
             virtual HRESULT LDL_CALL GetBackground(LPD3DMATERIALHANDLE, LPBOOL) = 0;
             virtual HRESULT LDL_CALL SetBackgroundDepth(LPDIRECTDRAWSURFACE) = 0;
             virtual HRESULT LDL_CALL GetBackgroundDepth(LPDIRECTDRAWSURFACE*, LPBOOL) = 0;
             virtual HRESULT LDL_CALL Clear(DWORD, LPD3DRECT, DWORD) = 0;
             virtual HRESULT LDL_CALL AddLight(LPDIRECT3DLIGHT) = 0;
             virtual HRESULT LDL_CALL DeleteLight(LPDIRECT3DLIGHT) = 0;
             virtual HRESULT LDL_CALL NextLight(LPDIRECT3DLIGHT, LPDIRECT3DLIGHT*, DWORD) = 0;
             virtual HRESULT LDL_CALL GetViewport2(LPD3DVIEWPORT2) = 0;
             virtual HRESULT LDL_CALL SetViewport2(LPD3DVIEWPORT2) = 0;
             virtual HRESULT LDL_CALL SetBackgroundDepth2(LPDIRECTDRAWSURFACE4) = 0;
             virtual HRESULT LDL_CALL GetBackgroundDepth2(LPDIRECTDRAWSURFACE4*, LPBOOL) = 0;
             virtual HRESULT LDL_CALL Clear2(DWORD, LPD3DRECT, DWORD, D3DCOLOR, D3DVALUE, DWORD) = 0;
};

         typedef struct IDirect3DViewport3* LPDIRECT3DVIEWPORT3;

         struct IDirect3DVertexBuffer: IUnknown
         {
             /*** IUnknown methods ***/
             virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
             virtual ULONG LDL_CALL AddRef() = 0;
             virtual ULONG LDL_CALL Release() = 0;

             /*** IDirect3DVertexBuffer methods ***/
             virtual HRESULT LDL_CALL Lock(DWORD, LPVOID*, LPDWORD) = 0;
             virtual HRESULT LDL_CALL Unlock() = 0;
             virtual HRESULT LDL_CALL ProcessVertices(DWORD, DWORD, DWORD, LPDIRECT3DVERTEXBUFFER, DWORD, LPDIRECT3DDEVICE3, DWORD) = 0;
             virtual HRESULT LDL_CALL GetVertexBufferDesc(LPD3DVERTEXBUFFERDESC) = 0;
             virtual HRESULT LDL_CALL Optimize(LPDIRECT3DDEVICE3, DWORD) = 0;
};

         typedef struct IDirect3DVertexBuffer* LPDIRECT3DVERTEXBUFFER;

         /****************************************************************************
          *
          * Flags for IDirect3DDevice::NextViewport
          *
          ****************************************************************************/

          /*
           * Return the next viewport
           */
         const DWORD  D3DNEXT_NEXT = 0x00000001l;

             /*
              * Return the first viewport
              */
         const DWORD  D3DNEXT_HEAD = 0x00000002l;

             /*
              * Return the last viewport
              */
         const DWORD  D3DNEXT_TAIL = 0x00000004l;


             /****************************************************************************
              *
              * Flags for DrawPrimitive/DrawIndexedPrimitive
              *   Also valid for Begin/BeginIndexed
              *   Also valid for VertexBuffer::CreateVertexBuffer
              ****************************************************************************/

              /*
               * Wait until the device is ready to draw the primitive
               * This will cause DP to not return DDERR_WASSTILLDRAWING
               */
         const DWORD  D3DDP_WAIT = 0x00000001l;


             /*
              * Hint that the primitives have been clipped by the application.
              */
         const DWORD  D3DDP_DONOTCLIP = 0x00000004l;

             /*
              * Hint that the extents need not be updated.
              */
         const DWORD  D3DDP_DONOTUPDATEEXTENTS = 0x00000008l;


             /*
              * Hint that the lighting should not be applied on vertices.
              */

         const DWORD  D3DDP_DONOTLIGHT = 0x00000010l;


             /*
              * Direct3D Errors
              * DirectDraw error codes are used when errors not specified here.
              */
         const DWORD  D3D_OK = DD_OK;
         const DWORD  D3DERR_BADMAJORVERSION = MAKE_DDHRESULT(700);
         const DWORD  D3DERR_BADMINORVERSION = MAKE_DDHRESULT(701);

             /*
              * An invalid device was requested by the application.
              */
         const DWORD  D3DERR_INVALID_DEVICE = MAKE_DDHRESULT(705);
         const DWORD  D3DERR_INITFAILED = MAKE_DDHRESULT(706);

             /*
              * SetRenderTarget attempted on a device that was
              * QI'd off the render target.
              */
         const DWORD  D3DERR_DEVICEAGGREGATED = MAKE_DDHRESULT(707);

         const DWORD  D3DERR_EXECUTE_CREATE_FAILED = MAKE_DDHRESULT(710);
         const DWORD  D3DERR_EXECUTE_DESTROY_FAILED = MAKE_DDHRESULT(711);
         const DWORD  D3DERR_EXECUTE_LOCK_FAILED = MAKE_DDHRESULT(712);
         const DWORD  D3DERR_EXECUTE_UNLOCK_FAILED = MAKE_DDHRESULT(713);
         const DWORD  D3DERR_EXECUTE_LOCKED = MAKE_DDHRESULT(714);
         const DWORD  D3DERR_EXECUTE_NOT_LOCKED = MAKE_DDHRESULT(715);

         const DWORD  D3DERR_EXECUTE_FAILED = MAKE_DDHRESULT(716);
         const DWORD  D3DERR_EXECUTE_CLIPPED_FAILED = MAKE_DDHRESULT(717);

         const DWORD  D3DERR_TEXTURE_NO_SUPPORT = MAKE_DDHRESULT(720);
         const DWORD  D3DERR_TEXTURE_CREATE_FAILED = MAKE_DDHRESULT(721);
         const DWORD  D3DERR_TEXTURE_DESTROY_FAILED = MAKE_DDHRESULT(722);
         const DWORD  D3DERR_TEXTURE_LOCK_FAILED = MAKE_DDHRESULT(723);
         const DWORD  D3DERR_TEXTURE_UNLOCK_FAILED = MAKE_DDHRESULT(724);
         const DWORD  D3DERR_TEXTURE_LOAD_FAILED = MAKE_DDHRESULT(725);
         const DWORD  D3DERR_TEXTURE_SWAP_FAILED = MAKE_DDHRESULT(726);
         const DWORD  D3DERR_TEXTURE_LOCKED = MAKE_DDHRESULT(727);
         const DWORD  D3DERR_TEXTURE_NOT_LOCKED = MAKE_DDHRESULT(728);
         const DWORD  D3DERR_TEXTURE_GETSURF_FAILED = MAKE_DDHRESULT(729);

         const DWORD  D3DERR_MATRIX_CREATE_FAILED = MAKE_DDHRESULT(730);
         const DWORD  D3DERR_MATRIX_DESTROY_FAILED = MAKE_DDHRESULT(731);
         const DWORD  D3DERR_MATRIX_SETDATA_FAILED = MAKE_DDHRESULT(732);
         const DWORD  D3DERR_MATRIX_GETDATA_FAILED = MAKE_DDHRESULT(733);
         const DWORD  D3DERR_SETVIEWPORTDATA_FAILED = MAKE_DDHRESULT(734);

         const DWORD  D3DERR_INVALIDCURRENTVIEWPORT = MAKE_DDHRESULT(735);
         const DWORD  D3DERR_INVALIDPRIMITIVETYPE = MAKE_DDHRESULT(736);
         const DWORD  D3DERR_INVALIDVERTEXTYPE = MAKE_DDHRESULT(737);
         const DWORD  D3DERR_TEXTURE_BADSIZE = MAKE_DDHRESULT(738);
         const DWORD  D3DERR_INVALIDRAMPTEXTURE = MAKE_DDHRESULT(739);

         const DWORD  D3DERR_MATERIAL_CREATE_FAILED = MAKE_DDHRESULT(740);
         const DWORD  D3DERR_MATERIAL_DESTROY_FAILED = MAKE_DDHRESULT(741);
         const DWORD  D3DERR_MATERIAL_SETDATA_FAILED = MAKE_DDHRESULT(742);
         const DWORD  D3DERR_MATERIAL_GETDATA_FAILED = MAKE_DDHRESULT(743);

         const DWORD  D3DERR_INVALIDPALETTE = MAKE_DDHRESULT(744);

         const DWORD  D3DERR_ZBUFF_NEEDS_SYSTEMMEMORY = MAKE_DDHRESULT(745);
         const DWORD  D3DERR_ZBUFF_NEEDS_VIDEOMEMORY = MAKE_DDHRESULT(746);
         const DWORD  D3DERR_SURFACENOTINVIDMEM = MAKE_DDHRESULT(747);

         const DWORD  D3DERR_LIGHT_SET_FAILED = MAKE_DDHRESULT(750);
         const DWORD  D3DERR_LIGHTHASVIEWPORT = MAKE_DDHRESULT(751);
         const DWORD  D3DERR_LIGHTNOTINVIEWPORT = MAKE_DDHRESULT(752);

         const DWORD  D3DERR_SCENE_IN_SCENE = MAKE_DDHRESULT(760);
         const DWORD  D3DERR_SCENE_NOT_IN_SCENE = MAKE_DDHRESULT(761);
         const DWORD  D3DERR_SCENE_BEGIN_FAILED = MAKE_DDHRESULT(762);
         const DWORD  D3DERR_SCENE_END_FAILED = MAKE_DDHRESULT(763);

         const DWORD  D3DERR_INBEGIN = MAKE_DDHRESULT(770);
         const DWORD  D3DERR_NOTINBEGIN = MAKE_DDHRESULT(771);
         const DWORD  D3DERR_NOVIEWPORTS = MAKE_DDHRESULT(772);
         const DWORD  D3DERR_VIEWPORTDATANOTSET = MAKE_DDHRESULT(773);
         const DWORD  D3DERR_VIEWPORTHASNODEVICE = MAKE_DDHRESULT(774);
         const DWORD  D3DERR_NOCURRENTVIEWPORT = MAKE_DDHRESULT(775);

         const DWORD  D3DERR_INVALIDVERTEXFORMAT = MAKE_DDHRESULT(2048);

             /*
              * Attempted to CreateTexture on a surface that had a color key
              */
         const DWORD  D3DERR_COLORKEYATTACHED = MAKE_DDHRESULT(2050);

         const DWORD  D3DERR_VERTEXBUFFEROPTIMIZED = MAKE_DDHRESULT(2060);
         const DWORD  D3DERR_VBUF_CREATE_FAILED = MAKE_DDHRESULT(2061);
         const DWORD  D3DERR_VERTEXBUFFERLOCKED = MAKE_DDHRESULT(2062);

         const DWORD  D3DERR_ZBUFFER_NOTPRESENT = MAKE_DDHRESULT(2070);
         const DWORD  D3DERR_STENCILBUFFER_NOTPRESENT = MAKE_DDHRESULT(2071);

         const DWORD  D3DERR_WRONGTEXTUREFORMAT = MAKE_DDHRESULT(2072);
         const DWORD  D3DERR_UNSUPPORTEDCOLOROPERATION = MAKE_DDHRESULT(2073);
         const DWORD  D3DERR_UNSUPPORTEDCOLORARG = MAKE_DDHRESULT(2074);
         const DWORD  D3DERR_UNSUPPORTEDALPHAOPERATION = MAKE_DDHRESULT(2075);
         const DWORD  D3DERR_UNSUPPORTEDALPHAARG = MAKE_DDHRESULT(2076);
         const DWORD  D3DERR_TOOMANYOPERATIONS = MAKE_DDHRESULT(2077);
         const DWORD  D3DERR_CONFLICTINGTEXTUREFILTER = MAKE_DDHRESULT(2078);
         const DWORD  D3DERR_UNSUPPORTEDFACTORVALUE = MAKE_DDHRESULT(2079);
         const DWORD  D3DERR_CONFLICTINGRENDERSTATE = MAKE_DDHRESULT(2081);
         const DWORD  D3DERR_UNSUPPORTEDTEXTUREFILTER = MAKE_DDHRESULT(2082);
         const DWORD  D3DERR_TOOMANYPRIMITIVES = MAKE_DDHRESULT(2083);
         const DWORD  D3DERR_INVALIDMATRIX = MAKE_DDHRESULT(2084);
         const DWORD  D3DERR_TOOMANYVERTICES = MAKE_DDHRESULT(2085);
         const DWORD  D3DERR_CONFLICTINGTEXTUREPALETTE = MAKE_DDHRESULT(2086);

    }
}

#endif /* _D3D_H_ */

