// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_DirectX_DirectDraw_hpp
#define LDL_DirectX_DirectDraw_hpp

#include "DirectX.hpp"

/*
 * app wants to work as a regular Windows application
 */
#define DDSCL_NORMAL                            0x00000008l 

 /*
  * ddsCaps field is valid.
  */
#define DDSD_CAPS               0x00000000l     // default 

  /*
   * Indicates that this surface is the primary surface.  The primary
   * surface represents what the user is seeing at the moment.
   */
#define DDSCAPS_PRIMARYSURFACE                  0x00000200l

   /*
    * Indicates that this surface is a backbuffer.  It is generally
    * set by CreateSurface when the DDSCAPS_FLIP capability bit is set.
    * It indicates that this surface is THE back buffer of a surface
    * flipping structure.  DirectDraw supports N surfaces in a
    * surface flipping structure.  Only the surface that immediately
    * precedeces the DDSCAPS_FRONTBUFFER has this capability bit set.
    * The other surfaces are identified as back buffers by the presence
    * of the DDSCAPS_FLIP capability, their attachment order, and the
    * absence of the DDSCAPS_FRONTBUFFER and DDSCAPS_BACKBUFFER
    * capabilities.  The bit is sent to CreateSurface when a standalone
    * back buffer is being created.  This surface could be attached to
    * a front buffer and/or back buffers to form a flipping surface
    * structure after the CreateSurface call.  See AddAttachments for
    * a detailed description of the behaviors in this case.
    */
#define DDSCAPS_BACKBUFFER                      0x00000004l 

struct IDirectDraw;
struct IDirectDrawSurface;
struct IDirectDrawPalette;
struct IDirectDrawClipper;

typedef struct IDirectDraw                      FAR* LPDIRECTDRAW;
typedef struct IDirectDrawSurface               FAR* LPDIRECTDRAWSURFACE;
typedef struct IDirectDrawPalette               FAR* LPDIRECTDRAWPALETTE;
typedef struct IDirectDrawClipper               FAR* LPDIRECTDRAWCLIPPER;

typedef struct _DDSURFACEDESC           FAR* LPDDSURFACEDESC;

typedef HRESULT(FAR PASCAL* LPDDENUMMODESCALLBACK)(LPDDSURFACEDESC, LPVOID);
typedef HRESULT(FAR PASCAL* LPDDENUMSURFACESCALLBACK)(LPDIRECTDRAWSURFACE, LPDDSURFACEDESC, LPVOID);

typedef HRESULT(WINAPI* PFNDirectDrawCreate)(GUID FAR* lpGUID, LPDIRECTDRAW FAR* lplpDD, IUnknown FAR* pUnkOuter);
extern PFNDirectDrawCreate DirectDrawCreate;

typedef struct _DDSCAPS
{
    DWORD       dwCaps;         // capabilities of surface wanted
} DDSCAPS;

typedef DDSCAPS FAR* LPDDSCAPS;

#define DD_ROP_SPACE            (256/32)        // space required to store ROP array    

typedef struct _DDCAPS
{
    DWORD       dwSize;                 // size of the DDDRIVERCAPS structure
    DWORD       dwCaps;                 // driver specific capabilities
    DWORD       dwCaps2;                // more driver specific capabilites
    DWORD       dwCKeyCaps;             // color key capabilities of the surface
    DWORD       dwFXCaps;               // driver specific stretching and effects capabilites
    DWORD       dwFXAlphaCaps;          // alpha driver specific capabilities
    DWORD       dwPalCaps;              // palette capabilities
    DWORD       dwSVCaps;               // stereo vision capabilities
    DWORD       dwAlphaBltConstBitDepths;       // DDBD_2,4,8
    DWORD       dwAlphaBltPixelBitDepths;       // DDBD_1,2,4,8
    DWORD       dwAlphaBltSurfaceBitDepths;     // DDBD_1,2,4,8
    DWORD       dwAlphaOverlayConstBitDepths;   // DDBD_2,4,8
    DWORD       dwAlphaOverlayPixelBitDepths;   // DDBD_1,2,4,8
    DWORD       dwAlphaOverlaySurfaceBitDepths; // DDBD_1,2,4,8
    DWORD       dwZBufferBitDepths;             // DDBD_8,16,24,32
    DWORD       dwVidMemTotal;          // total amount of video memory
    DWORD       dwVidMemFree;           // amount of free video memory
    DWORD       dwMaxVisibleOverlays;   // maximum number of visible overlays
    DWORD       dwCurrVisibleOverlays;  // current number of visible overlays
    DWORD       dwNumFourCCCodes;       // number of four cc codes
    DWORD       dwAlignBoundarySrc;     // source rectangle alignment
    DWORD       dwAlignSizeSrc;         // source rectangle byte size
    DWORD       dwAlignBoundaryDest;    // dest rectangle alignment
    DWORD       dwAlignSizeDest;        // dest rectangle byte size
    DWORD       dwAlignStrideAlign;     // stride alignment
    DWORD       dwRops[DD_ROP_SPACE];   // ROPS supported
    DDSCAPS     ddsCaps;                // DDSCAPS structure has all the general capabilities
    DWORD       dwMinOverlayStretch;    // minimum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
    DWORD       dwMaxOverlayStretch;    // maximum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
    DWORD       dwMinLiveVideoStretch;  // minimum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
    DWORD       dwMaxLiveVideoStretch;  // maximum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
    DWORD       dwMinHwCodecStretch;    // minimum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
    DWORD       dwMaxHwCodecStretch;    // maximum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
    DWORD       dwReserved1;            // reserved
    DWORD       dwReserved2;            // reserved
    DWORD       dwReserved3;            // reserved
} DDCAPS;

typedef DDCAPS FAR* LPDDCAPS;

typedef struct _DDCOLORKEY
{
    DWORD       dwColorSpaceLowValue;   // low boundary of color space that is to 
    // be treated as Color Key, inclusive
    DWORD       dwColorSpaceHighValue;  // high boundary of color space that is 
    // to be treated as Color Key, inclusive
} DDCOLORKEY;

typedef DDCOLORKEY FAR* LPDDCOLORKEY;

typedef struct _DDBLTFX
{
    DWORD       dwSize;                         // size of structure
    DWORD       dwDDFX;                         // FX operations
    DWORD       dwROP;                          // Win32 raster operations
    DWORD       dwDDROP;                        // Raster operations new for DirectDraw
    DWORD       dwRotationAngle;                // Rotation angle for blt
    DWORD       dwZBufferOpCode;                // ZBuffer compares
    DWORD       dwZBufferLow;                   // Low limit of Z buffer
    DWORD       dwZBufferHigh;                  // High limit of Z buffer
    DWORD       dwZBufferBaseDest;              // Destination base value
    DWORD       dwZDestConstBitDepth;           // Bit depth used to specify Z constant for destination
    union
    {
        DWORD   dwZDestConst;                   // Constant to use as Z buffer for dest
        LPDIRECTDRAWSURFACE lpDDSZBufferDest;   // Surface to use as Z buffer for dest
    };
    DWORD       dwZSrcConstBitDepth;            // Bit depth used to specify Z constant for source
    union
    {
        DWORD   dwZSrcConst;                    // Constant to use as Z buffer for src
        LPDIRECTDRAWSURFACE lpDDSZBufferSrc;    // Surface to use as Z buffer for src
    };
    DWORD       dwAlphaEdgeBlendBitDepth;       // Bit depth used to specify constant for alpha edge blend
    DWORD       dwAlphaEdgeBlend;               // Alpha for edge blending
    DWORD       dwReserved;
    DWORD       dwAlphaDestConstBitDepth;       // Bit depth used to specify alpha constant for destination
    union
    {
        DWORD   dwAlphaDestConst;               // Constant to use as Alpha Channel
        LPDIRECTDRAWSURFACE lpDDSAlphaDest;     // Surface to use as Alpha Channel
    };
    DWORD       dwAlphaSrcConstBitDepth;        // Bit depth used to specify alpha constant for source
    union
    {
        DWORD   dwAlphaSrcConst;                // Constant to use as Alpha Channel
        LPDIRECTDRAWSURFACE lpDDSAlphaSrc;      // Surface to use as Alpha Channel
    };
    union
    {
        DWORD   dwFillColor;                    // color in RGB or Palettized
        LPDIRECTDRAWSURFACE lpDDSPattern;       // Surface to use as pattern
    };
    DDCOLORKEY  ddckDestColorkey;               // DestColorkey override
    DDCOLORKEY  ddckSrcColorkey;                // SrcColorkey override
} DDBLTFX;

typedef DDBLTFX FAR* LPDDBLTFX;

typedef struct _DDBLTBATCH
{
    LPRECT              lprDest;
    LPDIRECTDRAWSURFACE lpDDSSrc;
    LPRECT              lprSrc;
    DWORD               dwFlags;
    LPDDBLTFX           lpDDBltFx;
} DDBLTBATCH;

typedef DDBLTBATCH FAR* LPDDBLTBATCH;

typedef struct _DDPIXELFORMAT
{
    DWORD       dwSize;                 // size of structure
    DWORD       dwFlags;                // pixel format flags
    DWORD       dwFourCC;               // (FOURCC code)
    union
    {
        DWORD   dwRGBBitCount;          // how many bits per pixel (BD_4,8,16,24,32)
        DWORD   dwYUVBitCount;          // how many bits per pixel (BD_4,8,16,24,32)
        DWORD   dwZBufferBitDepth;      // how many bits for z buffers (BD_8,16,24,32)
        DWORD   dwAlphaBitDepth;        // how many bits for alpha channels (BD_1,2,4,8)
    };
    union
    {
        DWORD   dwRBitMask;             // mask for red bit
        DWORD   dwYBitMask;             // mask for Y bits
    };
    union
    {
        DWORD   dwGBitMask;             // mask for green bits
        DWORD   dwUBitMask;             // mask for U bits
    };
    union
    {
        DWORD   dwBBitMask;             // mask for blue bits
        DWORD   dwVBitMask;             // mask for V bits
    };
    union
    {
        DWORD   dwRGBAlphaBitMask;      // mask for alpha channel
        DWORD   dwYUVAlphaBitMask;      // mask for alpha channel
    };
} DDPIXELFORMAT;

typedef DDPIXELFORMAT FAR* LPDDPIXELFORMAT;

typedef struct _DDOVERLAYFX
{
    DWORD       dwSize;                         // size of structure
    DWORD       dwAlphaEdgeBlendBitDepth;       // Bit depth used to specify constant for alpha edge blend
    DWORD       dwAlphaEdgeBlend;               // Constant to use as alpha for edge blend
    DWORD       dwReserved;
    DWORD       dwAlphaDestConstBitDepth;       // Bit depth used to specify alpha constant for destination
    union
    {
        DWORD   dwAlphaDestConst;               // Constant to use as alpha channel for dest
        LPDIRECTDRAWSURFACE lpDDSAlphaDest;     // Surface to use as alpha channel for dest
    };
    DWORD       dwAlphaSrcConstBitDepth;        // Bit depth used to specify alpha constant for source
    union
    {
        DWORD   dwAlphaSrcConst;                // Constant to use as alpha channel for src
        LPDIRECTDRAWSURFACE lpDDSAlphaSrc;      // Surface to use as alpha channel for src
    };
    DDCOLORKEY  dckDestColorkey;                // DestColorkey override
    DDCOLORKEY  dckSrcColorkey;                 // DestColorkey override
    DWORD       dwDDFX;                         // Overlay FX
    DWORD       dwFlags;                        // flags
} DDOVERLAYFX;

typedef DDOVERLAYFX FAR* LPDDOVERLAYFX;

typedef struct _DDSURFACEDESC
{
    DWORD               dwSize;                 // size of the DDSURFACEDESC structure
    DWORD               dwFlags;                // determines what fields are valid
    DWORD               dwHeight;               // height of surface to be created
    DWORD               dwWidth;                // width of input surface
    LONG                lPitch;                 // distance to start of next line (return value only)
    DWORD               dwBackBufferCount;      // number of back buffers requested
    DWORD               dwZBufferBitDepth;      // depth of Z buffer requested
    DWORD               dwAlphaBitDepth;        // depth of alpha buffer requested
    DWORD               dwReserved;             // reserved
    LPVOID              lpSurface;              // pointer to the associated surface memory
    DDCOLORKEY          ddckCKDestOverlay;      // color key for destination overlay use
    DDCOLORKEY          ddckCKDestBlt;          // color key for destination blt use
    DDCOLORKEY          ddckCKSrcOverlay;       // color key for source overlay use
    DDCOLORKEY          ddckCKSrcBlt;           // color key for source blt use
    DDPIXELFORMAT       ddpfPixelFormat;        // pixel format description of the surface
    DDSCAPS             ddsCaps;                // direct draw surface capabilities
} DDSURFACEDESC;

DECLARE_INTERFACE_(IDirectDraw, IUnknown)
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG, Release) (THIS) PURE;
    /*** IDirectDraw methods ***/
    STDMETHOD(Compact)(THIS) PURE;
    STDMETHOD(CreateClipper)(THIS_ DWORD, LPDIRECTDRAWCLIPPER FAR*, IUnknown FAR*) PURE;
    STDMETHOD(CreatePalette)(THIS_ DWORD, LPPALETTEENTRY, LPDIRECTDRAWPALETTE FAR*, IUnknown FAR*) PURE;
    STDMETHOD(CreateSurface)(THIS_  LPDDSURFACEDESC, LPDIRECTDRAWSURFACE FAR*, IUnknown FAR*) PURE;
    STDMETHOD(DuplicateSurface)(THIS_ LPDIRECTDRAWSURFACE, LPDIRECTDRAWSURFACE FAR*) PURE;
    STDMETHOD(EnumDisplayModes)(THIS_ DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMMODESCALLBACK) PURE;
    STDMETHOD(EnumSurfaces)(THIS_ DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMSURFACESCALLBACK) PURE;
    STDMETHOD(FlipToGDISurface)(THIS) PURE;
    STDMETHOD(GetCaps)(THIS_ LPDDCAPS, LPDDCAPS) PURE;
    STDMETHOD(GetDisplayMode)(THIS_ LPDDSURFACEDESC) PURE;
    STDMETHOD(GetFourCCCodes)(THIS_  LPDWORD, LPDWORD) PURE;
    STDMETHOD(GetGDISurface)(THIS_ LPDIRECTDRAWSURFACE FAR*) PURE;
    STDMETHOD(GetMonitorFrequency)(THIS_ LPDWORD) PURE;
    STDMETHOD(GetScanLine)(THIS_ LPDWORD) PURE;
    STDMETHOD(GetVerticalBlankStatus)(THIS_ LPBOOL) PURE;
    STDMETHOD(Initialize)(THIS_ GUID FAR*) PURE;
    STDMETHOD(RestoreDisplayMode)(THIS) PURE;
    STDMETHOD(SetCooperativeLevel)(THIS_ HWND, DWORD) PURE;
    STDMETHOD(SetDisplayMode)(THIS_ DWORD, DWORD, DWORD) PURE;
    STDMETHOD(WaitForVerticalBlank)(THIS_ DWORD, HANDLE) PURE;
};

DECLARE_INTERFACE_(IDirectDrawClipper, IUnknown)
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG, Release) (THIS) PURE;
    /*** IDirectDrawClipper methods ***/
    STDMETHOD(GetClipList)(THIS_ LPRECT, LPRGNDATA, LPDWORD) PURE;
    STDMETHOD(GetHWnd)(THIS_ HWND FAR*) PURE;
    STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, DWORD) PURE;
    STDMETHOD(IsClipListChanged)(THIS_ BOOL FAR*) PURE;
    STDMETHOD(SetClipList)(THIS_ LPRGNDATA, DWORD) PURE;
    STDMETHOD(SetHWnd)(THIS_ DWORD, HWND) PURE;
};

DECLARE_INTERFACE_(IDirectDrawSurface, IUnknown)
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG, Release) (THIS) PURE;
    /*** IDirectDrawSurface methods ***/
    STDMETHOD(AddAttachedSurface)(THIS_ LPDIRECTDRAWSURFACE) PURE;
    STDMETHOD(AddOverlayDirtyRect)(THIS_ LPRECT) PURE;
    STDMETHOD(Blt)(THIS_ LPRECT, LPDIRECTDRAWSURFACE, LPRECT, DWORD, LPDDBLTFX) PURE;
    STDMETHOD(BltBatch)(THIS_ LPDDBLTBATCH, DWORD, DWORD) PURE;
    STDMETHOD(BltFast)(THIS_ DWORD, DWORD, LPDIRECTDRAWSURFACE, LPRECT, DWORD) PURE;
    STDMETHOD(DeleteAttachedSurface)(THIS_ DWORD, LPDIRECTDRAWSURFACE) PURE;
    STDMETHOD(EnumAttachedSurfaces)(THIS_ LPVOID, LPDDENUMSURFACESCALLBACK) PURE;
    STDMETHOD(EnumOverlayZOrders)(THIS_ DWORD, LPVOID, LPDDENUMSURFACESCALLBACK) PURE;
    STDMETHOD(Flip)(THIS_ LPDIRECTDRAWSURFACE, DWORD) PURE;
    STDMETHOD(GetAttachedSurface)(THIS_ LPDDSCAPS, LPDIRECTDRAWSURFACE FAR*) PURE;
    STDMETHOD(GetBltStatus)(THIS_ DWORD) PURE;
    STDMETHOD(GetCaps)(THIS_ LPDDSCAPS) PURE;
    STDMETHOD(GetClipper)(THIS_ LPDIRECTDRAWCLIPPER FAR*) PURE;
    STDMETHOD(GetColorKey)(THIS_ DWORD, LPDDCOLORKEY) PURE;
    STDMETHOD(GetDC)(THIS_ HDC FAR*) PURE;
    STDMETHOD(GetFlipStatus)(THIS_ DWORD) PURE;
    STDMETHOD(GetOverlayPosition)(THIS_ LPLONG, LPLONG) PURE;
    STDMETHOD(GetPalette)(THIS_ LPDIRECTDRAWPALETTE FAR*) PURE;
    STDMETHOD(GetPixelFormat)(THIS_ LPDDPIXELFORMAT) PURE;
    STDMETHOD(GetSurfaceDesc)(THIS_ LPDDSURFACEDESC) PURE;
    STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, LPDDSURFACEDESC) PURE;
    STDMETHOD(IsLost)(THIS) PURE;
    STDMETHOD(Lock)(THIS_ LPRECT, LPDDSURFACEDESC, DWORD, HANDLE) PURE;
    STDMETHOD(ReleaseDC)(THIS_ HDC) PURE;
    STDMETHOD(Restore)(THIS) PURE;
    STDMETHOD(SetClipper)(THIS_ LPDIRECTDRAWCLIPPER) PURE;
    STDMETHOD(SetColorKey)(THIS_ DWORD, LPDDCOLORKEY) PURE;
    STDMETHOD(SetOverlayPosition)(THIS_ LONG, LONG) PURE;
    STDMETHOD(SetPalette)(THIS_ LPDIRECTDRAWPALETTE) PURE;
    STDMETHOD(Unlock)(THIS_ LPVOID) PURE;
    STDMETHOD(UpdateOverlay)(THIS_ LPRECT, LPDIRECTDRAWSURFACE, LPRECT, DWORD, LPDDOVERLAYFX) PURE;
    STDMETHOD(UpdateOverlayDisplay)(THIS_ DWORD) PURE;
    STDMETHOD(UpdateOverlayZOrder)(THIS_ DWORD, LPDIRECTDRAWSURFACE) PURE;
};

DECLARE_INTERFACE_(IDirectDrawPalette, IUnknown)
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG, Release) (THIS) PURE;
    /*** IDirectDrawPalette methods ***/
    STDMETHOD(GetCaps)(THIS_ LPDWORD) PURE;
    STDMETHOD(GetEntries)(THIS_ DWORD, DWORD, DWORD, LPPALETTEENTRY) PURE;
    STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, DWORD, LPPALETTEENTRY) PURE;
    STDMETHOD(SetEntries)(THIS_ DWORD, DWORD, DWORD, LPPALETTEENTRY) PURE;
};

#endif
