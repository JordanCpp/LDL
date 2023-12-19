#ifndef LDL_Glide_Glide_hpp
#define LDL_Glide_Glide_hpp

#include <LDL/Config.hpp>
#include <LDL/Core/Types.hpp>
#include <LDL/APIs/Glide/3dfx.hpp>

namespace LDL
{
    namespace Glide
    {
        typedef FxU32 GrColor_t;
        typedef FxU8  GrAlpha_t;
        typedef FxU32 GrMipMapId_t;
        typedef FxU8  GrFog_t;
        typedef FxU32 GrContext_t;
        typedef int (*GrProc)();

        typedef FxI32 GrScreenResolution_t;
        const FxI32 GR_RESOLUTION_320x200 = 0x0;
        const FxI32 GR_RESOLUTION_320x240 = 0x1;
        const FxI32 GR_RESOLUTION_400x256 = 0x2;
        const FxI32 GR_RESOLUTION_512x384 = 0x3;
        const FxI32 GR_RESOLUTION_640x200 = 0x4;
        const FxI32 GR_RESOLUTION_640x350 = 0x5;
        const FxI32 GR_RESOLUTION_640x400 = 0x6;
        const FxI32 GR_RESOLUTION_640x480 = 0x7;
        const FxI32 GR_RESOLUTION_800x600 = 0x8;
        const FxI32 GR_RESOLUTION_960x720 = 0x9;
        const FxI32 GR_RESOLUTION_856x480 = 0xa;
        const FxI32 GR_RESOLUTION_512x256 = 0xb;
        const FxI32 GR_RESOLUTION_NONE    = 0xff;

        typedef FxI32 GrScreenRefresh_t;
        const FxI32 GR_REFRESH_60Hz  = 0x0;
        const FxI32 GR_REFRESH_70Hz  = 0x1;
        const FxI32 GR_REFRESH_72Hz  = 0x2;
        const FxI32 GR_REFRESH_75Hz  = 0x3;
        const FxI32 GR_REFRESH_80Hz  = 0x4;
        const FxI32 GR_REFRESH_90Hz  = 0x5;
        const FxI32 GR_REFRESH_100Hz = 0x6;
        const FxI32 GR_REFRESH_85Hz  = 0x7;
        const FxI32 GR_REFRESH_120Hz = 0x8;
        const FxI32 GR_REFRESH_NONE  = 0xff;

        typedef FxI32 GrColorFormat_t;
        const FxI32 GR_COLORFORMAT_ARGB = 0x0;
        const FxI32 GR_COLORFORMAT_ABGR = 0x1;
        const FxI32 GR_COLORFORMAT_RGBA = 0x2;
        const FxI32 GR_COLORFORMAT_BGRA = 0x3;

        typedef FxI32 GrOriginLocation_t;
        const FxI32 GR_ORIGIN_UPPER_LEFT = 0x0;
        const FxI32 GR_ORIGIN_LOWER_LEFT = 0x1;
        const FxI32 GR_ORIGIN_ANY        = 0xFF;

        typedef FxI32 GrCombineFunction_t;
        const FxI32 GR_COMBINE_FUNCTION_ZERO                                    = 0x0;
        const FxI32 GR_COMBINE_FUNCTION_NONE                                    = GR_COMBINE_FUNCTION_ZERO;
        const FxI32 GR_COMBINE_FUNCTION_LOCAL                                   = 0x1;
        const FxI32 GR_COMBINE_FUNCTION_LOCAL_ALPHA                             = 0x2;
        const FxI32 GR_COMBINE_FUNCTION_SCALE_OTHER                             = 0x3;
        const FxI32 GR_COMBINE_FUNCTION_BLEND_OTHER                             = GR_COMBINE_FUNCTION_SCALE_OTHER;
        const FxI32 GR_COMBINE_FUNCTION_SCALE_OTHER_ADD_LOCAL                   = 0x4;
        const FxI32 GR_COMBINE_FUNCTION_SCALE_OTHER_ADD_LOCAL_ALPHA             = 0x5;
        const FxI32 GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL                 = 0x6;
        const FxI32 GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL_ADD_LOCAL       = 0x7;
        const FxI32 GR_COMBINE_FUNCTION_BLEND                                   = GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL_ADD_LOCAL;
        const FxI32 GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL_ADD_LOCAL_ALPHA = 0x8;
        const FxI32 GR_COMBINE_FUNCTION_SCALE_MINUS_LOCAL_ADD_LOCAL             = 0x9;
        const FxI32 GR_COMBINE_FUNCTION_BLEND_LOCAL                             = GR_COMBINE_FUNCTION_SCALE_MINUS_LOCAL_ADD_LOCAL;
        const FxI32 GR_COMBINE_FUNCTION_SCALE_MINUS_LOCAL_ADD_LOCAL_ALPHA       = 0x10;

        typedef FxI32 GrCombineFactor_t;
        const FxI32 GR_COMBINE_FACTOR_ZERO                    = 0x0;
        const FxI32 GR_COMBINE_FACTOR_NONE                    = GR_COMBINE_FACTOR_ZERO;
        const FxI32 GR_COMBINE_FACTOR_LOCAL                   = 0x1;
        const FxI32 GR_COMBINE_FACTOR_OTHER_ALPHA             = 0x2;
        const FxI32 GR_COMBINE_FACTOR_LOCAL_ALPHA             = 0x3;
        const FxI32 GR_COMBINE_FACTOR_TEXTURE_ALPHA           = 0x4;
        const FxI32 GR_COMBINE_FACTOR_TEXTURE_RGB             = 0x5;
        const FxI32 GR_COMBINE_FACTOR_DETAIL_FACTOR           = GR_COMBINE_FACTOR_TEXTURE_ALPHA;
        const FxI32 GR_COMBINE_FACTOR_LOD_FRACTION            = 0x5;
        const FxI32 GR_COMBINE_FACTOR_ONE                     = 0x8;
        const FxI32 GR_COMBINE_FACTOR_ONE_MINUS_LOCAL         = 0x9;
        const FxI32 GR_COMBINE_FACTOR_ONE_MINUS_OTHER_ALPHA   = 0xa;
        const FxI32 GR_COMBINE_FACTOR_ONE_MINUS_LOCAL_ALPHA   = 0xb;
        const FxI32 GR_COMBINE_FACTOR_ONE_MINUS_TEXTURE_ALPHA = 0xc;
        const FxI32 GR_COMBINE_FACTOR_ONE_MINUS_DETAIL_FACTOR = GR_COMBINE_FACTOR_ONE_MINUS_TEXTURE_ALPHA;
        const FxI32 GR_COMBINE_FACTOR_ONE_MINUS_LOD_FRACTION  = 0xd;

        typedef FxI32 GrCombineLocal_t;
        const FxI32 GR_COMBINE_LOCAL_ITERATED = 0x0;
        const FxI32 GR_COMBINE_LOCAL_CONSTANT = 0x1;
        const FxI32 GR_COMBINE_LOCAL_NONE     = GR_COMBINE_LOCAL_CONSTANT;
        const FxI32 GR_COMBINE_LOCAL_DEPTH    = 0x2;

        typedef FxI32 GrCombineOther_t;
        const FxI32 GR_COMBINE_OTHER_ITERATED = 0x0;
        const FxI32 GR_COMBINE_OTHER_TEXTURE  = 0x1;
        const FxI32 GR_COMBINE_OTHER_CONSTANT = 0x2;
        const FxI32 GR_COMBINE_OTHER_NONE     = GR_COMBINE_OTHER_CONSTANT;

        /* Parameters for strips */
        const FxU32 GR_PARAM_XY      = 0x01;
        const FxU32 GR_PARAM_Z       = 0x02;
        const FxU32 GR_PARAM_W       = 0x03;
        const FxU32 GR_PARAM_Q       = 0x04;
        const FxU32 GR_PARAM_FOG_EXT = 0x05;
        const FxU32 GR_PARAM_A       = 0x10;
        const FxU32 GR_PARAM_RGB     = 0x20;
        const FxU32 GR_PARAM_PARGB   = 0x30;
        const FxU32 GR_PARAM_ST0     = 0x40;
        const FxU32 GR_PARAM_ST1     = GR_PARAM_ST0 + 1;
        const FxU32 GR_PARAM_ST2     = GR_PARAM_ST0 + 2;
        const FxU32 GR_PARAM_Q0      = 0x50;
        const FxU32 GR_PARAM_Q1      = GR_PARAM_Q0 + 1;
        const FxU32 GR_PARAM_Q2      = GR_PARAM_Q0 + 2;
        const FxU32 GR_PARAM_DISABLE = 0x00;
        const FxU32 GR_PARAM_ENABLE  = 0x01;

        typedef FxI32 GrBuffer_t;
        const FxI32 GR_BUFFER_FRONTBUFFER  = 0x0;
        const FxI32 GR_BUFFER_BACKBUFFER   = 0x1;
        const FxI32 GR_BUFFER_AUXBUFFER    = 0x2;
        const FxI32 GR_BUFFER_DEPTHBUFFER  = 0x3;
        const FxI32 GR_BUFFER_ALPHABUFFER  = 0x4;
        const FxI32 GR_BUFFER_TRIPLEBUFFER = 0x5;

        typedef void (LDL_API_CALL PFN_grGlideInit)();
        LDL_API_ENTRY PFN_grGlideInit grGlideInit;

        typedef void (LDL_API_CALL PFN_grGlideShutdown)();
        LDL_API_ENTRY PFN_grGlideShutdown grGlideShutdown;

        typedef void (LDL_API_CALL PFN_grSstSelect)(int which_sst);
        LDL_API_ENTRY PFN_grSstSelect grSstSelect;

        typedef FxBool(LDL_API_CALL PFN_grSstWinOpen)(FxU32 hWnd, GrScreenResolution_t screen_resolution, GrScreenRefresh_t refresh_rate, GrColorFormat_t color_format, GrOriginLocation_t origin_location, int nColBuffers, int nAuxBuffers);
        LDL_API_ENTRY PFN_grSstWinOpen grSstWinOpen;

        typedef void (LDL_API_CALL PFN_grVertexLayout)(FxU32 param, FxI32 offset, FxU32 mode);
        LDL_API_ENTRY PFN_grVertexLayout grVertexLayout;

        typedef void (LDL_API_CALL PFN_grColorCombine)(GrCombineFunction_t function, GrCombineFactor_t factor, GrCombineLocal_t local, GrCombineOther_t other, FxBool invert);
        LDL_API_ENTRY PFN_grColorCombine grColorCombine;

        typedef void (LDL_API_CALL PFN_grConstantColorValue)(GrColor_t value);
        LDL_API_ENTRY PFN_grConstantColorValue grConstantColorValue;

        typedef void (LDL_API_CALL PFN_grDrawLine)(const void* v1, const void* v2);
        LDL_API_ENTRY PFN_grDrawLine grDrawLine;

/*
** buffer management
*/
        typedef void (LDL_API_CALL PFN_grBufferClear)(GrColor_t color, GrAlpha_t alpha, FxU32 depth);
        LDL_API_ENTRY PFN_grBufferClear grBufferClear;

        typedef void (LDL_API_CALL PFN_grBufferSwap)(FxU32 swap_interval);
        LDL_API_ENTRY PFN_grBufferSwap grBufferSwap;

        typedef void (LDL_API_CALL PFN_grRenderBuffer)(GrBuffer_t buffer);
        LDL_API_ENTRY PFN_grRenderBuffer grRenderBuffer;
    }
}

#endif
