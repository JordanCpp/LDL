
set(LDL_EXAMPLES
    "C++98_GL3_Triangle"
    "C++98_GL3_Texture"
    "C++98_GL3_RandomTriangles"
    "C++98_GL3_ColorFan"
    "C++98_GL3_Checkerboard"
    "C++98_GL3_ArchimedeanSpiral"
    "C++98_GL3_StarWithAlphaBlending"
    "C++98_GL3_BezierCurveWithControlPoints"
    "C++98_GL3_TextureAtlasAnimation"
    "C++98_GL3_FlyingCameraOverTerrain"
    "C++98_GL3_FlyingCameraWithZoomOverTerrain"
    "C++98_GL3_LargeTerrainWithFlyingCamera"
    "C++98_GL3_FirstPersonCameraOverTerrain"
)

foreach(EXE_NAME ${LDL_EXAMPLES})
    add_executable(${EXE_NAME} ${EXE_NAME}.cpp)
    target_link_libraries(${EXE_NAME} LDL)
endforeach()

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/ba_rock_hm.jpg" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/ba_rock_hm.jpg" DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
