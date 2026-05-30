
set(LDL_EXAMPLES
    "OpenGL3_AnimatedWaterSurface"
    "OpenGL3_ColoredCubeMouse"
    "OpenGL3_DancingTorus"
    "OpenGL3_FloatingSpheres"
    "OpenGL3_ParticleSystem"
    "OpenGL3_PlanetWithMoon"
    "OpenGL3_RotatingCube"
    "OpenGL3_TexturedCubeLighting"
    "OpenGL3_TexturedSphere"
    "OpenGL3_Triangle"
)

foreach(EXE_NAME ${LDL_EXAMPLES})
    add_executable(${EXE_NAME} ${EXE_NAME}.c)
    target_link_libraries(${EXE_NAME} LDL)
endforeach()
