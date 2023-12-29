/*==========================================================================;
 *
 *  Copyright (C) 1994-1997 Microsoft Corporation.  All Rights Reserved.
 *
 *  File:       ddraw.h
 *  Content:    DirectDraw include file
 *
 ***************************************************************************/

#ifndef LDL_DirectX_DirectX7_ddraw_hpp
#define LDL_DirectX_DirectX7_ddraw_hpp

#include <LDL/Config.hpp>

namespace LDL
{
    namespace DirectX7
    {
        #include <LDL/APIs/WinApi/TypesHeader.hpp>

        const DWORD  _FACDD = 0x876;

        inline HRESULT MAKE_DDHRESULT(DWORD code)
        {
            return MAKE_HRESULT(1, _FACDD, code);
        }

        /*
         * FOURCC codes for DX compressed-texture pixel formats
         */
        const DWORD  FOURCC_DXT1 = (MAKEFOURCC('D', 'X', 'T', '1'));
        const DWORD  FOURCC_DXT2 = (MAKEFOURCC('D', 'X', 'T', '2'));
        const DWORD  FOURCC_DXT3 = (MAKEFOURCC('D', 'X', 'T', '3'));
        const DWORD  FOURCC_DXT4 = (MAKEFOURCC('D', 'X', 'T', '4'));
        const DWORD  FOURCC_DXT5 = (MAKEFOURCC('D', 'X', 'T', '5'));

        /*
         * GUIDS used by DirectDraw objects
         */

        const GUID  CLSID_DirectDraw = { 0xD7B70EE0,0x4340,0x11CF,0xB0,0x63,0x00,0x20,0xAF,0xC2,0xCD,0x35 };
        const GUID  CLSID_DirectDraw7 = { 0x3c305196,0x50db,0x11d3,0x9c,0xfe,0x00,0xc0,0x4f,0xd9,0x30,0xc5 };
        const GUID  CLSID_DirectDrawClipper = { 0x593817A0,0x7DB3,0x11CF,0xA2,0xDE,0x00,0xAA,0x00,0xb9,0x33,0x56 };
        const GUID  IID_IDirectDraw = { 0x6C14DB80,0xA733,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60 };
        const GUID  IID_IDirectDraw2 = { 0xB3A6F3E0,0x2B43,0x11CF,0xA2,0xDE,0x00,0xAA,0x00,0xB9,0x33,0x56 };
        const GUID  IID_IDirectDraw4 = { 0x9c59509a,0x39bd,0x11d1,0x8c,0x4a,0x00,0xc0,0x4f,0xd9,0x30,0xc5 };
        const GUID  IID_IDirectDraw7 = { 0x15e65ec0,0x3b9c,0x11d2,0xb9,0x2f,0x00,0x60,0x97,0x97,0xea,0x5b };
        const GUID  IID_IDirectDrawSurface = { 0x6C14DB81,0xA733,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60 };
        const GUID  IID_IDirectDrawSurface2 = { 0x57805885,0x6eec,0x11cf,0x94,0x41,0xa8,0x23,0x03,0xc1,0x0e,0x27 };
        const GUID  IID_IDirectDrawSurface3 = { 0xDA044E00,0x69B2,0x11D0,0xA1,0xD5,0x00,0xAA,0x00,0xB8,0xDF,0xBB };
        const GUID  IID_IDirectDrawSurface4 = { 0x0B2B8630,0xAD35,0x11D0,0x8E,0xA6,0x00,0x60,0x97,0x97,0xEA,0x5B };
        const GUID  IID_IDirectDrawSurface7 = { 0x06675a80,0x3b9b,0x11d2,0xb9,0x2f,0x00,0x60,0x97,0x97,0xea,0x5b };

        const GUID  IID_IDirectDrawPalette = { 0x6C14DB84,0xA733,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60 };
        const GUID  IID_IDirectDrawClipper = { 0x6C14DB85,0xA733,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60 };
        const GUID  IID_IDirectDrawColorControl = { 0x4B9F0EE0,0x0D7E,0x11D0,0x9B,0x06,0x00,0xA0,0xC9,0x03,0xA3,0xB8 };
        const GUID  IID_IDirectDrawGammaControl = { 0x69C11C3E,0xB46B,0x11D1,0xAD,0x7A,0x00,0xC0,0x4F,0xC2,0x9B,0x4E };


        /*============================================================================
         *
         * DirectDraw Structures
         *
         * Various structures used to invoke DirectDraw.
         *
         *==========================================================================*/

        struct IDirectDraw;
        struct IDirectDrawSurface;
        struct IDirectDrawPalette;
        struct IDirectDrawClipper;

        typedef struct IDirectDraw* LPDIRECTDRAW;
        typedef struct IDirectDraw2* LPDIRECTDRAW2;
        typedef struct IDirectDraw4* LPDIRECTDRAW4;
        typedef struct IDirectDraw7* LPDIRECTDRAW7;
        typedef struct IDirectDrawSurface* LPDIRECTDRAWSURFACE;
        typedef struct IDirectDrawSurface2* LPDIRECTDRAWSURFACE2;
        typedef struct IDirectDrawSurface3* LPDIRECTDRAWSURFACE3;
        typedef struct IDirectDrawSurface4* LPDIRECTDRAWSURFACE4;
        typedef struct IDirectDrawSurface7* LPDIRECTDRAWSURFACE7;

        typedef struct IDirectDrawPalette* LPDIRECTDRAWPALETTE;
        typedef struct IDirectDrawClipper* LPDIRECTDRAWCLIPPER;
        typedef struct IDirectDrawColorControl* LPDIRECTDRAWCOLORCONTROL;
        typedef struct IDirectDrawGammaControl* LPDIRECTDRAWGAMMACONTROL;

        typedef struct _DDFXROP* LPDDFXROP;
        typedef struct _DDSURFACEDESC* LPDDSURFACEDESC;
        typedef struct _DDSURFACEDESC2* LPDDSURFACEDESC2;
        typedef struct _DDCOLORCONTROL* LPDDCOLORCONTROL;

        /*
         * API's
         */
         //extern HRESULT LDL_API_CALL DirectDrawCreate( GUID  *lpGUID, LPDIRECTDRAW  *lplpDD, IUnknown  *pUnkOuter );
         //extern HRESULT LDL_API_CALL DirectDrawCreateEx( GUID  * lpGuid, LPVOID  *lplpDD, const IID &   iid,IUnknown  *pUnkOuter );
         //extern HRESULT LDL_API_CALL DirectDrawCreateClipper( DWORD dwFlags, LPDIRECTDRAWCLIPPER  *lplpDDClipper, IUnknown  *pUnkOuter );

     /*
      * Flags for DirectDrawEnumerateEx
      * DirectDrawEnumerateEx supercedes DirectDrawEnumerate. You must use GetProcAddress to
      * obtain a function pointer (of type LPDIRECTDRAWENUMERATEEX) to DirectDrawEnumerateEx.
      * By default, only the primary display device is enumerated.
      * DirectDrawEnumerate is equivalent to DirectDrawEnumerate(,,DDENUM_NONDISPLAYDEVICES)
      */

      /*
       * This flag causes enumeration of any GDI display devices which are part of
       * the Windows Desktop
       */
        const DWORD  DDENUM_ATTACHEDSECONDARYDEVICES = 0x00000001L;

        /*
         * This flag causes enumeration of any GDI display devices which are not
         * part of the Windows Desktop
         */
        const DWORD  DDENUM_DETACHEDSECONDARYDEVICES = 0x00000002L;

        /*
         * This flag causes enumeration of non-display devices
         */
        const DWORD  DDENUM_NONDISPLAYDEVICES = 0x00000004L;

        const DWORD  DDCREATE_HARDWAREONLY = 0x00000001l;
        const DWORD  DDCREATE_EMULATIONONLY = 0x00000002l;

        //#ifndef WINNT
        typedef HRESULT(LDL_CALL* LPDDENUMMODESCALLBACK)(LPDDSURFACEDESC, LPVOID);
        typedef HRESULT(LDL_CALL* LPDDENUMMODESCALLBACK2)(LPDDSURFACEDESC2, LPVOID);
        typedef HRESULT(LDL_CALL* LPDDENUMSURFACESCALLBACK)(LPDIRECTDRAWSURFACE, LPDDSURFACEDESC, LPVOID);
        typedef HRESULT(LDL_CALL* LPDDENUMSURFACESCALLBACK2)(LPDIRECTDRAWSURFACE4, LPDDSURFACEDESC2, LPVOID);
        typedef HRESULT(LDL_CALL* LPDDENUMSURFACESCALLBACK7)(LPDIRECTDRAWSURFACE7, LPDDSURFACEDESC2, LPVOID);
        //#endif

        /*
         * Generic pixel format with 8-bit RGB and alpha components
         */
        typedef struct _DDARGB
        {
            BYTE blue;
            BYTE green;
            BYTE red;
            BYTE alpha;
        } DDARGB;

        typedef DDARGB* LPDDARGB;

        /*
         * This version of the structure remains for backwards source compatibility.
         * The DDARGB structure is the one that should be used for all DirectDraw APIs.
         */
        typedef struct _DDRGBA
        {
            BYTE red;
            BYTE green;
            BYTE blue;
            BYTE alpha;
        } DDRGBA;

        typedef DDRGBA* LPDDRGBA;


        /*
         * DDCOLORKEY
         */
        typedef struct _DDCOLORKEY
        {
            DWORD       dwColorSpaceLowValue;   // low boundary of color space that is to
            // be treated as Color Key, inclusive
            DWORD       dwColorSpaceHighValue;  // high boundary of color space that is
            // to be treated as Color Key, inclusive
        } DDCOLORKEY;

        typedef DDCOLORKEY* LPDDCOLORKEY;

        /*
         * DDBLTFX
         * Used to pass override information to the DIRECTDRAWSURFACE callback Blt.
         */
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
                DWORD   dwFillDepth;                    // depth value for z-buffer
                DWORD   dwFillPixel;                    // pixel value for RGBA or RGBZ
                LPDIRECTDRAWSURFACE lpDDSPattern;       // Surface to use as pattern
            };
            DDCOLORKEY  ddckDestColorkey;               // DestColorkey override
            DDCOLORKEY  ddckSrcColorkey;                // SrcColorkey override
        } DDBLTFX;

        typedef DDBLTFX* LPDDBLTFX;



        /*
         * DDSCAPS
         */
        typedef struct _DDSCAPS
        {
            DWORD       dwCaps;         // capabilities of surface wanted
        } DDSCAPS;

        typedef DDSCAPS* LPDDSCAPS;


        /*
         * DDOSCAPS
         */
        typedef struct _DDOSCAPS
        {
            DWORD       dwCaps;         // capabilities of surface wanted
        } DDOSCAPS;

        typedef DDOSCAPS* LPDDOSCAPS;

        /*
         * This structure is used internally by DirectDraw.
         */
        typedef struct _DDSCAPSEX
        {
            DWORD       dwCaps2;
            DWORD       dwCaps3;
            DWORD       dwCaps4;
        } DDSCAPSEX, * LPDDSCAPSEX;

        /*
         * DDSCAPS2
         */
        typedef struct _DDSCAPS2
        {
            DWORD       dwCaps;         // capabilities of surface wanted
            DWORD       dwCaps2;
            DWORD       dwCaps3;
            DWORD       dwCaps4;
        } DDSCAPS2;

        typedef DDSCAPS2* LPDDSCAPS2;

        /*
         * DDCAPS
         */
        const DWORD  DD_ROP_SPACE = (256 / 32);       // space required to store ROP array
        /*
         * NOTE: Our choosen structure number scheme is to append a single digit to
         * the end of the structure giving the version that structure is associated
         * with.
         */

         /*
          * This structure represents the DDCAPS structure released in DirectDraw 1.0.  It is used internally
          * by DirectDraw to interpret caps passed into ddraw by drivers written prior to the release of DirectDraw 2.0.
          * New applications should use the DDCAPS structure defined below.
          */
        typedef struct _DDCAPS_DX1
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
            DWORD       dwMinLiveVideoStretch;  // OBSOLETE! This field remains for compatability reasons only
            DWORD       dwMaxLiveVideoStretch;  // OBSOLETE! This field remains for compatability reasons only
            DWORD       dwMinHwCodecStretch;    // OBSOLETE! This field remains for compatability reasons only
            DWORD       dwMaxHwCodecStretch;    // OBSOLETE! This field remains for compatability reasons only
            DWORD       dwReserved1;            // reserved
            DWORD       dwReserved2;            // reserved
            DWORD       dwReserved3;            // reserved
        } DDCAPS_DX1;

        typedef DDCAPS_DX1* LPDDCAPS_DX1;

        /*
         * This structure is the DDCAPS structure as it was in version 2 and 3 of Direct X.
         * It is present for back compatability.
         */
        typedef struct _DDCAPS_DX3
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
            DWORD       dwSVBCaps;              // driver specific capabilities for System->Vmem blts
            DWORD       dwSVBCKeyCaps;          // driver color key capabilities for System->Vmem blts
            DWORD       dwSVBFXCaps;            // driver FX capabilities for System->Vmem blts
            DWORD       dwSVBRops[DD_ROP_SPACE];// ROPS supported for System->Vmem blts
            DWORD       dwVSBCaps;              // driver specific capabilities for Vmem->System blts
            DWORD       dwVSBCKeyCaps;          // driver color key capabilities for Vmem->System blts
            DWORD       dwVSBFXCaps;            // driver FX capabilities for Vmem->System blts
            DWORD       dwVSBRops[DD_ROP_SPACE];// ROPS supported for Vmem->System blts
            DWORD       dwSSBCaps;              // driver specific capabilities for System->System blts
            DWORD       dwSSBCKeyCaps;          // driver color key capabilities for System->System blts
            DWORD       dwSSBFXCaps;            // driver FX capabilities for System->System blts
            DWORD       dwSSBRops[DD_ROP_SPACE];// ROPS supported for System->System blts
            DWORD       dwReserved4;            // reserved
            DWORD       dwReserved5;            // reserved
            DWORD       dwReserved6;            // reserved
        } DDCAPS_DX3;
        typedef DDCAPS_DX3* LPDDCAPS_DX3;

        /*
         * This structure is the DDCAPS structure as it was in version 5 of Direct X.
         * It is present for back compatability.
         */
        typedef struct _DDCAPS_DX5
        {
            /*  0*/ DWORD   dwSize;                 // size of the DDDRIVERCAPS structure
            /*  4*/ DWORD   dwCaps;                 // driver specific capabilities
            /*  8*/ DWORD   dwCaps2;                // more driver specific capabilites
            /*  c*/ DWORD   dwCKeyCaps;             // color key capabilities of the surface
            /* 10*/ DWORD   dwFXCaps;               // driver specific stretching and effects capabilites
            /* 14*/ DWORD   dwFXAlphaCaps;          // alpha driver specific capabilities
            /* 18*/ DWORD   dwPalCaps;              // palette capabilities
            /* 1c*/ DWORD   dwSVCaps;               // stereo vision capabilities
            /* 20*/ DWORD   dwAlphaBltConstBitDepths;       // DDBD_2,4,8
            /* 24*/ DWORD   dwAlphaBltPixelBitDepths;       // DDBD_1,2,4,8
            /* 28*/ DWORD   dwAlphaBltSurfaceBitDepths;     // DDBD_1,2,4,8
            /* 2c*/ DWORD   dwAlphaOverlayConstBitDepths;   // DDBD_2,4,8
            /* 30*/ DWORD   dwAlphaOverlayPixelBitDepths;   // DDBD_1,2,4,8
            /* 34*/ DWORD   dwAlphaOverlaySurfaceBitDepths; // DDBD_1,2,4,8
            /* 38*/ DWORD   dwZBufferBitDepths;             // DDBD_8,16,24,32
            /* 3c*/ DWORD   dwVidMemTotal;          // total amount of video memory
            /* 40*/ DWORD   dwVidMemFree;           // amount of free video memory
            /* 44*/ DWORD   dwMaxVisibleOverlays;   // maximum number of visible overlays
            /* 48*/ DWORD   dwCurrVisibleOverlays;  // current number of visible overlays
            /* 4c*/ DWORD   dwNumFourCCCodes;       // number of four cc codes
            /* 50*/ DWORD   dwAlignBoundarySrc;     // source rectangle alignment
            /* 54*/ DWORD   dwAlignSizeSrc;         // source rectangle byte size
            /* 58*/ DWORD   dwAlignBoundaryDest;    // dest rectangle alignment
            /* 5c*/ DWORD   dwAlignSizeDest;        // dest rectangle byte size
            /* 60*/ DWORD   dwAlignStrideAlign;     // stride alignment
            /* 64*/ DWORD   dwRops[DD_ROP_SPACE];   // ROPS supported
            /* 84*/ DDSCAPS ddsCaps;                // DDSCAPS structure has all the general capabilities
            /* 88*/ DWORD   dwMinOverlayStretch;    // minimum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
            /* 8c*/ DWORD   dwMaxOverlayStretch;    // maximum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
            /* 90*/ DWORD   dwMinLiveVideoStretch;  // minimum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
            /* 94*/ DWORD   dwMaxLiveVideoStretch;  // maximum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
            /* 98*/ DWORD   dwMinHwCodecStretch;    // minimum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
            /* 9c*/ DWORD   dwMaxHwCodecStretch;    // maximum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
            /* a0*/ DWORD   dwReserved1;            // reserved
            /* a4*/ DWORD   dwReserved2;            // reserved
            /* a8*/ DWORD   dwReserved3;            // reserved
            /* ac*/ DWORD   dwSVBCaps;              // driver specific capabilities for System->Vmem blts
            /* b0*/ DWORD   dwSVBCKeyCaps;          // driver color key capabilities for System->Vmem blts
            /* b4*/ DWORD   dwSVBFXCaps;            // driver FX capabilities for System->Vmem blts
            /* b8*/ DWORD   dwSVBRops[DD_ROP_SPACE];// ROPS supported for System->Vmem blts
            /* d8*/ DWORD   dwVSBCaps;              // driver specific capabilities for Vmem->System blts
            /* dc*/ DWORD   dwVSBCKeyCaps;          // driver color key capabilities for Vmem->System blts
            /* e0*/ DWORD   dwVSBFXCaps;            // driver FX capabilities for Vmem->System blts
            /* e4*/ DWORD   dwVSBRops[DD_ROP_SPACE];// ROPS supported for Vmem->System blts
            /*104*/ DWORD   dwSSBCaps;              // driver specific capabilities for System->System blts
            /*108*/ DWORD   dwSSBCKeyCaps;          // driver color key capabilities for System->System blts
            /*10c*/ DWORD   dwSSBFXCaps;            // driver FX capabilities for System->System blts
            /*110*/ DWORD   dwSSBRops[DD_ROP_SPACE];// ROPS supported for System->System blts
            // Members added for DX5:
            /*130*/ DWORD   dwMaxVideoPorts;        // maximum number of usable video ports
            /*134*/ DWORD   dwCurrVideoPorts;       // current number of video ports used
            /*138*/ DWORD   dwSVBCaps2;             // more driver specific capabilities for System->Vmem blts
            /*13c*/ DWORD   dwNLVBCaps;               // driver specific capabilities for non-local->local vidmem blts
            /*140*/ DWORD   dwNLVBCaps2;              // more driver specific capabilities non-local->local vidmem blts
            /*144*/ DWORD   dwNLVBCKeyCaps;           // driver color key capabilities for non-local->local vidmem blts
            /*148*/ DWORD   dwNLVBFXCaps;             // driver FX capabilities for non-local->local blts
            /*14c*/ DWORD   dwNLVBRops[DD_ROP_SPACE]; // ROPS supported for non-local->local blts
        } DDCAPS_DX5;
        typedef DDCAPS_DX5* LPDDCAPS_DX5;

        typedef struct _DDCAPS_DX6
        {
            /*  0*/ DWORD   dwSize;                 // size of the DDDRIVERCAPS structure
            /*  4*/ DWORD   dwCaps;                 // driver specific capabilities
            /*  8*/ DWORD   dwCaps2;                // more driver specific capabilites
            /*  c*/ DWORD   dwCKeyCaps;             // color key capabilities of the surface
            /* 10*/ DWORD   dwFXCaps;               // driver specific stretching and effects capabilites
            /* 14*/ DWORD   dwFXAlphaCaps;          // alpha caps
            /* 18*/ DWORD   dwPalCaps;              // palette capabilities
            /* 1c*/ DWORD   dwSVCaps;               // stereo vision capabilities
            /* 20*/ DWORD   dwAlphaBltConstBitDepths;       // DDBD_2,4,8
            /* 24*/ DWORD   dwAlphaBltPixelBitDepths;       // DDBD_1,2,4,8
            /* 28*/ DWORD   dwAlphaBltSurfaceBitDepths;     // DDBD_1,2,4,8
            /* 2c*/ DWORD   dwAlphaOverlayConstBitDepths;   // DDBD_2,4,8
            /* 30*/ DWORD   dwAlphaOverlayPixelBitDepths;   // DDBD_1,2,4,8
            /* 34*/ DWORD   dwAlphaOverlaySurfaceBitDepths; // DDBD_1,2,4,8
            /* 38*/ DWORD   dwZBufferBitDepths;             // DDBD_8,16,24,32
            /* 3c*/ DWORD   dwVidMemTotal;          // total amount of video memory
            /* 40*/ DWORD   dwVidMemFree;           // amount of free video memory
            /* 44*/ DWORD   dwMaxVisibleOverlays;   // maximum number of visible overlays
            /* 48*/ DWORD   dwCurrVisibleOverlays;  // current number of visible overlays
            /* 4c*/ DWORD   dwNumFourCCCodes;       // number of four cc codes
            /* 50*/ DWORD   dwAlignBoundarySrc;     // source rectangle alignment
            /* 54*/ DWORD   dwAlignSizeSrc;         // source rectangle byte size
            /* 58*/ DWORD   dwAlignBoundaryDest;    // dest rectangle alignment
            /* 5c*/ DWORD   dwAlignSizeDest;        // dest rectangle byte size
            /* 60*/ DWORD   dwAlignStrideAlign;     // stride alignment
            /* 64*/ DWORD   dwRops[DD_ROP_SPACE];   // ROPS supported
            /* 84*/ DDSCAPS ddsOldCaps;             // Was DDSCAPS  ddsCaps. ddsCaps is of type DDSCAPS2 for DX6
            /* 88*/ DWORD   dwMinOverlayStretch;    // minimum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
            /* 8c*/ DWORD   dwMaxOverlayStretch;    // maximum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
            /* 90*/ DWORD   dwMinLiveVideoStretch;  // minimum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
            /* 94*/ DWORD   dwMaxLiveVideoStretch;  // maximum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
            /* 98*/ DWORD   dwMinHwCodecStretch;    // minimum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
            /* 9c*/ DWORD   dwMaxHwCodecStretch;    // maximum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
            /* a0*/ DWORD   dwReserved1;            // reserved
            /* a4*/ DWORD   dwReserved2;            // reserved
            /* a8*/ DWORD   dwReserved3;            // reserved
            /* ac*/ DWORD   dwSVBCaps;              // driver specific capabilities for System->Vmem blts
            /* b0*/ DWORD   dwSVBCKeyCaps;          // driver color key capabilities for System->Vmem blts
            /* b4*/ DWORD   dwSVBFXCaps;            // driver FX capabilities for System->Vmem blts
            /* b8*/ DWORD   dwSVBRops[DD_ROP_SPACE];// ROPS supported for System->Vmem blts
            /* d8*/ DWORD   dwVSBCaps;              // driver specific capabilities for Vmem->System blts
            /* dc*/ DWORD   dwVSBCKeyCaps;          // driver color key capabilities for Vmem->System blts
            /* e0*/ DWORD   dwVSBFXCaps;            // driver FX capabilities for Vmem->System blts
            /* e4*/ DWORD   dwVSBRops[DD_ROP_SPACE];// ROPS supported for Vmem->System blts
            /*104*/ DWORD   dwSSBCaps;              // driver specific capabilities for System->System blts
            /*108*/ DWORD   dwSSBCKeyCaps;          // driver color key capabilities for System->System blts
            /*10c*/ DWORD   dwSSBFXCaps;            // driver FX capabilities for System->System blts
            /*110*/ DWORD   dwSSBRops[DD_ROP_SPACE];// ROPS supported for System->System blts
            /*130*/ DWORD   dwMaxVideoPorts;        // maximum number of usable video ports
            /*134*/ DWORD   dwCurrVideoPorts;       // current number of video ports used
            /*138*/ DWORD   dwSVBCaps2;             // more driver specific capabilities for System->Vmem blts
            /*13c*/ DWORD   dwNLVBCaps;               // driver specific capabilities for non-local->local vidmem blts
            /*140*/ DWORD   dwNLVBCaps2;              // more driver specific capabilities non-local->local vidmem blts
            /*144*/ DWORD   dwNLVBCKeyCaps;           // driver color key capabilities for non-local->local vidmem blts
            /*148*/ DWORD   dwNLVBFXCaps;             // driver FX capabilities for non-local->local blts
            /*14c*/ DWORD   dwNLVBRops[DD_ROP_SPACE]; // ROPS supported for non-local->local blts
            // Members added for DX6 release
            /*16c*/ DDSCAPS2 ddsCaps;               // Surface Caps
        } DDCAPS_DX6;
        typedef DDCAPS_DX6* LPDDCAPS_DX6;

        typedef struct _DDCAPS_DX7
        {
            /*  0*/ DWORD   dwSize;                 // size of the DDDRIVERCAPS structure
            /*  4*/ DWORD   dwCaps;                 // driver specific capabilities
            /*  8*/ DWORD   dwCaps2;                // more driver specific capabilites
            /*  c*/ DWORD   dwCKeyCaps;             // color key capabilities of the surface
            /* 10*/ DWORD   dwFXCaps;               // driver specific stretching and effects capabilites
            /* 14*/ DWORD   dwFXAlphaCaps;          // alpha driver specific capabilities
            /* 18*/ DWORD   dwPalCaps;              // palette capabilities
            /* 1c*/ DWORD   dwSVCaps;               // stereo vision capabilities
            /* 20*/ DWORD   dwAlphaBltConstBitDepths;       // DDBD_2,4,8
            /* 24*/ DWORD   dwAlphaBltPixelBitDepths;       // DDBD_1,2,4,8
            /* 28*/ DWORD   dwAlphaBltSurfaceBitDepths;     // DDBD_1,2,4,8
            /* 2c*/ DWORD   dwAlphaOverlayConstBitDepths;   // DDBD_2,4,8
            /* 30*/ DWORD   dwAlphaOverlayPixelBitDepths;   // DDBD_1,2,4,8
            /* 34*/ DWORD   dwAlphaOverlaySurfaceBitDepths; // DDBD_1,2,4,8
            /* 38*/ DWORD   dwZBufferBitDepths;             // DDBD_8,16,24,32
            /* 3c*/ DWORD   dwVidMemTotal;          // total amount of video memory
            /* 40*/ DWORD   dwVidMemFree;           // amount of free video memory
            /* 44*/ DWORD   dwMaxVisibleOverlays;   // maximum number of visible overlays
            /* 48*/ DWORD   dwCurrVisibleOverlays;  // current number of visible overlays
            /* 4c*/ DWORD   dwNumFourCCCodes;       // number of four cc codes
            /* 50*/ DWORD   dwAlignBoundarySrc;     // source rectangle alignment
            /* 54*/ DWORD   dwAlignSizeSrc;         // source rectangle byte size
            /* 58*/ DWORD   dwAlignBoundaryDest;    // dest rectangle alignment
            /* 5c*/ DWORD   dwAlignSizeDest;        // dest rectangle byte size
            /* 60*/ DWORD   dwAlignStrideAlign;     // stride alignment
            /* 64*/ DWORD   dwRops[DD_ROP_SPACE];   // ROPS supported
            /* 84*/ DDSCAPS ddsOldCaps;             // Was DDSCAPS  ddsCaps. ddsCaps is of type DDSCAPS2 for DX6
            /* 88*/ DWORD   dwMinOverlayStretch;    // minimum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
            /* 8c*/ DWORD   dwMaxOverlayStretch;    // maximum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
            /* 90*/ DWORD   dwMinLiveVideoStretch;  // minimum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
            /* 94*/ DWORD   dwMaxLiveVideoStretch;  // maximum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
            /* 98*/ DWORD   dwMinHwCodecStretch;    // minimum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
            /* 9c*/ DWORD   dwMaxHwCodecStretch;    // maximum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
            /* a0*/ DWORD   dwReserved1;            // reserved
            /* a4*/ DWORD   dwReserved2;            // reserved
            /* a8*/ DWORD   dwReserved3;            // reserved
            /* ac*/ DWORD   dwSVBCaps;              // driver specific capabilities for System->Vmem blts
            /* b0*/ DWORD   dwSVBCKeyCaps;          // driver color key capabilities for System->Vmem blts
            /* b4*/ DWORD   dwSVBFXCaps;            // driver FX capabilities for System->Vmem blts
            /* b8*/ DWORD   dwSVBRops[DD_ROP_SPACE];// ROPS supported for System->Vmem blts
            /* d8*/ DWORD   dwVSBCaps;              // driver specific capabilities for Vmem->System blts
            /* dc*/ DWORD   dwVSBCKeyCaps;          // driver color key capabilities for Vmem->System blts
            /* e0*/ DWORD   dwVSBFXCaps;            // driver FX capabilities for Vmem->System blts
            /* e4*/ DWORD   dwVSBRops[DD_ROP_SPACE];// ROPS supported for Vmem->System blts
            /*104*/ DWORD   dwSSBCaps;              // driver specific capabilities for System->System blts
            /*108*/ DWORD   dwSSBCKeyCaps;          // driver color key capabilities for System->System blts
            /*10c*/ DWORD   dwSSBFXCaps;            // driver FX capabilities for System->System blts
            /*110*/ DWORD   dwSSBRops[DD_ROP_SPACE];// ROPS supported for System->System blts
            /*130*/ DWORD   dwMaxVideoPorts;        // maximum number of usable video ports
            /*134*/ DWORD   dwCurrVideoPorts;       // current number of video ports used
            /*138*/ DWORD   dwSVBCaps2;             // more driver specific capabilities for System->Vmem blts
            /*13c*/ DWORD   dwNLVBCaps;               // driver specific capabilities for non-local->local vidmem blts
            /*140*/ DWORD   dwNLVBCaps2;              // more driver specific capabilities non-local->local vidmem blts
            /*144*/ DWORD   dwNLVBCKeyCaps;           // driver color key capabilities for non-local->local vidmem blts
            /*148*/ DWORD   dwNLVBFXCaps;             // driver FX capabilities for non-local->local blts
            /*14c*/ DWORD   dwNLVBRops[DD_ROP_SPACE]; // ROPS supported for non-local->local blts
            // Members added for DX6 release
            /*16c*/ DDSCAPS2 ddsCaps;               // Surface Caps
        } DDCAPS_DX7;
        typedef DDCAPS_DX7* LPDDCAPS_DX7;

        typedef DDCAPS_DX7 DDCAPS;

        typedef DDCAPS* LPDDCAPS;


        /*
         * DDPIXELFORMAT
         */
        typedef struct _DDPIXELFORMAT
        {
            DWORD       dwSize;                 // size of structure
            DWORD       dwFlags;                // pixel format flags
            DWORD       dwFourCC;               // (FOURCC code)
            union
            {
                DWORD   dwRGBBitCount;          // how many bits per pixel
                DWORD   dwYUVBitCount;          // how many bits per pixel
                DWORD   dwZBufferBitDepth;      // how many total bits/pixel in z buffer (including any stencil bits)
                DWORD   dwAlphaBitDepth;        // how many bits for alpha channels
                DWORD   dwLuminanceBitCount;    // how many bits per pixel
                DWORD   dwBumpBitCount;         // how many bits per "buxel", total
            };
            union
            {
                DWORD   dwRBitMask;             // mask for red bit
                DWORD   dwYBitMask;             // mask for Y bits
                DWORD   dwStencilBitDepth;      // how many stencil bits (note: dwZBufferBitDepth-dwStencilBitDepth is total Z-only bits)
                DWORD   dwLuminanceBitMask;     // mask for luminance bits
                DWORD   dwBumpDuBitMask;        // mask for bump map U delta bits
            };
            union
            {
                DWORD   dwGBitMask;             // mask for green bits
                DWORD   dwUBitMask;             // mask for U bits
                DWORD   dwZBitMask;             // mask for Z bits
                DWORD   dwBumpDvBitMask;        // mask for bump map V delta bits
            };
            union
            {
                DWORD   dwBBitMask;             // mask for blue bits
                DWORD   dwVBitMask;             // mask for V bits
                DWORD   dwStencilBitMask;       // mask for stencil bits
                DWORD   dwBumpLuminanceBitMask; // mask for luminance in bump map
            };
            union
            {
                DWORD   dwRGBAlphaBitMask;      // mask for alpha channel
                DWORD   dwYUVAlphaBitMask;      // mask for alpha channel
                DWORD   dwLuminanceAlphaBitMask;// mask for alpha channel
                DWORD   dwRGBZBitMask;          // mask for Z channel
                DWORD   dwYUVZBitMask;          // mask for Z channel
            };
        } DDPIXELFORMAT;

        typedef DDPIXELFORMAT* LPDDPIXELFORMAT;

        /*
         * DDOVERLAYFX
         */
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

        typedef DDOVERLAYFX* LPDDOVERLAYFX;


        /*
         * DDBLTBATCH: BltBatch entry structure
         */
        typedef struct _DDBLTBATCH
        {
            LPRECT              lprDest;
            LPDIRECTDRAWSURFACE lpDDSSrc;
            LPRECT              lprSrc;
            DWORD               dwFlags;
            LPDDBLTFX           lpDDBltFx;
        } DDBLTBATCH;

        typedef DDBLTBATCH* LPDDBLTBATCH;


        /*
         * DDGAMMARAMP
         */
        typedef struct _DDGAMMARAMP
        {
            WORD                red[256];
            WORD                green[256];
            WORD                blue[256];
        } DDGAMMARAMP;
        typedef DDGAMMARAMP* LPDDGAMMARAMP;

        /*
         *  This is the structure within which DirectDraw returns data about the current graphics driver and chipset
         */

        const DWORD  MAX_DDDEVICEID_STRING = 512;

        typedef struct tagDDDEVICEIDENTIFIER
        {
            /*
             * These elements are for presentation to the user only. They should not be used to identify particular
             * drivers, since this is unreliable and many different strings may be associated with the same
             * device, and the same driver from different vendors.
             */
            char    szDriver[MAX_DDDEVICEID_STRING];
            char    szDescription[MAX_DDDEVICEID_STRING];

            /*
             * This element is the version of the DirectDraw/3D driver. It is legal to do <, > comparisons
             * on the whole 64 bits. Caution should be exercised if you use this element to identify problematic
             * drivers. It is recommended that guidDeviceIdentifier is used for this purpose.
             *
             * This version has the form:
             *  wProduct = HIWORD(liDriverVersion.HighPart)
             *  wVersion = LOWORD(liDriverVersion.HighPart)
             *  wSubVersion = HIWORD(liDriverVersion.LowPart)
             *  wBuild = LOWORD(liDriverVersion.LowPart)
             */

            LARGE_INTEGER liDriverVersion;      /* Defined for applications and other 32 bit components */


            /*
             * These elements can be used to identify particular chipsets. Use with extreme caution.
             *   dwVendorId     Identifies the manufacturer. May be zero if unknown.
             *   dwDeviceId     Identifies the type of chipset. May be zero if unknown.
             *   dwSubSysId     Identifies the subsystem, typically this means the particular board. May be zero if unknown.
             *   dwRevision     Identifies the revision level of the chipset. May be zero if unknown.
             */
            DWORD   dwVendorId;
            DWORD   dwDeviceId;
            DWORD   dwSubSysId;
            DWORD   dwRevision;

            /*
             * This element can be used to check changes in driver/chipset. This GUID is a unique identifier for the
             * driver/chipset pair. Use this element if you wish to track changes to the driver/chipset in order to
             * reprofile the graphics subsystem.
             * This element can also be used to identify particular problematic drivers.
             */
            GUID    guidDeviceIdentifier;
        } DDDEVICEIDENTIFIER, * LPDDDEVICEIDENTIFIER;

        typedef struct tagDDDEVICEIDENTIFIER2
        {
            /*
             * These elements are for presentation to the user only. They should not be used to identify particular
             * drivers, since this is unreliable and many different strings may be associated with the same
             * device, and the same driver from different vendors.
             */
            char    szDriver[MAX_DDDEVICEID_STRING];
            char    szDescription[MAX_DDDEVICEID_STRING];

            /*
             * This element is the version of the DirectDraw/3D driver. It is legal to do <, > comparisons
             * on the whole 64 bits. Caution should be exercised if you use this element to identify problematic
             * drivers. It is recommended that guidDeviceIdentifier is used for this purpose.
             *
             * This version has the form:
             *  wProduct = HIWORD(liDriverVersion.HighPart)
             *  wVersion = LOWORD(liDriverVersion.HighPart)
             *  wSubVersion = HIWORD(liDriverVersion.LowPart)
             *  wBuild = LOWORD(liDriverVersion.LowPart)
             */

            LARGE_INTEGER liDriverVersion;      /* Defined for applications and other 32 bit components */


            /*
             * These elements can be used to identify particular chipsets. Use with extreme caution.
             *   dwVendorId     Identifies the manufacturer. May be zero if unknown.
             *   dwDeviceId     Identifies the type of chipset. May be zero if unknown.
             *   dwSubSysId     Identifies the subsystem, typically this means the particular board. May be zero if unknown.
             *   dwRevision     Identifies the revision level of the chipset. May be zero if unknown.
             */
            DWORD   dwVendorId;
            DWORD   dwDeviceId;
            DWORD   dwSubSysId;
            DWORD   dwRevision;

            /*
             * This element can be used to check changes in driver/chipset. This GUID is a unique identifier for the
             * driver/chipset pair. Use this element if you wish to track changes to the driver/chipset in order to
             * reprofile the graphics subsystem.
             * This element can also be used to identify particular problematic drivers.
             */
            GUID    guidDeviceIdentifier;

            /*
             * This element is used to determine the Windows Hardware Quality Lab (WHQL)
             * certification level for this driver/device pair.
             */
            DWORD   dwWHQLLevel;

        } DDDEVICEIDENTIFIER2, * LPDDDEVICEIDENTIFIER2;

        /*
         * Flags for the IDirectDraw4::GetDeviceIdentifier method
         */

         /*
          * This flag causes GetDeviceIdentifier to return information about the host (typically 2D) adapter in a system equipped
          * with a stacked secondary 3D adapter. Such an adapter appears to the application as if it were part of the
          * host adapter, but is typically physcially located on a separate card. The stacked secondary's information is
          * returned when GetDeviceIdentifier's dwFlags field is zero, since this most accurately reflects the qualities
          * of the DirectDraw object involved.
          */
        const DWORD  DDGDI_GETHOSTIDENTIFIER = 0x00000001L;

        /*
         * Macros for interpretting DDEVICEIDENTIFIER2.dwWHQLLevel
         */
        inline DWORD  GET_WHQL_YEAR(DWORD dwWHQLLevel)
        {
            return (dwWHQLLevel / 0x10000);
        }

        inline DWORD  GET_WHQL_MONTH(DWORD dwWHQLLevel)
        {
            return ((dwWHQLLevel / 0x100) & 0x00ff);
        }

        inline DWORD  GET_WHQL_DAY(DWORD dwWHQLLevel)
        {
            return (dwWHQLLevel & 0xff);
        }

        /*
         * callbacks
         */
        typedef DWORD(LDL_CALL* LPCLIPPERCALLBACK)(LPDIRECTDRAWCLIPPER lpDDClipper, HWND hWnd, DWORD code, LPVOID lpContext);


        /*
         * INTERACES FOLLOW:
         *      IDirectDraw
         *      IDirectDrawClipper
         *      IDirectDrawPalette
         *      IDirectDrawSurface
         */

         /*
          * IDirectDraw
          */

        struct  IDirectDraw : IUnknown
        {
            /*** IUnknown methods ***/
            virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
            virtual ULONG LDL_CALL AddRef() = 0;
            virtual ULONG LDL_CALL Release() = 0;
            /*** IDirectDraw methods ***/
            virtual HRESULT LDL_CALL Compact() = 0;
            virtual HRESULT LDL_CALL CreateClipper(DWORD, LPDIRECTDRAWCLIPPER*, IUnknown*) = 0;
            virtual HRESULT LDL_CALL CreatePalette(DWORD, LPPALETTEENTRY, LPDIRECTDRAWPALETTE*, IUnknown*) = 0;
            virtual HRESULT LDL_CALL CreateSurface(LPDDSURFACEDESC, LPDIRECTDRAWSURFACE*, IUnknown*) = 0;
            virtual HRESULT LDL_CALL DuplicateSurface(LPDIRECTDRAWSURFACE, LPDIRECTDRAWSURFACE*) = 0;
            virtual HRESULT LDL_CALL EnumDisplayModes(DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMMODESCALLBACK) = 0;
            virtual HRESULT LDL_CALL EnumSurfaces(DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMSURFACESCALLBACK) = 0;
            virtual HRESULT LDL_CALL FlipToGDISurface() = 0;
            virtual HRESULT LDL_CALL GetCaps(LPDDCAPS, LPDDCAPS) = 0;
            virtual HRESULT LDL_CALL GetDisplayMode(LPDDSURFACEDESC) = 0;
            virtual HRESULT LDL_CALL GetFourCCCodes(LPDWORD, LPDWORD) = 0;
            virtual HRESULT LDL_CALL GetGDISurface(LPDIRECTDRAWSURFACE*) = 0;
            virtual HRESULT LDL_CALL GetMonitorFrequency(LPDWORD) = 0;
            virtual HRESULT LDL_CALL GetScanLine(LPDWORD) = 0;
            virtual HRESULT LDL_CALL GetVerticalBlankStatus(LPBOOL) = 0;
            virtual HRESULT LDL_CALL Initialize(GUID*) = 0;
            virtual HRESULT LDL_CALL RestoreDisplayMode() = 0;
            virtual HRESULT LDL_CALL SetCooperativeLevel(HWND, DWORD) = 0;
            virtual HRESULT LDL_CALL SetDisplayMode(DWORD, DWORD, DWORD) = 0;
            virtual HRESULT LDL_CALL WaitForVerticalBlank(DWORD, HANDLE) = 0;
        };

        struct  IDirectDraw2 : IUnknown
        {
            /*** IUnknown methods ***/
            virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
            virtual ULONG LDL_CALL AddRef() = 0;
            virtual ULONG LDL_CALL Release() = 0;
            /*** IDirectDraw methods ***/
            virtual HRESULT LDL_CALL Compact() = 0;
            virtual HRESULT LDL_CALL CreateClipper(DWORD, LPDIRECTDRAWCLIPPER*, IUnknown*) = 0;
            virtual HRESULT LDL_CALL CreatePalette(DWORD, LPPALETTEENTRY, LPDIRECTDRAWPALETTE*, IUnknown*) = 0;
            virtual HRESULT LDL_CALL CreateSurface(LPDDSURFACEDESC, LPDIRECTDRAWSURFACE*, IUnknown*) = 0;
            virtual HRESULT LDL_CALL DuplicateSurface(LPDIRECTDRAWSURFACE, LPDIRECTDRAWSURFACE*) = 0;
            virtual HRESULT LDL_CALL EnumDisplayModes(DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMMODESCALLBACK) = 0;
            virtual HRESULT LDL_CALL EnumSurfaces(DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMSURFACESCALLBACK) = 0;
            virtual HRESULT LDL_CALL FlipToGDISurface() = 0;
            virtual HRESULT LDL_CALL GetCaps(LPDDCAPS, LPDDCAPS) = 0;
            virtual HRESULT LDL_CALL GetDisplayMode(LPDDSURFACEDESC) = 0;
            virtual HRESULT LDL_CALL GetFourCCCodes(LPDWORD, LPDWORD) = 0;
            virtual HRESULT LDL_CALL GetGDISurface(LPDIRECTDRAWSURFACE*) = 0;
            virtual HRESULT LDL_CALL GetMonitorFrequency(LPDWORD) = 0;
            virtual HRESULT LDL_CALL GetScanLine(LPDWORD) = 0;
            virtual HRESULT LDL_CALL GetVerticalBlankStatus(LPBOOL) = 0;
            virtual HRESULT LDL_CALL Initialize(GUID*) = 0;
            virtual HRESULT LDL_CALL RestoreDisplayMode() = 0;
            virtual HRESULT LDL_CALL SetCooperativeLevel(HWND, DWORD) = 0;
            virtual HRESULT LDL_CALL SetDisplayMode(DWORD, DWORD, DWORD, DWORD, DWORD) = 0;
            virtual HRESULT LDL_CALL WaitForVerticalBlank(DWORD, HANDLE) = 0;
            /*** Added in the v2 interface ***/
            virtual HRESULT LDL_CALL GetAvailableVidMem(LPDDSCAPS, LPDWORD, LPDWORD) = 0;
        };

        struct  IDirectDraw4 : IUnknown
        {
            /*** IUnknown methods ***/
            virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
            virtual ULONG LDL_CALL AddRef() = 0;
            virtual ULONG LDL_CALL Release() = 0;
            /*** IDirectDraw methods ***/
            virtual HRESULT LDL_CALL Compact() = 0;
            virtual HRESULT LDL_CALL CreateClipper(DWORD, LPDIRECTDRAWCLIPPER*, IUnknown*) = 0;
            virtual HRESULT LDL_CALL CreatePalette(DWORD, LPPALETTEENTRY, LPDIRECTDRAWPALETTE*, IUnknown*) = 0;
            virtual HRESULT LDL_CALL CreateSurface(LPDDSURFACEDESC2, LPDIRECTDRAWSURFACE4*, IUnknown*) = 0;
            virtual HRESULT LDL_CALL DuplicateSurface(LPDIRECTDRAWSURFACE4, LPDIRECTDRAWSURFACE4*) = 0;
            virtual HRESULT LDL_CALL EnumDisplayModes(DWORD, LPDDSURFACEDESC2, LPVOID, LPDDENUMMODESCALLBACK2) = 0;
            virtual HRESULT LDL_CALL EnumSurfaces(DWORD, LPDDSURFACEDESC2, LPVOID, LPDDENUMSURFACESCALLBACK2) = 0;
            virtual HRESULT LDL_CALL FlipToGDISurface() = 0;
            virtual HRESULT LDL_CALL GetCaps(LPDDCAPS, LPDDCAPS) = 0;
            virtual HRESULT LDL_CALL GetDisplayMode(LPDDSURFACEDESC2) = 0;
            virtual HRESULT LDL_CALL GetFourCCCodes(LPDWORD, LPDWORD) = 0;
            virtual HRESULT LDL_CALL GetGDISurface(LPDIRECTDRAWSURFACE4*) = 0;
            virtual HRESULT LDL_CALL GetMonitorFrequency(LPDWORD) = 0;
            virtual HRESULT LDL_CALL GetScanLine(LPDWORD) = 0;
            virtual HRESULT LDL_CALL GetVerticalBlankStatus(LPBOOL) = 0;
            virtual HRESULT LDL_CALL Initialize(GUID*) = 0;
            virtual HRESULT LDL_CALL RestoreDisplayMode() = 0;
            virtual HRESULT LDL_CALL SetCooperativeLevel(HWND, DWORD) = 0;
            virtual HRESULT LDL_CALL SetDisplayMode(DWORD, DWORD, DWORD, DWORD, DWORD) = 0;
            virtual HRESULT LDL_CALL WaitForVerticalBlank(DWORD, HANDLE) = 0;
            /*** Added in the v2 interface ***/
            virtual HRESULT LDL_CALL GetAvailableVidMem(LPDDSCAPS2, LPDWORD, LPDWORD) = 0;
            /*** Added in the V4 Interface ***/
            virtual HRESULT LDL_CALL GetSurfaceFromDC(HDC, LPDIRECTDRAWSURFACE4*) = 0;
            virtual HRESULT LDL_CALL RestoreAllSurfaces() = 0;
            virtual HRESULT LDL_CALL TestCooperativeLevel() = 0;
            virtual HRESULT LDL_CALL GetDeviceIdentifier(LPDDDEVICEIDENTIFIER, DWORD) = 0;
        };

        struct  IDirectDraw7 : IUnknown
        {
            /*** IUnknown methods ***/
            virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
            virtual ULONG LDL_CALL AddRef() = 0;
            virtual ULONG LDL_CALL Release() = 0;
            /*** IDirectDraw methods ***/
            virtual HRESULT LDL_CALL Compact() = 0;
            virtual HRESULT LDL_CALL CreateClipper(DWORD, LPDIRECTDRAWCLIPPER*, IUnknown*) = 0;
            virtual HRESULT LDL_CALL CreatePalette(DWORD, LPPALETTEENTRY, LPDIRECTDRAWPALETTE*, IUnknown*) = 0;
            virtual HRESULT LDL_CALL CreateSurface(LPDDSURFACEDESC2, LPDIRECTDRAWSURFACE7*, IUnknown*) = 0;
            virtual HRESULT LDL_CALL DuplicateSurface(LPDIRECTDRAWSURFACE7, LPDIRECTDRAWSURFACE7*) = 0;
            virtual HRESULT LDL_CALL EnumDisplayModes(DWORD, LPDDSURFACEDESC2, LPVOID, LPDDENUMMODESCALLBACK2) = 0;
            virtual HRESULT LDL_CALL EnumSurfaces(DWORD, LPDDSURFACEDESC2, LPVOID, LPDDENUMSURFACESCALLBACK7) = 0;
            virtual HRESULT LDL_CALL FlipToGDISurface() = 0;
            virtual HRESULT LDL_CALL GetCaps(LPDDCAPS, LPDDCAPS) = 0;
            virtual HRESULT LDL_CALL GetDisplayMode(LPDDSURFACEDESC2) = 0;
            virtual HRESULT LDL_CALL GetFourCCCodes(LPDWORD, LPDWORD) = 0;
            virtual HRESULT LDL_CALL GetGDISurface(LPDIRECTDRAWSURFACE7*) = 0;
            virtual HRESULT LDL_CALL GetMonitorFrequency(LPDWORD) = 0;
            virtual HRESULT LDL_CALL GetScanLine(LPDWORD) = 0;
            virtual HRESULT LDL_CALL GetVerticalBlankStatus(LPBOOL) = 0;
            virtual HRESULT LDL_CALL Initialize(GUID*) = 0;
            virtual HRESULT LDL_CALL RestoreDisplayMode() = 0;
            virtual HRESULT LDL_CALL SetCooperativeLevel(HWND, DWORD) = 0;
            virtual HRESULT LDL_CALL SetDisplayMode(DWORD, DWORD, DWORD, DWORD, DWORD) = 0;
            virtual HRESULT LDL_CALL WaitForVerticalBlank(DWORD, HANDLE) = 0;
            /*** Added in the v2 interface ***/
            virtual HRESULT LDL_CALL GetAvailableVidMem(LPDDSCAPS2, LPDWORD, LPDWORD) = 0;
            /*** Added in the V4 Interface ***/
            virtual HRESULT LDL_CALL GetSurfaceFromDC(HDC, LPDIRECTDRAWSURFACE7*) = 0;
            virtual HRESULT LDL_CALL RestoreAllSurfaces() = 0;
            virtual HRESULT LDL_CALL TestCooperativeLevel() = 0;
            virtual HRESULT LDL_CALL GetDeviceIdentifier(LPDDDEVICEIDENTIFIER2, DWORD) = 0;
            virtual HRESULT LDL_CALL StartModeTest(LPSIZE, DWORD, DWORD) = 0;
            virtual HRESULT LDL_CALL EvaluateMode(DWORD, DWORD*) = 0;
        };

        struct  IDirectDrawPalette : IUnknown
        {
            /*** IUnknown methods ***/
            virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
            virtual ULONG LDL_CALL AddRef() = 0;
            virtual ULONG LDL_CALL Release() = 0;
            /*** IDirectDrawPalette methods ***/
            virtual HRESULT LDL_CALL GetCaps(LPDWORD) = 0;
            virtual HRESULT LDL_CALL GetEntries(DWORD, DWORD, DWORD, LPPALETTEENTRY) = 0;
            virtual HRESULT LDL_CALL Initialize(LPDIRECTDRAW, DWORD, LPPALETTEENTRY) = 0;
            virtual HRESULT LDL_CALL SetEntries(DWORD, DWORD, DWORD, LPPALETTEENTRY) = 0;
        };

        /*
         * IDirectDrawClipper
         */
        struct  IDirectDrawClipper : IUnknown
        {
            /*** IUnknown methods ***/
            virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
            virtual ULONG LDL_CALL AddRef() = 0;
            virtual ULONG LDL_CALL Release() = 0;
            /*** IDirectDrawClipper methods ***/
            virtual HRESULT LDL_CALL GetClipList(LPRECT, LPRGNDATA, LPDWORD) = 0;
            virtual HRESULT LDL_CALL GetHWnd(HWND*) = 0;
            virtual HRESULT LDL_CALL Initialize(LPDIRECTDRAW, DWORD) = 0;
            virtual HRESULT LDL_CALL IsClipListChanged(BOOL*) = 0;
            virtual HRESULT LDL_CALL SetClipList(LPRGNDATA, DWORD) = 0;
            virtual HRESULT LDL_CALL SetHWnd(DWORD, HWND) = 0;
        };

        /*
         * IDirectDrawSurface and related interfaces
         */

        struct  IDirectDrawSurface : IUnknown
        {
            /*** IUnknown methods ***/
            virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
            virtual ULONG LDL_CALL AddRef() = 0;
            virtual ULONG LDL_CALL Release() = 0;
            /*** IDirectDrawSurface methods ***/
            virtual HRESULT LDL_CALL AddAttachedSurface(LPDIRECTDRAWSURFACE) = 0;
            virtual HRESULT LDL_CALL AddOverlayDirtyRect(LPRECT) = 0;
            virtual HRESULT LDL_CALL Blt(LPRECT, LPDIRECTDRAWSURFACE, LPRECT, DWORD, LPDDBLTFX) = 0;
            virtual HRESULT LDL_CALL BltBatch(LPDDBLTBATCH, DWORD, DWORD) = 0;
            virtual HRESULT LDL_CALL BltFast(DWORD, DWORD, LPDIRECTDRAWSURFACE, LPRECT, DWORD) = 0;
            virtual HRESULT LDL_CALL DeleteAttachedSurface(DWORD, LPDIRECTDRAWSURFACE) = 0;
            virtual HRESULT LDL_CALL EnumAttachedSurfaces(LPVOID, LPDDENUMSURFACESCALLBACK) = 0;
            virtual HRESULT LDL_CALL EnumOverlayZOrders(DWORD, LPVOID, LPDDENUMSURFACESCALLBACK) = 0;
            virtual HRESULT LDL_CALL Flip(LPDIRECTDRAWSURFACE, DWORD) = 0;
            virtual HRESULT LDL_CALL GetAttachedSurface(LPDDSCAPS, LPDIRECTDRAWSURFACE*) = 0;
            virtual HRESULT LDL_CALL GetBltStatus(DWORD) = 0;
            virtual HRESULT LDL_CALL GetCaps(LPDDSCAPS) = 0;
            virtual HRESULT LDL_CALL GetClipper(LPDIRECTDRAWCLIPPER*) = 0;
            virtual HRESULT LDL_CALL GetColorKey(DWORD, LPDDCOLORKEY) = 0;
            virtual HRESULT LDL_CALL GetDC(HDC*) = 0;
            virtual HRESULT LDL_CALL GetFlipStatus(DWORD) = 0;
            virtual HRESULT LDL_CALL GetOverlayPosition(LPLONG, LPLONG) = 0;
            virtual HRESULT LDL_CALL GetPalette(LPDIRECTDRAWPALETTE*) = 0;
            virtual HRESULT LDL_CALL GetPixelFormat(LPDDPIXELFORMAT) = 0;
            virtual HRESULT LDL_CALL GetSurfaceDesc(LPDDSURFACEDESC) = 0;
            virtual HRESULT LDL_CALL Initialize(LPDIRECTDRAW, LPDDSURFACEDESC) = 0;
            virtual HRESULT LDL_CALL IsLost() = 0;
            virtual HRESULT LDL_CALL Lock(LPRECT, LPDDSURFACEDESC, DWORD, HANDLE) = 0;
            virtual HRESULT LDL_CALL ReleaseDC(HDC) = 0;
            virtual HRESULT LDL_CALL Restore() = 0;
            virtual HRESULT LDL_CALL SetClipper(LPDIRECTDRAWCLIPPER) = 0;
            virtual HRESULT LDL_CALL SetColorKey(DWORD, LPDDCOLORKEY) = 0;
            virtual HRESULT LDL_CALL SetOverlayPosition(LONG, LONG) = 0;
            virtual HRESULT LDL_CALL SetPalette(LPDIRECTDRAWPALETTE) = 0;
            virtual HRESULT LDL_CALL Unlock(LPVOID) = 0;
            virtual HRESULT LDL_CALL UpdateOverlay(LPRECT, LPDIRECTDRAWSURFACE, LPRECT, DWORD, LPDDOVERLAYFX) = 0;
            virtual HRESULT LDL_CALL UpdateOverlayDisplay(DWORD) = 0;
            virtual HRESULT LDL_CALL UpdateOverlayZOrder(DWORD, LPDIRECTDRAWSURFACE) = 0;
        };

        struct  IDirectDrawSurface2 : IUnknown
        {
            /*** IUnknown methods ***/
            virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
            virtual ULONG LDL_CALL AddRef() = 0;
            virtual ULONG LDL_CALL Release() = 0;
            /*** IDirectDrawSurface methods ***/
            virtual HRESULT LDL_CALL AddAttachedSurface(LPDIRECTDRAWSURFACE2) = 0;
            virtual HRESULT LDL_CALL AddOverlayDirtyRect(LPRECT) = 0;
            virtual HRESULT LDL_CALL Blt(LPRECT, LPDIRECTDRAWSURFACE2, LPRECT, DWORD, LPDDBLTFX) = 0;
            virtual HRESULT LDL_CALL BltBatch(LPDDBLTBATCH, DWORD, DWORD) = 0;
            virtual HRESULT LDL_CALL BltFast(DWORD, DWORD, LPDIRECTDRAWSURFACE2, LPRECT, DWORD) = 0;
            virtual HRESULT LDL_CALL DeleteAttachedSurface(DWORD, LPDIRECTDRAWSURFACE2) = 0;
            virtual HRESULT LDL_CALL EnumAttachedSurfaces(LPVOID, LPDDENUMSURFACESCALLBACK) = 0;
            virtual HRESULT LDL_CALL EnumOverlayZOrders(DWORD, LPVOID, LPDDENUMSURFACESCALLBACK) = 0;
            virtual HRESULT LDL_CALL Flip(LPDIRECTDRAWSURFACE2, DWORD) = 0;
            virtual HRESULT LDL_CALL GetAttachedSurface(LPDDSCAPS, LPDIRECTDRAWSURFACE2*) = 0;
            virtual HRESULT LDL_CALL GetBltStatus(DWORD) = 0;
            virtual HRESULT LDL_CALL GetCaps(LPDDSCAPS) = 0;
            virtual HRESULT LDL_CALL GetClipper(LPDIRECTDRAWCLIPPER*) = 0;
            virtual HRESULT LDL_CALL GetColorKey(DWORD, LPDDCOLORKEY) = 0;
            virtual HRESULT LDL_CALL GetDC(HDC*) = 0;
            virtual HRESULT LDL_CALL GetFlipStatus(DWORD) = 0;
            virtual HRESULT LDL_CALL GetOverlayPosition(LPLONG, LPLONG) = 0;
            virtual HRESULT LDL_CALL GetPalette(LPDIRECTDRAWPALETTE*) = 0;
            virtual HRESULT LDL_CALL GetPixelFormat(LPDDPIXELFORMAT) = 0;
            virtual HRESULT LDL_CALL GetSurfaceDesc(LPDDSURFACEDESC) = 0;
            virtual HRESULT LDL_CALL Initialize(LPDIRECTDRAW, LPDDSURFACEDESC) = 0;
            virtual HRESULT LDL_CALL IsLost() = 0;
            virtual HRESULT LDL_CALL Lock(LPRECT, LPDDSURFACEDESC, DWORD, HANDLE) = 0;
            virtual HRESULT LDL_CALL ReleaseDC(HDC) = 0;
            virtual HRESULT LDL_CALL Restore() = 0;
            virtual HRESULT LDL_CALL SetClipper(LPDIRECTDRAWCLIPPER) = 0;
            virtual HRESULT LDL_CALL SetColorKey(DWORD, LPDDCOLORKEY) = 0;
            virtual HRESULT LDL_CALL SetOverlayPosition(LONG, LONG) = 0;
            virtual HRESULT LDL_CALL SetPalette(LPDIRECTDRAWPALETTE) = 0;
            virtual HRESULT LDL_CALL Unlock(LPVOID) = 0;
            virtual HRESULT LDL_CALL UpdateOverlay(LPRECT, LPDIRECTDRAWSURFACE2, LPRECT, DWORD, LPDDOVERLAYFX) = 0;
            virtual HRESULT LDL_CALL UpdateOverlayDisplay(DWORD) = 0;
            virtual HRESULT LDL_CALL UpdateOverlayZOrder(DWORD, LPDIRECTDRAWSURFACE2) = 0;
            /*** Added in the v2 interface ***/
            virtual HRESULT LDL_CALL GetDDInterface(LPVOID*) = 0;
            virtual HRESULT LDL_CALL PageLock(DWORD) = 0;
            virtual HRESULT LDL_CALL PageUnlock(DWORD) = 0;
        };

        /*
         * IDirectDrawSurface3 and related interfaces
         */

        struct  IDirectDrawSurface3 : IUnknown
        {
            /*** IUnknown methods ***/
            virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
            virtual ULONG LDL_CALL AddRef() = 0;
            virtual ULONG LDL_CALL Release() = 0;
            /*** IDirectDrawSurface methods ***/
            virtual HRESULT LDL_CALL AddAttachedSurface(LPDIRECTDRAWSURFACE3) = 0;
            virtual HRESULT LDL_CALL AddOverlayDirtyRect(LPRECT) = 0;
            virtual HRESULT LDL_CALL Blt(LPRECT, LPDIRECTDRAWSURFACE3, LPRECT, DWORD, LPDDBLTFX) = 0;
            virtual HRESULT LDL_CALL BltBatch(LPDDBLTBATCH, DWORD, DWORD) = 0;
            virtual HRESULT LDL_CALL BltFast(DWORD, DWORD, LPDIRECTDRAWSURFACE3, LPRECT, DWORD) = 0;
            virtual HRESULT LDL_CALL DeleteAttachedSurface(DWORD, LPDIRECTDRAWSURFACE3) = 0;
            virtual HRESULT LDL_CALL EnumAttachedSurfaces(LPVOID, LPDDENUMSURFACESCALLBACK) = 0;
            virtual HRESULT LDL_CALL EnumOverlayZOrders(DWORD, LPVOID, LPDDENUMSURFACESCALLBACK) = 0;
            virtual HRESULT LDL_CALL Flip(LPDIRECTDRAWSURFACE3, DWORD) = 0;
            virtual HRESULT LDL_CALL GetAttachedSurface(LPDDSCAPS, LPDIRECTDRAWSURFACE3*) = 0;
            virtual HRESULT LDL_CALL GetBltStatus(DWORD) = 0;
            virtual HRESULT LDL_CALL GetCaps(LPDDSCAPS) = 0;
            virtual HRESULT LDL_CALL GetClipper(LPDIRECTDRAWCLIPPER*) = 0;
            virtual HRESULT LDL_CALL GetColorKey(DWORD, LPDDCOLORKEY) = 0;
            virtual HRESULT LDL_CALL GetDC(HDC*) = 0;
            virtual HRESULT LDL_CALL GetFlipStatus(DWORD) = 0;
            virtual HRESULT LDL_CALL GetOverlayPosition(LPLONG, LPLONG) = 0;
            virtual HRESULT LDL_CALL GetPalette(LPDIRECTDRAWPALETTE*) = 0;
            virtual HRESULT LDL_CALL GetPixelFormat(LPDDPIXELFORMAT) = 0;
            virtual HRESULT LDL_CALL GetSurfaceDesc(LPDDSURFACEDESC) = 0;
            virtual HRESULT LDL_CALL Initialize(LPDIRECTDRAW, LPDDSURFACEDESC) = 0;
            virtual HRESULT LDL_CALL IsLost() = 0;
            virtual HRESULT LDL_CALL Lock(LPRECT, LPDDSURFACEDESC, DWORD, HANDLE) = 0;
            virtual HRESULT LDL_CALL ReleaseDC(HDC) = 0;
            virtual HRESULT LDL_CALL Restore() = 0;
            virtual HRESULT LDL_CALL SetClipper(LPDIRECTDRAWCLIPPER) = 0;
            virtual HRESULT LDL_CALL SetColorKey(DWORD, LPDDCOLORKEY) = 0;
            virtual HRESULT LDL_CALL SetOverlayPosition(LONG, LONG) = 0;
            virtual HRESULT LDL_CALL SetPalette(LPDIRECTDRAWPALETTE) = 0;
            virtual HRESULT LDL_CALL Unlock(LPVOID) = 0;
            virtual HRESULT LDL_CALL UpdateOverlay(LPRECT, LPDIRECTDRAWSURFACE3, LPRECT, DWORD, LPDDOVERLAYFX) = 0;
            virtual HRESULT LDL_CALL UpdateOverlayDisplay(DWORD) = 0;
            virtual HRESULT LDL_CALL UpdateOverlayZOrder(DWORD, LPDIRECTDRAWSURFACE3) = 0;
            /*** Added in the v2 interface ***/
            virtual HRESULT LDL_CALL GetDDInterface(LPVOID*) = 0;
            virtual HRESULT LDL_CALL PageLock(DWORD) = 0;
            virtual HRESULT LDL_CALL PageUnlock(DWORD) = 0;
            /*** Added in the V3 interface ***/
            virtual HRESULT LDL_CALL SetSurfaceDesc(LPDDSURFACEDESC, DWORD) = 0;
        };

        struct  IDirectDrawSurface4 : IUnknown
        {
            /*** IUnknown methods ***/
            virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
            virtual ULONG LDL_CALL AddRef() = 0;
            virtual ULONG LDL_CALL Release() = 0;
            /*** IDirectDrawSurface methods ***/
            virtual HRESULT LDL_CALL AddAttachedSurface(LPDIRECTDRAWSURFACE4) = 0;
            virtual HRESULT LDL_CALL AddOverlayDirtyRect(LPRECT) = 0;
            virtual HRESULT LDL_CALL Blt(LPRECT, LPDIRECTDRAWSURFACE4, LPRECT, DWORD, LPDDBLTFX) = 0;
            virtual HRESULT LDL_CALL BltBatch(LPDDBLTBATCH, DWORD, DWORD) = 0;
            virtual HRESULT LDL_CALL BltFast(DWORD, DWORD, LPDIRECTDRAWSURFACE4, LPRECT, DWORD) = 0;
            virtual HRESULT LDL_CALL DeleteAttachedSurface(DWORD, LPDIRECTDRAWSURFACE4) = 0;
            virtual HRESULT LDL_CALL EnumAttachedSurfaces(LPVOID, LPDDENUMSURFACESCALLBACK2) = 0;
            virtual HRESULT LDL_CALL EnumOverlayZOrders(DWORD, LPVOID, LPDDENUMSURFACESCALLBACK2) = 0;
            virtual HRESULT LDL_CALL Flip(LPDIRECTDRAWSURFACE4, DWORD) = 0;
            virtual HRESULT LDL_CALL GetAttachedSurface(LPDDSCAPS2, LPDIRECTDRAWSURFACE4*) = 0;
            virtual HRESULT LDL_CALL GetBltStatus(DWORD) = 0;
            virtual HRESULT LDL_CALL GetCaps(LPDDSCAPS2) = 0;
            virtual HRESULT LDL_CALL GetClipper(LPDIRECTDRAWCLIPPER*) = 0;
            virtual HRESULT LDL_CALL GetColorKey(DWORD, LPDDCOLORKEY) = 0;
            virtual HRESULT LDL_CALL GetDC(HDC*) = 0;
            virtual HRESULT LDL_CALL GetFlipStatus(DWORD) = 0;
            virtual HRESULT LDL_CALL GetOverlayPosition(LPLONG, LPLONG) = 0;
            virtual HRESULT LDL_CALL GetPalette(LPDIRECTDRAWPALETTE*) = 0;
            virtual HRESULT LDL_CALL GetPixelFormat(LPDDPIXELFORMAT) = 0;
            virtual HRESULT LDL_CALL GetSurfaceDesc(LPDDSURFACEDESC2) = 0;
            virtual HRESULT LDL_CALL Initialize(LPDIRECTDRAW, LPDDSURFACEDESC2) = 0;
            virtual HRESULT LDL_CALL IsLost() = 0;
            virtual HRESULT LDL_CALL Lock(LPRECT, LPDDSURFACEDESC2, DWORD, HANDLE) = 0;
            virtual HRESULT LDL_CALL ReleaseDC(HDC) = 0;
            virtual HRESULT LDL_CALL Restore() = 0;
            virtual HRESULT LDL_CALL SetClipper(LPDIRECTDRAWCLIPPER) = 0;
            virtual HRESULT LDL_CALL SetColorKey(DWORD, LPDDCOLORKEY) = 0;
            virtual HRESULT LDL_CALL SetOverlayPosition(LONG, LONG) = 0;
            virtual HRESULT LDL_CALL SetPalette(LPDIRECTDRAWPALETTE) = 0;
            virtual HRESULT LDL_CALL Unlock(LPRECT) = 0;
            virtual HRESULT LDL_CALL UpdateOverlay(LPRECT, LPDIRECTDRAWSURFACE4, LPRECT, DWORD, LPDDOVERLAYFX) = 0;
            virtual HRESULT LDL_CALL UpdateOverlayDisplay(DWORD) = 0;
            virtual HRESULT LDL_CALL UpdateOverlayZOrder(DWORD, LPDIRECTDRAWSURFACE4) = 0;
            /*** Added in the v2 interface ***/
            virtual HRESULT LDL_CALL GetDDInterface(LPVOID*) = 0;
            virtual HRESULT LDL_CALL PageLock(DWORD) = 0;
            virtual HRESULT LDL_CALL PageUnlock(DWORD) = 0;
            /*** Added in the v3 interface ***/
            virtual HRESULT LDL_CALL SetSurfaceDesc(LPDDSURFACEDESC2, DWORD) = 0;
            /*** Added in the v4 interface ***/
            virtual HRESULT LDL_CALL SetPrivateData(const GUID&, LPVOID, DWORD, DWORD) = 0;
            virtual HRESULT LDL_CALL GetPrivateData(const GUID&, LPVOID, LPDWORD) = 0;
            virtual HRESULT LDL_CALL FreePrivateData(const GUID&) = 0;
            virtual HRESULT LDL_CALL GetUniquenessValue(LPDWORD) = 0;
            virtual HRESULT LDL_CALL ChangeUniquenessValue() = 0;
        };

        struct  IDirectDrawSurface7 : IUnknown
        {
            /*** IUnknown methods ***/
            virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
            virtual ULONG LDL_CALL AddRef() = 0;
            virtual ULONG LDL_CALL Release() = 0;
            /*** IDirectDrawSurface methods ***/
            virtual HRESULT LDL_CALL AddAttachedSurface(LPDIRECTDRAWSURFACE7) = 0;
            virtual HRESULT LDL_CALL AddOverlayDirtyRect(LPRECT) = 0;
            virtual HRESULT LDL_CALL Blt(LPRECT, LPDIRECTDRAWSURFACE7, LPRECT, DWORD, LPDDBLTFX) = 0;
            virtual HRESULT LDL_CALL BltBatch(LPDDBLTBATCH, DWORD, DWORD) = 0;
            virtual HRESULT LDL_CALL BltFast(DWORD, DWORD, LPDIRECTDRAWSURFACE7, LPRECT, DWORD) = 0;
            virtual HRESULT LDL_CALL DeleteAttachedSurface(DWORD, LPDIRECTDRAWSURFACE7) = 0;
            virtual HRESULT LDL_CALL EnumAttachedSurfaces(LPVOID, LPDDENUMSURFACESCALLBACK7) = 0;
            virtual HRESULT LDL_CALL EnumOverlayZOrders(DWORD, LPVOID, LPDDENUMSURFACESCALLBACK7) = 0;
            virtual HRESULT LDL_CALL Flip(LPDIRECTDRAWSURFACE7, DWORD) = 0;
            virtual HRESULT LDL_CALL GetAttachedSurface(LPDDSCAPS2, LPDIRECTDRAWSURFACE7*) = 0;
            virtual HRESULT LDL_CALL GetBltStatus(DWORD) = 0;
            virtual HRESULT LDL_CALL GetCaps(LPDDSCAPS2) = 0;
            virtual HRESULT LDL_CALL GetClipper(LPDIRECTDRAWCLIPPER*) = 0;
            virtual HRESULT LDL_CALL GetColorKey(DWORD, LPDDCOLORKEY) = 0;
            virtual HRESULT LDL_CALL GetDC(HDC*) = 0;
            virtual HRESULT LDL_CALL GetFlipStatus(DWORD) = 0;
            virtual HRESULT LDL_CALL GetOverlayPosition(LPLONG, LPLONG) = 0;
            virtual HRESULT LDL_CALL GetPalette(LPDIRECTDRAWPALETTE*) = 0;
            virtual HRESULT LDL_CALL GetPixelFormat(LPDDPIXELFORMAT) = 0;
            virtual HRESULT LDL_CALL GetSurfaceDesc(LPDDSURFACEDESC2) = 0;
            virtual HRESULT LDL_CALL Initialize(LPDIRECTDRAW, LPDDSURFACEDESC2) = 0;
            virtual HRESULT LDL_CALL IsLost() = 0;
            virtual HRESULT LDL_CALL Lock(LPRECT, LPDDSURFACEDESC2, DWORD, HANDLE) = 0;
            virtual HRESULT LDL_CALL ReleaseDC(HDC) = 0;
            virtual HRESULT LDL_CALL Restore() = 0;
            virtual HRESULT LDL_CALL SetClipper(LPDIRECTDRAWCLIPPER) = 0;
            virtual HRESULT LDL_CALL SetColorKey(DWORD, LPDDCOLORKEY) = 0;
            virtual HRESULT LDL_CALL SetOverlayPosition(LONG, LONG) = 0;
            virtual HRESULT LDL_CALL SetPalette(LPDIRECTDRAWPALETTE) = 0;
            virtual HRESULT LDL_CALL Unlock(LPRECT) = 0;
            virtual HRESULT LDL_CALL UpdateOverlay(LPRECT, LPDIRECTDRAWSURFACE7, LPRECT, DWORD, LPDDOVERLAYFX) = 0;
            virtual HRESULT LDL_CALL UpdateOverlayDisplay(DWORD) = 0;
            virtual HRESULT LDL_CALL UpdateOverlayZOrder(DWORD, LPDIRECTDRAWSURFACE7) = 0;
            /*** Added in the v2 interface ***/
            virtual HRESULT LDL_CALL GetDDInterface(LPVOID*) = 0;
            virtual HRESULT LDL_CALL PageLock(DWORD) = 0;
            virtual HRESULT LDL_CALL PageUnlock(DWORD) = 0;
            /*** Added in the v3 interface ***/
            virtual HRESULT LDL_CALL SetSurfaceDesc(LPDDSURFACEDESC2, DWORD) = 0;
            /*** Added in the v4 interface ***/
            virtual HRESULT LDL_CALL SetPrivateData(const GUID&, LPVOID, DWORD, DWORD) = 0;
            virtual HRESULT LDL_CALL GetPrivateData(const GUID&, LPVOID, LPDWORD) = 0;
            virtual HRESULT LDL_CALL FreePrivateData(const GUID&) = 0;
            virtual HRESULT LDL_CALL GetUniquenessValue(LPDWORD) = 0;
            virtual HRESULT LDL_CALL ChangeUniquenessValue() = 0;
            /*** Moved Texture7 methods here ***/
            virtual HRESULT LDL_CALL SetPriority(DWORD) = 0;
            virtual HRESULT LDL_CALL GetPriority(LPDWORD) = 0;
            virtual HRESULT LDL_CALL SetLOD(DWORD) = 0;
            virtual HRESULT LDL_CALL GetLOD(LPDWORD) = 0;
        };

        struct  IDirectDrawColorControl : IUnknown
        {
            /*** IUnknown methods ***/
            virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
            virtual ULONG LDL_CALL AddRef() = 0;
            virtual ULONG LDL_CALL Release() = 0;
            /*** IDirectDrawColorControl methods ***/
            virtual HRESULT LDL_CALL GetColorControls(LPDDCOLORCONTROL) = 0;
            virtual HRESULT LDL_CALL SetColorControls(LPDDCOLORCONTROL) = 0;
        };


        /*
         * IDirectDrawGammaControl
         */

        struct  IDirectDrawGammaControl : IUnknown
        {
            /*** IUnknown methods ***/
            virtual HRESULT LDL_CALL QueryInterface(const IID& riid, LPVOID* ppvObj) = 0;
            virtual ULONG LDL_CALL AddRef() = 0;
            virtual ULONG LDL_CALL Release() = 0;
            /*** IDirectDrawGammaControl methods ***/
            virtual HRESULT LDL_CALL GetGammaRamp(DWORD, LPDDGAMMARAMP) = 0;
            virtual HRESULT LDL_CALL SetGammaRamp(DWORD, LPDDGAMMARAMP) = 0;
        };

        /*
         * DDSURFACEDESC
         */
        typedef struct _DDSURFACEDESC
        {
            DWORD               dwSize;                 // size of the DDSURFACEDESC structure
            DWORD               dwFlags;                // determines what fields are valid
            DWORD               dwHeight;               // height of surface to be created
            DWORD               dwWidth;                // width of input surface
            union
            {
                LONG            lPitch;                 // distance to start of next line (return value only)
                DWORD           dwLinearSize;           // Formless late-allocated optimized surface size
            };
            DWORD               dwBackBufferCount;      // number of back buffers requested
            union
            {
                DWORD           dwMipMapCount;          // number of mip-map levels requested
                DWORD           dwZBufferBitDepth;      // depth of Z buffer requested
                DWORD           dwRefreshRate;          // refresh rate (used when display mode is described)
            };
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

        /*
         * DDSURFACEDESC2
         */
        typedef struct _DDSURFACEDESC2
        {
            DWORD               dwSize;                 // size of the DDSURFACEDESC structure
            DWORD               dwFlags;                // determines what fields are valid
            DWORD               dwHeight;               // height of surface to be created
            DWORD               dwWidth;                // width of input surface
            union
            {
                LONG            lPitch;                 // distance to start of next line (return value only)
                DWORD           dwLinearSize;           // Formless late-allocated optimized surface size
            };
            DWORD               dwBackBufferCount;      // number of back buffers requested
            union
            {
                DWORD           dwMipMapCount;          // number of mip-map levels requestde
                // dwZBufferBitDepth removed, use ddpfPixelFormat one instead
                DWORD           dwRefreshRate;          // refresh rate (used when display mode is described)
                DWORD           dwSrcVBHandle;          // The source used in VB::Optimize
            };
            DWORD               dwAlphaBitDepth;        // depth of alpha buffer requested
            DWORD               dwReserved;             // reserved
            LPVOID              lpSurface;              // pointer to the associated surface memory
            union
            {
                DDCOLORKEY      ddckCKDestOverlay;      // color key for destination overlay use
                DWORD           dwEmptyFaceColor;       // Physical color for empty cubemap faces
            };
            DDCOLORKEY          ddckCKDestBlt;          // color key for destination blt use
            DDCOLORKEY          ddckCKSrcOverlay;       // color key for source overlay use
            DDCOLORKEY          ddckCKSrcBlt;           // color key for source blt use
            union
            {
                DDPIXELFORMAT   ddpfPixelFormat;        // pixel format description of the surface
                DWORD           dwFVF;                  // vertex format description of vertex buffers
            };
            DDSCAPS2            ddsCaps;                // direct draw surface capabilities
            DWORD               dwTextureStage;         // stage in multitexture cascade
        } DDSURFACEDESC2;

        /*
         * ddsCaps field is valid.
         */
        const DWORD  DDSD_CAPS = 0x00000001l;  // default

        /*
         * dwHeight field is valid.
         */
        const DWORD  DDSD_HEIGHT = 0x00000002l;

        /*
         * dwWidth field is valid.
         */
        const DWORD  DDSD_WIDTH = 0x00000004l;

        /*
         * lPitch is valid.
         */
        const DWORD  DDSD_PITCH = 0x00000008l;

        /*
         * dwBackBufferCount is valid.
         */
        const DWORD  DDSD_BACKBUFFERCOUNT = 0x00000020l;

        /*
         * dwZBufferBitDepth is valid.  (shouldnt be used in DDSURFACEDESC2)
         */
        const DWORD  DDSD_ZBUFFERBITDEPTH = 0x00000040l;

        /*
         * dwAlphaBitDepth is valid.
         */
        const DWORD  DDSD_ALPHABITDEPTH = 0x00000080l;


        /*
         * lpSurface is valid.
         */
        const DWORD  DDSD_LPSURFACE = 0x00000800l;

        /*
         * ddpfPixelFormat is valid.
         */
        const DWORD  DDSD_PIXELFORMAT = 0x00001000l;

        /*
         * ddckCKDestOverlay is valid.
         */
        const DWORD  DDSD_CKDESTOVERLAY = 0x00002000l;

        /*
         * ddckCKDestBlt is valid.
         */
        const DWORD  DDSD_CKDESTBLT = 0x00004000l;

        /*
         * ddckCKSrcOverlay is valid.
         */
        const DWORD  DDSD_CKSRCOVERLAY = 0x00008000l;

        /*
         * ddckCKSrcBlt is valid.
         */
        const DWORD  DDSD_CKSRCBLT = 0x00010000l;

        /*
         * dwMipMapCount is valid.
         */
        const DWORD  DDSD_MIPMAPCOUNT = 0x00020000l;

        /*
         * dwRefreshRate is valid
         */
        const DWORD  DDSD_REFRESHRATE = 0x00040000l;

        /*
         * dwLinearSize is valid
         */
        const DWORD  DDSD_LINEARSIZE = 0x00080000l;

        /*
         * dwTextureStage is valid
         */
        const DWORD  DDSD_TEXTURESTAGE = 0x00100000l;
        /*
         * dwFVF is valid
         */
        const DWORD  DDSD_FVF = 0x00200000l;
        /*
         * dwSrcVBHandle is valid
         */
        const DWORD  DDSD_SRCVBHANDLE = 0x00400000l;
        /*
         * All input fields are valid.
         */
        const DWORD  DDSD_ALL = 0x007ff9eel;


        /*
         * DDOPTSURFACEDESC
         */
        typedef struct _DDOPTSURFACEDESC
        {
            DWORD       dwSize;             // size of the DDOPTSURFACEDESC structure
            DWORD       dwFlags;            // determines what fields are valid
            DDSCAPS2    ddSCaps;            // Common caps like: Memory type
            DDOSCAPS    ddOSCaps;           // Common caps like: Memory type
            GUID        guid;               // Compression technique GUID
            DWORD       dwCompressionRatio; // Compression ratio
        } DDOPTSURFACEDESC;

        /*
         * guid field is valid.
         */
        const DWORD  DDOSD_GUID = 0x00000001l;

        /*
         * dwCompressionRatio field is valid.
         */
        const DWORD  DDOSD_COMPRESSION_RATIO = 0x00000002l;

        /*
         * ddSCaps field is valid.
         */
        const DWORD  DDOSD_SCAPS = 0x00000004l;

        /*
         * ddOSCaps field is valid.
         */
        const DWORD  DDOSD_OSCAPS = 0x00000008l;

        /*
         * All input fields are valid.
         */
        const DWORD  DDOSD_ALL = 0x0000000fl;

        /*
         * The surface's optimized pixelformat is compressed
         */
        const DWORD  DDOSDCAPS_OPTCOMPRESSED = 0x00000001l;

        /*
         * The surface's optimized pixelformat is reordered
         */
        const DWORD  DDOSDCAPS_OPTREORDERED = 0x00000002l;

        /*
         * The opt surface is a monolithic mipmap
         */
        const DWORD  DDOSDCAPS_MONOLITHICMIPMAP = 0x00000004l;

        /*
         * The valid Surf caps:
         * #define DDSCAPS_SYSTEMMEMORY                 0x00000800l
         * #define DDSCAPS_VIDEOMEMORY          0x00004000l
         * #define DDSCAPS_LOCALVIDMEM          0x10000000l
         * #define DDSCAPS_NONLOCALVIDMEM       0x20000000l
         */
        const DWORD  DDOSDCAPS_VALIDSCAPS = 0x30004800l;

        /*
         * The valid OptSurf caps
         */
        const DWORD  DDOSDCAPS_VALIDOSCAPS = 0x00000007l;


        /*
         * DDCOLORCONTROL
         */
        typedef struct _DDCOLORCONTROL
        {
            DWORD               dwSize;
            DWORD               dwFlags;
            LONG                lBrightness;
            LONG                lContrast;
            LONG                lHue;
            LONG                lSaturation;
            LONG                lSharpness;
            LONG                lGamma;
            LONG                lColorEnable;
            DWORD               dwReserved1;
        } DDCOLORCONTROL;


        /*
         * lBrightness field is valid.
         */
        const DWORD  DDCOLOR_BRIGHTNESS = 0x00000001l;

        /*
         * lContrast field is valid.
         */
        const DWORD  DDCOLOR_CONTRAST = 0x00000002l;

        /*
         * lHue field is valid.
         */
        const DWORD  DDCOLOR_HUE = 0x00000004l;

        /*
         * lSaturation field is valid.
         */
        const DWORD  DDCOLOR_SATURATION = 0x00000008l;

        /*
         * lSharpness field is valid.
         */
        const DWORD  DDCOLOR_SHARPNESS = 0x00000010l;

        /*
         * lGamma field is valid.
         */
        const DWORD  DDCOLOR_GAMMA = 0x00000020l;

        /*
         * lColorEnable field is valid.
         */
        const DWORD  DDCOLOR_COLORENABLE = 0x00000040l;



        /*============================================================================
         *
         * Direct Draw Capability Flags
         *
         * These flags are used to describe the capabilities of a given Surface.
         * All flags are bit flags.
         *
         *==========================================================================*/

         /****************************************************************************
          *
          * DIRECTDRAWSURFACE CAPABILITY FLAGS
          *
          ****************************************************************************/

          /*
           * This bit is reserved. It should not be specified.
           */
        const DWORD  DDSCAPS_RESERVED1 = 0x00000001l;

        /*
         * Indicates that this surface contains alpha-only information.
         * (To determine if a surface is RGBA/YUVA, the pixel format must be
         * interrogated.)
         */
        const DWORD  DDSCAPS_ALPHA = 0x00000002l;

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
        const DWORD  DDSCAPS_BACKBUFFER = 0x00000004l;

        /*
         * Indicates a complex surface structure is being described.  A
         * complex surface structure results in the creation of more than
         * one surface.  The additional surfaces are attached to the root
         * surface.  The complex structure can only be destroyed by
         * destroying the root.
         */
        const DWORD  DDSCAPS_COMPLEX = 0x00000008l;

        /*
         * Indicates that this surface is a part of a surface flipping structure.
         * When it is passed to CreateSurface the DDSCAPS_FRONTBUFFER and
         * DDSCAP_BACKBUFFER bits are not set.  They are set by CreateSurface
         * on the resulting creations.  The dwBackBufferCount field in the
         * DDSURFACEDESC structure must be set to at least 1 in order for
         * the CreateSurface call to succeed.  The DDSCAPS_COMPLEX capability
         * must always be set with creating multiple surfaces through CreateSurface.
         */
        const DWORD  DDSCAPS_FLIP = 0x00000010l;

        /*
         * Indicates that this surface is THE front buffer of a surface flipping
         * structure.  It is generally set by CreateSurface when the DDSCAPS_FLIP
         * capability bit is set.
         * If this capability is sent to CreateSurface then a standalonw front buffer
         * is created.  This surface will not have the DDSCAPS_FLIP capability.
         * It can be attached to other back buffers to form a flipping structure.
         * See AddAttachments for a detailed description of the behaviors in this
         * case.
         */
        const DWORD  DDSCAPS_FRONTBUFFER = 0x00000020l;

        /*
         * Indicates that this surface is any offscreen surface that is not an overlay,
         * texture, zbuffer, front buffer, back buffer, or alpha surface.  It is used
         * to identify plain vanilla surfaces.
         */
        const DWORD  DDSCAPS_OFFSCREENPLAIN = 0x00000040l;

        /*
         * Indicates that this surface is an overlay.  It may or may not be directly visible
         * depending on whether or not it is currently being overlayed onto the primary
         * surface.  DDSCAPS_VISIBLE can be used to determine whether or not it is being
         * overlayed at the moment.
         */
        const DWORD  DDSCAPS_OVERLAY = 0x00000080l;

        /*
         * Indicates that unique DirectDrawPalette objects can be created and
         * attached to this surface.
         */
        const DWORD  DDSCAPS_PALETTE = 0x00000100l;

        /*
         * Indicates that this surface is the primary surface.  The primary
         * surface represents what the user is seeing at the moment.
         */
        const DWORD  DDSCAPS_PRIMARYSURFACE = 0x00000200l;


        /*
         * This flag used to be DDSCAPS_PRIMARYSURFACELEFT, which is now
         * obsolete.
         */
        const DWORD  DDSCAPS_RESERVED3 = 0x00000400l;

        /*
         * Indicates that this surface memory was allocated in system memory
         */
        const DWORD  DDSCAPS_SYSTEMMEMORY = 0x00000800l;

        /*
         * Indicates that this surface can be used as a 3D texture.  It does not
         * indicate whether or not the surface is being used for that purpose.
         */
        const DWORD  DDSCAPS_TEXTURE = 0x00001000l;

        /*
         * Indicates that a surface may be a destination for 3D rendering.  This
         * bit must be set in order to query for a Direct3D Device Interface
         * from this surface.
         */
        const DWORD  DDSCAPS_3DDEVICE = 0x00002000l;

        /*
         * Indicates that this surface exists in video memory.
         */
        const DWORD  DDSCAPS_VIDEOMEMORY = 0x00004000l;

        /*
         * Indicates that changes made to this surface are immediately visible.
         * It is always set for the primary surface and is set for overlays while
         * they are being overlayed and texture maps while they are being textured.
         */
        const DWORD  DDSCAPS_VISIBLE = 0x00008000l;

        /*
         * Indicates that only writes are permitted to the surface.  Read accesses
         * from the surface may or may not generate a protection fault, but the
         * results of a read from this surface will not be meaningful.  READ ONLY.
         */
        const DWORD  DDSCAPS_WRITEONLY = 0x00010000l;

        /*
         * Indicates that this surface is a z buffer. A z buffer does not contain
         * displayable information.  Instead it contains bit depth information that is
         * used to determine which pixels are visible and which are obscured.
         */
        const DWORD  DDSCAPS_ZBUFFER = 0x00020000l;

        /*
         * Indicates surface will have a DC associated long term
         */
        const DWORD  DDSCAPS_OWNDC = 0x00040000l;

        /*
         * Indicates surface should be able to receive live video
         */
        const DWORD  DDSCAPS_LIVEVIDEO = 0x00080000l;

        /*
         * Indicates surface should be able to have a stream decompressed
         * to it by the hardware.
         */
        const DWORD  DDSCAPS_HWCODEC = 0x00100000l;

        /*
         * Surface is a ModeX surface.
         *
         */
        const DWORD  DDSCAPS_MODEX = 0x00200000l;

        /*
         * Indicates surface is one level of a mip-map. This surface will
         * be attached to other DDSCAPS_MIPMAP surfaces to form the mip-map.
         * This can be done explicitly, by creating a number of surfaces and
         * attaching them with AddAttachedSurface or by implicitly by CreateSurface.
         * If this bit is set then DDSCAPS_TEXTURE must also be set.
         */
        const DWORD  DDSCAPS_MIPMAP = 0x00400000l;

        /*
         * This bit is reserved. It should not be specified.
         */
        const DWORD  DDSCAPS_RESERVED2 = 0x00800000l;


        /*
         * Indicates that memory for the surface is not allocated until the surface
         * is loaded (via the Direct3D texture Load() function).
         */
        const DWORD  DDSCAPS_ALLOCONLOAD = 0x04000000l;

        /*
         * Indicates that the surface will recieve data from a video port.
         */
        const DWORD  DDSCAPS_VIDEOPORT = 0x08000000l;

        /*
         * Indicates that a video memory surface is resident in true, local video
         * memory rather than non-local video memory. If this flag is specified then
         * so must DDSCAPS_VIDEOMEMORY. This flag is mutually exclusive with
         * DDSCAPS_NONLOCALVIDMEM.
         */
        const DWORD  DDSCAPS_LOCALVIDMEM = 0x10000000l;

        /*
         * Indicates that a video memory surface is resident in non-local video
         * memory rather than true, local video memory. If this flag is specified
         * then so must DDSCAPS_VIDEOMEMORY. This flag is mutually exclusive with
         * DDSCAPS_LOCALVIDMEM.
         */
        const DWORD  DDSCAPS_NONLOCALVIDMEM = 0x20000000l;

        /*
         * Indicates that this surface is a standard VGA mode surface, and not a
         * ModeX surface. (This flag will never be set in combination with the
         * DDSCAPS_MODEX flag).
         */
        const DWORD  DDSCAPS_STANDARDVGAMODE = 0x40000000l;

        /*
         * Indicates that this surface will be an optimized surface. This flag is
         * currently only valid in conjunction with the DDSCAPS_TEXTURE flag. The surface
         * will be created without any underlying video memory until loaded.
         */
        const DWORD  DDSCAPS_OPTIMIZED = 0x80000000l;




        /*
         * Indicates that this surface will receive data from a video port using
         * the de-interlacing hardware.  This allows the driver to allocate memory
         * for any extra buffers that may be required.  The DDSCAPS_VIDEOPORT and
         * DDSCAPS_OVERLAY flags must also be set.
         */
        const DWORD  DDSCAPS2_HARDWAREDEINTERLACE = 0x00000002L;

        /*
         * Indicates to the driver that this surface will be locked very frequently
         * (for procedural textures, dynamic lightmaps, etc). Surfaces with this cap
         * set must also have DDSCAPS_TEXTURE. This cap cannot be used with
         * DDSCAPS2_HINTSTATIC and DDSCAPS2_OPAQUE.
         */
        const DWORD  DDSCAPS2_HINTDYNAMIC = 0x00000004L;

        /*
         * Indicates to the driver that this surface can be re-ordered/retiled on
         * load. This operation will not change the size of the texture. It is
         * relatively fast and symmetrical, since the application may lock these
         * bits (although it will take a performance hit when doing so). Surfaces
         * with this cap set must also have DDSCAPS_TEXTURE. This cap cannot be
         * used with DDSCAPS2_HINTDYNAMIC and DDSCAPS2_OPAQUE.
         */
        const DWORD  DDSCAPS2_HINTSTATIC = 0x00000008L;

        /*
         * Indicates that the client would like this texture surface to be managed by the
         * DirectDraw/Direct3D runtime. Surfaces with this cap set must also have
         * DDSCAPS_TEXTURE set.
         */
        const DWORD  DDSCAPS2_TEXTUREMANAGE = 0x00000010L;

        /*
         * These bits are reserved for internal use */
        const DWORD  DDSCAPS2_RESERVED1 = 0x00000020L;
        const DWORD  DDSCAPS2_RESERVED2 = 0x00000040L;

        /*
         * Indicates to the driver that this surface will never be locked again.
         * The driver is free to optimize this surface via retiling and actual compression.
         * All calls to Lock() or Blts from this surface will fail. Surfaces with this
         * cap set must also have DDSCAPS_TEXTURE. This cap cannot be used with
         * DDSCAPS2_HINTDYNAMIC and DDSCAPS2_HINTSTATIC.
         */
        const DWORD  DDSCAPS2_OPAQUE = 0x00000080L;

        /*
         * Applications should set this bit at CreateSurface time to indicate that they
         * intend to use antialiasing. Only valid if DDSCAPS_3DDEVICE is also set.
         */
        const DWORD  DDSCAPS2_HINTANTIALIASING = 0x00000100L;


        /*
         * This flag is used at CreateSurface time to indicate that this set of
         * surfaces is a cubic environment map
         */
        const DWORD  DDSCAPS2_CUBEMAP = 0x00000200L;

        /*
         * These flags preform two functions:
         * - At CreateSurface time, they define which of the six cube faces are
         *   required by the application.
         * - After creation, each face in the cubemap will have exactly one of these
         *   bits set.
         */
        const DWORD  DDSCAPS2_CUBEMAP_POSITIVEX = 0x00000400L;
        const DWORD  DDSCAPS2_CUBEMAP_NEGATIVEX = 0x00000800L;
        const DWORD  DDSCAPS2_CUBEMAP_POSITIVEY = 0x00001000L;
        const DWORD  DDSCAPS2_CUBEMAP_NEGATIVEY = 0x00002000L;
        const DWORD  DDSCAPS2_CUBEMAP_POSITIVEZ = 0x00004000L;
        const DWORD  DDSCAPS2_CUBEMAP_NEGATIVEZ = 0x00008000L;

        /*
         * This macro may be used to specify all faces of a cube map at CreateSurface time
         */
        const DWORD  DDSCAPS2_CUBEMAP_ALLFACES = (DDSCAPS2_CUBEMAP_POSITIVEX | \
            DDSCAPS2_CUBEMAP_NEGATIVEX | \
            DDSCAPS2_CUBEMAP_POSITIVEY | \
            DDSCAPS2_CUBEMAP_NEGATIVEY | \
            DDSCAPS2_CUBEMAP_POSITIVEZ | \
            DDSCAPS2_CUBEMAP_NEGATIVEZ);


        /*
         * This flag is an additional flag which is present on mipmap sublevels from DX7 onwards
         * It enables easier use of GetAttachedSurface rather than EnumAttachedSurfaces for surface
         * constructs such as Cube Maps, wherein there are more than one mipmap surface attached
         * to the root surface.
         * This caps bit is ignored by CreateSurface
         */
        const DWORD  DDSCAPS2_MIPMAPSUBLEVEL = 0x00010000L;

        /* This flag indicates that the texture should be managed by D3D only */
        const DWORD  DDSCAPS2_D3DTEXTUREMANAGE = 0x00020000L;

        /* This flag indicates that the managed surface can be safely lost */
        const DWORD  DDSCAPS2_DONOTPERSIST = 0x00040000L;

        /* indicates that this surface is part of a stereo flipping chain */
        const DWORD  DDSCAPS2_STEREOSURFACELEFT = 0x00080000L;





        /****************************************************************************
        *
        * DIRECTDRAW DRIVER CAPABILITY FLAGS
        *
        ****************************************************************************/

        /*
         * Display hardware has 3D acceleration.
         */
        const DWORD  DDCAPS_3D = 0x00000001l;

        /*
         * Indicates that DirectDraw will support only dest rectangles that are aligned
         * on DIRECTDRAWCAPS.dwAlignBoundaryDest boundaries of the surface, respectively.
         * READ ONLY.
         */
        const DWORD  DDCAPS_ALIGNBOUNDARYDEST = 0x00000002l;

        /*
         * Indicates that DirectDraw will support only source rectangles  whose sizes in
         * BYTEs are DIRECTDRAWCAPS.dwAlignSizeDest multiples, respectively.  READ ONLY.
         */
        const DWORD  DDCAPS_ALIGNSIZEDEST = 0x00000004l;
        /*
         * Indicates that DirectDraw will support only source rectangles that are aligned
         * on DIRECTDRAWCAPS.dwAlignBoundarySrc boundaries of the surface, respectively.
         * READ ONLY.
         */
        const DWORD  DDCAPS_ALIGNBOUNDARYSRC = 0x00000008l;

        /*
         * Indicates that DirectDraw will support only source rectangles  whose sizes in
         * BYTEs are DIRECTDRAWCAPS.dwAlignSizeSrc multiples, respectively.  READ ONLY.
         */
        const DWORD  DDCAPS_ALIGNSIZESRC = 0x00000010l;

        /*
         * Indicates that DirectDraw will create video memory surfaces that have a stride
         * alignment equal to DIRECTDRAWCAPS.dwAlignStride.  READ ONLY.
         */
        const DWORD  DDCAPS_ALIGNSTRIDE = 0x00000020l;

        /*
         * Display hardware is capable of blt operations.
         */
        const DWORD  DDCAPS_BLT = 0x00000040l;

        /*
         * Display hardware is capable of asynchronous blt operations.
         */
        const DWORD  DDCAPS_BLTQUEUE = 0x00000080l;

        /*
         * Display hardware is capable of color space conversions during the blt operation.
         */
        const DWORD  DDCAPS_BLTFOURCC = 0x00000100l;

        /*
         * Display hardware is capable of stretching during blt operations.
         */
        const DWORD  DDCAPS_BLTSTRETCH = 0x00000200l;

        /*
         * Display hardware is shared with GDI.
         */
        const DWORD  DDCAPS_GDI = 0x00000400l;

        /*
         * Display hardware can overlay.
         */
        const DWORD  DDCAPS_OVERLAY = 0x00000800l;

        /*
         * Set if display hardware supports overlays but can not clip them.
         */
        const DWORD  DDCAPS_OVERLAYCANTCLIP = 0x00001000l;

        /*
         * Indicates that overlay hardware is capable of color space conversions during
         * the overlay operation.
         */
        const DWORD  DDCAPS_OVERLAYFOURCC = 0x00002000l;

        /*
         * Indicates that stretching can be done by the overlay hardware.
         */
        const DWORD  DDCAPS_OVERLAYSTRETCH = 0x00004000l;

        /*
         * Indicates that unique DirectDrawPalettes can be created for DirectDrawSurfaces
         * other than the primary surface.
         */
        const DWORD  DDCAPS_PALETTE = 0x00008000l;

        /*
         * Indicates that palette changes can be syncd with the veritcal refresh.
         */
        const DWORD  DDCAPS_PALETTEVSYNC = 0x00010000l;

        /*
         * Display hardware can return the current scan line.
         */
        const DWORD  DDCAPS_READSCANLINE = 0x00020000l;


        /*
         * This flag used to bo DDCAPS_STEREOVIEW, which is now obsolete
         */
        const DWORD  DDCAPS_RESERVED1 = 0x00040000l;

        /*
         * Display hardware is capable of generating a vertical blank interrupt.
         */
        const DWORD  DDCAPS_VBI = 0x00080000l;

        /*
         * Supports the use of z buffers with blt operations.
         */
        const DWORD  DDCAPS_ZBLTS = 0x00100000l;

        /*
         * Supports Z Ordering of overlays.
         */
        const DWORD  DDCAPS_ZOVERLAYS = 0x00200000l;

        /*
         * Supports color key
         */
        const DWORD  DDCAPS_COLORKEY = 0x00400000l;

        /*
         * Supports alpha surfaces
         */
        const DWORD  DDCAPS_ALPHA = 0x00800000l;

        /*
         * colorkey is hardware assisted(DDCAPS_COLORKEY will also be set)
         */
        const DWORD  DDCAPS_COLORKEYHWASSIST = 0x01000000l;

        /*
         * no hardware support at all
         */
        const DWORD  DDCAPS_NOHARDWARE = 0x02000000l;

        /*
         * Display hardware is capable of color fill with bltter
         */
        const DWORD  DDCAPS_BLTCOLORFILL = 0x04000000l;

        /*
         * Display hardware is bank switched, and potentially very slow at
         * random access to VRAM.
         */
        const DWORD  DDCAPS_BANKSWITCHED = 0x08000000l;

        /*
         * Display hardware is capable of depth filling Z-buffers with bltter
         */
        const DWORD  DDCAPS_BLTDEPTHFILL = 0x10000000l;

        /*
         * Display hardware is capable of clipping while bltting.
         */
        const DWORD  DDCAPS_CANCLIP = 0x20000000l;

        /*
         * Display hardware is capable of clipping while stretch bltting.
         */
        const DWORD  DDCAPS_CANCLIPSTRETCHED = 0x40000000l;

        /*
         * Display hardware is capable of bltting to or from system memory
         */
        const DWORD  DDCAPS_CANBLTSYSMEM = 0x80000000l;


        /****************************************************************************
        *
        * MORE DIRECTDRAW DRIVER CAPABILITY FLAGS (dwCaps2)
        *
        ****************************************************************************/

        /*
         * Display hardware is certified
         */
        const DWORD  DDCAPS2_CERTIFIED = 0x00000001l;

        /*
         * Driver cannot interleave 2D operations (lock and blt) to surfaces with
         * Direct3D rendering operations between calls to BeginScene() and EndScene()
         */
        const DWORD  DDCAPS2_NO2DDURING3DSCENE = 0x00000002l;

        /*
         * Display hardware contains a video port
         */
        const DWORD  DDCAPS2_VIDEOPORT = 0x00000004l;

        /*
         * The overlay can be automatically flipped according to the video port
         * VSYNCs, providing automatic doubled buffered display of video port
         * data using an overlay
         */
        const DWORD  DDCAPS2_AUTOFLIPOVERLAY = 0x00000008l;

        /*
         * Overlay can display each field of interlaced data individually while
         * it is interleaved in memory without causing jittery artifacts.
         */
        const DWORD  DDCAPS2_CANBOBINTERLEAVED = 0x00000010l;

        /*
         * Overlay can display each field of interlaced data individually while
         * it is not interleaved in memory without causing jittery artifacts.
         */
        const DWORD  DDCAPS2_CANBOBNONINTERLEAVED = 0x00000020l;

        /*
         * The overlay surface contains color controls (brightness, sharpness, etc.)
         */
        const DWORD  DDCAPS2_COLORCONTROLOVERLAY = 0x00000040l;

        /*
         * The primary surface contains color controls (gamma, etc.)
         */
        const DWORD  DDCAPS2_COLORCONTROLPRIMARY = 0x00000080l;

        /*
         * RGBZ -> RGB supported for 16:16 RGB:Z
         */
        const DWORD  DDCAPS2_CANDROPZ16BIT = 0x00000100l;

        /*
         * Driver supports non-local video memory.
         */
        const DWORD  DDCAPS2_NONLOCALVIDMEM = 0x00000200l;

        /*
         * Dirver supports non-local video memory but has different capabilities for
         * non-local video memory surfaces. If this bit is set then so must
         * DDCAPS2_NONLOCALVIDMEM.
         */
        const DWORD  DDCAPS2_NONLOCALVIDMEMCAPS = 0x00000400l;

        /*
         * Driver neither requires nor prefers surfaces to be pagelocked when performing
         * blts involving system memory surfaces
         */
        const DWORD  DDCAPS2_NOPAGELOCKREQUIRED = 0x00000800l;

        /*
         * Driver can create surfaces which are wider than the primary surface
         */
        const DWORD  DDCAPS2_WIDESURFACES = 0x00001000l;

        /*
         * Driver supports bob without using a video port by handling the
         * DDFLIP_ODD and DDFLIP_EVEN flags specified in Flip.
         */
        const DWORD  DDCAPS2_CANFLIPODDEVEN = 0x00002000l;

        /*
         * Driver supports bob using hardware
         */
        const DWORD  DDCAPS2_CANBOBHARDWARE = 0x00004000l;

        /*
         * Driver supports bltting any FOURCC surface to another surface of the same FOURCC
         */
        const DWORD  DDCAPS2_COPYFOURCC = 0x00008000l;


        /*
         * Driver supports loadable gamma ramps for the primary surface
         */
        const DWORD  DDCAPS2_PRIMARYGAMMA = 0x00020000l;

        /*
         * Driver can render in windowed mode.
         */
        const DWORD  DDCAPS2_CANRENDERWINDOWED = 0x00080000l;

        /*
         * A calibrator is available to adjust the gamma ramp according to the
         * physical display properties so that the result will be identical on
         * all calibrated systems.
         */
        const DWORD  DDCAPS2_CANCALIBRATEGAMMA = 0x00100000l;

        /*
         * Indicates that the driver will respond to DDFLIP_INTERVALn flags
         */
        const DWORD  DDCAPS2_FLIPINTERVAL = 0x00200000l;

        /*
         * Indicates that the driver will respond to DDFLIP_NOVSYNC
         */
        const DWORD  DDCAPS2_FLIPNOVSYNC = 0x00400000l;

        /*
         * Driver supports management of video memory, if this flag is ON,
         * driver manages the texture if requested with DDSCAPS2_TEXTUREMANAGE on
         * DirectX manages the texture if this flag is OFF and surface has DDSCAPS2_TEXTUREMANAGE on
         */
        const DWORD  DDCAPS2_CANMANAGETEXTURE = 0x00800000l;

        /*
         * The Direct3D texture manager uses this cap to decide whether to put managed
         * surfaces in non-local video memory. If the cap is set, the texture manager will
         * put managed surfaces in non-local vidmem. Drivers that cannot texture from
         * local vidmem SHOULD NOT set this cap.
         */
        const DWORD  DDCAPS2_TEXMANINNONLOCALVIDMEM = 0x01000000l;

        /*
         * Indicates that the driver supports DX7 type of stereo in at least one mode (which may
         * not necessarily be the current mode). Applications should use IDirectDraw7 (or higher)
         * ::EnumDisplayModes and check the DDSURFACEDESC.ddsCaps.dwCaps2 field for the presence of
         * DDSCAPS2_STEREOSURFACELEFT to check if a particular mode supports stereo. The application
         * can also use IDirectDraw7(or higher)::GetDisplayMode to check the current mode.
         */
        const DWORD  DDCAPS2_STEREO = 0x02000000L;

        /*
         * This caps bit is intended for internal DirectDraw use.
         * -It is only valid if DDCAPS2_NONLOCALVIDMEMCAPS is set.
         * -If this bit is set, then DDCAPS_CANBLTSYSMEM MUST be set by the driver (and
         *  all the assoicated system memory blt caps must be correct).
         * -It implies that the system->video blt caps in DDCAPS also apply to system to
         *  nonlocal blts. I.e. the dwSVBCaps, dwSVBCKeyCaps, dwSVBFXCaps and dwSVBRops
         *  members of DDCAPS (DDCORECAPS) are filled in correctly.
         * -Any blt from system to nonlocal memory that matches these caps bits will
         *  be passed to the driver.
         *
         * NOTE: This is intended to enable the driver itself to do efficient reordering
         * of textures. This is NOT meant to imply that hardware can write into AGP memory.
         * This operation is not currently supported.
         */
        const DWORD  DDCAPS2_SYSTONONLOCAL_AS_SYSTOLOCAL = 0x04000000L;



        /****************************************************************************
         *
         * DIRECTDRAW FX ALPHA CAPABILITY FLAGS
         *
         ****************************************************************************/

         /*
          * Supports alpha blending around the edge of a source color keyed surface.
          * For Blt.
          */
        const DWORD  DDFXALPHACAPS_BLTALPHAEDGEBLEND = 0x00000001l;

        /*
         * Supports alpha information in the pixel format.  The bit depth of alpha
         * information in the pixel format can be 1,2,4, or 8.  The alpha value becomes
         * more opaque as the alpha value increases.  (0 is transparent.)
         * For Blt.
         */
        const DWORD  DDFXALPHACAPS_BLTALPHAPIXELS = 0x00000002l;

        /*
         * Supports alpha information in the pixel format.  The bit depth of alpha
         * information in the pixel format can be 1,2,4, or 8.  The alpha value
         * becomes more transparent as the alpha value increases.  (0 is opaque.)
         * This flag can only be set if DDCAPS_ALPHA is set.
         * For Blt.
         */
        const DWORD  DDFXALPHACAPS_BLTALPHAPIXELSNEG = 0x00000004l;

        /*
         * Supports alpha only surfaces.  The bit depth of an alpha only surface can be
         * 1,2,4, or 8.  The alpha value becomes more opaque as the alpha value increases.
         * (0 is transparent.)
         * For Blt.
         */
        const DWORD  DDFXALPHACAPS_BLTALPHASURFACES = 0x00000008l;

        /*
         * The depth of the alpha channel data can range can be 1,2,4, or 8.
         * The NEG suffix indicates that this alpha channel becomes more transparent
         * as the alpha value increases. (0 is opaque.)  This flag can only be set if
         * DDCAPS_ALPHA is set.
         * For Blt.
         */
        const DWORD  DDFXALPHACAPS_BLTALPHASURFACESNEG = 0x00000010l;

        /*
         * Supports alpha blending around the edge of a source color keyed surface.
         * For Overlays.
         */
        const DWORD  DDFXALPHACAPS_OVERLAYALPHAEDGEBLEND = 0x00000020l;

        /*
         * Supports alpha information in the pixel format.  The bit depth of alpha
         * information in the pixel format can be 1,2,4, or 8.  The alpha value becomes
         * more opaque as the alpha value increases.  (0 is transparent.)
         * For Overlays.
         */
        const DWORD  DDFXALPHACAPS_OVERLAYALPHAPIXELS = 0x00000040l;

        /*
         * Supports alpha information in the pixel format.  The bit depth of alpha
         * information in the pixel format can be 1,2,4, or 8.  The alpha value
         * becomes more transparent as the alpha value increases.  (0 is opaque.)
         * This flag can only be set if DDCAPS_ALPHA is set.
         * For Overlays.
         */
        const DWORD  DDFXALPHACAPS_OVERLAYALPHAPIXELSNEG = 0x00000080l;

        /*
         * Supports alpha only surfaces.  The bit depth of an alpha only surface can be
         * 1,2,4, or 8.  The alpha value becomes more opaque as the alpha value increases.
         * (0 is transparent.)
         * For Overlays.
         */
        const DWORD  DDFXALPHACAPS_OVERLAYALPHASURFACES = 0x00000100l;

        /*
         * The depth of the alpha channel data can range can be 1,2,4, or 8.
         * The NEG suffix indicates that this alpha channel becomes more transparent
         * as the alpha value increases. (0 is opaque.)  This flag can only be set if
         * DDCAPS_ALPHA is set.
         * For Overlays.
         */
        const DWORD  DDFXALPHACAPS_OVERLAYALPHASURFACESNEG = 0x00000200l;

        /****************************************************************************
         *
         * DIRECTDRAW FX CAPABILITY FLAGS
         *
         ****************************************************************************/

         /*
          * Uses arithmetic operations to stretch and shrink surfaces during blt
          * rather than pixel doubling techniques.  Along the Y axis.
          */
        const DWORD  DDFXCAPS_BLTARITHSTRETCHY = 0x00000020l;

        /*
         * Uses arithmetic operations to stretch during blt
         * rather than pixel doubling techniques.  Along the Y axis. Only
         * works for x1, x2, etc.
         */
        const DWORD  DDFXCAPS_BLTARITHSTRETCHYN = 0x00000010l;

        /*
         * Supports mirroring left to right in blt.
         */
        const DWORD  DDFXCAPS_BLTMIRRORLEFTRIGHT = 0x00000040l;

        /*
         * Supports mirroring top to bottom in blt.
         */
        const DWORD  DDFXCAPS_BLTMIRRORUPDOWN = 0x00000080l;

        /*
         * Supports arbitrary rotation for blts.
         */
        const DWORD  DDFXCAPS_BLTROTATION = 0x00000100l;

        /*
         * Supports 90 degree rotations for blts.
         */
        const DWORD  DDFXCAPS_BLTROTATION90 = 0x00000200l;

        /*
         * DirectDraw supports arbitrary shrinking of a surface along the
         * x axis (horizontal direction) for blts.
         */
        const DWORD  DDFXCAPS_BLTSHRINKX = 0x00000400l;

        /*
         * DirectDraw supports integer shrinking (1x,2x,) of a surface
         * along the x axis (horizontal direction) for blts.
         */
        const DWORD  DDFXCAPS_BLTSHRINKXN = 0x00000800l;

        /*
         * DirectDraw supports arbitrary shrinking of a surface along the
         * y axis (horizontal direction) for blts.
         */
        const DWORD  DDFXCAPS_BLTSHRINKY = 0x00001000l;

        /*
         * DirectDraw supports integer shrinking (1x,2x,) of a surface
         * along the y axis (vertical direction) for blts.
         */
        const DWORD  DDFXCAPS_BLTSHRINKYN = 0x00002000l;

        /*
         * DirectDraw supports arbitrary stretching of a surface along the
         * x axis (horizontal direction) for blts.
         */
        const DWORD  DDFXCAPS_BLTSTRETCHX = 0x00004000l;

        /*
         * DirectDraw supports integer stretching (1x,2x,) of a surface
         * along the x axis (horizontal direction) for blts.
         */
        const DWORD  DDFXCAPS_BLTSTRETCHXN = 0x00008000l;

        /*
         * DirectDraw supports arbitrary stretching of a surface along the
         * y axis (horizontal direction) for blts.
         */
        const DWORD  DDFXCAPS_BLTSTRETCHY = 0x00010000l;

        /*
         * DirectDraw supports integer stretching (1x,2x,) of a surface
         * along the y axis (vertical direction) for blts.
         */
        const DWORD  DDFXCAPS_BLTSTRETCHYN = 0x00020000l;

        /*
         * Uses arithmetic operations to stretch and shrink surfaces during
         * overlay rather than pixel doubling techniques.  Along the Y axis
         * for overlays.
         */
        const DWORD  DDFXCAPS_OVERLAYARITHSTRETCHY = 0x00040000l;

        /*
         * Uses arithmetic operations to stretch surfaces during
         * overlay rather than pixel doubling techniques.  Along the Y axis
         * for overlays. Only works for x1, x2, etc.
         */
        const DWORD  DDFXCAPS_OVERLAYARITHSTRETCHYN = 0x00000008l;

        /*
         * DirectDraw supports arbitrary shrinking of a surface along the
         * x axis (horizontal direction) for overlays.
         */
        const DWORD  DDFXCAPS_OVERLAYSHRINKX = 0x00080000l;

        /*
         * DirectDraw supports integer shrinking (1x,2x,) of a surface
         * along the x axis (horizontal direction) for overlays.
         */
        const DWORD  DDFXCAPS_OVERLAYSHRINKXN = 0x00100000l;

        /*
         * DirectDraw supports arbitrary shrinking of a surface along the
         * y axis (horizontal direction) for overlays.
         */
        const DWORD  DDFXCAPS_OVERLAYSHRINKY = 0x00200000l;

        /*
         * DirectDraw supports integer shrinking (1x,2x,) of a surface
         * along the y axis (vertical direction) for overlays.
         */
        const DWORD  DDFXCAPS_OVERLAYSHRINKYN = 0x00400000l;

        /*
         * DirectDraw supports arbitrary stretching of a surface along the
         * x axis (horizontal direction) for overlays.
         */
        const DWORD  DDFXCAPS_OVERLAYSTRETCHX = 0x00800000l;

        /*
         * DirectDraw supports integer stretching (1x,2x,) of a surface
         * along the x axis (horizontal direction) for overlays.
         */
        const DWORD  DDFXCAPS_OVERLAYSTRETCHXN = 0x01000000l;

        /*
         * DirectDraw supports arbitrary stretching of a surface along the
         * y axis (horizontal direction) for overlays.
         */
        const DWORD  DDFXCAPS_OVERLAYSTRETCHY = 0x02000000l;

        /*
         * DirectDraw supports integer stretching (1x,2x,) of a surface
         * along the y axis (vertical direction) for overlays.
         */
        const DWORD  DDFXCAPS_OVERLAYSTRETCHYN = 0x04000000l;

        /*
         * DirectDraw supports mirroring of overlays across the vertical axis
         */
        const DWORD  DDFXCAPS_OVERLAYMIRRORLEFTRIGHT = 0x08000000l;

        /*
         * DirectDraw supports mirroring of overlays across the horizontal axis
         */
        const DWORD  DDFXCAPS_OVERLAYMIRRORUPDOWN = 0x10000000l;

        /*
         * Driver can do alpha blending for blits.
         */
        const DWORD  DDFXCAPS_BLTALPHA = 0x00000001l;


        /*
         * Driver can do surface-reconstruction filtering for warped blits.
         */
        const DWORD  DDFXCAPS_BLTFILTER = DDFXCAPS_BLTARITHSTRETCHY;

        /*
         * Driver can do alpha blending for overlays.
         */
        const DWORD  DDFXCAPS_OVERLAYALPHA = 0x00000004l;


        /*
         * Driver can do surface-reconstruction filtering for warped overlays.
         */
        const DWORD  DDFXCAPS_OVERLAYFILTER = DDFXCAPS_OVERLAYARITHSTRETCHY;


        /****************************************************************************
         *
         * DIRECTDRAW STEREO VIEW CAPABILITIES
         *
         ****************************************************************************/

         /*
          * This flag used to be DDSVCAPS_ENIGMA, which is now obsolete
          */

        const DWORD  DDSVCAPS_RESERVED1 = 0x00000001l;

        /*
         * This flag used to be DDSVCAPS_FLICKER, which is now obsolete
         */
        const DWORD  DDSVCAPS_RESERVED2 = 0x00000002l;

        /*
         * This flag used to be DDSVCAPS_REDBLUE, which is now obsolete
         */
        const DWORD  DDSVCAPS_RESERVED3 = 0x00000004l;

        /*
         * This flag used to be DDSVCAPS_SPLIT, which is now obsolete
         */
        const DWORD  DDSVCAPS_RESERVED4 = 0x00000008l;

        /*
         * The stereo view is accomplished with switching technology
         */

        const DWORD  DDSVCAPS_STEREOSEQUENTIAL = 0x00000010L;




        /****************************************************************************
         *
         * DIRECTDRAWPALETTE CAPABILITIES
         *
         ****************************************************************************/

         /*
          * Index is 4 bits.  There are sixteen color entries in the palette table.
          */
        const DWORD  DDPCAPS_4BIT = 0x00000001l;

        /*
         * Index is onto a 8 bit color index.  This field is only valid with the
         * DDPCAPS_1BIT, DDPCAPS_2BIT or DDPCAPS_4BIT capability and the target
         * surface is in 8bpp. Each color entry is one byte long and is an index
         * into destination surface's 8bpp palette.
         */
        const DWORD  DDPCAPS_8BITENTRIES = 0x00000002l;

        /*
         * Index is 8 bits.  There are 256 color entries in the palette table.
         */
        const DWORD  DDPCAPS_8BIT = 0x00000004l;

        /*
         * Indicates that this DIRECTDRAWPALETTE should use the palette color array
         * passed into the lpDDColorArray parameter to initialize the DIRECTDRAWPALETTE
         * object.
         * This flag is obsolete. DirectDraw always initializes the color array from
         * the lpDDColorArray parameter. The definition remains for source-level
         * compatibility.
         */
        const DWORD  DDPCAPS_INITIALIZE = 0x00000000l;

        /*
         * This palette is the one attached to the primary surface.  Changing this
         * table has immediate effect on the display unless DDPSETPAL_VSYNC is specified
         * and supported.
         */
        const DWORD  DDPCAPS_PRIMARYSURFACE = 0x00000010l;

        /*
         * This palette is the one attached to the primary surface left.  Changing
         * this table has immediate effect on the display for the left eye unless
         * DDPSETPAL_VSYNC is specified and supported.
         */
        const DWORD  DDPCAPS_PRIMARYSURFACELEFT = 0x00000020l;

        /*
         * This palette can have all 256 entries defined
         */
        const DWORD  DDPCAPS_ALLOW256 = 0x00000040l;

        /*
         * This palette can have modifications to it synced with the monitors
         * refresh rate.
         */
        const DWORD  DDPCAPS_VSYNC = 0x00000080l;

        /*
         * Index is 1 bit.  There are two color entries in the palette table.
         */
        const DWORD  DDPCAPS_1BIT = 0x00000100l;

        /*
         * Index is 2 bit.  There are four color entries in the palette table.
         */
        const DWORD  DDPCAPS_2BIT = 0x00000200l;

        /*
         * The peFlags member of PALETTEENTRY denotes an 8 bit alpha value
         */
        const DWORD  DDPCAPS_ALPHA = 0x00000400l;


        /****************************************************************************
         *
         * DIRECTDRAWPALETTE SETENTRY CONSTANTS
         *
         ****************************************************************************/


         /****************************************************************************
          *
          * DIRECTDRAWPALETTE GETENTRY CONSTANTS
          *
          ****************************************************************************/

          /* 0 is the only legal value */

          /****************************************************************************
           *
           * DIRECTDRAWSURFACE SETPRIVATEDATA CONSTANTS
           *
           ****************************************************************************/

           /*
            * The passed pointer is an IUnknown ptr. The cbData argument to SetPrivateData
            * must be set to sizeof(IUnknown*). DirectDraw will call AddRef through this
            * pointer and Release when the private data is destroyed. This includes when
            * the surface or palette is destroyed before such priovate data is destroyed.
            */
        const DWORD  DDSPD_IUNKNOWNPOINTER = 0x00000001L;

        /*
         * Private data is only valid for the current state of the object,
         * as determined by the uniqueness value.
         */
        const DWORD  DDSPD_VOLATILE = 0x00000002L;


        /****************************************************************************
         *
         * DIRECTDRAWSURFACE SETPALETTE CONSTANTS
         *
         ****************************************************************************/


         /****************************************************************************
          *
          * DIRECTDRAW BITDEPTH CONSTANTS
          *
          * NOTE:  These are only used to indicate supported bit depths.   These
          * are flags only, they are not to be used as an actual bit depth.   The
          * absolute numbers 1, 2, 4, 8, 16, 24 and 32 are used to indicate actual
          * bit depths in a surface or for changing the display mode.
          *
          ****************************************************************************/

          /*
           * 1 bit per pixel.
           */
        const DWORD  DDBD_1 = 0x00004000l;

        /*
         * 2 bits per pixel.
         */
        const DWORD  DDBD_2 = 0x00002000l;

        /*
         * 4 bits per pixel.
         */
        const DWORD  DDBD_4 = 0x00001000l;

        /*
         * 8 bits per pixel.
         */
        const DWORD  DDBD_8 = 0x00000800l;

        /*
         * 16 bits per pixel.
         */
        const DWORD  DDBD_16 = 0x00000400l;

        /*
         * 24 bits per pixel.
         */
        const DWORD  DDBD_24 = 0X00000200l;

        /*
         * 32 bits per pixel.
         */
        const DWORD  DDBD_32 = 0x00000100l;

        /****************************************************************************
         *
         * DIRECTDRAWSURFACE SET/GET COLOR KEY FLAGS
         *
         ****************************************************************************/

         /*
          * Set if the structure contains a color space.  Not set if the structure
          * contains a single color key.
          */
        const DWORD  DDCKEY_COLORSPACE = 0x00000001l;

        /*
         * Set if the structure specifies a color key or color space which is to be
         * used as a destination color key for blt operations.
         */
        const DWORD  DDCKEY_DESTBLT = 0x00000002l;

        /*
         * Set if the structure specifies a color key or color space which is to be
         * used as a destination color key for overlay operations.
         */
        const DWORD  DDCKEY_DESTOVERLAY = 0x00000004l;

        /*
         * Set if the structure specifies a color key or color space which is to be
         * used as a source color key for blt operations.
         */
        const DWORD  DDCKEY_SRCBLT = 0x00000008l;

        /*
         * Set if the structure specifies a color key or color space which is to be
         * used as a source color key for overlay operations.
         */
        const DWORD  DDCKEY_SRCOVERLAY = 0x00000010l;


        /****************************************************************************
         *
         * DIRECTDRAW COLOR KEY CAPABILITY FLAGS
         *
         ****************************************************************************/

         /*
          * Supports transparent blting using a color key to identify the replaceable
          * bits of the destination surface for RGB colors.
          */
        const DWORD  DDCKEYCAPS_DESTBLT = 0x00000001l;

        /*
         * Supports transparent blting using a color space to identify the replaceable
         * bits of the destination surface for RGB colors.
         */
        const DWORD  DDCKEYCAPS_DESTBLTCLRSPACE = 0x00000002l;

        /*
         * Supports transparent blting using a color space to identify the replaceable
         * bits of the destination surface for YUV colors.
         */
        const DWORD  DDCKEYCAPS_DESTBLTCLRSPACEYUV = 0x00000004l;

        /*
         * Supports transparent blting using a color key to identify the replaceable
         * bits of the destination surface for YUV colors.
         */
        const DWORD  DDCKEYCAPS_DESTBLTYUV = 0x00000008l;

        /*
         * Supports overlaying using colorkeying of the replaceable bits of the surface
         * being overlayed for RGB colors.
         */
        const DWORD  DDCKEYCAPS_DESTOVERLAY = 0x00000010l;

        /*
         * Supports a color space as the color key for the destination for RGB colors.
         */
        const DWORD  DDCKEYCAPS_DESTOVERLAYCLRSPACE = 0x00000020l;

        /*
         * Supports a color space as the color key for the destination for YUV colors.
         */
        const DWORD  DDCKEYCAPS_DESTOVERLAYCLRSPACEYUV = 0x00000040l;

        /*
         * Supports only one active destination color key value for visible overlay
         * surfaces.
         */
        const DWORD  DDCKEYCAPS_DESTOVERLAYONEACTIVE = 0x00000080l;

        /*
         * Supports overlaying using colorkeying of the replaceable bits of the
         * surface being overlayed for YUV colors.
         */
        const DWORD  DDCKEYCAPS_DESTOVERLAYYUV = 0x00000100l;

        /*
         * Supports transparent blting using the color key for the source with
         * this surface for RGB colors.
         */
        const DWORD  DDCKEYCAPS_SRCBLT = 0x00000200l;

        /*
         * Supports transparent blting using a color space for the source with
         * this surface for RGB colors.
         */
        const DWORD  DDCKEYCAPS_SRCBLTCLRSPACE = 0x00000400l;

        /*
         * Supports transparent blting using a color space for the source with
         * this surface for YUV colors.
         */
        const DWORD  DDCKEYCAPS_SRCBLTCLRSPACEYUV = 0x00000800l;

        /*
         * Supports transparent blting using the color key for the source with
         * this surface for YUV colors.
         */
        const DWORD  DDCKEYCAPS_SRCBLTYUV = 0x00001000l;

        /*
         * Supports overlays using the color key for the source with this
         * overlay surface for RGB colors.
         */
        const DWORD  DDCKEYCAPS_SRCOVERLAY = 0x00002000l;

        /*
         * Supports overlays using a color space as the source color key for
         * the overlay surface for RGB colors.
         */
        const DWORD  DDCKEYCAPS_SRCOVERLAYCLRSPACE = 0x00004000l;

        /*
         * Supports overlays using a color space as the source color key for
         * the overlay surface for YUV colors.
         */
        const DWORD  DDCKEYCAPS_SRCOVERLAYCLRSPACEYUV = 0x00008000l;

        /*
         * Supports only one active source color key value for visible
         * overlay surfaces.
         */
        const DWORD  DDCKEYCAPS_SRCOVERLAYONEACTIVE = 0x00010000l;

        /*
         * Supports overlays using the color key for the source with this
         * overlay surface for YUV colors.
         */
        const DWORD  DDCKEYCAPS_SRCOVERLAYYUV = 0x00020000l;

        /*
         * there are no bandwidth trade-offs for using colorkey with an overlay
         */
        const DWORD  DDCKEYCAPS_NOCOSTOVERLAY = 0x00040000l;


        /****************************************************************************
         *
         * DIRECTDRAW PIXELFORMAT FLAGS
         *
         ****************************************************************************/

         /*
          * The surface has alpha channel information in the pixel format.
          */
        const DWORD  DDPF_ALPHAPIXELS = 0x00000001l;

        /*
         * The pixel format contains alpha only information
         */
        const DWORD  DDPF_ALPHA = 0x00000002l;

        /*
         * The FourCC code is valid.
         */
        const DWORD  DDPF_FOURCC = 0x00000004l;

        /*
         * The surface is 4-bit color indexed.
         */
        const DWORD  DDPF_PALETTEINDEXED4 = 0x00000008l;

        /*
         * The surface is indexed into a palette which stores indices
         * into the destination surface's 8-bit palette.
         */
        const DWORD  DDPF_PALETTEINDEXEDTO8 = 0x00000010l;

        /*
         * The surface is 8-bit color indexed.
         */
        const DWORD  DDPF_PALETTEINDEXED8 = 0x00000020l;

        /*
         * The RGB data in the pixel format structure is valid.
         */
        const DWORD  DDPF_RGB = 0x00000040l;

        /*
         * The surface will accept pixel data in the format specified
         * and compress it during the write.
         */
        const DWORD  DDPF_COMPRESSED = 0x00000080l;

        /*
         * The surface will accept RGB data and translate it during
         * the write to YUV data.  The format of the data to be written
         * will be contained in the pixel format structure.  The DDPF_RGB
         * flag will be set.
         */
        const DWORD  DDPF_RGBTOYUV = 0x00000100l;

        /*
         * pixel format is YUV - YUV data in pixel format struct is valid
         */
        const DWORD  DDPF_YUV = 0x00000200l;

        /*
         * pixel format is a z buffer only surface
         */
        const DWORD  DDPF_ZBUFFER = 0x00000400l;

        /*
         * The surface is 1-bit color indexed.
         */
        const DWORD  DDPF_PALETTEINDEXED1 = 0x00000800l;

        /*
         * The surface is 2-bit color indexed.
         */
        const DWORD  DDPF_PALETTEINDEXED2 = 0x00001000l;

        /*
         * The surface contains Z information in the pixels
         */
        const DWORD  DDPF_ZPIXELS = 0x00002000l;

        /*
         * The surface contains stencil information along with Z
         */
        const DWORD  DDPF_STENCILBUFFER = 0x00004000l;

        /*
         * Premultiplied alpha format -- the color components have been
         * premultiplied by the alpha component.
         */
        const DWORD  DDPF_ALPHAPREMULT = 0x00008000l;


        /*
         * Luminance data in the pixel format is valid.
         * Use this flag for luminance-only or luminance+alpha surfaces,
         * the bit depth is then ddpf.dwLuminanceBitCount.
         */
        const DWORD  DDPF_LUMINANCE = 0x00020000l;

        /*
         * Luminance data in the pixel format is valid.
         * Use this flag when hanging luminance off bumpmap surfaces,
         * the bit mask for the luminance portion of the pixel is then
         * ddpf.dwBumpLuminanceBitMask
         */
        const DWORD  DDPF_BUMPLUMINANCE = 0x00040000l;

        /*
         * Bump map dUdV data in the pixel format is valid.
         */
        const DWORD  DDPF_BUMPDUDV = 0x00080000l;


        /*===========================================================================
         *
         *
         * DIRECTDRAW CALLBACK FLAGS
         *
         *
         *==========================================================================*/

         /****************************************************************************
          *
          * DIRECTDRAW ENUMSURFACES FLAGS
          *
          ****************************************************************************/

          /*
           * Enumerate all of the surfaces that meet the search criterion.
           */
        const DWORD  DDENUMSURFACES_ALL = 0x00000001l;

        /*
         * A search hit is a surface that matches the surface description.
         */
        const DWORD  DDENUMSURFACES_MATCH = 0x00000002l;

        /*
         * A search hit is a surface that does not match the surface description.
         */
        const DWORD  DDENUMSURFACES_NOMATCH = 0x00000004l;

        /*
         * Enumerate the first surface that can be created which meets the search criterion.
         */
        const DWORD  DDENUMSURFACES_CANBECREATED = 0x00000008l;

        /*
         * Enumerate the surfaces that already exist that meet the search criterion.
         */
        const DWORD  DDENUMSURFACES_DOESEXIST = 0x00000010l;


        /****************************************************************************
         *
         * DIRECTDRAW SETDISPLAYMODE FLAGS
         *
         ****************************************************************************/

         /*
          * The desired mode is a standard VGA mode
          */
        const DWORD  DDSDM_STANDARDVGAMODE = 0x00000001l;
        ;


        /****************************************************************************
         *
         * DIRECTDRAW ENUMDISPLAYMODES FLAGS
         *
         ****************************************************************************/

         /*
          * Enumerate Modes with different refresh rates.  EnumDisplayModes guarantees
          * that a particular mode will be enumerated only once.  This flag specifies whether
          * the refresh rate is taken into account when determining if a mode is unique.
          */
        const DWORD  DDEDM_REFRESHRATES = 0x00000001l;

        /*
         * Enumerate VGA modes. Specify this flag if you wish to enumerate supported VGA
         * modes such as mode 0x13 in addition to the usual ModeX modes (which are always
         * enumerated if the application has previously called SetCooperativeLevel with the
         * DDSCL_ALLOWMODEX flag set).
         */
        const DWORD  DDEDM_STANDARDVGAMODES = 0x00000002L;


        /****************************************************************************
         *
         * DIRECTDRAW SETCOOPERATIVELEVEL FLAGS
         *
         ****************************************************************************/

         /*
          * Exclusive mode owner will be responsible for the entire primary surface.
          * GDI can be ignored. used with DD
          */
        const DWORD  DDSCL_FULLSCREEN = 0x00000001l;

        /*
         * allow CTRL_ALT_DEL to work while in fullscreen exclusive mode
         */
        const DWORD  DDSCL_ALLOWREBOOT = 0x00000002l;

        /*
         * prevents DDRAW from modifying the application window.
         * prevents DDRAW from minimize/restore the application window on activation.
         */
        const DWORD  DDSCL_NOWINDOWCHANGES = 0x00000004l;

        /*
         * app wants to work as a regular Windows application
         */
        const DWORD  DDSCL_NORMAL = 0x00000008l;

        /*
         * app wants exclusive access
         */
        const DWORD  DDSCL_EXCLUSIVE = 0x00000010l;


        /*
         * app can deal with non-windows display modes
         */
        const DWORD  DDSCL_ALLOWMODEX = 0x00000040l;

        /*
         * this window will receive the focus messages
         */
        const DWORD  DDSCL_SETFOCUSWINDOW = 0x00000080l;

        /*
         * this window is associated with the DDRAW object and will
         * cover the screen in fullscreen mode
         */
        const DWORD  DDSCL_SETDEVICEWINDOW = 0x00000100l;

        /*
         * app wants DDRAW to create a window to be associated with the
         * DDRAW object
         */
        const DWORD  DDSCL_CREATEDEVICEWINDOW = 0x00000200l;

        /*
         * App explicitly asks DDRAW/D3D to be multithread safe. This makes D3D
         * take the global crtisec more frequently.
         */
        const DWORD  DDSCL_MULTITHREADED = 0x00000400l;

        /*
         * App specifies that it would like to keep the FPU set up for optimal Direct3D
         * performance (single precision and exceptions disabled) so Direct3D
         * does not need to explicitly set the FPU each time. This is assumed by
         * default in DirectX 7. See also DDSCL_FPUPRESERVE
         */
        const DWORD  DDSCL_FPUSETUP = 0x00000800l;

        /*
         * App specifies that it needs either double precision FPU or FPU exceptions
         * enabled. This makes Direct3D explicitly set the FPU state eah time it is
         * called. Setting the flag will reduce Direct3D performance. The flag is
         * assumed by default in DirectX 6 and earlier. See also DDSCL_FPUSETUP
         */
        const DWORD  DDSCL_FPUPRESERVE = 0x00001000l;


        /****************************************************************************
         *
         * DIRECTDRAW BLT FLAGS
         *
         ****************************************************************************/

         /*
          * Use the alpha information in the pixel format or the alpha channel surface
          * attached to the destination surface as the alpha channel for this blt.
          */
        const DWORD  DDBLT_ALPHADEST = 0x00000001l;

        /*
         * Use the dwConstAlphaDest field in the DDBLTFX structure as the alpha channel
         * for the destination surface for this blt.
         */
        const DWORD  DDBLT_ALPHADESTCONSTOVERRIDE = 0x00000002l;

        /*
         * The NEG suffix indicates that the destination surface becomes more
         * transparent as the alpha value increases. (0 is opaque)
         */
        const DWORD  DDBLT_ALPHADESTNEG = 0x00000004l;

        /*
         * Use the lpDDSAlphaDest field in the DDBLTFX structure as the alpha
         * channel for the destination for this blt.
         */
        const DWORD  DDBLT_ALPHADESTSURFACEOVERRIDE = 0x00000008l;

        /*
         * Use the dwAlphaEdgeBlend field in the DDBLTFX structure as the alpha channel
         * for the edges of the image that border the color key colors.
         */
        const DWORD  DDBLT_ALPHAEDGEBLEND = 0x00000010l;

        /*
         * Use the alpha information in the pixel format or the alpha channel surface
         * attached to the source surface as the alpha channel for this blt.
         */
        const DWORD  DDBLT_ALPHASRC = 0x00000020l;

        /*
         * Use the dwConstAlphaSrc field in the DDBLTFX structure as the alpha channel
         * for the source for this blt.
         */
        const DWORD  DDBLT_ALPHASRCCONSTOVERRIDE = 0x00000040l;

        /*
         * The NEG suffix indicates that the source surface becomes more transparent
         * as the alpha value increases. (0 is opaque)
         */
        const DWORD  DDBLT_ALPHASRCNEG = 0x00000080l;

        /*
         * Use the lpDDSAlphaSrc field in the DDBLTFX structure as the alpha channel
         * for the source for this blt.
         */
        const DWORD  DDBLT_ALPHASRCSURFACEOVERRIDE = 0x00000100l;

        /*
         * Do this blt asynchronously through the FIFO in the order received.  If
         * there is no room in the hardware FIFO fail the call.
         */
        const DWORD  DDBLT_ASYNC = 0x00000200l;

        /*
         * Uses the dwFillColor field in the DDBLTFX structure as the RGB color
         * to fill the destination rectangle on the destination surface with.
         */
        const DWORD  DDBLT_COLORFILL = 0x00000400l;

        /*
         * Uses the dwDDFX field in the DDBLTFX structure to specify the effects
         * to use for the blt.
         */
        const DWORD  DDBLT_DDFX = 0x00000800l;

        /*
         * Uses the dwDDROPS field in the DDBLTFX structure to specify the ROPS
         * that are not part of the Win32 API.
         */
        const DWORD  DDBLT_DDROPS = 0x00001000l;

        /*
         * Use the color key associated with the destination surface.
         */
        const DWORD  DDBLT_KEYDEST = 0x00002000l;

        /*
         * Use the dckDestColorkey field in the DDBLTFX structure as the color key
         * for the destination surface.
         */
        const DWORD  DDBLT_KEYDESTOVERRIDE = 0x00004000l;

        /*
         * Use the color key associated with the source surface.
         */
        const DWORD  DDBLT_KEYSRC = 0x00008000l;

        /*
         * Use the dckSrcColorkey field in the DDBLTFX structure as the color key
         * for the source surface.
         */
        const DWORD  DDBLT_KEYSRCOVERRIDE = 0x00010000l;

        /*
         * Use the dwROP field in the DDBLTFX structure for the raster operation
         * for this blt.  These ROPs are the same as the ones defined in the Win32 API.
         */
        const DWORD  DDBLT_ROP = 0x00020000l;

        /*
         * Use the dwRotationAngle field in the DDBLTFX structure as the angle
         * (specified in 1/100th of a degree) to rotate the surface.
         */
        const DWORD  DDBLT_ROTATIONANGLE = 0x00040000l;

        /*
         * Z-buffered blt using the z-buffers attached to the source and destination
         * surfaces and the dwZBufferOpCode field in the DDBLTFX structure as the
         * z-buffer opcode.
         */
        const DWORD  DDBLT_ZBUFFER = 0x00080000l;

        /*
         * Z-buffered blt using the dwConstDest Zfield and the dwZBufferOpCode field
         * in the DDBLTFX structure as the z-buffer and z-buffer opcode respectively
         * for the destination.
         */
        const DWORD  DDBLT_ZBUFFERDESTCONSTOVERRIDE = 0x00100000l;

        /*
         * Z-buffered blt using the lpDDSDestZBuffer field and the dwZBufferOpCode
         * field in the DDBLTFX structure as the z-buffer and z-buffer opcode
         * respectively for the destination.
         */
        const DWORD  DDBLT_ZBUFFERDESTOVERRIDE = 0x00200000l;

        /*
         * Z-buffered blt using the dwConstSrcZ field and the dwZBufferOpCode field
         * in the DDBLTFX structure as the z-buffer and z-buffer opcode respectively
         * for the source.
         */
        const DWORD  DDBLT_ZBUFFERSRCCONSTOVERRIDE = 0x00400000l;

        /*
         * Z-buffered blt using the lpDDSSrcZBuffer field and the dwZBufferOpCode
         * field in the DDBLTFX structure as the z-buffer and z-buffer opcode
         * respectively for the source.
         */
        const DWORD  DDBLT_ZBUFFERSRCOVERRIDE = 0x00800000l;

        /*
         * wait until the device is ready to handle the blt
         * this will cause blt to not return DDERR_WASSTILLDRAWING
         */
        const DWORD  DDBLT_WAIT = 0x01000000l;

        /*
         * Uses the dwFillDepth field in the DDBLTFX structure as the depth value
         * to fill the destination rectangle on the destination Z-buffer surface
         * with.
         */
        const DWORD  DDBLT_DEPTHFILL = 0x02000000l;


        /*
         * wait until the device is ready to handle the blt
         * this will cause blt to not return DDERR_WASSTILLDRAWING
         */
        const DWORD  DDBLT_DONOTWAIT = 0x08000000l;


        /****************************************************************************
         *
         * BLTFAST FLAGS
         *
         ****************************************************************************/

        const DWORD  DDBLTFAST_NOCOLORKEY = 0x00000000;
        const DWORD  DDBLTFAST_SRCCOLORKEY = 0x00000001;
        const DWORD  DDBLTFAST_DESTCOLORKEY = 0x00000002;
        const DWORD  DDBLTFAST_WAIT = 0x00000010;
        const DWORD  DDBLTFAST_DONOTWAIT = 0x00000020;



        /****************************************************************************
         *
         * FLIP FLAGS
         *
         ****************************************************************************/

        const DWORD  DDFLIP_WAIT = 0x00000001L;

        /*
         * Indicates that the target surface contains the even field of video data.
         * This flag is only valid with an overlay surface.
         */
        const DWORD  DDFLIP_EVEN = 0x00000002L;

        /*
         * Indicates that the target surface contains the odd field of video data.
         * This flag is only valid with an overlay surface.
         */
        const DWORD  DDFLIP_ODD = 0x00000004L;

        /*
         * Causes DirectDraw to perform the physical flip immediately and return
         * to the application. Typically, what was the front buffer but is now the back
         * buffer will still be visible (depending on timing) until the next vertical
         * retrace. Subsequent operations involving the two flipped surfaces will
         * not check to see if the physical flip has finished (i.e. will not return
         * DDERR_WASSTILLDRAWING for that reason (but may for other reasons)).
         * This allows an application to perform Flips at a higher frequency than the
         * monitor refresh rate, but may introduce visible artifacts.
         * Only effective if DDCAPS2_FLIPNOVSYNC is set. If that bit is not set,
         * DDFLIP_NOVSYNC has no effect.
         */
        const DWORD  DDFLIP_NOVSYNC = 0x00000008L;


        /*
         * Flip Interval Flags. These flags indicate how many vertical retraces to wait between
         * each flip. The default is one. DirectDraw will return DDERR_WASSTILLDRAWING for each
         * surface involved in the flip until the specified number of vertical retraces has
         * ocurred. Only effective if DDCAPS2_FLIPINTERVAL is set. If that bit is not set,
         * DDFLIP_INTERVALn has no effect.
         */

         /*
          * DirectDraw will flip on every other vertical sync
          */
        const DWORD  DDFLIP_INTERVAL2 = 0x02000000L;


        /*
         * DirectDraw will flip on every third vertical sync
         */
        const DWORD  DDFLIP_INTERVAL3 = 0x03000000L;


        /*
         * DirectDraw will flip on every fourth vertical sync
         */
        const DWORD  DDFLIP_INTERVAL4 = 0x04000000L;

        /*
         * DirectDraw will flip and display a main stereo surface
         */
        const DWORD  DDFLIP_STEREO = 0x00000010L;

        /*
         * On IDirectDrawSurface7 and higher interfaces, the default is DDFLIP_WAIT. If you wish
         * to override the default and use time when the accelerator is busy (as denoted by
         * the DDERR_WASSTILLDRAWING return code) then use DDFLIP_DONOTWAIT.
         */
        const DWORD  DDFLIP_DONOTWAIT = 0x00000020L;



        /****************************************************************************
         *
         * DIRECTDRAW SURFACE OVERLAY FLAGS
         *
         ****************************************************************************/

         /*
          * Use the alpha information in the pixel format or the alpha channel surface
          * attached to the destination surface as the alpha channel for the
          * destination overlay.
          */
        const DWORD  DDOVER_ALPHADEST = 0x00000001l;

        /*
         * Use the dwConstAlphaDest field in the DDOVERLAYFX structure as the
         * destination alpha channel for this overlay.
         */
        const DWORD  DDOVER_ALPHADESTCONSTOVERRIDE = 0x00000002l;

        /*
         * The NEG suffix indicates that the destination surface becomes more
         * transparent as the alpha value increases.
         */
        const DWORD  DDOVER_ALPHADESTNEG = 0x00000004l;

        /*
         * Use the lpDDSAlphaDest field in the DDOVERLAYFX structure as the alpha
         * channel destination for this overlay.
         */
        const DWORD  DDOVER_ALPHADESTSURFACEOVERRIDE = 0x00000008l;

        /*
         * Use the dwAlphaEdgeBlend field in the DDOVERLAYFX structure as the alpha
         * channel for the edges of the image that border the color key colors.
         */
        const DWORD  DDOVER_ALPHAEDGEBLEND = 0x00000010l;

        /*
         * Use the alpha information in the pixel format or the alpha channel surface
         * attached to the source surface as the source alpha channel for this overlay.
         */
        const DWORD  DDOVER_ALPHASRC = 0x00000020l;

        /*
         * Use the dwConstAlphaSrc field in the DDOVERLAYFX structure as the source
         * alpha channel for this overlay.
         */
        const DWORD  DDOVER_ALPHASRCCONSTOVERRIDE = 0x00000040l;

        /*
         * The NEG suffix indicates that the source surface becomes more transparent
         * as the alpha value increases.
         */
        const DWORD  DDOVER_ALPHASRCNEG = 0x00000080l;

        /*
         * Use the lpDDSAlphaSrc field in the DDOVERLAYFX structure as the alpha channel
         * source for this overlay.
         */
        const DWORD  DDOVER_ALPHASRCSURFACEOVERRIDE = 0x00000100l;

        /*
         * Turn this overlay off.
         */
        const DWORD  DDOVER_HIDE = 0x00000200l;

        /*
         * Use the color key associated with the destination surface.
         */
        const DWORD  DDOVER_KEYDEST = 0x00000400l;

        /*
         * Use the dckDestColorkey field in the DDOVERLAYFX structure as the color key
         * for the destination surface
         */
        const DWORD  DDOVER_KEYDESTOVERRIDE = 0x00000800l;

        /*
         * Use the color key associated with the source surface.
         */
        const DWORD  DDOVER_KEYSRC = 0x00001000l;

        /*
         * Use the dckSrcColorkey field in the DDOVERLAYFX structure as the color key
         * for the source surface.
         */
        const DWORD  DDOVER_KEYSRCOVERRIDE = 0x00002000l;

        /*
         * Turn this overlay on.
         */
        const DWORD  DDOVER_SHOW = 0x00004000l;

        /*
         * Add a dirty rect to an emulated overlayed surface.
         */
        const DWORD  DDOVER_ADDDIRTYRECT = 0x00008000l;

        /*
         * Redraw all dirty rects on an emulated overlayed surface.
         */
        const DWORD  DDOVER_REFRESHDIRTYRECTS = 0x00010000l;

        /*
         * Redraw the entire surface on an emulated overlayed surface.
         */
        const DWORD  DDOVER_REFRESHALL = 0x00020000l;


        /*
         * Use the overlay FX flags to define special overlay FX
         */
        const DWORD  DDOVER_DDFX = 0x00080000l;

        /*
         * Autoflip the overlay when ever the video port autoflips
         */
        const DWORD  DDOVER_AUTOFLIP = 0x00100000l;

        /*
         * Display each field of video port data individually without
         * causing any jittery artifacts
         */
        const DWORD  DDOVER_BOB = 0x00200000l;

        /*
         * Indicates that bob/weave decisions should not be overridden by other
         * interfaces.
         */
        const DWORD  DDOVER_OVERRIDEBOBWEAVE = 0x00400000l;

        /*
         * Indicates that the surface memory is composed of interleaved fields.
         */
        const DWORD  DDOVER_INTERLEAVED = 0x00800000l;

        /*
         * Indicates that bob will be performed using hardware rather than
         * software or emulated.
         */
        const DWORD  DDOVER_BOBHARDWARE = 0x01000000l;

        /*
         * Indicates that overlay FX structure contains valid ARGB scaling factors.
         */
        const DWORD  DDOVER_ARGBSCALEFACTORS = 0x02000000l;

        /*
         * Indicates that ARGB scaling factors can be degraded to fit driver capabilities.
         */
        const DWORD  DDOVER_DEGRADEARGBSCALING = 0x04000000l;








        /****************************************************************************
         *
         * DIRECTDRAWSURFACE LOCK FLAGS
         *
         ****************************************************************************/

         /*
          * The default.  Set to indicate that Lock should return a valid memory pointer
          * to the top of the specified rectangle.  If no rectangle is specified then a
          * pointer to the top of the surface is returned.
          */
        const DWORD  DDLOCK_SURFACEMEMORYPTR = 0x00000000L;   // default

        /*
         * Set to indicate that Lock should wait until it can obtain a valid memory
         * pointer before returning.  If this bit is set, Lock will never return
         * DDERR_WASSTILLDRAWING.
         */
        const DWORD  DDLOCK_WAIT = 0x00000001L;

        /*
         * Set if an event handle is being passed to Lock.  Lock will trigger the event
         * when it can return the surface memory pointer requested.
         */
        const DWORD  DDLOCK_EVENT = 0x00000002L;

        /*
         * Indicates that the surface being locked will only be read from.
         */
        const DWORD  DDLOCK_READONLY = 0x00000010L;

        /*
         * Indicates that the surface being locked will only be written to
         */
        const DWORD  DDLOCK_WRITEONLY = 0x00000020L;


        /*
         * Indicates that a system wide lock should not be taken when this surface
         * is locked. This has several advantages (cursor responsiveness, ability
         * to call more Windows functions, easier debugging) when locking video
         * memory surfaces. However, an application specifying this flag must
         * comply with a number of conditions documented in the help file.
         * Furthermore, this flag cannot be specified when locking the primary.
         */
        const DWORD  DDLOCK_NOSYSLOCK = 0x00000800L;

        /*
         * Used only with Direct3D Vertex Buffer Locks. Indicates that no vertices
         * that were referred to in Draw*PrimtiveVB calls since the start of the
         * frame (or the last lock without this flag) will be modified during the
         * lock. This can be useful when one is only appending data to the vertex
         * buffer
         */
        const DWORD  DDLOCK_NOOVERWRITE = 0x00001000L;

        /*
         * Indicates that no assumptions will be made about the contents of the
         * surface or vertex buffer during this lock.
         * This enables two things:
         * -    Direct3D or the driver may provide an alternative memory
         *      area as the vertex buffer. This is useful when one plans to clear the
         *      contents of the vertex buffer and fill in new data.
         * -    Drivers sometimes store surface data in a re-ordered format.
         *      When the application locks the surface, the driver is forced to un-re-order
         *      the surface data before allowing the application to see the surface contents.
         *      This flag is a hint to the driver that it can skip the un-re-ordering process
         *      since the application plans to overwrite every single pixel in the surface
         *      or locked rectangle (and so erase any un-re-ordered pixels anyway).
         *      Applications should always set this flag when they intend to overwrite the entire
         *      surface or locked rectangle.
         */
        const DWORD  DDLOCK_DISCARDCONTENTS = 0x00002000L;
        /*
         * DDLOCK_OKTOSWAP is an older, less informative name for DDLOCK_DISCARDCONTENTS
         */
        const DWORD  DDLOCK_OKTOSWAP = 0x00002000L;

        /*
         * On IDirectDrawSurface7 and higher interfaces, the default is DDLOCK_WAIT. If you wish
         * to override the default and use time when the accelerator is busy (as denoted by
         * the DDERR_WASSTILLDRAWING return code) then use DDLOCK_DONOTWAIT.
         */
        const DWORD  DDLOCK_DONOTWAIT = 0x00004000L;



        /****************************************************************************
         *
         * DIRECTDRAWSURFACE PAGELOCK FLAGS
         *
         ****************************************************************************/

         /*
          * No flags defined at present
          */


          /****************************************************************************
           *
           * DIRECTDRAWSURFACE PAGEUNLOCK FLAGS
           *
           ****************************************************************************/

           /*
            * No flags defined at present
            */


            /****************************************************************************
             *
             * DIRECTDRAWSURFACE BLT FX FLAGS
             *
             ****************************************************************************/

             /*
              * If stretching, use arithmetic stretching along the Y axis for this blt.
              */
        const DWORD  DDBLTFX_ARITHSTRETCHY = 0x00000001l;

        /*
         * Do this blt mirroring the surface left to right.  Spin the
         * surface around its y-axis.
         */
        const DWORD  DDBLTFX_MIRRORLEFTRIGHT = 0x00000002l;

        /*
         * Do this blt mirroring the surface up and down.  Spin the surface
         * around its x-axis.
         */
        const DWORD  DDBLTFX_MIRRORUPDOWN = 0x00000004l;

        /*
         * Schedule this blt to avoid tearing.
         */
        const DWORD  DDBLTFX_NOTEARING = 0x00000008l;

        /*
         * Do this blt rotating the surface one hundred and eighty degrees.
         */
        const DWORD  DDBLTFX_ROTATE180 = 0x00000010l;

        /*
         * Do this blt rotating the surface two hundred and seventy degrees.
         */
        const DWORD  DDBLTFX_ROTATE270 = 0x00000020l;

        /*
         * Do this blt rotating the surface ninety degrees.
         */
        const DWORD  DDBLTFX_ROTATE90 = 0x00000040l;

        /*
         * Do this z blt using dwZBufferLow and dwZBufferHigh as  range values
         * specified to limit the bits copied from the source surface.
         */
        const DWORD  DDBLTFX_ZBUFFERRANGE = 0x00000080l;

        /*
         * Do this z blt adding the dwZBufferBaseDest to each of the sources z values
         * before comparing it with the desting z values.
         */
        const DWORD  DDBLTFX_ZBUFFERBASEDEST = 0x00000100l;

        /****************************************************************************
         *
         * DIRECTDRAWSURFACE OVERLAY FX FLAGS
         *
         ****************************************************************************/

         /*
          * If stretching, use arithmetic stretching along the Y axis for this overlay.
          */
        const DWORD  DDOVERFX_ARITHSTRETCHY = 0x00000001l;

        /*
         * Mirror the overlay across the vertical axis
         */
        const DWORD  DDOVERFX_MIRRORLEFTRIGHT = 0x00000002l;

        /*
         * Mirror the overlay across the horizontal axis
         */
        const DWORD  DDOVERFX_MIRRORUPDOWN = 0x00000004l;


        /****************************************************************************
         *
         * DIRECTDRAW WAITFORVERTICALBLANK FLAGS
         *
         ****************************************************************************/

         /*
          * return when the vertical blank interval begins
          */
        const DWORD  DDWAITVB_BLOCKBEGIN = 0x00000001l;

        /*
         * set up an event to trigger when the vertical blank begins
         */
        const DWORD  DDWAITVB_BLOCKBEGINEVENT = 0x00000002l;

        /*
         * return when the vertical blank interval ends and display begins
         */
        const DWORD  DDWAITVB_BLOCKEND = 0x00000004l;

        /****************************************************************************
         *
         * DIRECTDRAW GETFLIPSTATUS FLAGS
         *
         ****************************************************************************/

         /*
          * is it OK to flip now?
          */
        const DWORD  DDGFS_CANFLIP = 0x00000001l;

        /*
         * is the last flip finished?
         */
        const DWORD  DDGFS_ISFLIPDONE = 0x00000002l;

        /****************************************************************************
         *
         * DIRECTDRAW GETBLTSTATUS FLAGS
         *
         ****************************************************************************/

         /*
          * is it OK to blt now?
          */
        const DWORD  DDGBS_CANBLT = 0x00000001l;

        /*
         * is the blt to the surface finished?
         */
        const DWORD  DDGBS_ISBLTDONE = 0x00000002l;


        /****************************************************************************
         *
         * DIRECTDRAW ENUMOVERLAYZORDER FLAGS
         *
         ****************************************************************************/

         /*
          * Enumerate overlays back to front.
          */
        const DWORD  DDENUMOVERLAYZ_BACKTOFRONT = 0x00000000l;

        /*
         * Enumerate overlays front to back
         */
        const DWORD  DDENUMOVERLAYZ_FRONTTOBACK = 0x00000001l;

        /****************************************************************************
         *
         * DIRECTDRAW UPDATEOVERLAYZORDER FLAGS
         *
         ****************************************************************************/

         /*
          * Send overlay to front
          */
        const DWORD  DDOVERZ_SENDTOFRONT = 0x00000000l;

        /*
         * Send overlay to back
         */
        const DWORD  DDOVERZ_SENDTOBACK = 0x00000001l;

        /*
         * Move Overlay forward
         */
        const DWORD  DDOVERZ_MOVEFORWARD = 0x00000002l;

        /*
         * Move Overlay backward
         */
        const DWORD  DDOVERZ_MOVEBACKWARD = 0x00000003l;

        /*
         * Move Overlay in front of relative surface
         */
        const DWORD  DDOVERZ_INSERTINFRONTOF = 0x00000004l;

        /*
         * Move Overlay in back of relative surface
         */
        const DWORD  DDOVERZ_INSERTINBACKOF = 0x00000005l;



        /****************************************************************************
         *
         * DIRECTDRAW SETGAMMARAMP FLAGS
         *
         ****************************************************************************/

         /*
          * Request calibrator to adjust the gamma ramp according to the physical
          * properties of the display so that the result should appear identical
          * on all systems.
          */
        const DWORD  DDSGR_CALIBRATE = 0x00000001L;


        /****************************************************************************
         *
         * DIRECTDRAW STARTMODETEST FLAGS
         *
         ****************************************************************************/

         /*
          * Indicates that the mode being tested has passed
          */
        const DWORD  DDSMT_ISTESTREQUIRED = 0x00000001L;


        /****************************************************************************
         *
         * DIRECTDRAW EVALUATEMODE FLAGS
         *
         ****************************************************************************/

         /*
          * Indicates that the mode being tested has passed
          */
        const DWORD  DDEM_MODEPASSED = 0x00000001L;

        /*
         * Indicates that the mode being tested has failed
         */
        const DWORD  DDEM_MODEFAILED = 0x00000002L;


        /*===========================================================================
         *
         *
         * DIRECTDRAW RETURN CODES
         *
         * The return values from DirectDraw Commands and Surface that return an HRESULT
         * are codes from DirectDraw concerning the results of the action
         * requested by DirectDraw.
         *
         *==========================================================================*/

         /*
          * Status is OK
          *
          * Issued by: DirectDraw Commands and all callbacks
          */
        const DWORD  DD_OK = 0;
        const DWORD  DD_FALSE = S_FALSE;

        /****************************************************************************
         *
         * DIRECTDRAW ENUMCALLBACK RETURN VALUES
         *
         * EnumCallback returns are used to control the flow of the DIRECTDRAW and
         * DIRECTDRAWSURFACE object enumerations.   They can only be returned by
         * enumeration callback routines.
         *
         ****************************************************************************/

         /*
          * stop the enumeration
          */
        const DWORD  DDENUMRET_CANCEL = 0;

        /*
         * continue the enumeration
         */
        const DWORD  DDENUMRET_OK = 1;

        /****************************************************************************
         *
         * DIRECTDRAW ERRORS
         *
         * Errors are represented by negative values and cannot be combined.
         *
         ****************************************************************************/

         /*
          * This object is already initialized
          */
        const DWORD  DDERR_ALREADYINITIALIZED = MAKE_DDHRESULT(5);

        /*
         * This surface can not be attached to the requested surface.
         */
        const DWORD  DDERR_CANNOTATTACHSURFACE = MAKE_DDHRESULT(10);

        /*
         * This surface can not be detached from the requested surface.
         */
        const DWORD  DDERR_CANNOTDETACHSURFACE = MAKE_DDHRESULT(20);

        /*
         * Support is currently not available.
         */
        const DWORD  DDERR_CURRENTLYNOTAVAIL = MAKE_DDHRESULT(40);

        /*
         * An exception was encountered while performing the requested operation
         */
        const DWORD  DDERR_EXCEPTION = MAKE_DDHRESULT(55);

        /*
         * Generic failure.
         */
        const DWORD  DDERR_GENERIC = E_FAIL;

        /*
         * Height of rectangle provided is not a multiple of reqd alignment
         */
        const DWORD  DDERR_HEIGHTALIGN = MAKE_DDHRESULT(90);

        /*
         * Unable to match primary surface creation request with existing
         * primary surface.
         */
        const DWORD  DDERR_INCOMPATIBLEPRIMARY = MAKE_DDHRESULT(95);

        /*
         * One or more of the caps bits passed to the callback are incorrect.
         */
        const DWORD  DDERR_INVALIDCAPS = MAKE_DDHRESULT(100);

        /*
         * DirectDraw does not support provided Cliplist.
         */
        const DWORD  DDERR_INVALIDCLIPLIST = MAKE_DDHRESULT(110);

        /*
         * DirectDraw does not support the requested mode
         */
        const DWORD  DDERR_INVALIDMODE = MAKE_DDHRESULT(120);

        /*
         * DirectDraw received a pointer that was an invalid DIRECTDRAW object.
         */
        const DWORD  DDERR_INVALIDOBJECT = MAKE_DDHRESULT(130);

        /*
         * One or more of the parameters passed to the callback function are
         * incorrect.
         */
        const DWORD  DDERR_INVALIDPARAMS = E_INVALIDARG;

        /*
         * pixel format was invalid as specified
         */
        const DWORD  DDERR_INVALIDPIXELFORMAT = MAKE_DDHRESULT(145);

        /*
         * Rectangle provided was invalid.
         */
        const DWORD  DDERR_INVALIDRECT = MAKE_DDHRESULT(150);

        /*
         * Operation could not be carried out because one or more surfaces are locked
         */
        const DWORD  DDERR_LOCKEDSURFACES = MAKE_DDHRESULT(160);

        /*
         * There is no 3D present.
         */
        const DWORD  DDERR_NO3D = MAKE_DDHRESULT(170);

        /*
         * Operation could not be carried out because there is no alpha accleration
         * hardware present or available.
         */
        const DWORD  DDERR_NOALPHAHW = MAKE_DDHRESULT(180);

        /*
         * Operation could not be carried out because there is no stereo
         * hardware present or available.
         */
        const DWORD  DDERR_NOSTEREOHARDWARE = MAKE_DDHRESULT(181);

        /*
         * Operation could not be carried out because there is no hardware
         * present which supports stereo surfaces
         */
        const DWORD  DDERR_NOSURFACELEFT = MAKE_DDHRESULT(182);



        /*
         * no clip list available
         */
        const DWORD  DDERR_NOCLIPLIST = MAKE_DDHRESULT(205);

        /*
         * Operation could not be carried out because there is no color conversion
         * hardware present or available.
         */
        const DWORD  DDERR_NOCOLORCONVHW = MAKE_DDHRESULT(210);

        /*
         * Create function called without DirectDraw object method SetCooperativeLevel
         * being called.
         */
        const DWORD  DDERR_NOCOOPERATIVELEVELSET = MAKE_DDHRESULT(212);

        /*
         * Surface doesn't currently have a color key
         */
        const DWORD  DDERR_NOCOLORKEY = MAKE_DDHRESULT(215);

        /*
         * Operation could not be carried out because there is no hardware support
         * of the dest color key.
         */
        const DWORD  DDERR_NOCOLORKEYHW = MAKE_DDHRESULT(220);

        /*
         * No DirectDraw support possible with current display driver
         */
        const DWORD  DDERR_NODIRECTDRAWSUPPORT = MAKE_DDHRESULT(222);

        /*
         * Operation requires the application to have exclusive mode but the
         * application does not have exclusive mode.
         */
        const DWORD  DDERR_NOEXCLUSIVEMODE = MAKE_DDHRESULT(225);

        /*
         * Flipping visible surfaces is not supported.
         */
        const DWORD  DDERR_NOFLIPHW = MAKE_DDHRESULT(230);

        /*
         * There is no GDI present.
         */
        const DWORD  DDERR_NOGDI = MAKE_DDHRESULT(240);

        /*
         * Operation could not be carried out because there is no hardware present
         * or available.
         */
        const DWORD  DDERR_NOMIRRORHW = MAKE_DDHRESULT(250);

        /*
         * Requested item was not found
         */
        const DWORD  DDERR_NOTFOUND = MAKE_DDHRESULT(255);

        /*
         * Operation could not be carried out because there is no overlay hardware
         * present or available.
         */
        const DWORD  DDERR_NOOVERLAYHW = MAKE_DDHRESULT(260);

        /*
         * Operation could not be carried out because the source and destination
         * rectangles are on the same surface and overlap each other.
         */
        const DWORD  DDERR_OVERLAPPINGRECTS = MAKE_DDHRESULT(270);

        /*
         * Operation could not be carried out because there is no appropriate raster
         * op hardware present or available.
         */
        const DWORD  DDERR_NORASTEROPHW = MAKE_DDHRESULT(280);

        /*
         * Operation could not be carried out because there is no rotation hardware
         * present or available.
         */
        const DWORD  DDERR_NOROTATIONHW = MAKE_DDHRESULT(290);

        /*
         * Operation could not be carried out because there is no hardware support
         * for stretching
         */
        const DWORD  DDERR_NOSTRETCHHW = MAKE_DDHRESULT(310);

        /*
         * DirectDrawSurface is not in 4 bit color palette and the requested operation
         * requires 4 bit color palette.
         */
        const DWORD  DDERR_NOT4BITCOLOR = MAKE_DDHRESULT(316);

        /*
         * DirectDrawSurface is not in 4 bit color index palette and the requested
         * operation requires 4 bit color index palette.
         */
        const DWORD  DDERR_NOT4BITCOLORINDEX = MAKE_DDHRESULT(317);

        /*
         * DirectDraw Surface is not in 8 bit color mode and the requested operation
         * requires 8 bit color.
         */
        const DWORD  DDERR_NOT8BITCOLOR = MAKE_DDHRESULT(320);

        /*
         * Operation could not be carried out because there is no texture mapping
         * hardware present or available.
         */
        const DWORD  DDERR_NOTEXTUREHW = MAKE_DDHRESULT(330);

        /*
         * Operation could not be carried out because there is no hardware support
         * for vertical blank synchronized operations.
         */
        const DWORD  DDERR_NOVSYNCHW = MAKE_DDHRESULT(335);

        /*
         * Operation could not be carried out because there is no hardware support
         * for zbuffer blting.
         */
        const DWORD  DDERR_NOZBUFFERHW = MAKE_DDHRESULT(340);

        /*
         * Overlay surfaces could not be z layered based on their BltOrder because
         * the hardware does not support z layering of overlays.
         */
        const DWORD  DDERR_NOZOVERLAYHW = MAKE_DDHRESULT(350);

        /*
         * The hardware needed for the requested operation has already been
         * allocated.
         */
        const DWORD  DDERR_OUTOFCAPS = MAKE_DDHRESULT(360);

        /*
         * DirectDraw does not have enough memory to perform the operation.
         */
        const DWORD  DDERR_OUTOFMEMORY = E_OUTOFMEMORY;

        /*
         * DirectDraw does not have enough memory to perform the operation.
         */
        const DWORD  DDERR_OUTOFVIDEOMEMORY = MAKE_DDHRESULT(380);

        /*
         * hardware does not support clipped overlays
         */
        const DWORD  DDERR_OVERLAYCANTCLIP = MAKE_DDHRESULT(382);

        /*
         * Can only have ony color key active at one time for overlays
         */
        const DWORD  DDERR_OVERLAYCOLORKEYONLYONEACTIVE = MAKE_DDHRESULT(384);

        /*
         * Access to this palette is being refused because the palette is already
         * locked by another thread.
         */
        const DWORD  DDERR_PALETTEBUSY = MAKE_DDHRESULT(387);

        /*
         * No src color key specified for this operation.
         */
        const DWORD  DDERR_COLORKEYNOTSET = MAKE_DDHRESULT(400);

        /*
         * This surface is already attached to the surface it is being attached to.
         */
        const DWORD  DDERR_SURFACEALREADYATTACHED = MAKE_DDHRESULT(410);

        /*
         * This surface is already a dependency of the surface it is being made a
         * dependency of.
         */
        const DWORD  DDERR_SURFACEALREADYDEPENDENT = MAKE_DDHRESULT(420);

        /*
         * Access to this surface is being refused because the surface is already
         * locked by another thread.
         */
        const DWORD  DDERR_SURFACEBUSY = MAKE_DDHRESULT(430);

        /*
         * Access to this surface is being refused because no driver exists
         * which can supply a pointer to the surface.
         * This is most likely to happen when attempting to lock the primary
         * surface when no DCI provider is present.
         * Will also happen on attempts to lock an optimized surface.
         */
        const DWORD  DDERR_CANTLOCKSURFACE = MAKE_DDHRESULT(435);

        /*
         * Access to Surface refused because Surface is obscured.
         */
        const DWORD  DDERR_SURFACEISOBSCURED = MAKE_DDHRESULT(440);

        /*
         * Access to this surface is being refused because the surface is gone.
         * The DIRECTDRAWSURFACE object representing this surface should
         * have Restore called on it.
         */
        const DWORD  DDERR_SURFACELOST = MAKE_DDHRESULT(450);

        /*
         * The requested surface is not attached.
         */
        const DWORD  DDERR_SURFACENOTATTACHED = MAKE_DDHRESULT(460);

        /*
         * Height requested by DirectDraw is too large.
         */
        const DWORD  DDERR_TOOBIGHEIGHT = MAKE_DDHRESULT(470);

        /*
         * Size requested by DirectDraw is too large --  The individual height and
         * width are OK.
         */
        const DWORD  DDERR_TOOBIGSIZE = MAKE_DDHRESULT(480);

        /*
         * Width requested by DirectDraw is too large.
         */
        const DWORD  DDERR_TOOBIGWIDTH = MAKE_DDHRESULT(490);

        /*
         * Action not supported.
         */
        const DWORD  DDERR_UNSUPPORTED = E_NOTIMPL;

        /*
         * Pixel format requested is unsupported by DirectDraw
         */
        const DWORD  DDERR_UNSUPPORTEDFORMAT = MAKE_DDHRESULT(510);

        /*
         * Bitmask in the pixel format requested is unsupported by DirectDraw
         */
        const DWORD  DDERR_UNSUPPORTEDMASK = MAKE_DDHRESULT(520);

        /*
         * The specified stream contains invalid data
         */
        const DWORD  DDERR_INVALIDSTREAM = MAKE_DDHRESULT(521);

        /*
         * vertical blank is in progress
         */
        const DWORD  DDERR_VERTICALBLANKINPROGRESS = MAKE_DDHRESULT(537);

        /*
         * Informs DirectDraw that the previous Blt which is transfering information
         * to or from this Surface is incomplete.
         */
        const DWORD  DDERR_WASSTILLDRAWING = MAKE_DDHRESULT(540);


        /*
         * The specified surface type requires specification of the COMPLEX flag
         */
        const DWORD  DDERR_DDSCAPSCOMPLEXREQUIRED = MAKE_DDHRESULT(542);


        /*
         * Rectangle provided was not horizontally aligned on reqd. boundary
         */
        const DWORD  DDERR_XALIGN = MAKE_DDHRESULT(560);

        /*
         * The GUID passed to DirectDrawCreate is not a valid DirectDraw driver
         * identifier.
         */
        const DWORD  DDERR_INVALIDDIRECTDRAWGUID = MAKE_DDHRESULT(561);

        /*
         * A DirectDraw object representing this driver has already been created
         * for this process.
         */
        const DWORD  DDERR_DIRECTDRAWALREADYCREATED = MAKE_DDHRESULT(562);

        /*
         * A hardware only DirectDraw object creation was attempted but the driver
         * did not support any hardware.
         */
        const DWORD  DDERR_NODIRECTDRAWHW = MAKE_DDHRESULT(563);

        /*
         * this process already has created a primary surface
         */
        const DWORD  DDERR_PRIMARYSURFACEALREADYEXISTS = MAKE_DDHRESULT(564);

        /*
         * software emulation not available.
         */
        const DWORD  DDERR_NOEMULATION = MAKE_DDHRESULT(565);

        /*
         * region passed to Clipper::GetClipList is too small.
         */
        const DWORD  DDERR_REGIONTOOSMALL = MAKE_DDHRESULT(566);

        /*
         * an attempt was made to set a clip list for a clipper objec that
         * is already monitoring an hwnd.
         */
        const DWORD  DDERR_CLIPPERISUSINGHWND = MAKE_DDHRESULT(567);

        /*
         * No clipper object attached to surface object
         */
        const DWORD  DDERR_NOCLIPPERATTACHED = MAKE_DDHRESULT(568);

        /*
         * Clipper notification requires an HWND or
         * no HWND has previously been set as the CooperativeLevel HWND.
         */
        const DWORD  DDERR_NOHWND = MAKE_DDHRESULT(569);

        /*
         * HWND used by DirectDraw CooperativeLevel has been subclassed,
         * this prevents DirectDraw from restoring state.
         */
        const DWORD  DDERR_HWNDSUBCLASSED = MAKE_DDHRESULT(570);

        /*
         * The CooperativeLevel HWND has already been set.
         * It can not be reset while the process has surfaces or palettes created.
         */
        const DWORD  DDERR_HWNDALREADYSET = MAKE_DDHRESULT(571);

        /*
         * No palette object attached to this surface.
         */
        const DWORD  DDERR_NOPALETTEATTACHED = MAKE_DDHRESULT(572);

        /*
         * No hardware support for 16 or 256 color palettes.
         */
        const DWORD  DDERR_NOPALETTEHW = MAKE_DDHRESULT(573);

        /*
         * If a clipper object is attached to the source surface passed into a
         * BltFast call.
         */
        const DWORD  DDERR_BLTFASTCANTCLIP = MAKE_DDHRESULT(574);

        /*
         * No blter.
         */
        const DWORD  DDERR_NOBLTHW = MAKE_DDHRESULT(575);

        /*
         * No DirectDraw ROP hardware.
         */
        const DWORD  DDERR_NODDROPSHW = MAKE_DDHRESULT(576);

        /*
         * returned when GetOverlayPosition is called on a hidden overlay
         */
        const DWORD  DDERR_OVERLAYNOTVISIBLE = MAKE_DDHRESULT(577);

        /*
         * returned when GetOverlayPosition is called on a overlay that UpdateOverlay
         * has never been called on to establish a destionation.
         */
        const DWORD  DDERR_NOOVERLAYDEST = MAKE_DDHRESULT(578);

        /*
         * returned when the position of the overlay on the destionation is no longer
         * legal for that destionation.
         */
        const DWORD  DDERR_INVALIDPOSITION = MAKE_DDHRESULT(579);

        /*
         * returned when an overlay member is called for a non-overlay surface
         */
        const DWORD  DDERR_NOTAOVERLAYSURFACE = MAKE_DDHRESULT(580);

        /*
         * An attempt was made to set the cooperative level when it was already
         * set to exclusive.
         */
        const DWORD  DDERR_EXCLUSIVEMODEALREADYSET = MAKE_DDHRESULT(581);

        /*
         * An attempt has been made to flip a surface that is not flippable.
         */
        const DWORD  DDERR_NOTFLIPPABLE = MAKE_DDHRESULT(582);

        /*
         * Can't duplicate primary & 3D surfaces, or surfaces that are implicitly
         * created.
         */
        const DWORD  DDERR_CANTDUPLICATE = MAKE_DDHRESULT(583);

        /*
         * Surface was not locked.  An attempt to unlock a surface that was not
         * locked at all, or by this process, has been attempted.
         */
        const DWORD  DDERR_NOTLOCKED = MAKE_DDHRESULT(584);

        /*
         * Windows can not create any more DCs, or a DC was requested for a paltte-indexed
         * surface when the surface had no palette AND the display mode was not palette-indexed
         * (in this case DirectDraw cannot select a proper palette into the DC)
         */
        const DWORD  DDERR_CANTCREATEDC = MAKE_DDHRESULT(585);

        /*
         * No DC was ever created for this surface.
         */
        const DWORD  DDERR_NODC = MAKE_DDHRESULT(586);

        /*
         * This surface can not be restored because it was created in a different
         * mode.
         */
        const DWORD  DDERR_WRONGMODE = MAKE_DDHRESULT(587);

        /*
         * This surface can not be restored because it is an implicitly created
         * surface.
         */
        const DWORD  DDERR_IMPLICITLYCREATED = MAKE_DDHRESULT(588);

        /*
         * The surface being used is not a palette-based surface
         */
        const DWORD  DDERR_NOTPALETTIZED = MAKE_DDHRESULT(589);


        /*
         * The display is currently in an unsupported mode
         */
        const DWORD  DDERR_UNSUPPORTEDMODE = MAKE_DDHRESULT(590);

        /*
         * Operation could not be carried out because there is no mip-map
         * texture mapping hardware present or available.
         */
        const DWORD  DDERR_NOMIPMAPHW = MAKE_DDHRESULT(591);

        /*
         * The requested action could not be performed because the surface was of
         * the wrong type.
         */
        const DWORD  DDERR_INVALIDSURFACETYPE = MAKE_DDHRESULT(592);



        /*
         * Device does not support optimized surfaces, therefore no video memory optimized surfaces
         */
        const DWORD  DDERR_NOOPTIMIZEHW = MAKE_DDHRESULT(600);

        /*
         * Surface is an optimized surface, but has not yet been allocated any memory
         */
        const DWORD  DDERR_NOTLOADED = MAKE_DDHRESULT(601);

        /*
         * Attempt was made to create or set a device window without first setting
         * the focus window
         */
        const DWORD  DDERR_NOFOCUSWINDOW = MAKE_DDHRESULT(602);

        /*
         * Attempt was made to set a palette on a mipmap sublevel
         */
        const DWORD  DDERR_NOTONMIPMAPSUBLEVEL = MAKE_DDHRESULT(603);

        /*
         * A DC has already been returned for this surface. Only one DC can be
         * retrieved per surface.
         */
        const DWORD  DDERR_DCALREADYCREATED = MAKE_DDHRESULT(620);

        /*
         * An attempt was made to allocate non-local video memory from a device
         * that does not support non-local video memory.
         */
        const DWORD  DDERR_NONONLOCALVIDMEM = MAKE_DDHRESULT(630);

        /*
         * The attempt to page lock a surface failed.
         */
        const DWORD  DDERR_CANTPAGELOCK = MAKE_DDHRESULT(640);


        /*
         * The attempt to page unlock a surface failed.
         */
        const DWORD  DDERR_CANTPAGEUNLOCK = MAKE_DDHRESULT(660);

        /*
         * An attempt was made to page unlock a surface with no outstanding page locks.
         */
        const DWORD  DDERR_NOTPAGELOCKED = MAKE_DDHRESULT(680);

        /*
         * There is more data available than the specified buffer size could hold
         */
        const DWORD  DDERR_MOREDATA = MAKE_DDHRESULT(690);

        /*
         * The data has expired and is therefore no longer valid.
         */
        const DWORD  DDERR_EXPIRED = MAKE_DDHRESULT(691);

        /*
         * The mode test has finished executing.
         */
        const DWORD  DDERR_TESTFINISHED = MAKE_DDHRESULT(692);

        /*
         * The mode test has switched to a new mode.
         */
        const DWORD  DDERR_NEWMODE = MAKE_DDHRESULT(693);

        /*
         * D3D has not yet been initialized.
         */
        const DWORD  DDERR_D3DNOTINITIALIZED = MAKE_DDHRESULT(694);

        /*
         * The video port is not active
         */
        const DWORD  DDERR_VIDEONOTACTIVE = MAKE_DDHRESULT(695);

        /*
         * The monitor does not have EDID data.
         */
        const DWORD  DDERR_NOMONITORINFORMATION = MAKE_DDHRESULT(696);

        /*
         * The driver does not enumerate display mode refresh rates.
         */
        const DWORD  DDERR_NODRIVERSUPPORT = MAKE_DDHRESULT(697);

        /*
         * Surfaces created by one direct draw device cannot be used directly by
         * another direct draw device.
         */
        const DWORD  DDERR_DEVICEDOESNTOWNSURFACE = MAKE_DDHRESULT(699);



        /*
         * An attempt was made to invoke an interface member of a DirectDraw object
         * created by CoCreateInstance() before it was initialized.
         */
        const DWORD  DDERR_NOTINITIALIZED = CO_E_NOTINITIALIZED;
    }
}

#endif //__DDRAW_INCLUDED__
