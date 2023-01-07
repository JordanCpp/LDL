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

typedef	void	(OPENGL_API_CALL pglAccum)(GLenum	op, GLfloat	value);
typedef	void	(OPENGL_API_CALL pglAlphaFunc)(GLenum	func, GLclampf	ref);
typedef	GLboolean(OPENGL_API_CALL pglAreTexturesResident)	(GLsizei	n, const	GLuint* textures, GLboolean* residences);
typedef	void	(OPENGL_API_CALL pglArrayElement)(GLint	i);
typedef	void	(OPENGL_API_CALL pglBegin)(GLenum	mode);
typedef	void	(OPENGL_API_CALL pglBindTexture)(GLenum	target, GLuint	texture);
typedef	void	(OPENGL_API_CALL pglBitmap)(GLsizei	width, GLsizei	height, GLfloat	xorig, GLfloat	yorig, GLfloat	xmove, GLfloat	ymove, const	GLubyte* bitmap);
typedef	void	(OPENGL_API_CALL pglBlendFunc)(GLenum	sfactor, GLenum	dfactor);
typedef	void	(OPENGL_API_CALL pglCallList)(GLuint	list);
typedef	void	(OPENGL_API_CALL pglCallLists)(GLsizei	n, GLenum	type, const	GLvoid* lists);
typedef	void	(OPENGL_API_CALL pglClear)(GLbitfield	mask);
typedef	void	(OPENGL_API_CALL pglClearAccum)(GLfloat	red, GLfloat	green, GLfloat	blue, GLfloat	alpha);
typedef	void	(OPENGL_API_CALL pglClearColor)(GLclampf	red, GLclampf	green, GLclampf	blue, GLclampf	alpha);
typedef	void	(OPENGL_API_CALL pglClearDepth)(GLclampd	depth);
typedef	void	(OPENGL_API_CALL pglClearIndex)(GLfloat	c);
typedef	void	(OPENGL_API_CALL pglClearStencil)(GLint	s);
typedef	void	(OPENGL_API_CALL pglClipPlane)(GLenum	plane, const	GLdouble* equation);
typedef	void	(OPENGL_API_CALL pglColor3b)(GLbyte	red, GLbyte	green, GLbyte	blue);
typedef	void	(OPENGL_API_CALL pglColor3bv)(const	GLbyte* v);
typedef	void	(OPENGL_API_CALL pglColor3d)(GLdouble	red, GLdouble	green, GLdouble	blue);
typedef	void	(OPENGL_API_CALL pglColor3dv)(const	GLdouble* v);
typedef	void	(OPENGL_API_CALL pglColor3f)(GLfloat	red, GLfloat	green, GLfloat	blue);
typedef	void	(OPENGL_API_CALL pglColor3fv)(const	GLfloat* v);
typedef	void	(OPENGL_API_CALL pglColor3i)(GLint	red, GLint	green, GLint	blue);
typedef	void	(OPENGL_API_CALL pglColor3iv)(const	GLint* v);
typedef	void	(OPENGL_API_CALL pglColor3s)(GLshort	red, GLshort	green, GLshort	blue);
typedef	void	(OPENGL_API_CALL pglColor3sv)(const	GLshort* v);
typedef	void	(OPENGL_API_CALL pglColor3ub)(GLubyte	red, GLubyte	green, GLubyte	blue);
typedef	void	(OPENGL_API_CALL pglColor3ubv)(const	GLubyte* v);
typedef	void	(OPENGL_API_CALL pglColor3ui)(GLuint	red, GLuint	green, GLuint	blue);
typedef	void	(OPENGL_API_CALL pglColor3uiv)(const	GLuint* v);
typedef	void	(OPENGL_API_CALL pglColor3us)(GLushort	red, GLushort	green, GLushort	blue);
typedef	void	(OPENGL_API_CALL pglColor3usv)(const	GLushort* v);
typedef	void	(OPENGL_API_CALL pglColor4b)(GLbyte	red, GLbyte	green, GLbyte	blue, GLbyte	alpha);
typedef	void	(OPENGL_API_CALL pglColor4bv)(const	GLbyte* v);
typedef	void	(OPENGL_API_CALL pglColor4d)(GLdouble	red, GLdouble	green, GLdouble	blue, GLdouble	alpha);
typedef	void	(OPENGL_API_CALL pglColor4dv)(const	GLdouble* v);
typedef	void	(OPENGL_API_CALL pglColor4f)(GLfloat	red, GLfloat	green, GLfloat	blue, GLfloat	alpha);
typedef	void	(OPENGL_API_CALL pglColor4fv)(const	GLfloat* v);
typedef	void	(OPENGL_API_CALL pglColor4i)(GLint	red, GLint	green, GLint	blue, GLint	alpha);
typedef	void	(OPENGL_API_CALL pglColor4iv)(const	GLint* v);
typedef	void	(OPENGL_API_CALL pglColor4s)(GLshort	red, GLshort	green, GLshort	blue, GLshort	alpha);
typedef	void	(OPENGL_API_CALL pglColor4sv)(const	GLshort* v);
typedef	void	(OPENGL_API_CALL pglColor4ub)(GLubyte	red, GLubyte	green, GLubyte	blue, GLubyte	alpha);
typedef	void	(OPENGL_API_CALL pglColor4ubv)(const	GLubyte* v);
typedef	void	(OPENGL_API_CALL pglColor4ui)(GLuint	red, GLuint	green, GLuint	blue, GLuint	alpha);
typedef	void	(OPENGL_API_CALL pglColor4uiv)(const	GLuint* v);
typedef	void	(OPENGL_API_CALL pglColor4us)(GLushort	red, GLushort	green, GLushort	blue, GLushort	alpha);
typedef	void	(OPENGL_API_CALL pglColor4usv)(const	GLushort* v);
typedef	void	(OPENGL_API_CALL pglColorMask)(GLboolean	red, GLboolean	green, GLboolean	blue, GLboolean	alpha);
typedef	void	(OPENGL_API_CALL pglColorMaterial)(GLenum	face, GLenum	mode);
typedef	void	(OPENGL_API_CALL pglColorPointer)(GLint	size, GLenum	type, GLsizei	stride, const	GLvoid* pointer);
typedef	void	(OPENGL_API_CALL pglCopyPixels)(GLint	x, GLint	y, GLsizei	width, GLsizei	height, GLenum	type);
typedef	void	(OPENGL_API_CALL pglCopyTexImage1D)(GLenum	target, GLint	level, GLenum	internalFormat, GLint	x, GLint	y, GLsizei	width, GLint	border);
typedef	void	(OPENGL_API_CALL pglCopyTexImage2D)(GLenum	target, GLint	level, GLenum	internalFormat, GLint	x, GLint	y, GLsizei	width, GLsizei	height, GLint	border);
typedef	void	(OPENGL_API_CALL pglCopyTexSubImage1D)(GLenum	target, GLint	level, GLint	xoffset, GLint	x, GLint	y, GLsizei	width);
typedef	void	(OPENGL_API_CALL pglCopyTexSubImage2D)(GLenum	target, GLint	level, GLint	xoffset, GLint	yoffset, GLint	x, GLint	y, GLsizei	width, GLsizei	height);
typedef	void	(OPENGL_API_CALL pglCullFace)(GLenum	mode);
typedef	void	(OPENGL_API_CALL pglDeleteLists)(GLuint	list, GLsizei	range);
typedef	void	(OPENGL_API_CALL pglDeleteTextures)(GLsizei	n, const	GLuint* textures);
typedef	void	(OPENGL_API_CALL pglDepthFunc)(GLenum	func);
typedef	void	(OPENGL_API_CALL pglDepthMask)(GLboolean	flag);
typedef	void	(OPENGL_API_CALL pglDepthRange)(GLclampd	zNear, GLclampd	zFar);
typedef	void	(OPENGL_API_CALL pglDisable)(GLenum	cap);
typedef	void	(OPENGL_API_CALL pglDisableClientState)(GLenum	array);
typedef	void	(OPENGL_API_CALL pglDrawArrays)(GLenum	mode, GLint	first, GLsizei	count);
typedef	void	(OPENGL_API_CALL pglDrawBuffer)(GLenum	mode);
typedef	void	(OPENGL_API_CALL pglDrawElements)(GLenum	mode, GLsizei	count, GLenum	type, const	GLvoid* indices);
typedef	void	(OPENGL_API_CALL pglDrawPixels)(GLsizei	width, GLsizei	height, GLenum	format, GLenum	type, const	GLvoid* pixels);
typedef	void	(OPENGL_API_CALL pglEdgeFlag)(GLboolean	flag);
typedef	void	(OPENGL_API_CALL pglEdgeFlagPointer)(GLsizei	stride, const	GLvoid* pointer);
typedef	void	(OPENGL_API_CALL pglEdgeFlagv)(const	GLboolean* flag);
typedef	void	(OPENGL_API_CALL pglEnable)(GLenum	cap);
typedef	void	(OPENGL_API_CALL pglEnableClientState)(GLenum	array);
typedef	void	(OPENGL_API_CALL pglEnd)(void);
typedef	void	(OPENGL_API_CALL pglEndList)(void);
typedef	void	(OPENGL_API_CALL pglEvalCoord1d)(GLdouble	u);
typedef	void	(OPENGL_API_CALL pglEvalCoord1dv)(const	GLdouble* u);
typedef	void	(OPENGL_API_CALL pglEvalCoord1f)(GLfloat	u);
typedef	void	(OPENGL_API_CALL pglEvalCoord1fv)(const	GLfloat* u);
typedef	void	(OPENGL_API_CALL pglEvalCoord2d)(GLdouble	u, GLdouble	v);
typedef	void	(OPENGL_API_CALL pglEvalCoord2dv)(const	GLdouble* u);
typedef	void	(OPENGL_API_CALL pglEvalCoord2f)(GLfloat	u, GLfloat	v);
typedef	void	(OPENGL_API_CALL pglEvalCoord2fv)(const	GLfloat* u);
typedef	void	(OPENGL_API_CALL pglEvalMesh1)(GLenum	mode, GLint	i1, GLint	i2);
typedef	void	(OPENGL_API_CALL pglEvalMesh2)(GLenum	mode, GLint	i1, GLint	i2, GLint	j1, GLint	j2);
typedef	void	(OPENGL_API_CALL pglEvalPoint1)(GLint	i);
typedef	void	(OPENGL_API_CALL pglEvalPoint2)(GLint	i, GLint	j);
typedef	void	(OPENGL_API_CALL pglFeedbackBuffer)(GLsizei	size, GLenum	type, GLfloat* buffer);
typedef	void	(OPENGL_API_CALL pglFinish)(void);
typedef	void	(OPENGL_API_CALL pglFlush)(void);
typedef	void	(OPENGL_API_CALL pglFogf)(GLenum	pname, GLfloat	param);
typedef	void	(OPENGL_API_CALL pglFogfv)(GLenum	pname, const	GLfloat* params);
typedef	void	(OPENGL_API_CALL pglFogi)(GLenum	pname, GLint	param);
typedef	void	(OPENGL_API_CALL pglFogiv)(GLenum	pname, const	GLint* params);
typedef	void	(OPENGL_API_CALL pglFrontFace)(GLenum	mode);
typedef	void	(OPENGL_API_CALL pglFrustum)(GLdouble	left, GLdouble	right, GLdouble	bottom, GLdouble	top, GLdouble	zNear, GLdouble	zFar);
typedef	GLuint(OPENGL_API_CALL pglGenLists)	(GLsizei	range);
typedef	void	(OPENGL_API_CALL pglGenTextures)(GLsizei	n, GLuint* textures);
typedef	void	(OPENGL_API_CALL pglGetBooleanv)(GLenum	pname, GLboolean* params);
typedef	void	(OPENGL_API_CALL pglGetClipPlane)(GLenum	plane, GLdouble* equation);
typedef	void	(OPENGL_API_CALL pglGetDoublev)(GLenum	pname, GLdouble* params);
typedef	GLenum(OPENGL_API_CALL pglGetError)	(void);
typedef	void	(OPENGL_API_CALL pglGetFloatv)(GLenum	pname, GLfloat* params);
typedef	void	(OPENGL_API_CALL pglGetIntegerv)(GLenum	pname, GLint* params);
typedef	void	(OPENGL_API_CALL pglGetLightfv)(GLenum	light, GLenum	pname, GLfloat* params);
typedef	void	(OPENGL_API_CALL pglGetLightiv)(GLenum	light, GLenum	pname, GLint* params);
typedef	void	(OPENGL_API_CALL pglGetMapdv)(GLenum	target, GLenum	query, GLdouble* v);
typedef	void	(OPENGL_API_CALL pglGetMapfv)(GLenum	target, GLenum	query, GLfloat* v);
typedef	void	(OPENGL_API_CALL pglGetMapiv)(GLenum	target, GLenum	query, GLint* v);
typedef	void	(OPENGL_API_CALL pglGetMaterialfv)(GLenum	face, GLenum	pname, GLfloat* params);
typedef	void	(OPENGL_API_CALL pglGetMaterialiv)(GLenum	face, GLenum	pname, GLint* params);
typedef	void	(OPENGL_API_CALL pglGetPixelMapfv)(GLenum	map, GLfloat* values);
typedef	void	(OPENGL_API_CALL pglGetPixelMapuiv)(GLenum	map, GLuint* values);
typedef	void	(OPENGL_API_CALL pglGetPixelMapusv)(GLenum	map, GLushort* values);
typedef	void	(OPENGL_API_CALL pglGetPointerv)(GLenum	pname, GLvoid** params);
typedef	void	(OPENGL_API_CALL pglGetPolygonStipple)(GLubyte* mask);
typedef	const GLubyte* (OPENGL_API_CALL pglGetString)(GLenum name);
typedef	void	(OPENGL_API_CALL pglGetTexEnvfv)(GLenum	target, GLenum	pname, GLfloat* params);
typedef	void	(OPENGL_API_CALL pglGetTexEnviv)(GLenum	target, GLenum	pname, GLint* params);
typedef	void	(OPENGL_API_CALL pglGetTexGendv)(GLenum	coord, GLenum	pname, GLdouble* params);
typedef	void	(OPENGL_API_CALL pglGetTexGenfv)(GLenum	coord, GLenum	pname, GLfloat* params);
typedef	void	(OPENGL_API_CALL pglGetTexGeniv)(GLenum	coord, GLenum	pname, GLint* params);
typedef	void	(OPENGL_API_CALL pglGetTexImage)(GLenum	target, GLint	level, GLenum	format, GLenum	type, GLvoid* pixels);
typedef	void	(OPENGL_API_CALL pglGetTexLevelParameterfv)(GLenum	target, GLint	level, GLenum	pname, GLfloat* params);
typedef	void	(OPENGL_API_CALL pglGetTexLevelParameteriv)(GLenum	target, GLint	level, GLenum	pname, GLint* params);
typedef	void	(OPENGL_API_CALL pglGetTexParameterfv)(GLenum	target, GLenum	pname, GLfloat* params);
typedef	void	(OPENGL_API_CALL pglGetTexParameteriv)(GLenum	target, GLenum	pname, GLint* params);
typedef	void	(OPENGL_API_CALL pglHint)(GLenum	target, GLenum	mode);
typedef	void	(OPENGL_API_CALL pglIndexMask)(GLuint	mask);
typedef	void	(OPENGL_API_CALL pglIndexPointer)(GLenum	type, GLsizei	stride, const	GLvoid* pointer);
typedef	void	(OPENGL_API_CALL pglIndexd)(GLdouble	c);
typedef	void	(OPENGL_API_CALL pglIndexdv)(const	GLdouble* c);
typedef	void	(OPENGL_API_CALL pglIndexf)(GLfloat	c);
typedef	void	(OPENGL_API_CALL pglIndexfv)(const	GLfloat* c);
typedef	void	(OPENGL_API_CALL pglIndexi)(GLint	c);
typedef	void	(OPENGL_API_CALL pglIndexiv)(const	GLint* c);
typedef	void	(OPENGL_API_CALL pglIndexs)(GLshort	c);
typedef	void	(OPENGL_API_CALL pglIndexsv)(const	GLshort* c);
typedef	void	(OPENGL_API_CALL pglIndexub)(GLubyte	c);
typedef	void	(OPENGL_API_CALL pglIndexubv)(const	GLubyte* c);
typedef	void	(OPENGL_API_CALL pglInitNames)(void);
typedef	void	(OPENGL_API_CALL pglInterleavedArrays)(GLenum	format, GLsizei	stride, const	GLvoid* pointer);
typedef	GLboolean(OPENGL_API_CALL pglIsEnabled)	(GLenum	cap);
typedef	GLboolean(OPENGL_API_CALL pglIsList)	(GLuint	list);
typedef	GLboolean(OPENGL_API_CALL pglIsTexture)	(GLuint	texture);
typedef	void	(OPENGL_API_CALL pglLightModelf)(GLenum	pname, GLfloat	param);
typedef	void	(OPENGL_API_CALL pglLightModelfv)(GLenum	pname, const	GLfloat* params);
typedef	void	(OPENGL_API_CALL pglLightModeli)(GLenum	pname, GLint	param);
typedef	void	(OPENGL_API_CALL pglLightModeliv)(GLenum	pname, const	GLint* params);
typedef	void	(OPENGL_API_CALL pglLightf)(GLenum	light, GLenum	pname, GLfloat	param);
typedef	void	(OPENGL_API_CALL pglLightfv)(GLenum	light, GLenum	pname, const	GLfloat* params);
typedef	void	(OPENGL_API_CALL pglLighti)(GLenum	light, GLenum	pname, GLint	param);
typedef	void	(OPENGL_API_CALL pglLightiv)(GLenum	light, GLenum	pname, const	GLint* params);
typedef	void	(OPENGL_API_CALL pglLineStipple)(GLint	factor, GLushort	pattern);
typedef	void	(OPENGL_API_CALL pglLineWidth)(GLfloat	width);
typedef	void	(OPENGL_API_CALL pglListBase)(GLuint	base);
typedef	void	(OPENGL_API_CALL pglLoadIdentity)(void);
typedef	void	(OPENGL_API_CALL pglLoadMatrixd)(const	GLdouble* m);
typedef	void	(OPENGL_API_CALL pglLoadMatrixf)(const	GLfloat* m);
typedef	void	(OPENGL_API_CALL pglLoadName)(GLuint	name);
typedef	void	(OPENGL_API_CALL pglLogicOp)(GLenum	opcode);
typedef	void	(OPENGL_API_CALL pglMap1d)(GLenum	target, GLdouble	u1, GLdouble	u2, GLint	stride, GLint	order, const	GLdouble* points);
typedef	void	(OPENGL_API_CALL pglMap1f)(GLenum	target, GLfloat	u1, GLfloat	u2, GLint	stride, GLint	order, const	GLfloat* points);
typedef	void	(OPENGL_API_CALL pglMap2d)(GLenum	target, GLdouble	u1, GLdouble	u2, GLint	ustride, GLint	uorder, GLdouble	v1, GLdouble	v2, GLint	vstride, GLint	vorder, const	GLdouble* points);
typedef	void	(OPENGL_API_CALL pglMap2f)(GLenum	target, GLfloat	u1, GLfloat	u2, GLint	ustride, GLint	uorder, GLfloat	v1, GLfloat	v2, GLint	vstride, GLint	vorder, const	GLfloat* points);
typedef	void	(OPENGL_API_CALL pglMapGrid1d)(GLint	un, GLdouble	u1, GLdouble	u2);
typedef	void	(OPENGL_API_CALL pglMapGrid1f)(GLint	un, GLfloat	u1, GLfloat	u2);
typedef	void	(OPENGL_API_CALL pglMapGrid2d)(GLint	un, GLdouble	u1, GLdouble	u2, GLint	vn, GLdouble	v1, GLdouble	v2);
typedef	void	(OPENGL_API_CALL pglMapGrid2f)(GLint	un, GLfloat	u1, GLfloat	u2, GLint	vn, GLfloat	v1, GLfloat	v2);
typedef	void	(OPENGL_API_CALL pglMaterialf)(GLenum	face, GLenum	pname, GLfloat	param);
typedef	void	(OPENGL_API_CALL pglMaterialfv)(GLenum	face, GLenum	pname, const	GLfloat* params);
typedef	void	(OPENGL_API_CALL pglMateriali)(GLenum	face, GLenum	pname, GLint	param);
typedef	void	(OPENGL_API_CALL pglMaterialiv)(GLenum	face, GLenum	pname, const	GLint* params);
typedef	void	(OPENGL_API_CALL pglMatrixMode)(GLenum	mode);
typedef	void	(OPENGL_API_CALL pglMultMatrixd)(const	GLdouble* m);
typedef	void	(OPENGL_API_CALL pglMultMatrixf)(const	GLfloat* m);
typedef	void	(OPENGL_API_CALL pglNewList)(GLuint	list, GLenum	mode);
typedef	void	(OPENGL_API_CALL pglNormal3b)(GLbyte	nx, GLbyte	ny, GLbyte	nz);
typedef	void	(OPENGL_API_CALL pglNormal3bv)(const	GLbyte* v);
typedef	void	(OPENGL_API_CALL pglNormal3d)(GLdouble	nx, GLdouble	ny, GLdouble	nz);
typedef	void	(OPENGL_API_CALL pglNormal3dv)(const	GLdouble* v);
typedef	void	(OPENGL_API_CALL pglNormal3f)(GLfloat	nx, GLfloat	ny, GLfloat	nz);
typedef	void	(OPENGL_API_CALL pglNormal3fv)(const	GLfloat* v);
typedef	void	(OPENGL_API_CALL pglNormal3i)(GLint	nx, GLint	ny, GLint	nz);
typedef	void	(OPENGL_API_CALL pglNormal3iv)(const	GLint* v);
typedef	void	(OPENGL_API_CALL pglNormal3s)(GLshort	nx, GLshort	ny, GLshort	nz);
typedef	void	(OPENGL_API_CALL pglNormal3sv)(const	GLshort* v);
typedef	void	(OPENGL_API_CALL pglNormalPointer)(GLenum	type, GLsizei	stride, const	GLvoid* pointer);
typedef	void	(OPENGL_API_CALL pglOrtho)(GLdouble	left, GLdouble	right, GLdouble	bottom, GLdouble	top, GLdouble	zNear, GLdouble	zFar);
typedef	void	(OPENGL_API_CALL pglPassThrough)(GLfloat	token);
typedef	void	(OPENGL_API_CALL pglPixelMapfv)(GLenum	map, GLsizei	mapsize, const	GLfloat* values);
typedef	void	(OPENGL_API_CALL pglPixelMapuiv)(GLenum	map, GLsizei	mapsize, const	GLuint* values);
typedef	void	(OPENGL_API_CALL pglPixelMapusv)(GLenum	map, GLsizei	mapsize, const	GLushort* values);
typedef	void	(OPENGL_API_CALL pglPixelStoref)(GLenum	pname, GLfloat	param);
typedef	void	(OPENGL_API_CALL pglPixelStorei)(GLenum	pname, GLint	param);
typedef	void	(OPENGL_API_CALL pglPixelTransferf)(GLenum	pname, GLfloat	param);
typedef	void	(OPENGL_API_CALL pglPixelTransferi)(GLenum	pname, GLint	param);
typedef	void	(OPENGL_API_CALL pglPixelZoom)(GLfloat	xfactor, GLfloat	yfactor);
typedef	void	(OPENGL_API_CALL pglPointSize)(GLfloat	size);
typedef	void	(OPENGL_API_CALL pglPolygonMode)(GLenum	face, GLenum	mode);
typedef	void	(OPENGL_API_CALL pglPolygonOffset)(GLfloat	factor, GLfloat	units);
typedef	void	(OPENGL_API_CALL pglPolygonStipple)(const	GLubyte* mask);
typedef	void	(OPENGL_API_CALL pglPopAttrib)(void);
typedef	void	(OPENGL_API_CALL pglPopClientAttrib)(void);
typedef	void	(OPENGL_API_CALL pglPopMatrix)(void);
typedef	void	(OPENGL_API_CALL pglPopName)(void);
typedef	void	(OPENGL_API_CALL pglPrioritizeTextures)(GLsizei	n, const	GLuint* textures, const	GLclampf* priorities);
typedef	void	(OPENGL_API_CALL pglPushAttrib)(GLbitfield	mask);
typedef	void	(OPENGL_API_CALL pglPushClientAttrib)(GLbitfield	mask);
typedef	void	(OPENGL_API_CALL pglPushMatrix)(void);
typedef	void	(OPENGL_API_CALL pglPushName)(GLuint	name);
typedef	void	(OPENGL_API_CALL pglRasterPos2d)(GLdouble	x, GLdouble	y);
typedef	void	(OPENGL_API_CALL pglRasterPos2dv)(const	GLdouble* v);
typedef	void	(OPENGL_API_CALL pglRasterPos2f)(GLfloat	x, GLfloat	y);
typedef	void	(OPENGL_API_CALL pglRasterPos2fv)(const	GLfloat* v);
typedef	void	(OPENGL_API_CALL pglRasterPos2i)(GLint	x, GLint	y);
typedef	void	(OPENGL_API_CALL pglRasterPos2iv)(const	GLint* v);
typedef	void	(OPENGL_API_CALL pglRasterPos2s)(GLshort	x, GLshort	y);
typedef	void	(OPENGL_API_CALL pglRasterPos2sv)(const	GLshort* v);
typedef	void	(OPENGL_API_CALL pglRasterPos3d)(GLdouble	x, GLdouble	y, GLdouble	z);
typedef	void	(OPENGL_API_CALL pglRasterPos3dv)(const	GLdouble* v);
typedef	void	(OPENGL_API_CALL pglRasterPos3f)(GLfloat	x, GLfloat	y, GLfloat	z);
typedef	void	(OPENGL_API_CALL pglRasterPos3fv)(const	GLfloat* v);
typedef	void	(OPENGL_API_CALL pglRasterPos3i)(GLint	x, GLint	y, GLint	z);
typedef	void	(OPENGL_API_CALL pglRasterPos3iv)(const	GLint* v);
typedef	void	(OPENGL_API_CALL pglRasterPos3s)(GLshort	x, GLshort	y, GLshort	z);
typedef	void	(OPENGL_API_CALL pglRasterPos3sv)(const	GLshort* v);
typedef	void	(OPENGL_API_CALL pglRasterPos4d)(GLdouble	x, GLdouble	y, GLdouble	z, GLdouble	w);
typedef	void	(OPENGL_API_CALL pglRasterPos4dv)(const	GLdouble* v);
typedef	void	(OPENGL_API_CALL pglRasterPos4f)(GLfloat	x, GLfloat	y, GLfloat	z, GLfloat	w);
typedef	void	(OPENGL_API_CALL pglRasterPos4fv)(const	GLfloat* v);
typedef	void	(OPENGL_API_CALL pglRasterPos4i)(GLint	x, GLint	y, GLint	z, GLint	w);
typedef	void	(OPENGL_API_CALL pglRasterPos4iv)(const	GLint* v);
typedef	void	(OPENGL_API_CALL pglRasterPos4s)(GLshort	x, GLshort	y, GLshort	z, GLshort	w);
typedef	void	(OPENGL_API_CALL pglRasterPos4sv)(const	GLshort* v);
typedef	void	(OPENGL_API_CALL pglReadBuffer)(GLenum	mode);
typedef	void	(OPENGL_API_CALL pglReadPixels)(GLint	x, GLint	y, GLsizei	width, GLsizei	height, GLenum	format, GLenum	type, GLvoid* pixels);
typedef	void	(OPENGL_API_CALL pglRectd)(GLdouble	x1, GLdouble	y1, GLdouble	x2, GLdouble	y2);
typedef	void	(OPENGL_API_CALL pglRectdv)(const	GLdouble* v1, const	GLdouble* v2);
typedef	void	(OPENGL_API_CALL pglRectf)(GLfloat	x1, GLfloat	y1, GLfloat	x2, GLfloat	y2);
typedef	void	(OPENGL_API_CALL pglRectfv)(const	GLfloat* v1, const	GLfloat* v2);
typedef	void	(OPENGL_API_CALL pglRecti)(GLint	x1, GLint	y1, GLint	x2, GLint	y2);
typedef	void	(OPENGL_API_CALL pglRectiv)(const	GLint* v1, const	GLint* v2);
typedef	void	(OPENGL_API_CALL pglRects)(GLshort	x1, GLshort	y1, GLshort	x2, GLshort	y2);
typedef	void	(OPENGL_API_CALL pglRectsv)(const	GLshort* v1, const	GLshort* v2);
typedef	GLint(OPENGL_API_CALL pglRenderMode)	(GLenum	mode);
typedef	void	(OPENGL_API_CALL pglRotated)(GLdouble	angle, GLdouble	x, GLdouble	y, GLdouble	z);
typedef	void	(OPENGL_API_CALL pglRotatef)(GLfloat	angle, GLfloat	x, GLfloat	y, GLfloat	z);
typedef	void	(OPENGL_API_CALL pglScaled)(GLdouble	x, GLdouble	y, GLdouble	z);
typedef	void	(OPENGL_API_CALL pglScalef)(GLfloat	x, GLfloat	y, GLfloat	z);
typedef	void	(OPENGL_API_CALL pglScissor)(GLint	x, GLint	y, GLsizei	width, GLsizei	height);
typedef	void	(OPENGL_API_CALL pglSelectBuffer)(GLsizei	size, GLuint* buffer);
typedef	void	(OPENGL_API_CALL pglShadeModel)(GLenum	mode);
typedef	void	(OPENGL_API_CALL pglStencilFunc)(GLenum	func, GLint	ref, GLuint	mask);
typedef	void	(OPENGL_API_CALL pglStencilMask)(GLuint	mask);
typedef	void	(OPENGL_API_CALL pglStencilOp)(GLenum	fail, GLenum	zfail, GLenum	zpass);
typedef	void	(OPENGL_API_CALL pglTexCoord1d)(GLdouble	s);
typedef	void	(OPENGL_API_CALL pglTexCoord1dv)(const	GLdouble* v);
typedef	void	(OPENGL_API_CALL pglTexCoord1f)(GLfloat	s);
typedef	void	(OPENGL_API_CALL pglTexCoord1fv)(const	GLfloat* v);
typedef	void	(OPENGL_API_CALL pglTexCoord1i)(GLint	s);
typedef	void	(OPENGL_API_CALL pglTexCoord1iv)(const	GLint* v);
typedef	void	(OPENGL_API_CALL pglTexCoord1s)(GLshort	s);
typedef	void	(OPENGL_API_CALL pglTexCoord1sv)(const	GLshort* v);
typedef	void	(OPENGL_API_CALL pglTexCoord2d)(GLdouble	s, GLdouble	t);
typedef	void	(OPENGL_API_CALL pglTexCoord2dv)(const	GLdouble* v);
typedef	void	(OPENGL_API_CALL pglTexCoord2f)(GLfloat	s, GLfloat	t);
typedef	void	(OPENGL_API_CALL pglTexCoord2fv)(const	GLfloat* v);
typedef	void	(OPENGL_API_CALL pglTexCoord2i)(GLint	s, GLint	t);
typedef	void	(OPENGL_API_CALL pglTexCoord2iv)(const	GLint* v);
typedef	void	(OPENGL_API_CALL pglTexCoord2s)(GLshort	s, GLshort	t);
typedef	void	(OPENGL_API_CALL pglTexCoord2sv)(const	GLshort* v);
typedef	void	(OPENGL_API_CALL pglTexCoord3d)(GLdouble	s, GLdouble	t, GLdouble	r);
typedef	void	(OPENGL_API_CALL pglTexCoord3dv)(const	GLdouble* v);
typedef	void	(OPENGL_API_CALL pglTexCoord3f)(GLfloat	s, GLfloat	t, GLfloat	r);
typedef	void	(OPENGL_API_CALL pglTexCoord3fv)(const	GLfloat* v);
typedef	void	(OPENGL_API_CALL pglTexCoord3i)(GLint	s, GLint	t, GLint	r);
typedef	void	(OPENGL_API_CALL pglTexCoord3iv)(const	GLint* v);
typedef	void	(OPENGL_API_CALL pglTexCoord3s)(GLshort	s, GLshort	t, GLshort	r);
typedef	void	(OPENGL_API_CALL pglTexCoord3sv)(const	GLshort* v);
typedef	void	(OPENGL_API_CALL pglTexCoord4d)(GLdouble	s, GLdouble	t, GLdouble	r, GLdouble	q);
typedef	void	(OPENGL_API_CALL pglTexCoord4dv)(const	GLdouble* v);
typedef	void	(OPENGL_API_CALL pglTexCoord4f)(GLfloat	s, GLfloat	t, GLfloat	r, GLfloat	q);
typedef	void	(OPENGL_API_CALL pglTexCoord4fv)(const	GLfloat* v);
typedef	void	(OPENGL_API_CALL pglTexCoord4i)(GLint	s, GLint	t, GLint	r, GLint	q);
typedef	void	(OPENGL_API_CALL pglTexCoord4iv)(const	GLint* v);
typedef	void	(OPENGL_API_CALL pglTexCoord4s)(GLshort	s, GLshort	t, GLshort	r, GLshort	q);
typedef	void	(OPENGL_API_CALL pglTexCoord4sv)(const	GLshort* v);
typedef	void	(OPENGL_API_CALL pglTexCoordPointer)(GLint	size, GLenum	type, GLsizei	stride, const	GLvoid* pointer);
typedef	void	(OPENGL_API_CALL pglTexEnvf)(GLenum	target, GLenum	pname, GLfloat	param);
typedef	void	(OPENGL_API_CALL pglTexEnvfv)(GLenum	target, GLenum	pname, const	GLfloat* params);
typedef	void	(OPENGL_API_CALL pglTexEnvi)(GLenum	target, GLenum	pname, GLint	param);
typedef	void	(OPENGL_API_CALL pglTexEnviv)(GLenum	target, GLenum	pname, const	GLint* params);
typedef	void	(OPENGL_API_CALL pglTexGend)(GLenum	coord, GLenum	pname, GLdouble	param);
typedef	void	(OPENGL_API_CALL pglTexGendv)(GLenum	coord, GLenum	pname, const	GLdouble* params);
typedef	void	(OPENGL_API_CALL pglTexGenf)(GLenum	coord, GLenum	pname, GLfloat	param);
typedef	void	(OPENGL_API_CALL pglTexGenfv)(GLenum	coord, GLenum	pname, const	GLfloat* params);
typedef	void	(OPENGL_API_CALL pglTexGeni)(GLenum	coord, GLenum	pname, GLint	param);
typedef	void	(OPENGL_API_CALL pglTexGeniv)(GLenum	coord, GLenum	pname, const	GLint* params);
typedef	void	(OPENGL_API_CALL pglTexImage1D)(GLenum	target, GLint	level, GLint	internalformat, GLsizei	width, GLint	border, GLenum	format, GLenum	type, const	GLvoid* pixels);
typedef	void	(OPENGL_API_CALL pglTexImage2D)(GLenum	target, GLint	level, GLint	internalformat, GLsizei	width, GLsizei	height, GLint	border, GLenum	format, GLenum	type, const	GLvoid* pixels);
typedef	void	(OPENGL_API_CALL pglTexParameterf)(GLenum	target, GLenum	pname, GLfloat	param);
typedef	void	(OPENGL_API_CALL pglTexParameterfv)(GLenum	target, GLenum	pname, const	GLfloat* params);
typedef	void	(OPENGL_API_CALL pglTexParameteri)(GLenum	target, GLenum	pname, GLint	param);
typedef	void	(OPENGL_API_CALL pglTexParameteriv)(GLenum	target, GLenum	pname, const	GLint* params);
typedef	void	(OPENGL_API_CALL pglTexSubImage1D)(GLenum	target, GLint	level, GLint	xoffset, GLsizei	width, GLenum	format, GLenum	type, const	GLvoid* pixels);
typedef	void	(OPENGL_API_CALL pglTexSubImage2D)(GLenum	target, GLint	level, GLint	xoffset, GLint	yoffset, GLsizei	width, GLsizei	height, GLenum	format, GLenum	type, const	GLvoid* pixels);
typedef	void	(OPENGL_API_CALL pglTranslated)(GLdouble	x, GLdouble	y, GLdouble	z);
typedef	void	(OPENGL_API_CALL pglTranslatef)(GLfloat	x, GLfloat	y, GLfloat	z);
typedef	void	(OPENGL_API_CALL pglVertex2d)(GLdouble	x, GLdouble	y);
typedef	void	(OPENGL_API_CALL pglVertex2dv)(const	GLdouble* v);
typedef	void	(OPENGL_API_CALL pglVertex2f)(GLfloat	x, GLfloat	y);
typedef	void	(OPENGL_API_CALL pglVertex2fv)(const	GLfloat* v);
typedef	void	(OPENGL_API_CALL pglVertex2i)(GLint	x, GLint	y);
typedef	void	(OPENGL_API_CALL pglVertex2iv)(const	GLint* v);
typedef	void	(OPENGL_API_CALL pglVertex2s)(GLshort	x, GLshort	y);
typedef	void	(OPENGL_API_CALL pglVertex2sv)(const	GLshort* v);
typedef	void	(OPENGL_API_CALL pglVertex3d)(GLdouble	x, GLdouble	y, GLdouble	z);
typedef	void	(OPENGL_API_CALL pglVertex3dv)(const	GLdouble* v);
typedef	void	(OPENGL_API_CALL pglVertex3f)(GLfloat	x, GLfloat	y, GLfloat	z);
typedef	void	(OPENGL_API_CALL pglVertex3fv)(const	GLfloat* v);
typedef	void	(OPENGL_API_CALL pglVertex3i)(GLint	x, GLint	y, GLint	z);
typedef	void	(OPENGL_API_CALL pglVertex3iv)(const	GLint* v);
typedef	void	(OPENGL_API_CALL pglVertex3s)(GLshort	x, GLshort	y, GLshort	z);
typedef	void	(OPENGL_API_CALL pglVertex3sv)(const	GLshort* v);
typedef	void	(OPENGL_API_CALL pglVertex4d)(GLdouble	x, GLdouble	y, GLdouble	z, GLdouble	w);
typedef	void	(OPENGL_API_CALL pglVertex4dv)(const	GLdouble* v);
typedef	void	(OPENGL_API_CALL pglVertex4f)(GLfloat	x, GLfloat	y, GLfloat	z, GLfloat	w);
typedef	void	(OPENGL_API_CALL pglVertex4fv)(const	GLfloat* v);
typedef	void	(OPENGL_API_CALL pglVertex4i)(GLint	x, GLint	y, GLint	z, GLint	w);
typedef	void	(OPENGL_API_CALL pglVertex4iv)(const	GLint* v);
typedef	void	(OPENGL_API_CALL pglVertex4s)(GLshort	x, GLshort	y, GLshort	z, GLshort	w);
typedef	void	(OPENGL_API_CALL pglVertex4sv)(const	GLshort* v);
typedef	void	(OPENGL_API_CALL pglViewport)(GLint	x, GLint	y, GLsizei	width, GLsizei	height);

extern	pglAccum* glAccum;
extern	pglAlphaFunc* glAlphaFunc;
extern	pglAreTexturesResident* glAreTexturesResident;
extern	pglArrayElement* glArrayElement;
extern	pglBegin* glBegin;
extern	pglBindTexture* glBindTexture;
extern	pglBitmap* glBitmap;
extern	pglBlendFunc* glBlendFunc;
extern	pglCallList* glCallList;
extern	pglCallLists* glCallLists;
extern	pglClear* glClear;
extern	pglClearAccum* glClearAccum;
extern	pglClearColor* glClearColor;
extern	pglClearDepth* glClearDepth;
extern	pglClearIndex* glClearIndex;
extern	pglClearStencil* glClearStencil;
extern	pglClipPlane* glClipPlane;
extern	pglColor3b* glColor3b;
extern	pglColor3bv* glColor3bv;
extern	pglColor3d* glColor3d;
extern	pglColor3dv* glColor3dv;
extern	pglColor3f* glColor3f;
extern	pglColor3fv* glColor3fv;
extern	pglColor3i* glColor3i;
extern	pglColor3iv* glColor3iv;
extern	pglColor3s* glColor3s;
extern	pglColor3sv* glColor3sv;
extern	pglColor3ub* glColor3ub;
extern	pglColor3ubv* glColor3ubv;
extern	pglColor3ui* glColor3ui;
extern	pglColor3uiv* glColor3uiv;
extern	pglColor3us* glColor3us;
extern	pglColor3usv* glColor3usv;
extern	pglColor4b* glColor4b;
extern	pglColor4bv* glColor4bv;
extern	pglColor4d* glColor4d;
extern	pglColor4dv* glColor4dv;
extern	pglColor4f* glColor4f;
extern	pglColor4fv* glColor4fv;
extern	pglColor4i* glColor4i;
extern	pglColor4iv* glColor4iv;
extern	pglColor4s* glColor4s;
extern	pglColor4sv* glColor4sv;
extern	pglColor4ub* glColor4ub;
extern	pglColor4ubv* glColor4ubv;
extern	pglColor4ui* glColor4ui;
extern	pglColor4uiv* glColor4uiv;
extern	pglColor4us* glColor4us;
extern	pglColor4usv* glColor4usv;
extern	pglColorMask* glColorMask;
extern	pglColorMaterial* glColorMaterial;
extern	pglColorPointer* glColorPointer;
extern	pglCopyPixels* glCopyPixels;
extern	pglCopyTexImage1D* glCopyTexImage1D;
extern	pglCopyTexImage2D* glCopyTexImage2D;
extern	pglCopyTexSubImage1D* glCopyTexSubImage1D;
extern	pglCopyTexSubImage2D* glCopyTexSubImage2D;
extern	pglCullFace* glCullFace;
extern	pglDeleteLists* glDeleteLists;
extern	pglDeleteTextures* glDeleteTextures;
extern	pglDepthFunc* glDepthFunc;
extern	pglDepthMask* glDepthMask;
extern	pglDepthRange* glDepthRange;
extern	pglDisable* glDisable;
extern	pglDisableClientState* glDisableClientState;
extern	pglDrawArrays* glDrawArrays;
extern	pglDrawBuffer* glDrawBuffer;
extern	pglDrawElements* glDrawElements;
extern	pglDrawPixels* glDrawPixels;
extern	pglEdgeFlag* glEdgeFlag;
extern	pglEdgeFlagPointer* glEdgeFlagPointer;
extern	pglEdgeFlagv* glEdgeFlagv;
extern	pglEnable* glEnable;
extern	pglEnableClientState* glEnableClientState;
extern	pglEnd* glEnd;
extern	pglEndList* glEndList;
extern	pglEvalCoord1d* glEvalCoord1d;
extern	pglEvalCoord1dv* glEvalCoord1dv;
extern	pglEvalCoord1f* glEvalCoord1f;
extern	pglEvalCoord1fv* glEvalCoord1fv;
extern	pglEvalCoord2d* glEvalCoord2d;
extern	pglEvalCoord2dv* glEvalCoord2dv;
extern	pglEvalCoord2f* glEvalCoord2f;
extern	pglEvalCoord2fv* glEvalCoord2fv;
extern	pglEvalMesh1* glEvalMesh1;
extern	pglEvalMesh2* glEvalMesh2;
extern	pglEvalPoint1* glEvalPoint1;
extern	pglEvalPoint2* glEvalPoint2;
extern	pglFeedbackBuffer* glFeedbackBuffer;
extern	pglFinish* glFinish;
extern	pglFlush* glFlush;
extern	pglFogf* glFogf;
extern	pglFogfv* glFogfv;
extern	pglFogi* glFogi;
extern	pglFogiv* glFogiv;
extern	pglFrontFace* glFrontFace;
extern	pglFrustum* glFrustum;
extern	pglGenLists* glGenLists;
extern	pglGenTextures* glGenTextures;
extern	pglGetBooleanv* glGetBooleanv;
extern	pglGetClipPlane* glGetClipPlane;
extern	pglGetDoublev* glGetDoublev;
extern	pglGetError* glGetError;
extern	pglGetFloatv* glGetFloatv;
extern	pglGetIntegerv* glGetIntegerv;
extern	pglGetLightfv* glGetLightfv;
extern	pglGetLightiv* glGetLightiv;
extern	pglGetMapdv* glGetMapdv;
extern	pglGetMapfv* glGetMapfv;
extern	pglGetMapiv* glGetMapiv;
extern	pglGetMaterialfv* glGetMaterialfv;
extern	pglGetMaterialiv* glGetMaterialiv;
extern	pglGetPixelMapfv* glGetPixelMapfv;
extern	pglGetPixelMapuiv* glGetPixelMapuiv;
extern	pglGetPixelMapusv* glGetPixelMapusv;
extern	pglGetPointerv* glGetPointerv;
extern	pglGetPolygonStipple* glGetPolygonStipple;
extern	pglGetString* glGetString;
extern	pglGetTexEnvfv* glGetTexEnvfv;
extern	pglGetTexEnviv* glGetTexEnviv;
extern	pglGetTexGendv* glGetTexGendv;
extern	pglGetTexGenfv* glGetTexGenfv;
extern	pglGetTexGeniv* glGetTexGeniv;
extern	pglGetTexImage* glGetTexImage;
extern	pglGetTexLevelParameterfv* glGetTexLevelParameterfv;
extern	pglGetTexLevelParameteriv* glGetTexLevelParameteriv;
extern	pglGetTexParameterfv* glGetTexParameterfv;
extern	pglGetTexParameteriv* glGetTexParameteriv;
extern	pglHint* glHint;
extern	pglIndexMask* glIndexMask;
extern	pglIndexPointer* glIndexPointer;
extern	pglIndexd* glIndexd;
extern	pglIndexdv* glIndexdv;
extern	pglIndexf* glIndexf;
extern	pglIndexfv* glIndexfv;
extern	pglIndexi* glIndexi;
extern	pglIndexiv* glIndexiv;
extern	pglIndexs* glIndexs;
extern	pglIndexsv* glIndexsv;
extern	pglIndexub* glIndexub;
extern	pglIndexubv* glIndexubv;
extern	pglInitNames* glInitNames;
extern	pglInterleavedArrays* glInterleavedArrays;
extern	pglIsEnabled* glIsEnabled;
extern	pglIsList* glIsList;
extern	pglIsTexture* glIsTexture;
extern	pglLightModelf* glLightModelf;
extern	pglLightModelfv* glLightModelfv;
extern	pglLightModeli* glLightModeli;
extern	pglLightModeliv* glLightModeliv;
extern	pglLightf* glLightf;
extern	pglLightfv* glLightfv;
extern	pglLighti* glLighti;
extern	pglLightiv* glLightiv;
extern	pglLineStipple* glLineStipple;
extern	pglLineWidth* glLineWidth;
extern	pglListBase* glListBase;
extern	pglLoadIdentity* glLoadIdentity;
extern	pglLoadMatrixd* glLoadMatrixd;
extern	pglLoadMatrixf* glLoadMatrixf;
extern	pglLoadName* glLoadName;
extern	pglLogicOp* glLogicOp;
extern	pglMap1d* glMap1d;
extern	pglMap1f* glMap1f;
extern	pglMap2d* glMap2d;
extern	pglMap2f* glMap2f;
extern	pglMapGrid1d* glMapGrid1d;
extern	pglMapGrid1f* glMapGrid1f;
extern	pglMapGrid2d* glMapGrid2d;
extern	pglMapGrid2f* glMapGrid2f;
extern	pglMaterialf* glMaterialf;
extern	pglMaterialfv* glMaterialfv;
extern	pglMateriali* glMateriali;
extern	pglMaterialiv* glMaterialiv;
extern	pglMatrixMode* glMatrixMode;
extern	pglMultMatrixd* glMultMatrixd;
extern	pglMultMatrixf* glMultMatrixf;
extern	pglNewList* glNewList;
extern	pglNormal3b* glNormal3b;
extern	pglNormal3bv* glNormal3bv;
extern	pglNormal3d* glNormal3d;
extern	pglNormal3dv* glNormal3dv;
extern	pglNormal3f* glNormal3f;
extern	pglNormal3fv* glNormal3fv;
extern	pglNormal3i* glNormal3i;
extern	pglNormal3iv* glNormal3iv;
extern	pglNormal3s* glNormal3s;
extern	pglNormal3sv* glNormal3sv;
extern	pglNormalPointer* glNormalPointer;
extern	pglOrtho* glOrtho;
extern	pglPassThrough* glPassThrough;
extern	pglPixelMapfv* glPixelMapfv;
extern	pglPixelMapuiv* glPixelMapuiv;
extern	pglPixelMapusv* glPixelMapusv;
extern	pglPixelStoref* glPixelStoref;
extern	pglPixelStorei* glPixelStorei;
extern	pglPixelTransferf* glPixelTransferf;
extern	pglPixelTransferi* glPixelTransferi;
extern	pglPixelZoom* glPixelZoom;
extern	pglPointSize* glPointSize;
extern	pglPolygonMode* glPolygonMode;
extern	pglPolygonOffset* glPolygonOffset;
extern	pglPolygonStipple* glPolygonStipple;
extern	pglPopAttrib* glPopAttrib;
extern	pglPopClientAttrib* glPopClientAttrib;
extern	pglPopMatrix* glPopMatrix;
extern	pglPopName* glPopName;
extern	pglPrioritizeTextures* glPrioritizeTextures;
extern	pglPushAttrib* glPushAttrib;
extern	pglPushClientAttrib* glPushClientAttrib;
extern	pglPushMatrix* glPushMatrix;
extern	pglPushName* glPushName;
extern	pglRasterPos2d* glRasterPos2d;
extern	pglRasterPos2dv* glRasterPos2dv;
extern	pglRasterPos2f* glRasterPos2f;
extern	pglRasterPos2fv* glRasterPos2fv;
extern	pglRasterPos2i* glRasterPos2i;
extern	pglRasterPos2iv* glRasterPos2iv;
extern	pglRasterPos2s* glRasterPos2s;
extern	pglRasterPos2sv* glRasterPos2sv;
extern	pglRasterPos3d* glRasterPos3d;
extern	pglRasterPos3dv* glRasterPos3dv;
extern	pglRasterPos3f* glRasterPos3f;
extern	pglRasterPos3fv* glRasterPos3fv;
extern	pglRasterPos3i* glRasterPos3i;
extern	pglRasterPos3iv* glRasterPos3iv;
extern	pglRasterPos3s* glRasterPos3s;
extern	pglRasterPos3sv* glRasterPos3sv;
extern	pglRasterPos4d* glRasterPos4d;
extern	pglRasterPos4dv* glRasterPos4dv;
extern	pglRasterPos4f* glRasterPos4f;
extern	pglRasterPos4fv* glRasterPos4fv;
extern	pglRasterPos4i* glRasterPos4i;
extern	pglRasterPos4iv* glRasterPos4iv;
extern	pglRasterPos4s* glRasterPos4s;
extern	pglRasterPos4sv* glRasterPos4sv;
extern	pglReadBuffer* glReadBuffer;
extern	pglReadPixels* glReadPixels;
extern	pglRectd* glRectd;
extern	pglRectdv* glRectdv;
extern	pglRectf* glRectf;
extern	pglRectfv* glRectfv;
extern	pglRecti* glRecti;
extern	pglRectiv* glRectiv;
extern	pglRects* glRects;
extern	pglRectsv* glRectsv;
extern	pglRenderMode* glRenderMode;
extern	pglRotated* glRotated;
extern	pglRotatef* glRotatef;
extern	pglScaled* glScaled;
extern	pglScalef* glScalef;
extern	pglScissor* glScissor;
extern	pglSelectBuffer* glSelectBuffer;
extern	pglShadeModel* glShadeModel;
extern	pglStencilFunc* glStencilFunc;
extern	pglStencilMask* glStencilMask;
extern	pglStencilOp* glStencilOp;
extern	pglTexCoord1d* glTexCoord1d;
extern	pglTexCoord1dv* glTexCoord1dv;
extern	pglTexCoord1f* glTexCoord1f;
extern	pglTexCoord1fv* glTexCoord1fv;
extern	pglTexCoord1i* glTexCoord1i;
extern	pglTexCoord1iv* glTexCoord1iv;
extern	pglTexCoord1s* glTexCoord1s;
extern	pglTexCoord1sv* glTexCoord1sv;
extern	pglTexCoord2d* glTexCoord2d;
extern	pglTexCoord2dv* glTexCoord2dv;
extern	pglTexCoord2f* glTexCoord2f;
extern	pglTexCoord2fv* glTexCoord2fv;
extern	pglTexCoord2i* glTexCoord2i;
extern	pglTexCoord2iv* glTexCoord2iv;
extern	pglTexCoord2s* glTexCoord2s;
extern	pglTexCoord2sv* glTexCoord2sv;
extern	pglTexCoord3d* glTexCoord3d;
extern	pglTexCoord3dv* glTexCoord3dv;
extern	pglTexCoord3f* glTexCoord3f;
extern	pglTexCoord3fv* glTexCoord3fv;
extern	pglTexCoord3i* glTexCoord3i;
extern	pglTexCoord3iv* glTexCoord3iv;
extern	pglTexCoord3s* glTexCoord3s;
extern	pglTexCoord3sv* glTexCoord3sv;
extern	pglTexCoord4d* glTexCoord4d;
extern	pglTexCoord4dv* glTexCoord4dv;
extern	pglTexCoord4f* glTexCoord4f;
extern	pglTexCoord4fv* glTexCoord4fv;
extern	pglTexCoord4i* glTexCoord4i;
extern	pglTexCoord4iv* glTexCoord4iv;
extern	pglTexCoord4s* glTexCoord4s;
extern	pglTexCoord4sv* glTexCoord4sv;
extern	pglTexCoordPointer* glTexCoordPointer;
extern	pglTexEnvf* glTexEnvf;
extern	pglTexEnvfv* glTexEnvfv;
extern	pglTexEnvi* glTexEnvi;
extern	pglTexEnviv* glTexEnviv;
extern	pglTexGend* glTexGend;
extern	pglTexGendv* glTexGendv;
extern	pglTexGenf* glTexGenf;
extern	pglTexGenfv* glTexGenfv;
extern	pglTexGeni* glTexGeni;
extern	pglTexGeniv* glTexGeniv;
extern	pglTexImage1D* glTexImage1D;
extern	pglTexImage2D* glTexImage2D;
extern	pglTexParameterf* glTexParameterf;
extern	pglTexParameterfv* glTexParameterfv;
extern	pglTexParameteri* glTexParameteri;
extern	pglTexParameteriv* glTexParameteriv;
extern	pglTexSubImage1D* glTexSubImage1D;
extern	pglTexSubImage2D* glTexSubImage2D;
extern	pglTranslated* glTranslated;
extern	pglTranslatef* glTranslatef;
extern	pglVertex2d* glVertex2d;
extern	pglVertex2dv* glVertex2dv;
extern	pglVertex2f* glVertex2f;
extern	pglVertex2fv* glVertex2fv;
extern	pglVertex2i* glVertex2i;
extern	pglVertex2iv* glVertex2iv;
extern	pglVertex2s* glVertex2s;
extern	pglVertex2sv* glVertex2sv;
extern	pglVertex3d* glVertex3d;
extern	pglVertex3dv* glVertex3dv;
extern	pglVertex3f* glVertex3f;
extern	pglVertex3fv* glVertex3fv;
extern	pglVertex3i* glVertex3i;
extern	pglVertex3iv* glVertex3iv;
extern	pglVertex3s* glVertex3s;
extern	pglVertex3sv* glVertex3sv;
extern	pglVertex4d* glVertex4d;
extern	pglVertex4dv* glVertex4dv;
extern	pglVertex4f* glVertex4f;
extern	pglVertex4fv* glVertex4fv;
extern	pglVertex4i* glVertex4i;
extern	pglVertex4iv* glVertex4iv;
extern	pglVertex4s* glVertex4s;
extern	pglVertex4sv* glVertex4sv;
extern	pglViewport* glViewport;

#endif     