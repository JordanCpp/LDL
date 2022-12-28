#ifndef LDL_OpenGL_OpenGL1_0_hpp
#define LDL_OpenGL_OpenGL1_0_hpp

#include <LDL/OpenGL/OpenGLTypes.hpp>

/* Version */
#define GL_VERSION_1_1                    1

/* AccumOp */
#define GL_ACCUM                          0x0100
#define GL_LOAD                           0x0101
#define GL_RETURN                         0x0102
#define GL_MULT                           0x0103
#define GL_ADD                            0x0104

/* AlphaFunction */
#define GL_NEVER                          0x0200
#define GL_LESS                           0x0201
#define GL_EQUAL                          0x0202
#define GL_LEQUAL                         0x0203
#define GL_GREATER                        0x0204
#define GL_NOTEQUAL                       0x0205
#define GL_GEQUAL                         0x0206
#define GL_ALWAYS                         0x0207

/* AttribMask */
#define GL_CURRENT_BIT                    0x00000001
#define GL_POINT_BIT                      0x00000002
#define GL_LINE_BIT                       0x00000004
#define GL_POLYGON_BIT                    0x00000008
#define GL_POLYGON_STIPPLE_BIT            0x00000010
#define GL_PIXEL_MODE_BIT                 0x00000020
#define GL_LIGHTING_BIT                   0x00000040
#define GL_FOG_BIT                        0x00000080
#define GL_DEPTH_BUFFER_BIT               0x00000100
#define GL_ACCUM_BUFFER_BIT               0x00000200
#define GL_STENCIL_BUFFER_BIT             0x00000400
#define GL_VIEWPORT_BIT                   0x00000800
#define GL_TRANSFORM_BIT                  0x00001000
#define GL_ENABLE_BIT                     0x00002000
#define GL_COLOR_BUFFER_BIT               0x00004000
#define GL_HINT_BIT                       0x00008000
#define GL_EVAL_BIT                       0x00010000
#define GL_LIST_BIT                       0x00020000
#define GL_TEXTURE_BIT                    0x00040000
#define GL_SCISSOR_BIT                    0x00080000
#define GL_ALL_ATTRIB_BITS                0x000fffff

/* BeginMode */
#define GL_POINTS                         0x0000
#define GL_LINES                          0x0001
#define GL_LINE_LOOP                      0x0002
#define GL_LINE_STRIP                     0x0003
#define GL_TRIANGLES                      0x0004
#define GL_TRIANGLE_STRIP                 0x0005
#define GL_TRIANGLE_FAN                   0x0006
#define GL_QUADS                          0x0007
#define GL_QUAD_STRIP                     0x0008
#define GL_POLYGON                        0x0009

/* BlendingFactorDest */
#define GL_ZERO                           0
#define GL_ONE                            1
#define GL_SRC_COLOR                      0x0300
#define GL_ONE_MINUS_SRC_COLOR            0x0301
#define GL_SRC_ALPHA                      0x0302
#define GL_ONE_MINUS_SRC_ALPHA            0x0303
#define GL_DST_ALPHA                      0x0304
#define GL_ONE_MINUS_DST_ALPHA            0x0305

/* BlendingFactorSrc */
#define GL_DST_COLOR                      0x0306
#define GL_ONE_MINUS_DST_COLOR            0x0307
#define GL_SRC_ALPHA_SATURATE             0x0308

/* Boolean */
#define GL_TRUE                           1
#define GL_FALSE                          0

/* ClipPlaneName */
#define GL_CLIP_PLANE0                    0x3000
#define GL_CLIP_PLANE1                    0x3001
#define GL_CLIP_PLANE2                    0x3002
#define GL_CLIP_PLANE3                    0x3003
#define GL_CLIP_PLANE4                    0x3004
#define GL_CLIP_PLANE5                    0x3005

/* DataType */
#define GL_BYTE                           0x1400
#define GL_UNSIGNED_BYTE                  0x1401
#define GL_SHORT                          0x1402
#define GL_UNSIGNED_SHORT                 0x1403
#define GL_INT                            0x1404
#define GL_UNSIGNED_INT                   0x1405
#define GL_FLOAT                          0x1406
#define GL_2_BYTES                        0x1407
#define GL_3_BYTES                        0x1408
#define GL_4_BYTES                        0x1409
#define GL_DOUBLE                         0x140A

/* DrawBufferMode */
#define GL_NONE                           0
#define GL_FRONT_LEFT                     0x0400
#define GL_FRONT_RIGHT                    0x0401
#define GL_BACK_LEFT                      0x0402
#define GL_BACK_RIGHT                     0x0403
#define GL_FRONT                          0x0404
#define GL_BACK                           0x0405
#define GL_LEFT                           0x0406
#define GL_RIGHT                          0x0407
#define GL_FRONT_AND_BACK                 0x0408
#define GL_AUX0                           0x0409
#define GL_AUX1                           0x040A
#define GL_AUX2                           0x040B
#define GL_AUX3                           0x040C

/* ErrorCode */
#define GL_NO_ERROR                       0
#define GL_INVALID_ENUM                   0x0500
#define GL_INVALID_VALUE                  0x0501
#define GL_INVALID_OPERATION              0x0502
#define GL_STACK_OVERFLOW                 0x0503
#define GL_STACK_UNDERFLOW                0x0504
#define GL_OUT_OF_MEMORY                  0x0505

/* FeedBackMode */
#define GL_2D                             0x0600
#define GL_3D                             0x0601
#define GL_3D_COLOR                       0x0602
#define GL_3D_COLOR_TEXTURE               0x0603
#define GL_4D_COLOR_TEXTURE               0x0604

/* FeedBackToken */
#define GL_PASS_THROUGH_TOKEN             0x0700
#define GL_POINT_TOKEN                    0x0701
#define GL_LINE_TOKEN                     0x0702
#define GL_POLYGON_TOKEN                  0x0703
#define GL_BITMAP_TOKEN                   0x0704
#define GL_DRAW_PIXEL_TOKEN               0x0705
#define GL_COPY_PIXEL_TOKEN               0x0706
#define GL_LINE_RESET_TOKEN               0x0707

/* FogMode */
#define GL_EXP                            0x0800
#define GL_EXP2                           0x0801

/* FrontFaceDirection */
#define GL_CW                             0x0900
#define GL_CCW                            0x0901

/* GetMapTarget */
#define GL_COEFF                          0x0A00
#define GL_ORDER                          0x0A01
#define GL_DOMAIN                         0x0A02

/* GetTarget */
#define GL_CURRENT_COLOR                  0x0B00
#define GL_CURRENT_INDEX                  0x0B01
#define GL_CURRENT_NORMAL                 0x0B02
#define GL_CURRENT_TEXTURE_COORDS         0x0B03
#define GL_CURRENT_RASTER_COLOR           0x0B04
#define GL_CURRENT_RASTER_INDEX           0x0B05
#define GL_CURRENT_RASTER_TEXTURE_COORDS  0x0B06
#define GL_CURRENT_RASTER_POSITION        0x0B07
#define GL_CURRENT_RASTER_POSITION_VALID  0x0B08
#define GL_CURRENT_RASTER_DISTANCE        0x0B09
#define GL_POINT_SMOOTH                   0x0B10
#define GL_POINT_SIZE                     0x0B11
#define GL_POINT_SIZE_RANGE               0x0B12
#define GL_POINT_SIZE_GRANULARITY         0x0B13
#define GL_LINE_SMOOTH                    0x0B20
#define GL_LINE_WIDTH                     0x0B21
#define GL_LINE_WIDTH_RANGE               0x0B22
#define GL_LINE_WIDTH_GRANULARITY         0x0B23
#define GL_LINE_STIPPLE                   0x0B24
#define GL_LINE_STIPPLE_PATTERN           0x0B25
#define GL_LINE_STIPPLE_REPEAT            0x0B26
#define GL_LIST_MODE                      0x0B30
#define GL_MAX_LIST_NESTING               0x0B31
#define GL_LIST_BASE                      0x0B32
#define GL_LIST_INDEX                     0x0B33
#define GL_POLYGON_MODE                   0x0B40
#define GL_POLYGON_SMOOTH                 0x0B41
#define GL_POLYGON_STIPPLE                0x0B42
#define GL_EDGE_FLAG                      0x0B43
#define GL_CULL_FACE                      0x0B44
#define GL_CULL_FACE_MODE                 0x0B45
#define GL_FRONT_FACE                     0x0B46
#define GL_LIGHTING                       0x0B50
#define GL_LIGHT_MODEL_LOCAL_VIEWER       0x0B51
#define GL_LIGHT_MODEL_TWO_SIDE           0x0B52
#define GL_LIGHT_MODEL_AMBIENT            0x0B53
#define GL_SHADE_MODEL                    0x0B54
#define GL_COLOR_MATERIAL_FACE            0x0B55
#define GL_COLOR_MATERIAL_PARAMETER       0x0B56
#define GL_COLOR_MATERIAL                 0x0B57
#define GL_FOG                            0x0B60
#define GL_FOG_INDEX                      0x0B61
#define GL_FOG_DENSITY                    0x0B62
#define GL_FOG_START                      0x0B63
#define GL_FOG_END                        0x0B64
#define GL_FOG_MODE                       0x0B65
#define GL_FOG_COLOR                      0x0B66
#define GL_DEPTH_RANGE                    0x0B70
#define GL_DEPTH_TEST                     0x0B71
#define GL_DEPTH_WRITEMASK                0x0B72
#define GL_DEPTH_CLEAR_VALUE              0x0B73
#define GL_DEPTH_FUNC                     0x0B74
#define GL_ACCUM_CLEAR_VALUE              0x0B80
#define GL_STENCIL_TEST                   0x0B90
#define GL_STENCIL_CLEAR_VALUE            0x0B91
#define GL_STENCIL_FUNC                   0x0B92
#define GL_STENCIL_VALUE_MASK             0x0B93
#define GL_STENCIL_FAIL                   0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL        0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS        0x0B96
#define GL_STENCIL_REF                    0x0B97
#define GL_STENCIL_WRITEMASK              0x0B98
#define GL_MATRIX_MODE                    0x0BA0
#define GL_NORMALIZE                      0x0BA1
#define GL_VIEWPORT                       0x0BA2
#define GL_MODELVIEW_STACK_DEPTH          0x0BA3
#define GL_PROJECTION_STACK_DEPTH         0x0BA4
#define GL_TEXTURE_STACK_DEPTH            0x0BA5
#define GL_MODELVIEW_MATRIX               0x0BA6
#define GL_PROJECTION_MATRIX              0x0BA7
#define GL_TEXTURE_MATRIX                 0x0BA8
#define GL_ATTRIB_STACK_DEPTH             0x0BB0
#define GL_CLIENT_ATTRIB_STACK_DEPTH      0x0BB1
#define GL_ALPHA_TEST                     0x0BC0
#define GL_ALPHA_TEST_FUNC                0x0BC1
#define GL_ALPHA_TEST_REF                 0x0BC2
#define GL_DITHER                         0x0BD0
#define GL_BLEND_DST                      0x0BE0
#define GL_BLEND_SRC                      0x0BE1
#define GL_BLEND                          0x0BE2
#define GL_LOGIC_OP_MODE                  0x0BF0
#define GL_INDEX_LOGIC_OP                 0x0BF1
#define GL_COLOR_LOGIC_OP                 0x0BF2
#define GL_AUX_BUFFERS                    0x0C00
#define GL_DRAW_BUFFER                    0x0C01
#define GL_READ_BUFFER                    0x0C02
#define GL_SCISSOR_BOX                    0x0C10
#define GL_SCISSOR_TEST                   0x0C11
#define GL_INDEX_CLEAR_VALUE              0x0C20
#define GL_INDEX_WRITEMASK                0x0C21
#define GL_COLOR_CLEAR_VALUE              0x0C22
#define GL_COLOR_WRITEMASK                0x0C23
#define GL_INDEX_MODE                     0x0C30
#define GL_RGBA_MODE                      0x0C31
#define GL_DOUBLEBUFFER                   0x0C32
#define GL_STEREO                         0x0C33
#define GL_RENDER_MODE                    0x0C40
#define GL_PERSPECTIVE_CORRECTION_HINT    0x0C50
#define GL_POINT_SMOOTH_HINT              0x0C51
#define GL_LINE_SMOOTH_HINT               0x0C52
#define GL_POLYGON_SMOOTH_HINT            0x0C53
#define GL_FOG_HINT                       0x0C54
#define GL_TEXTURE_GEN_S                  0x0C60
#define GL_TEXTURE_GEN_T                  0x0C61
#define GL_TEXTURE_GEN_R                  0x0C62
#define GL_TEXTURE_GEN_Q                  0x0C63
#define GL_PIXEL_MAP_I_TO_I               0x0C70
#define GL_PIXEL_MAP_S_TO_S               0x0C71
#define GL_PIXEL_MAP_I_TO_R               0x0C72
#define GL_PIXEL_MAP_I_TO_G               0x0C73
#define GL_PIXEL_MAP_I_TO_B               0x0C74
#define GL_PIXEL_MAP_I_TO_A               0x0C75
#define GL_PIXEL_MAP_R_TO_R               0x0C76
#define GL_PIXEL_MAP_G_TO_G               0x0C77
#define GL_PIXEL_MAP_B_TO_B               0x0C78
#define GL_PIXEL_MAP_A_TO_A               0x0C79
#define GL_PIXEL_MAP_I_TO_I_SIZE          0x0CB0
#define GL_PIXEL_MAP_S_TO_S_SIZE          0x0CB1
#define GL_PIXEL_MAP_I_TO_R_SIZE          0x0CB2
#define GL_PIXEL_MAP_I_TO_G_SIZE          0x0CB3
#define GL_PIXEL_MAP_I_TO_B_SIZE          0x0CB4
#define GL_PIXEL_MAP_I_TO_A_SIZE          0x0CB5
#define GL_PIXEL_MAP_R_TO_R_SIZE          0x0CB6
#define GL_PIXEL_MAP_G_TO_G_SIZE          0x0CB7
#define GL_PIXEL_MAP_B_TO_B_SIZE          0x0CB8
#define GL_PIXEL_MAP_A_TO_A_SIZE          0x0CB9
#define GL_UNPACK_SWAP_BYTES              0x0CF0
#define GL_UNPACK_LSB_FIRST               0x0CF1
#define GL_UNPACK_ROW_LENGTH              0x0CF2
#define GL_UNPACK_SKIP_ROWS               0x0CF3
#define GL_UNPACK_SKIP_PIXELS             0x0CF4
#define GL_UNPACK_ALIGNMENT               0x0CF5
#define GL_PACK_SWAP_BYTES                0x0D00
#define GL_PACK_LSB_FIRST                 0x0D01
#define GL_PACK_ROW_LENGTH                0x0D02
#define GL_PACK_SKIP_ROWS                 0x0D03
#define GL_PACK_SKIP_PIXELS               0x0D04
#define GL_PACK_ALIGNMENT                 0x0D05
#define GL_MAP_COLOR                      0x0D10
#define GL_MAP_STENCIL                    0x0D11
#define GL_INDEX_SHIFT                    0x0D12
#define GL_INDEX_OFFSET                   0x0D13
#define GL_RED_SCALE                      0x0D14
#define GL_RED_BIAS                       0x0D15
#define GL_ZOOM_X                         0x0D16
#define GL_ZOOM_Y                         0x0D17
#define GL_GREEN_SCALE                    0x0D18
#define GL_GREEN_BIAS                     0x0D19
#define GL_BLUE_SCALE                     0x0D1A
#define GL_BLUE_BIAS                      0x0D1B
#define GL_ALPHA_SCALE                    0x0D1C
#define GL_ALPHA_BIAS                     0x0D1D
#define GL_DEPTH_SCALE                    0x0D1E
#define GL_DEPTH_BIAS                     0x0D1F
#define GL_MAX_EVAL_ORDER                 0x0D30
#define GL_MAX_LIGHTS                     0x0D31
#define GL_MAX_CLIP_PLANES                0x0D32
#define GL_MAX_TEXTURE_SIZE               0x0D33
#define GL_MAX_PIXEL_MAP_TABLE            0x0D34
#define GL_MAX_ATTRIB_STACK_DEPTH         0x0D35
#define GL_MAX_MODELVIEW_STACK_DEPTH      0x0D36
#define GL_MAX_NAME_STACK_DEPTH           0x0D37
#define GL_MAX_PROJECTION_STACK_DEPTH     0x0D38
#define GL_MAX_TEXTURE_STACK_DEPTH        0x0D39
#define GL_MAX_VIEWPORT_DIMS              0x0D3A
#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH  0x0D3B
#define GL_SUBPIXEL_BITS                  0x0D50
#define GL_INDEX_BITS                     0x0D51
#define GL_RED_BITS                       0x0D52
#define GL_GREEN_BITS                     0x0D53
#define GL_BLUE_BITS                      0x0D54
#define GL_ALPHA_BITS                     0x0D55
#define GL_DEPTH_BITS                     0x0D56
#define GL_STENCIL_BITS                   0x0D57
#define GL_ACCUM_RED_BITS                 0x0D58
#define GL_ACCUM_GREEN_BITS               0x0D59
#define GL_ACCUM_BLUE_BITS                0x0D5A
#define GL_ACCUM_ALPHA_BITS               0x0D5B
#define GL_NAME_STACK_DEPTH               0x0D70
#define GL_AUTO_NORMAL                    0x0D80
#define GL_MAP1_COLOR_4                   0x0D90
#define GL_MAP1_INDEX                     0x0D91
#define GL_MAP1_NORMAL                    0x0D92
#define GL_MAP1_TEXTURE_COORD_1           0x0D93
#define GL_MAP1_TEXTURE_COORD_2           0x0D94
#define GL_MAP1_TEXTURE_COORD_3           0x0D95
#define GL_MAP1_TEXTURE_COORD_4           0x0D96
#define GL_MAP1_VERTEX_3                  0x0D97
#define GL_MAP1_VERTEX_4                  0x0D98
#define GL_MAP2_COLOR_4                   0x0DB0
#define GL_MAP2_INDEX                     0x0DB1
#define GL_MAP2_NORMAL                    0x0DB2
#define GL_MAP2_TEXTURE_COORD_1           0x0DB3
#define GL_MAP2_TEXTURE_COORD_2           0x0DB4
#define GL_MAP2_TEXTURE_COORD_3           0x0DB5
#define GL_MAP2_TEXTURE_COORD_4           0x0DB6
#define GL_MAP2_VERTEX_3                  0x0DB7
#define GL_MAP2_VERTEX_4                  0x0DB8
#define GL_MAP1_GRID_DOMAIN               0x0DD0
#define GL_MAP1_GRID_SEGMENTS             0x0DD1
#define GL_MAP2_GRID_DOMAIN               0x0DD2
#define GL_MAP2_GRID_SEGMENTS             0x0DD3
#define GL_TEXTURE_1D                     0x0DE0
#define GL_TEXTURE_2D                     0x0DE1
#define GL_FEEDBACK_BUFFER_POINTER        0x0DF0
#define GL_FEEDBACK_BUFFER_SIZE           0x0DF1
#define GL_FEEDBACK_BUFFER_TYPE           0x0DF2
#define GL_SELECTION_BUFFER_POINTER       0x0DF3
#define GL_SELECTION_BUFFER_SIZE          0x0DF4

/* GetTextureParameter */
#define GL_TEXTURE_WIDTH                  0x1000
#define GL_TEXTURE_HEIGHT                 0x1001
#define GL_TEXTURE_INTERNAL_FORMAT        0x1003
#define GL_TEXTURE_BORDER_COLOR           0x1004
#define GL_TEXTURE_BORDER                 0x1005

/* HintMode */
#define GL_DONT_CARE                      0x1100
#define GL_FASTEST                        0x1101
#define GL_NICEST                         0x1102

/* LightName */
#define GL_LIGHT0                         0x4000
#define GL_LIGHT1                         0x4001
#define GL_LIGHT2                         0x4002
#define GL_LIGHT3                         0x4003
#define GL_LIGHT4                         0x4004
#define GL_LIGHT5                         0x4005
#define GL_LIGHT6                         0x4006
#define GL_LIGHT7                         0x4007

/* LightParameter */
#define GL_AMBIENT                        0x1200
#define GL_DIFFUSE                        0x1201
#define GL_SPECULAR                       0x1202
#define GL_POSITION                       0x1203
#define GL_SPOT_DIRECTION                 0x1204
#define GL_SPOT_EXPONENT                  0x1205
#define GL_SPOT_CUTOFF                    0x1206
#define GL_CONSTANT_ATTENUATION           0x1207
#define GL_LINEAR_ATTENUATION             0x1208
#define GL_QUADRATIC_ATTENUATION          0x1209

/* ListMode */
#define GL_COMPILE                        0x1300
#define GL_COMPILE_AND_EXECUTE            0x1301

/* LogicOp */
#define GL_CLEAR                          0x1500
#define GL_AND                            0x1501
#define GL_AND_REVERSE                    0x1502
#define GL_COPY                           0x1503
#define GL_AND_INVERTED                   0x1504
#define GL_NOOP                           0x1505
#define GL_XOR                            0x1506
#define GL_OR                             0x1507
#define GL_NOR                            0x1508
#define GL_EQUIV                          0x1509
#define GL_INVERT                         0x150A
#define GL_OR_REVERSE                     0x150B
#define GL_COPY_INVERTED                  0x150C
#define GL_OR_INVERTED                    0x150D
#define GL_NAND                           0x150E
#define GL_SET                            0x150F

/* MaterialParameter */
#define GL_EMISSION                       0x1600
#define GL_SHININESS                      0x1601
#define GL_AMBIENT_AND_DIFFUSE            0x1602
#define GL_COLOR_INDEXES                  0x1603

/* MatrixMode */
#define GL_MODELVIEW                      0x1700
#define GL_PROJECTION                     0x1701
#define GL_TEXTURE                        0x1702

/* PixelCopyType */
#define GL_COLOR                          0x1800
#define GL_DEPTH                          0x1801
#define GL_STENCIL                        0x1802

/* PixelFormat */
#define GL_COLOR_INDEX                    0x1900
#define GL_STENCIL_INDEX                  0x1901
#define GL_DEPTH_COMPONENT                0x1902
#define GL_RED                            0x1903
#define GL_GREEN                          0x1904
#define GL_BLUE                           0x1905
#define GL_ALPHA                          0x1906
#define GL_RGB                            0x1907
#define GL_RGBA                           0x1908
#define GL_LUMINANCE                      0x1909
#define GL_LUMINANCE_ALPHA                0x190A

/* PixelType */
#define GL_BITMAP                         0x1A00

/* PolygonMode */
#define GL_POINT                          0x1B00
#define GL_LINE                           0x1B01
#define GL_FILL                           0x1B02

/* RenderingMode */
#define GL_RENDER                         0x1C00
#define GL_FEEDBACK                       0x1C01
#define GL_SELECT                         0x1C02

/* ShadingModel */
#define GL_FLAT                           0x1D00
#define GL_SMOOTH                         0x1D01


/* StencilOp */
#define GL_KEEP                           0x1E00
#define GL_REPLACE                        0x1E01
#define GL_INCR                           0x1E02
#define GL_DECR                           0x1E03

/* StringName */
#define GL_VENDOR                         0x1F00
#define GL_RENDERER                       0x1F01
#define GL_VERSION                        0x1F02
#define GL_EXTENSIONS                     0x1F03

/* TextureCoordName */
#define GL_S                              0x2000
#define GL_T                              0x2001
#define GL_R                              0x2002
#define GL_Q                              0x2003

/* TextureEnvMode */
#define GL_MODULATE                       0x2100
#define GL_DECAL                          0x2101

/* TextureEnvParameter */
#define GL_TEXTURE_ENV_MODE               0x2200
#define GL_TEXTURE_ENV_COLOR              0x2201

/* TextureEnvTarget */
#define GL_TEXTURE_ENV                    0x2300

/* TextureGenMode */
#define GL_EYE_LINEAR                     0x2400
#define GL_OBJECT_LINEAR                  0x2401
#define GL_SPHERE_MAP                     0x2402

/* TextureGenParameter */
#define GL_TEXTURE_GEN_MODE               0x2500
#define GL_OBJECT_PLANE                   0x2501
#define GL_EYE_PLANE                      0x2502

/* TextureMagFilter */
#define GL_NEAREST                        0x2600
#define GL_LINEAR                         0x2601

/* TextureMinFilter */
#define GL_NEAREST_MIPMAP_NEAREST         0x2700
#define GL_LINEAR_MIPMAP_NEAREST          0x2701
#define GL_NEAREST_MIPMAP_LINEAR          0x2702
#define GL_LINEAR_MIPMAP_LINEAR           0x2703

/* TextureParameterName */
#define GL_TEXTURE_MAG_FILTER             0x2800
#define GL_TEXTURE_MIN_FILTER             0x2801
#define GL_TEXTURE_WRAP_S                 0x2802
#define GL_TEXTURE_WRAP_T                 0x2803

/* TextureWrapMode */
#define GL_CLAMP                          0x2900
#define GL_REPEAT                         0x2901

/* ClientAttribMask */
#define GL_CLIENT_PIXEL_STORE_BIT         0x00000001
#define GL_CLIENT_VERTEX_ARRAY_BIT        0x00000002
#define GL_CLIENT_ALL_ATTRIB_BITS         0xffffffff

/* polygon_offset */
#define GL_POLYGON_OFFSET_FACTOR          0x8038
#define GL_POLYGON_OFFSET_UNITS           0x2A00
#define GL_POLYGON_OFFSET_POINT           0x2A01
#define GL_POLYGON_OFFSET_LINE            0x2A02
#define GL_POLYGON_OFFSET_FILL            0x8037

/* texture */
#define GL_ALPHA4                         0x803B
#define GL_ALPHA8                         0x803C
#define GL_ALPHA12                        0x803D
#define GL_ALPHA16                        0x803E
#define GL_LUMINANCE4                     0x803F
#define GL_LUMINANCE8                     0x8040
#define GL_LUMINANCE12                    0x8041
#define GL_LUMINANCE16                    0x8042
#define GL_LUMINANCE4_ALPHA4              0x8043
#define GL_LUMINANCE6_ALPHA2              0x8044
#define GL_LUMINANCE8_ALPHA8              0x8045
#define GL_LUMINANCE12_ALPHA4             0x8046
#define GL_LUMINANCE12_ALPHA12            0x8047
#define GL_LUMINANCE16_ALPHA16            0x8048
#define GL_INTENSITY                      0x8049
#define GL_INTENSITY4                     0x804A
#define GL_INTENSITY8                     0x804B
#define GL_INTENSITY12                    0x804C
#define GL_INTENSITY16                    0x804D
#define GL_R3_G3_B2                       0x2A10
#define GL_RGB4                           0x804F
#define GL_RGB5                           0x8050
#define GL_RGB8                           0x8051
#define GL_RGB10                          0x8052
#define GL_RGB12                          0x8053
#define GL_RGB16                          0x8054
#define GL_RGBA2                          0x8055
#define GL_RGBA4                          0x8056
#define GL_RGB5_A1                        0x8057
#define GL_RGBA8                          0x8058
#define GL_RGB10_A2                       0x8059
#define GL_RGBA12                         0x805A
#define GL_RGBA16                         0x805B
#define GL_TEXTURE_RED_SIZE               0x805C
#define GL_TEXTURE_GREEN_SIZE             0x805D
#define GL_TEXTURE_BLUE_SIZE              0x805E
#define GL_TEXTURE_ALPHA_SIZE             0x805F
#define GL_TEXTURE_LUMINANCE_SIZE         0x8060
#define GL_TEXTURE_INTENSITY_SIZE         0x8061
#define GL_PROXY_TEXTURE_1D               0x8063
#define GL_PROXY_TEXTURE_2D               0x8064

/* texture_object */
#define GL_TEXTURE_PRIORITY               0x8066
#define GL_TEXTURE_RESIDENT               0x8067
#define GL_TEXTURE_BINDING_1D             0x8068
#define GL_TEXTURE_BINDING_2D             0x8069

/* vertex_array */
#define GL_VERTEX_ARRAY                   0x8074
#define GL_NORMAL_ARRAY                   0x8075
#define GL_COLOR_ARRAY                    0x8076
#define GL_INDEX_ARRAY                    0x8077
#define GL_TEXTURE_COORD_ARRAY            0x8078
#define GL_EDGE_FLAG_ARRAY                0x8079
#define GL_VERTEX_ARRAY_SIZE              0x807A
#define GL_VERTEX_ARRAY_TYPE              0x807B
#define GL_VERTEX_ARRAY_STRIDE            0x807C
#define GL_NORMAL_ARRAY_TYPE              0x807E
#define GL_NORMAL_ARRAY_STRIDE            0x807F
#define GL_COLOR_ARRAY_SIZE               0x8081
#define GL_COLOR_ARRAY_TYPE               0x8082
#define GL_COLOR_ARRAY_STRIDE             0x8083
#define GL_INDEX_ARRAY_TYPE               0x8085
#define GL_INDEX_ARRAY_STRIDE             0x8086
#define GL_TEXTURE_COORD_ARRAY_SIZE       0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE       0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE     0x808A
#define GL_EDGE_FLAG_ARRAY_STRIDE         0x808C
#define GL_VERTEX_ARRAY_POINTER           0x808E
#define GL_NORMAL_ARRAY_POINTER           0x808F
#define GL_COLOR_ARRAY_POINTER            0x8090
#define GL_INDEX_ARRAY_POINTER            0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER    0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER        0x8093
#define GL_V2F                            0x2A20
#define GL_V3F                            0x2A21
#define GL_C4UB_V2F                       0x2A22
#define GL_C4UB_V3F                       0x2A23
#define GL_C3F_V3F                        0x2A24
#define GL_N3F_V3F                        0x2A25
#define GL_C4F_N3F_V3F                    0x2A26
#define GL_T2F_V3F                        0x2A27
#define GL_T4F_V4F                        0x2A28
#define GL_T2F_C4UB_V3F                   0x2A29
#define GL_T2F_C3F_V3F                    0x2A2A
#define GL_T2F_N3F_V3F                    0x2A2B
#define GL_T2F_C4F_N3F_V3F                0x2A2C
#define GL_T4F_C4F_N3F_V4F                0x2A2D

/* Extensions */
#define GL_EXT_vertex_array               1
#define GL_EXT_bgra                       1
#define GL_EXT_paletted_texture           1
#define GL_WIN_swap_hint                  1
#define GL_WIN_draw_range_elements        1

/* EXT_vertex_array */
#define GL_VERTEX_ARRAY_EXT               0x8074
#define GL_NORMAL_ARRAY_EXT               0x8075
#define GL_COLOR_ARRAY_EXT                0x8076
#define GL_INDEX_ARRAY_EXT                0x8077
#define GL_TEXTURE_COORD_ARRAY_EXT        0x8078
#define GL_EDGE_FLAG_ARRAY_EXT            0x8079
#define GL_VERTEX_ARRAY_SIZE_EXT          0x807A
#define GL_VERTEX_ARRAY_TYPE_EXT          0x807B
#define GL_VERTEX_ARRAY_STRIDE_EXT        0x807C
#define GL_VERTEX_ARRAY_COUNT_EXT         0x807D
#define GL_NORMAL_ARRAY_TYPE_EXT          0x807E
#define GL_NORMAL_ARRAY_STRIDE_EXT        0x807F
#define GL_NORMAL_ARRAY_COUNT_EXT         0x8080
#define GL_COLOR_ARRAY_SIZE_EXT           0x8081
#define GL_COLOR_ARRAY_TYPE_EXT           0x8082
#define GL_COLOR_ARRAY_STRIDE_EXT         0x8083
#define GL_COLOR_ARRAY_COUNT_EXT          0x8084
#define GL_INDEX_ARRAY_TYPE_EXT           0x8085
#define GL_INDEX_ARRAY_STRIDE_EXT         0x8086
#define GL_INDEX_ARRAY_COUNT_EXT          0x8087
#define GL_TEXTURE_COORD_ARRAY_SIZE_EXT   0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE_EXT   0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE_EXT 0x808A
#define GL_TEXTURE_COORD_ARRAY_COUNT_EXT  0x808B
#define GL_EDGE_FLAG_ARRAY_STRIDE_EXT     0x808C
#define GL_EDGE_FLAG_ARRAY_COUNT_EXT      0x808D
#define GL_VERTEX_ARRAY_POINTER_EXT       0x808E
#define GL_NORMAL_ARRAY_POINTER_EXT       0x808F
#define GL_COLOR_ARRAY_POINTER_EXT        0x8090
#define GL_INDEX_ARRAY_POINTER_EXT        0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER_EXT 0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER_EXT    0x8093
#define GL_DOUBLE_EXT                     GL_DOUBLE

/* EXT_bgra */
#define GL_BGR_EXT                        0x80E0
#define GL_BGRA_EXT                       0x80E1

/* These must match the GL_COLOR_TABLE_*_SGI enumerants */
#define GL_COLOR_TABLE_FORMAT_EXT         0x80D8
#define GL_COLOR_TABLE_WIDTH_EXT          0x80D9
#define GL_COLOR_TABLE_RED_SIZE_EXT       0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE_EXT     0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE_EXT      0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE_EXT     0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE_EXT 0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE_EXT 0x80DF

#define GL_COLOR_INDEX1_EXT               0x80E2
#define GL_COLOR_INDEX2_EXT               0x80E3
#define GL_COLOR_INDEX4_EXT               0x80E4
#define GL_COLOR_INDEX8_EXT               0x80E5
#define GL_COLOR_INDEX12_EXT              0x80E6
#define GL_COLOR_INDEX16_EXT              0x80E7

/* WIN_draw_range_elements */
#define GL_MAX_ELEMENTS_VERTICES_WIN      0x80E8
#define GL_MAX_ELEMENTS_INDICES_WIN       0x80E9

/* WIN_phong_shading */
#define GL_PHONG_WIN                      0x80EA 
#define GL_PHONG_HINT_WIN                 0x80EB 

/* WIN_specular_fog */
#define GL_FOG_SPECULAR_TEXTURE_WIN       0x80EC

/* For compatibility with OpenGL v1.0 */
#define GL_LOGIC_OP GL_INDEX_LOGIC_OP
#define GL_TEXTURE_COMPONENTS GL_TEXTURE_INTERNAL_FORMAT

typedef	void	(pglAccum)(GLenum	op, GLfloat	value);
typedef	void	(pglAlphaFunc)(GLenum	func, GLclampf	ref);
typedef	GLboolean(pglAreTexturesResident)	(GLsizei	n, const	GLuint* textures, GLboolean* residences);
typedef	void	(pglArrayElement)(GLint	i);
typedef	void	(pglBegin)(GLenum	mode);
typedef	void	(pglBindTexture)(GLenum	target, GLuint	texture);
typedef	void	(pglBitmap)(GLsizei	width, GLsizei	height, GLfloat	xorig, GLfloat	yorig, GLfloat	xmove, GLfloat	ymove, const	GLubyte* bitmap);
typedef	void	(pglBlendFunc)(GLenum	sfactor, GLenum	dfactor);
typedef	void	(pglCallList)(GLuint	list);
typedef	void	(pglCallLists)(GLsizei	n, GLenum	type, const	GLvoid* lists);
typedef	void	(pglClear)(GLbitfield	mask);
typedef	void	(pglClearAccum)(GLfloat	red, GLfloat	green, GLfloat	blue, GLfloat	alpha);
typedef	void	(pglClearColor)(GLclampf	red, GLclampf	green, GLclampf	blue, GLclampf	alpha);
typedef	void	(pglClearDepth)(GLclampd	depth);
typedef	void	(pglClearIndex)(GLfloat	c);
typedef	void	(pglClearStencil)(GLint	s);
typedef	void	(pglClipPlane)(GLenum	plane, const	GLdouble* equation);
typedef	void	(pglColor3b)(GLbyte	red, GLbyte	green, GLbyte	blue);
typedef	void	(pglColor3bv)(const	GLbyte* v);
typedef	void	(pglColor3d)(GLdouble	red, GLdouble	green, GLdouble	blue);
typedef	void	(pglColor3dv)(const	GLdouble* v);
typedef	void	(pglColor3f)(GLfloat	red, GLfloat	green, GLfloat	blue);
typedef	void	(pglColor3fv)(const	GLfloat* v);
typedef	void	(pglColor3i)(GLint	red, GLint	green, GLint	blue);
typedef	void	(pglColor3iv)(const	GLint* v);
typedef	void	(pglColor3s)(GLshort	red, GLshort	green, GLshort	blue);
typedef	void	(pglColor3sv)(const	GLshort* v);
typedef	void	(pglColor3ub)(GLubyte	red, GLubyte	green, GLubyte	blue);
typedef	void	(pglColor3ubv)(const	GLubyte* v);
typedef	void	(pglColor3ui)(GLuint	red, GLuint	green, GLuint	blue);
typedef	void	(pglColor3uiv)(const	GLuint* v);
typedef	void	(pglColor3us)(GLushort	red, GLushort	green, GLushort	blue);
typedef	void	(pglColor3usv)(const	GLushort* v);
typedef	void	(pglColor4b)(GLbyte	red, GLbyte	green, GLbyte	blue, GLbyte	alpha);
typedef	void	(pglColor4bv)(const	GLbyte* v);
typedef	void	(pglColor4d)(GLdouble	red, GLdouble	green, GLdouble	blue, GLdouble	alpha);
typedef	void	(pglColor4dv)(const	GLdouble* v);
typedef	void	(pglColor4f)(GLfloat	red, GLfloat	green, GLfloat	blue, GLfloat	alpha);
typedef	void	(pglColor4fv)(const	GLfloat* v);
typedef	void	(pglColor4i)(GLint	red, GLint	green, GLint	blue, GLint	alpha);
typedef	void	(pglColor4iv)(const	GLint* v);
typedef	void	(pglColor4s)(GLshort	red, GLshort	green, GLshort	blue, GLshort	alpha);
typedef	void	(pglColor4sv)(const	GLshort* v);
typedef	void	(pglColor4ub)(GLubyte	red, GLubyte	green, GLubyte	blue, GLubyte	alpha);
typedef	void	(pglColor4ubv)(const	GLubyte* v);
typedef	void	(pglColor4ui)(GLuint	red, GLuint	green, GLuint	blue, GLuint	alpha);
typedef	void	(pglColor4uiv)(const	GLuint* v);
typedef	void	(pglColor4us)(GLushort	red, GLushort	green, GLushort	blue, GLushort	alpha);
typedef	void	(pglColor4usv)(const	GLushort* v);
typedef	void	(pglColorMask)(GLboolean	red, GLboolean	green, GLboolean	blue, GLboolean	alpha);
typedef	void	(pglColorMaterial)(GLenum	face, GLenum	mode);
typedef	void	(pglColorPointer)(GLint	size, GLenum	type, GLsizei	stride, const	GLvoid* pointer);
typedef	void	(pglCopyPixels)(GLint	x, GLint	y, GLsizei	width, GLsizei	height, GLenum	type);
typedef	void	(pglCopyTexImage1D)(GLenum	target, GLint	level, GLenum	internalFormat, GLint	x, GLint	y, GLsizei	width, GLint	border);
typedef	void	(pglCopyTexImage2D)(GLenum	target, GLint	level, GLenum	internalFormat, GLint	x, GLint	y, GLsizei	width, GLsizei	height, GLint	border);
typedef	void	(pglCopyTexSubImage1D)(GLenum	target, GLint	level, GLint	xoffset, GLint	x, GLint	y, GLsizei	width);
typedef	void	(pglCopyTexSubImage2D)(GLenum	target, GLint	level, GLint	xoffset, GLint	yoffset, GLint	x, GLint	y, GLsizei	width, GLsizei	height);
typedef	void	(pglCullFace)(GLenum	mode);
typedef	void	(pglDeleteLists)(GLuint	list, GLsizei	range);
typedef	void	(pglDeleteTextures)(GLsizei	n, const	GLuint* textures);
typedef	void	(pglDepthFunc)(GLenum	func);
typedef	void	(pglDepthMask)(GLboolean	flag);
typedef	void	(pglDepthRange)(GLclampd	zNear, GLclampd	zFar);
typedef	void	(pglDisable)(GLenum	cap);
typedef	void	(pglDisableClientState)(GLenum	array);
typedef	void	(pglDrawArrays)(GLenum	mode, GLint	first, GLsizei	count);
typedef	void	(pglDrawBuffer)(GLenum	mode);
typedef	void	(pglDrawElements)(GLenum	mode, GLsizei	count, GLenum	type, const	GLvoid* indices);
typedef	void	(pglDrawPixels)(GLsizei	width, GLsizei	height, GLenum	format, GLenum	type, const	GLvoid* pixels);
typedef	void	(pglEdgeFlag)(GLboolean	flag);
typedef	void	(pglEdgeFlagPointer)(GLsizei	stride, const	GLvoid* pointer);
typedef	void	(pglEdgeFlagv)(const	GLboolean* flag);
typedef	void	(pglEnable)(GLenum	cap);
typedef	void	(pglEnableClientState)(GLenum	array);
typedef	void	(pglEnd)(void);
typedef	void	(pglEndList)(void);
typedef	void	(pglEvalCoord1d)(GLdouble	u);
typedef	void	(pglEvalCoord1dv)(const	GLdouble* u);
typedef	void	(pglEvalCoord1f)(GLfloat	u);
typedef	void	(pglEvalCoord1fv)(const	GLfloat* u);
typedef	void	(pglEvalCoord2d)(GLdouble	u, GLdouble	v);
typedef	void	(pglEvalCoord2dv)(const	GLdouble* u);
typedef	void	(pglEvalCoord2f)(GLfloat	u, GLfloat	v);
typedef	void	(pglEvalCoord2fv)(const	GLfloat* u);
typedef	void	(pglEvalMesh1)(GLenum	mode, GLint	i1, GLint	i2);
typedef	void	(pglEvalMesh2)(GLenum	mode, GLint	i1, GLint	i2, GLint	j1, GLint	j2);
typedef	void	(pglEvalPoint1)(GLint	i);
typedef	void	(pglEvalPoint2)(GLint	i, GLint	j);
typedef	void	(pglFeedbackBuffer)(GLsizei	size, GLenum	type, GLfloat* buffer);
typedef	void	(pglFinish)(void);
typedef	void	(pglFlush)(void);
typedef	void	(pglFogf)(GLenum	pname, GLfloat	param);
typedef	void	(pglFogfv)(GLenum	pname, const	GLfloat* params);
typedef	void	(pglFogi)(GLenum	pname, GLint	param);
typedef	void	(pglFogiv)(GLenum	pname, const	GLint* params);
typedef	void	(pglFrontFace)(GLenum	mode);
typedef	void	(pglFrustum)(GLdouble	left, GLdouble	right, GLdouble	bottom, GLdouble	top, GLdouble	zNear, GLdouble	zFar);
typedef	GLuint(pglGenLists)	(GLsizei	range);
typedef	void	(pglGenTextures)(GLsizei	n, GLuint* textures);
typedef	void	(pglGetBooleanv)(GLenum	pname, GLboolean* params);
typedef	void	(pglGetClipPlane)(GLenum	plane, GLdouble* equation);
typedef	void	(pglGetDoublev)(GLenum	pname, GLdouble* params);
typedef	GLenum(pglGetError)	(void);
typedef	void	(pglGetFloatv)(GLenum	pname, GLfloat* params);
typedef	void	(pglGetIntegerv)(GLenum	pname, GLint* params);
typedef	void	(pglGetLightfv)(GLenum	light, GLenum	pname, GLfloat* params);
typedef	void	(pglGetLightiv)(GLenum	light, GLenum	pname, GLint* params);
typedef	void	(pglGetMapdv)(GLenum	target, GLenum	query, GLdouble* v);
typedef	void	(pglGetMapfv)(GLenum	target, GLenum	query, GLfloat* v);
typedef	void	(pglGetMapiv)(GLenum	target, GLenum	query, GLint* v);
typedef	void	(pglGetMaterialfv)(GLenum	face, GLenum	pname, GLfloat* params);
typedef	void	(pglGetMaterialiv)(GLenum	face, GLenum	pname, GLint* params);
typedef	void	(pglGetPixelMapfv)(GLenum	map, GLfloat* values);
typedef	void	(pglGetPixelMapuiv)(GLenum	map, GLuint* values);
typedef	void	(pglGetPixelMapusv)(GLenum	map, GLushort* values);
typedef	void	(pglGetPointerv)(GLenum	pname, GLvoid** params);
typedef	void	(pglGetPolygonStipple)(GLubyte* mask);
typedef	const GLubyte* (pglGetString)(GLenum name);
typedef	void	(pglGetTexEnvfv)(GLenum	target, GLenum	pname, GLfloat* params);
typedef	void	(pglGetTexEnviv)(GLenum	target, GLenum	pname, GLint* params);
typedef	void	(pglGetTexGendv)(GLenum	coord, GLenum	pname, GLdouble* params);
typedef	void	(pglGetTexGenfv)(GLenum	coord, GLenum	pname, GLfloat* params);
typedef	void	(pglGetTexGeniv)(GLenum	coord, GLenum	pname, GLint* params);
typedef	void	(pglGetTexImage)(GLenum	target, GLint	level, GLenum	format, GLenum	type, GLvoid* pixels);
typedef	void	(pglGetTexLevelParameterfv)(GLenum	target, GLint	level, GLenum	pname, GLfloat* params);
typedef	void	(pglGetTexLevelParameteriv)(GLenum	target, GLint	level, GLenum	pname, GLint* params);
typedef	void	(pglGetTexParameterfv)(GLenum	target, GLenum	pname, GLfloat* params);
typedef	void	(pglGetTexParameteriv)(GLenum	target, GLenum	pname, GLint* params);
typedef	void	(pglHint)(GLenum	target, GLenum	mode);
typedef	void	(pglIndexMask)(GLuint	mask);
typedef	void	(pglIndexPointer)(GLenum	type, GLsizei	stride, const	GLvoid* pointer);
typedef	void	(pglIndexd)(GLdouble	c);
typedef	void	(pglIndexdv)(const	GLdouble* c);
typedef	void	(pglIndexf)(GLfloat	c);
typedef	void	(pglIndexfv)(const	GLfloat* c);
typedef	void	(pglIndexi)(GLint	c);
typedef	void	(pglIndexiv)(const	GLint* c);
typedef	void	(pglIndexs)(GLshort	c);
typedef	void	(pglIndexsv)(const	GLshort* c);
typedef	void	(pglIndexub)(GLubyte	c);
typedef	void	(pglIndexubv)(const	GLubyte* c);
typedef	void	(pglInitNames)(void);
typedef	void	(pglInterleavedArrays)(GLenum	format, GLsizei	stride, const	GLvoid* pointer);
typedef	GLboolean(pglIsEnabled)	(GLenum	cap);
typedef	GLboolean(pglIsList)	(GLuint	list);
typedef	GLboolean(pglIsTexture)	(GLuint	texture);
typedef	void	(pglLightModelf)(GLenum	pname, GLfloat	param);
typedef	void	(pglLightModelfv)(GLenum	pname, const	GLfloat* params);
typedef	void	(pglLightModeli)(GLenum	pname, GLint	param);
typedef	void	(pglLightModeliv)(GLenum	pname, const	GLint* params);
typedef	void	(pglLightf)(GLenum	light, GLenum	pname, GLfloat	param);
typedef	void	(pglLightfv)(GLenum	light, GLenum	pname, const	GLfloat* params);
typedef	void	(pglLighti)(GLenum	light, GLenum	pname, GLint	param);
typedef	void	(pglLightiv)(GLenum	light, GLenum	pname, const	GLint* params);
typedef	void	(pglLineStipple)(GLint	factor, GLushort	pattern);
typedef	void	(pglLineWidth)(GLfloat	width);
typedef	void	(pglListBase)(GLuint	base);
typedef	void	(pglLoadIdentity)(void);
typedef	void	(pglLoadMatrixd)(const	GLdouble* m);
typedef	void	(pglLoadMatrixf)(const	GLfloat* m);
typedef	void	(pglLoadName)(GLuint	name);
typedef	void	(pglLogicOp)(GLenum	opcode);
typedef	void	(pglMap1d)(GLenum	target, GLdouble	u1, GLdouble	u2, GLint	stride, GLint	order, const	GLdouble* points);
typedef	void	(pglMap1f)(GLenum	target, GLfloat	u1, GLfloat	u2, GLint	stride, GLint	order, const	GLfloat* points);
typedef	void	(pglMap2d)(GLenum	target, GLdouble	u1, GLdouble	u2, GLint	ustride, GLint	uorder, GLdouble	v1, GLdouble	v2, GLint	vstride, GLint	vorder, const	GLdouble* points);
typedef	void	(pglMap2f)(GLenum	target, GLfloat	u1, GLfloat	u2, GLint	ustride, GLint	uorder, GLfloat	v1, GLfloat	v2, GLint	vstride, GLint	vorder, const	GLfloat* points);
typedef	void	(pglMapGrid1d)(GLint	un, GLdouble	u1, GLdouble	u2);
typedef	void	(pglMapGrid1f)(GLint	un, GLfloat	u1, GLfloat	u2);
typedef	void	(pglMapGrid2d)(GLint	un, GLdouble	u1, GLdouble	u2, GLint	vn, GLdouble	v1, GLdouble	v2);
typedef	void	(pglMapGrid2f)(GLint	un, GLfloat	u1, GLfloat	u2, GLint	vn, GLfloat	v1, GLfloat	v2);
typedef	void	(pglMaterialf)(GLenum	face, GLenum	pname, GLfloat	param);
typedef	void	(pglMaterialfv)(GLenum	face, GLenum	pname, const	GLfloat* params);
typedef	void	(pglMateriali)(GLenum	face, GLenum	pname, GLint	param);
typedef	void	(pglMaterialiv)(GLenum	face, GLenum	pname, const	GLint* params);
typedef	void	(pglMatrixMode)(GLenum	mode);
typedef	void	(pglMultMatrixd)(const	GLdouble* m);
typedef	void	(pglMultMatrixf)(const	GLfloat* m);
typedef	void	(pglNewList)(GLuint	list, GLenum	mode);
typedef	void	(pglNormal3b)(GLbyte	nx, GLbyte	ny, GLbyte	nz);
typedef	void	(pglNormal3bv)(const	GLbyte* v);
typedef	void	(pglNormal3d)(GLdouble	nx, GLdouble	ny, GLdouble	nz);
typedef	void	(pglNormal3dv)(const	GLdouble* v);
typedef	void	(pglNormal3f)(GLfloat	nx, GLfloat	ny, GLfloat	nz);
typedef	void	(pglNormal3fv)(const	GLfloat* v);
typedef	void	(pglNormal3i)(GLint	nx, GLint	ny, GLint	nz);
typedef	void	(pglNormal3iv)(const	GLint* v);
typedef	void	(pglNormal3s)(GLshort	nx, GLshort	ny, GLshort	nz);
typedef	void	(pglNormal3sv)(const	GLshort* v);
typedef	void	(pglNormalPointer)(GLenum	type, GLsizei	stride, const	GLvoid* pointer);
typedef	void	(pglOrtho)(GLdouble	left, GLdouble	right, GLdouble	bottom, GLdouble	top, GLdouble	zNear, GLdouble	zFar);
typedef	void	(pglPassThrough)(GLfloat	token);
typedef	void	(pglPixelMapfv)(GLenum	map, GLsizei	mapsize, const	GLfloat* values);
typedef	void	(pglPixelMapuiv)(GLenum	map, GLsizei	mapsize, const	GLuint* values);
typedef	void	(pglPixelMapusv)(GLenum	map, GLsizei	mapsize, const	GLushort* values);
typedef	void	(pglPixelStoref)(GLenum	pname, GLfloat	param);
typedef	void	(pglPixelStorei)(GLenum	pname, GLint	param);
typedef	void	(pglPixelTransferf)(GLenum	pname, GLfloat	param);
typedef	void	(pglPixelTransferi)(GLenum	pname, GLint	param);
typedef	void	(pglPixelZoom)(GLfloat	xfactor, GLfloat	yfactor);
typedef	void	(pglPointSize)(GLfloat	size);
typedef	void	(pglPolygonMode)(GLenum	face, GLenum	mode);
typedef	void	(pglPolygonOffset)(GLfloat	factor, GLfloat	units);
typedef	void	(pglPolygonStipple)(const	GLubyte* mask);
typedef	void	(pglPopAttrib)(void);
typedef	void	(pglPopClientAttrib)(void);
typedef	void	(pglPopMatrix)(void);
typedef	void	(pglPopName)(void);
typedef	void	(pglPrioritizeTextures)(GLsizei	n, const	GLuint* textures, const	GLclampf* priorities);
typedef	void	(pglPushAttrib)(GLbitfield	mask);
typedef	void	(pglPushClientAttrib)(GLbitfield	mask);
typedef	void	(pglPushMatrix)(void);
typedef	void	(pglPushName)(GLuint	name);
typedef	void	(pglRasterPos2d)(GLdouble	x, GLdouble	y);
typedef	void	(pglRasterPos2dv)(const	GLdouble* v);
typedef	void	(pglRasterPos2f)(GLfloat	x, GLfloat	y);
typedef	void	(pglRasterPos2fv)(const	GLfloat* v);
typedef	void	(pglRasterPos2i)(GLint	x, GLint	y);
typedef	void	(pglRasterPos2iv)(const	GLint* v);
typedef	void	(pglRasterPos2s)(GLshort	x, GLshort	y);
typedef	void	(pglRasterPos2sv)(const	GLshort* v);
typedef	void	(pglRasterPos3d)(GLdouble	x, GLdouble	y, GLdouble	z);
typedef	void	(pglRasterPos3dv)(const	GLdouble* v);
typedef	void	(pglRasterPos3f)(GLfloat	x, GLfloat	y, GLfloat	z);
typedef	void	(pglRasterPos3fv)(const	GLfloat* v);
typedef	void	(pglRasterPos3i)(GLint	x, GLint	y, GLint	z);
typedef	void	(pglRasterPos3iv)(const	GLint* v);
typedef	void	(pglRasterPos3s)(GLshort	x, GLshort	y, GLshort	z);
typedef	void	(pglRasterPos3sv)(const	GLshort* v);
typedef	void	(pglRasterPos4d)(GLdouble	x, GLdouble	y, GLdouble	z, GLdouble	w);
typedef	void	(pglRasterPos4dv)(const	GLdouble* v);
typedef	void	(pglRasterPos4f)(GLfloat	x, GLfloat	y, GLfloat	z, GLfloat	w);
typedef	void	(pglRasterPos4fv)(const	GLfloat* v);
typedef	void	(pglRasterPos4i)(GLint	x, GLint	y, GLint	z, GLint	w);
typedef	void	(pglRasterPos4iv)(const	GLint* v);
typedef	void	(pglRasterPos4s)(GLshort	x, GLshort	y, GLshort	z, GLshort	w);
typedef	void	(pglRasterPos4sv)(const	GLshort* v);
typedef	void	(pglReadBuffer)(GLenum	mode);
typedef	void	(pglReadPixels)(GLint	x, GLint	y, GLsizei	width, GLsizei	height, GLenum	format, GLenum	type, GLvoid* pixels);
typedef	void	(pglRectd)(GLdouble	x1, GLdouble	y1, GLdouble	x2, GLdouble	y2);
typedef	void	(pglRectdv)(const	GLdouble* v1, const	GLdouble* v2);
typedef	void	(pglRectf)(GLfloat	x1, GLfloat	y1, GLfloat	x2, GLfloat	y2);
typedef	void	(pglRectfv)(const	GLfloat* v1, const	GLfloat* v2);
typedef	void	(pglRecti)(GLint	x1, GLint	y1, GLint	x2, GLint	y2);
typedef	void	(pglRectiv)(const	GLint* v1, const	GLint* v2);
typedef	void	(pglRects)(GLshort	x1, GLshort	y1, GLshort	x2, GLshort	y2);
typedef	void	(pglRectsv)(const	GLshort* v1, const	GLshort* v2);
typedef	GLint(pglRenderMode)	(GLenum	mode);
typedef	void	(pglRotated)(GLdouble	angle, GLdouble	x, GLdouble	y, GLdouble	z);
typedef	void	(pglRotatef)(GLfloat	angle, GLfloat	x, GLfloat	y, GLfloat	z);
typedef	void	(pglScaled)(GLdouble	x, GLdouble	y, GLdouble	z);
typedef	void	(pglScalef)(GLfloat	x, GLfloat	y, GLfloat	z);
typedef	void	(pglScissor)(GLint	x, GLint	y, GLsizei	width, GLsizei	height);
typedef	void	(pglSelectBuffer)(GLsizei	size, GLuint* buffer);
typedef	void	(pglShadeModel)(GLenum	mode);
typedef	void	(pglStencilFunc)(GLenum	func, GLint	ref, GLuint	mask);
typedef	void	(pglStencilMask)(GLuint	mask);
typedef	void	(pglStencilOp)(GLenum	fail, GLenum	zfail, GLenum	zpass);
typedef	void	(pglTexCoord1d)(GLdouble	s);
typedef	void	(pglTexCoord1dv)(const	GLdouble* v);
typedef	void	(pglTexCoord1f)(GLfloat	s);
typedef	void	(pglTexCoord1fv)(const	GLfloat* v);
typedef	void	(pglTexCoord1i)(GLint	s);
typedef	void	(pglTexCoord1iv)(const	GLint* v);
typedef	void	(pglTexCoord1s)(GLshort	s);
typedef	void	(pglTexCoord1sv)(const	GLshort* v);
typedef	void	(pglTexCoord2d)(GLdouble	s, GLdouble	t);
typedef	void	(pglTexCoord2dv)(const	GLdouble* v);
typedef	void	(pglTexCoord2f)(GLfloat	s, GLfloat	t);
typedef	void	(pglTexCoord2fv)(const	GLfloat* v);
typedef	void	(pglTexCoord2i)(GLint	s, GLint	t);
typedef	void	(pglTexCoord2iv)(const	GLint* v);
typedef	void	(pglTexCoord2s)(GLshort	s, GLshort	t);
typedef	void	(pglTexCoord2sv)(const	GLshort* v);
typedef	void	(pglTexCoord3d)(GLdouble	s, GLdouble	t, GLdouble	r);
typedef	void	(pglTexCoord3dv)(const	GLdouble* v);
typedef	void	(pglTexCoord3f)(GLfloat	s, GLfloat	t, GLfloat	r);
typedef	void	(pglTexCoord3fv)(const	GLfloat* v);
typedef	void	(pglTexCoord3i)(GLint	s, GLint	t, GLint	r);
typedef	void	(pglTexCoord3iv)(const	GLint* v);
typedef	void	(pglTexCoord3s)(GLshort	s, GLshort	t, GLshort	r);
typedef	void	(pglTexCoord3sv)(const	GLshort* v);
typedef	void	(pglTexCoord4d)(GLdouble	s, GLdouble	t, GLdouble	r, GLdouble	q);
typedef	void	(pglTexCoord4dv)(const	GLdouble* v);
typedef	void	(pglTexCoord4f)(GLfloat	s, GLfloat	t, GLfloat	r, GLfloat	q);
typedef	void	(pglTexCoord4fv)(const	GLfloat* v);
typedef	void	(pglTexCoord4i)(GLint	s, GLint	t, GLint	r, GLint	q);
typedef	void	(pglTexCoord4iv)(const	GLint* v);
typedef	void	(pglTexCoord4s)(GLshort	s, GLshort	t, GLshort	r, GLshort	q);
typedef	void	(pglTexCoord4sv)(const	GLshort* v);
typedef	void	(pglTexCoordPointer)(GLint	size, GLenum	type, GLsizei	stride, const	GLvoid* pointer);
typedef	void	(pglTexEnvf)(GLenum	target, GLenum	pname, GLfloat	param);
typedef	void	(pglTexEnvfv)(GLenum	target, GLenum	pname, const	GLfloat* params);
typedef	void	(pglTexEnvi)(GLenum	target, GLenum	pname, GLint	param);
typedef	void	(pglTexEnviv)(GLenum	target, GLenum	pname, const	GLint* params);
typedef	void	(pglTexGend)(GLenum	coord, GLenum	pname, GLdouble	param);
typedef	void	(pglTexGendv)(GLenum	coord, GLenum	pname, const	GLdouble* params);
typedef	void	(pglTexGenf)(GLenum	coord, GLenum	pname, GLfloat	param);
typedef	void	(pglTexGenfv)(GLenum	coord, GLenum	pname, const	GLfloat* params);
typedef	void	(pglTexGeni)(GLenum	coord, GLenum	pname, GLint	param);
typedef	void	(pglTexGeniv)(GLenum	coord, GLenum	pname, const	GLint* params);
typedef	void	(pglTexImage1D)(GLenum	target, GLint	level, GLint	internalformat, GLsizei	width, GLint	border, GLenum	format, GLenum	type, const	GLvoid* pixels);
typedef	void	(pglTexImage2D)(GLenum	target, GLint	level, GLint	internalformat, GLsizei	width, GLsizei	height, GLint	border, GLenum	format, GLenum	type, const	GLvoid* pixels);
typedef	void	(pglTexParameterf)(GLenum	target, GLenum	pname, GLfloat	param);
typedef	void	(pglTexParameterfv)(GLenum	target, GLenum	pname, const	GLfloat* params);
typedef	void	(pglTexParameteri)(GLenum	target, GLenum	pname, GLint	param);
typedef	void	(pglTexParameteriv)(GLenum	target, GLenum	pname, const	GLint* params);
typedef	void	(pglTexSubImage1D)(GLenum	target, GLint	level, GLint	xoffset, GLsizei	width, GLenum	format, GLenum	type, const	GLvoid* pixels);
typedef	void	(pglTexSubImage2D)(GLenum	target, GLint	level, GLint	xoffset, GLint	yoffset, GLsizei	width, GLsizei	height, GLenum	format, GLenum	type, const	GLvoid* pixels);
typedef	void	(pglTranslated)(GLdouble	x, GLdouble	y, GLdouble	z);
typedef	void	(pglTranslatef)(GLfloat	x, GLfloat	y, GLfloat	z);
typedef	void	(pglVertex2d)(GLdouble	x, GLdouble	y);
typedef	void	(pglVertex2dv)(const	GLdouble* v);
typedef	void	(pglVertex2f)(GLfloat	x, GLfloat	y);
typedef	void	(pglVertex2fv)(const	GLfloat* v);
typedef	void	(pglVertex2i)(GLint	x, GLint	y);
typedef	void	(pglVertex2iv)(const	GLint* v);
typedef	void	(pglVertex2s)(GLshort	x, GLshort	y);
typedef	void	(pglVertex2sv)(const	GLshort* v);
typedef	void	(pglVertex3d)(GLdouble	x, GLdouble	y, GLdouble	z);
typedef	void	(pglVertex3dv)(const	GLdouble* v);
typedef	void	(pglVertex3f)(GLfloat	x, GLfloat	y, GLfloat	z);
typedef	void	(pglVertex3fv)(const	GLfloat* v);
typedef	void	(pglVertex3i)(GLint	x, GLint	y, GLint	z);
typedef	void	(pglVertex3iv)(const	GLint* v);
typedef	void	(pglVertex3s)(GLshort	x, GLshort	y, GLshort	z);
typedef	void	(pglVertex3sv)(const	GLshort* v);
typedef	void	(pglVertex4d)(GLdouble	x, GLdouble	y, GLdouble	z, GLdouble	w);
typedef	void	(pglVertex4dv)(const	GLdouble* v);
typedef	void	(pglVertex4f)(GLfloat	x, GLfloat	y, GLfloat	z, GLfloat	w);
typedef	void	(pglVertex4fv)(const	GLfloat* v);
typedef	void	(pglVertex4i)(GLint	x, GLint	y, GLint	z, GLint	w);
typedef	void	(pglVertex4iv)(const	GLint* v);
typedef	void	(pglVertex4s)(GLshort	x, GLshort	y, GLshort	z, GLshort	w);
typedef	void	(pglVertex4sv)(const	GLshort* v);
typedef	void	(pglVertexPointer)(GLint	size, GLenum	type, GLsizei	stride, const	GLvoid* pointer);
typedef	void	(pglViewport)(GLint	x, GLint	y, GLsizei	width, GLsizei	height);


pglAccum* glAccum = NULL;
pglAlphaFunc* glAlphaFunc = NULL;
pglAreTexturesResident* glAreTexturesResident = NULL;
pglArrayElement* glArrayElement = NULL;
pglBegin* glBegin = NULL;
pglBindTexture* glBindTexture = NULL;
pglBitmap* glBitmap = NULL;
pglBlendFunc* glBlendFunc = NULL;
pglCallList* glCallList = NULL;
pglCallLists* glCallLists = NULL;
pglClear* glClear = NULL;
pglClearAccum* glClearAccum = NULL;
pglClearColor* glClearColor = NULL;
pglClearDepth* glClearDepth = NULL;
pglClearIndex* glClearIndex = NULL;
pglClearStencil* glClearStencil = NULL;
pglClipPlane* glClipPlane = NULL;
pglColor3b* glColor3b = NULL;
pglColor3bv* glColor3bv = NULL;
pglColor3d* glColor3d = NULL;
pglColor3dv* glColor3dv = NULL;
pglColor3f* glColor3f = NULL;
pglColor3fv* glColor3fv = NULL;
pglColor3i* glColor3i = NULL;
pglColor3iv* glColor3iv = NULL;
pglColor3s* glColor3s = NULL;
pglColor3sv* glColor3sv = NULL;
pglColor3ub* glColor3ub = NULL;
pglColor3ubv* glColor3ubv = NULL;
pglColor3ui* glColor3ui = NULL;
pglColor3uiv* glColor3uiv = NULL;
pglColor3us* glColor3us = NULL;
pglColor3usv* glColor3usv = NULL;
pglColor4b* glColor4b = NULL;
pglColor4bv* glColor4bv = NULL;
pglColor4d* glColor4d = NULL;
pglColor4dv* glColor4dv = NULL;
pglColor4f* glColor4f = NULL;
pglColor4fv* glColor4fv = NULL;
pglColor4i* glColor4i = NULL;
pglColor4iv* glColor4iv = NULL;
pglColor4s* glColor4s = NULL;
pglColor4sv* glColor4sv = NULL;
pglColor4ub* glColor4ub = NULL;
pglColor4ubv* glColor4ubv = NULL;
pglColor4ui* glColor4ui = NULL;
pglColor4uiv* glColor4uiv = NULL;
pglColor4us* glColor4us = NULL;
pglColor4usv* glColor4usv = NULL;
pglColorMask* glColorMask = NULL;
pglColorMaterial* glColorMaterial = NULL;
pglColorPointer* glColorPointer = NULL;
pglCopyPixels* glCopyPixels = NULL;
pglCopyTexImage1D* glCopyTexImage1D = NULL;
pglCopyTexImage2D* glCopyTexImage2D = NULL;
pglCopyTexSubImage1D* glCopyTexSubImage1D = NULL;
pglCopyTexSubImage2D* glCopyTexSubImage2D = NULL;
pglCullFace* glCullFace = NULL;
pglDeleteLists* glDeleteLists = NULL;
pglDeleteTextures* glDeleteTextures = NULL;
pglDepthFunc* glDepthFunc = NULL;
pglDepthMask* glDepthMask = NULL;
pglDepthRange* glDepthRange = NULL;
pglDisable* glDisable = NULL;
pglDisableClientState* glDisableClientState = NULL;
pglDrawArrays* glDrawArrays = NULL;
pglDrawBuffer* glDrawBuffer = NULL;
pglDrawElements* glDrawElements = NULL;
pglDrawPixels* glDrawPixels = NULL;
pglEdgeFlag* glEdgeFlag = NULL;
pglEdgeFlagPointer* glEdgeFlagPointer = NULL;
pglEdgeFlagv* glEdgeFlagv = NULL;
pglEnable* glEnable = NULL;
pglEnableClientState* glEnableClientState = NULL;
pglEnd* glEnd = NULL;
pglEndList* glEndList = NULL;
pglEvalCoord1d* glEvalCoord1d = NULL;
pglEvalCoord1dv* glEvalCoord1dv = NULL;
pglEvalCoord1f* glEvalCoord1f = NULL;
pglEvalCoord1fv* glEvalCoord1fv = NULL;
pglEvalCoord2d* glEvalCoord2d = NULL;
pglEvalCoord2dv* glEvalCoord2dv = NULL;
pglEvalCoord2f* glEvalCoord2f = NULL;
pglEvalCoord2fv* glEvalCoord2fv = NULL;
pglEvalMesh1* glEvalMesh1 = NULL;
pglEvalMesh2* glEvalMesh2 = NULL;
pglEvalPoint1* glEvalPoint1 = NULL;
pglEvalPoint2* glEvalPoint2 = NULL;
pglFeedbackBuffer* glFeedbackBuffer = NULL;
pglFinish* glFinish = NULL;
pglFlush* glFlush = NULL;
pglFogf* glFogf = NULL;
pglFogfv* glFogfv = NULL;
pglFogi* glFogi = NULL;
pglFogiv* glFogiv = NULL;
pglFrontFace* glFrontFace = NULL;
pglFrustum* glFrustum = NULL;
pglGenLists* glGenLists = NULL;
pglGenTextures* glGenTextures = NULL;
pglGetBooleanv* glGetBooleanv = NULL;
pglGetClipPlane* glGetClipPlane = NULL;
pglGetDoublev* glGetDoublev = NULL;
pglGetError* glGetError = NULL;
pglGetFloatv* glGetFloatv = NULL;
pglGetIntegerv* glGetIntegerv = NULL;
pglGetLightfv* glGetLightfv = NULL;
pglGetLightiv* glGetLightiv = NULL;
pglGetMapdv* glGetMapdv = NULL;
pglGetMapfv* glGetMapfv = NULL;
pglGetMapiv* glGetMapiv = NULL;
pglGetMaterialfv* glGetMaterialfv = NULL;
pglGetMaterialiv* glGetMaterialiv = NULL;
pglGetPixelMapfv* glGetPixelMapfv = NULL;
pglGetPixelMapuiv* glGetPixelMapuiv = NULL;
pglGetPixelMapusv* glGetPixelMapusv = NULL;
pglGetPointerv* glGetPointerv = NULL;
pglGetPolygonStipple* glGetPolygonStipple = NULL;
pglGetString* glGetString = NULL;
pglGetTexEnvfv* glGetTexEnvfv = NULL;
pglGetTexEnviv* glGetTexEnviv = NULL;
pglGetTexGendv* glGetTexGendv = NULL;
pglGetTexGenfv* glGetTexGenfv = NULL;
pglGetTexGeniv* glGetTexGeniv = NULL;
pglGetTexImage* glGetTexImage = NULL;
pglGetTexLevelParameterfv* glGetTexLevelParameterfv = NULL;
pglGetTexLevelParameteriv* glGetTexLevelParameteriv = NULL;
pglGetTexParameterfv* glGetTexParameterfv = NULL;
pglGetTexParameteriv* glGetTexParameteriv = NULL;
pglHint* glHint = NULL;
pglIndexMask* glIndexMask = NULL;
pglIndexPointer* glIndexPointer = NULL;
pglIndexd* glIndexd = NULL;
pglIndexdv* glIndexdv = NULL;
pglIndexf* glIndexf = NULL;
pglIndexfv* glIndexfv = NULL;
pglIndexi* glIndexi = NULL;
pglIndexiv* glIndexiv = NULL;
pglIndexs* glIndexs = NULL;
pglIndexsv* glIndexsv = NULL;
pglIndexub* glIndexub = NULL;
pglIndexubv* glIndexubv = NULL;
pglInitNames* glInitNames = NULL;
pglInterleavedArrays* glInterleavedArrays = NULL;
pglIsEnabled* glIsEnabled = NULL;
pglIsList* glIsList = NULL;
pglIsTexture* glIsTexture = NULL;
pglLightModelf* glLightModelf = NULL;
pglLightModelfv* glLightModelfv = NULL;
pglLightModeli* glLightModeli = NULL;
pglLightModeliv* glLightModeliv = NULL;
pglLightf* glLightf = NULL;
pglLightfv* glLightfv = NULL;
pglLighti* glLighti = NULL;
pglLightiv* glLightiv = NULL;
pglLineStipple* glLineStipple = NULL;
pglLineWidth* glLineWidth = NULL;
pglListBase* glListBase = NULL;
pglLoadIdentity* glLoadIdentity = NULL;
pglLoadMatrixd* glLoadMatrixd = NULL;
pglLoadMatrixf* glLoadMatrixf = NULL;
pglLoadName* glLoadName = NULL;
pglLogicOp* glLogicOp = NULL;
pglMap1d* glMap1d = NULL;
pglMap1f* glMap1f = NULL;
pglMap2d* glMap2d = NULL;
pglMap2f* glMap2f = NULL;
pglMapGrid1d* glMapGrid1d = NULL;
pglMapGrid1f* glMapGrid1f = NULL;
pglMapGrid2d* glMapGrid2d = NULL;
pglMapGrid2f* glMapGrid2f = NULL;
pglMaterialf* glMaterialf = NULL;
pglMaterialfv* glMaterialfv = NULL;
pglMateriali* glMateriali = NULL;
pglMaterialiv* glMaterialiv = NULL;
pglMatrixMode* glMatrixMode = NULL;
pglMultMatrixd* glMultMatrixd = NULL;
pglMultMatrixf* glMultMatrixf = NULL;
pglNewList* glNewList = NULL;
pglNormal3b* glNormal3b = NULL;
pglNormal3bv* glNormal3bv = NULL;
pglNormal3d* glNormal3d = NULL;
pglNormal3dv* glNormal3dv = NULL;
pglNormal3f* glNormal3f = NULL;
pglNormal3fv* glNormal3fv = NULL;
pglNormal3i* glNormal3i = NULL;
pglNormal3iv* glNormal3iv = NULL;
pglNormal3s* glNormal3s = NULL;
pglNormal3sv* glNormal3sv = NULL;
pglNormalPointer* glNormalPointer = NULL;
pglOrtho* glOrtho = NULL;
pglPassThrough* glPassThrough = NULL;
pglPixelMapfv* glPixelMapfv = NULL;
pglPixelMapuiv* glPixelMapuiv = NULL;
pglPixelMapusv* glPixelMapusv = NULL;
pglPixelStoref* glPixelStoref = NULL;
pglPixelStorei* glPixelStorei = NULL;
pglPixelTransferf* glPixelTransferf = NULL;
pglPixelTransferi* glPixelTransferi = NULL;
pglPixelZoom* glPixelZoom = NULL;
pglPointSize* glPointSize = NULL;
pglPolygonMode* glPolygonMode = NULL;
pglPolygonOffset* glPolygonOffset = NULL;
pglPolygonStipple* glPolygonStipple = NULL;
pglPopAttrib* glPopAttrib = NULL;
pglPopClientAttrib* glPopClientAttrib = NULL;
pglPopMatrix* glPopMatrix = NULL;
pglPopName* glPopName = NULL;
pglPrioritizeTextures* glPrioritizeTextures = NULL;
pglPushAttrib* glPushAttrib = NULL;
pglPushClientAttrib* glPushClientAttrib = NULL;
pglPushMatrix* glPushMatrix = NULL;
pglPushName* glPushName = NULL;
pglRasterPos2d* glRasterPos2d = NULL;
pglRasterPos2dv* glRasterPos2dv = NULL;
pglRasterPos2f* glRasterPos2f = NULL;
pglRasterPos2fv* glRasterPos2fv = NULL;
pglRasterPos2i* glRasterPos2i = NULL;
pglRasterPos2iv* glRasterPos2iv = NULL;
pglRasterPos2s* glRasterPos2s = NULL;
pglRasterPos2sv* glRasterPos2sv = NULL;
pglRasterPos3d* glRasterPos3d = NULL;
pglRasterPos3dv* glRasterPos3dv = NULL;
pglRasterPos3f* glRasterPos3f = NULL;
pglRasterPos3fv* glRasterPos3fv = NULL;
pglRasterPos3i* glRasterPos3i = NULL;
pglRasterPos3iv* glRasterPos3iv = NULL;
pglRasterPos3s* glRasterPos3s = NULL;
pglRasterPos3sv* glRasterPos3sv = NULL;
pglRasterPos4d* glRasterPos4d = NULL;
pglRasterPos4dv* glRasterPos4dv = NULL;
pglRasterPos4f* glRasterPos4f = NULL;
pglRasterPos4fv* glRasterPos4fv = NULL;
pglRasterPos4i* glRasterPos4i = NULL;
pglRasterPos4iv* glRasterPos4iv = NULL;
pglRasterPos4s* glRasterPos4s = NULL;
pglRasterPos4sv* glRasterPos4sv = NULL;
pglReadBuffer* glReadBuffer = NULL;
pglReadPixels* glReadPixels = NULL;
pglRectd* glRectd = NULL;
pglRectdv* glRectdv = NULL;
pglRectf* glRectf = NULL;
pglRectfv* glRectfv = NULL;
pglRecti* glRecti = NULL;
pglRectiv* glRectiv = NULL;
pglRects* glRects = NULL;
pglRectsv* glRectsv = NULL;
pglRenderMode* glRenderMode = NULL;
pglRotated* glRotated = NULL;
pglRotatef* glRotatef = NULL;
pglScaled* glScaled = NULL;
pglScalef* glScalef = NULL;
pglScissor* glScissor = NULL;
pglSelectBuffer* glSelectBuffer = NULL;
pglShadeModel* glShadeModel = NULL;
pglStencilFunc* glStencilFunc = NULL;
pglStencilMask* glStencilMask = NULL;
pglStencilOp* glStencilOp = NULL;
pglTexCoord1d* glTexCoord1d = NULL;
pglTexCoord1dv* glTexCoord1dv = NULL;
pglTexCoord1f* glTexCoord1f = NULL;
pglTexCoord1fv* glTexCoord1fv = NULL;
pglTexCoord1i* glTexCoord1i = NULL;
pglTexCoord1iv* glTexCoord1iv = NULL;
pglTexCoord1s* glTexCoord1s = NULL;
pglTexCoord1sv* glTexCoord1sv = NULL;
pglTexCoord2d* glTexCoord2d = NULL;
pglTexCoord2dv* glTexCoord2dv = NULL;
pglTexCoord2f* glTexCoord2f = NULL;
pglTexCoord2fv* glTexCoord2fv = NULL;
pglTexCoord2i* glTexCoord2i = NULL;
pglTexCoord2iv* glTexCoord2iv = NULL;
pglTexCoord2s* glTexCoord2s = NULL;
pglTexCoord2sv* glTexCoord2sv = NULL;
pglTexCoord3d* glTexCoord3d = NULL;
pglTexCoord3dv* glTexCoord3dv = NULL;
pglTexCoord3f* glTexCoord3f = NULL;
pglTexCoord3fv* glTexCoord3fv = NULL;
pglTexCoord3i* glTexCoord3i = NULL;
pglTexCoord3iv* glTexCoord3iv = NULL;
pglTexCoord3s* glTexCoord3s = NULL;
pglTexCoord3sv* glTexCoord3sv = NULL;
pglTexCoord4d* glTexCoord4d = NULL;
pglTexCoord4dv* glTexCoord4dv = NULL;
pglTexCoord4f* glTexCoord4f = NULL;
pglTexCoord4fv* glTexCoord4fv = NULL;
pglTexCoord4i* glTexCoord4i = NULL;
pglTexCoord4iv* glTexCoord4iv = NULL;
pglTexCoord4s* glTexCoord4s = NULL;
pglTexCoord4sv* glTexCoord4sv = NULL;
pglTexCoordPointer* glTexCoordPointer = NULL;
pglTexEnvf* glTexEnvf = NULL;
pglTexEnvfv* glTexEnvfv = NULL;
pglTexEnvi* glTexEnvi = NULL;
pglTexEnviv* glTexEnviv = NULL;
pglTexGend* glTexGend = NULL;
pglTexGendv* glTexGendv = NULL;
pglTexGenf* glTexGenf = NULL;
pglTexGenfv* glTexGenfv = NULL;
pglTexGeni* glTexGeni = NULL;
pglTexGeniv* glTexGeniv = NULL;
pglTexImage1D* glTexImage1D = NULL;
pglTexImage2D* glTexImage2D = NULL;
pglTexParameterf* glTexParameterf = NULL;
pglTexParameterfv* glTexParameterfv = NULL;
pglTexParameteri* glTexParameteri = NULL;
pglTexParameteriv* glTexParameteriv = NULL;
pglTexSubImage1D* glTexSubImage1D = NULL;
pglTexSubImage2D* glTexSubImage2D = NULL;
pglTranslated* glTranslated = NULL;
pglTranslatef* glTranslatef = NULL;
pglVertex2d* glVertex2d = NULL;
pglVertex2dv* glVertex2dv = NULL;
pglVertex2f* glVertex2f = NULL;
pglVertex2fv* glVertex2fv = NULL;
pglVertex2i* glVertex2i = NULL;
pglVertex2iv* glVertex2iv = NULL;
pglVertex2s* glVertex2s = NULL;
pglVertex2sv* glVertex2sv = NULL;
pglVertex3d* glVertex3d = NULL;
pglVertex3dv* glVertex3dv = NULL;
pglVertex3f* glVertex3f = NULL;
pglVertex3fv* glVertex3fv = NULL;
pglVertex3i* glVertex3i = NULL;
pglVertex3iv* glVertex3iv = NULL;
pglVertex3s* glVertex3s = NULL;
pglVertex3sv* glVertex3sv = NULL;
pglVertex4d* glVertex4d = NULL;
pglVertex4dv* glVertex4dv = NULL;
pglVertex4f* glVertex4f = NULL;
pglVertex4fv* glVertex4fv = NULL;
pglVertex4i* glVertex4i = NULL;
pglVertex4iv* glVertex4iv = NULL;
pglVertex4s* glVertex4s = NULL;
pglVertex4sv* glVertex4sv = NULL;
pglVertexPointer* glVertexPointer = NULL;
pglViewport* glViewport = NULL;


#endif     