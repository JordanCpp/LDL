
set(LDL_EXAMPLES
    "C89_OpenGL1_Animated3DTerrain"
    "C89_OpenGL1_FallingParticles"
    "C89_OpenGL1_FireworksShow"
    "C89_OpenGL1_FirstPersonMaze"
    "C89_OpenGL1_Interactive3DCube"
    "C89_OpenGL1_Move"
    "C89_OpenGL1_RectColor"
    "C89_OpenGL1_RectTexture"
    "C89_OpenGL1_Rotate"
    "C89_OpenGL1_RotatingColorfulTorus"
    "C89_OpenGL1_Rotating3DCube"
    "C89_OpenGL1_SnowfallParticles"
    "C89_OpenGL1_SolarSystem"
    "C89_OpenGL1_TargetShooter"
    "C89_OpenGL1_TerrainFlight"
    "C89_OpenGL1_WaterWaveSimulation"
    "C89_OpenGL1_3DAtomModel"
)

foreach(EXE_NAME ${LDL_EXAMPLES})
    add_executable(${EXE_NAME} ${EXE_NAME}.c)
    target_link_libraries(${EXE_NAME} LDL)
endforeach()
