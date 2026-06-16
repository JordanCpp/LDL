
set(LDL_EXAMPLES
    "C++98_OpenGL3_Triangle"
    "C++98_OpenGL3_Texture"
    "C++98_OpenGL3_RandomTriangles"
    "C++98_OpenGL3_ColorFan"
    "C++98_OpenGL3_Checkerboard"
    "C++98_OpenGL3_ArchimedeanSpiral"
    "C++98_OpenGL3_StarWithAlphaBlending"
    "C++98_OpenGL3_BezierCurveWithControlPoints"
    "C++98_OpenGL3_TextureAtlasAnimation"
    "C++98_OpenGL3_FlyingCameraOverTerrain"
    "C++98_OpenGL3_FlyingCameraWithZoomOverTerrain"
    "C++98_OpenGL3_LargeTerrainWithFlyingCamera"
    "C++98_OpenGL3_FirstPersonCameraOverTerrain"
)

foreach(EXE_NAME ${LDL_EXAMPLES})
    add_executable(${EXE_NAME} ${EXE_NAME}.cpp)
    target_link_libraries(${EXE_NAME} LDL)
endforeach()
