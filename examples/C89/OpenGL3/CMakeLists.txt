
set(LDL_EXAMPLES
    "C89_OpenGL3_AnimatedWaterSurface"
    "C89_OpenGL3_ColoredCubeMouse"
    "C89_OpenGL3_DancingTorus"
    "C89_OpenGL3_FloatingSpheres"
    "C89_OpenGL3_ParticleSystem"
    "C89_OpenGL3_PlanetWithMoon"
    "C89_OpenGL3_RotatingCube"
    "C89_OpenGL3_TexturedCubeLighting"
    "C89_OpenGL3_TexturedSphere"
    "C89_OpenGL3_Triangle"
)

foreach(EXE_NAME ${LDL_EXAMPLES})
    add_executable(${EXE_NAME} ${EXE_NAME}.c)
    target_link_libraries(${EXE_NAME} LDL)
endforeach()
