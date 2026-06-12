
set(LDL_EXAMPLES
    "OpenGL1_Animated3DTerrain"
    "OpenGL1_FallingParticles"
    "OpenGL1_FireworksShow"
    "OpenGL1_FirstPersonMaze"
    "OpenGL1_Interactive3DCube"
    "OpenGL1_Move"
    "OpenGL1_RectColor"
    "OpenGL1_RectTexture"
    "OpenGL1_Rotate"
    "OpenGL1_RotatingColorfulTorus"
    "OpenGL1_Rotating3DCube"
    "OpenGL1_SnowfallParticles"
    "OpenGL1_SolarSystem"
    "OpenGL1_TargetShooter"
    "OpenGL1_TerrainFlight"
    "OpenGL1_WaterWaveSimulation"
    "OpenGL1_3DAtomModel"
)

foreach(EXE_NAME ${LDL_EXAMPLES})
    add_executable(${EXE_NAME} ${EXE_NAME}.c)
    target_link_libraries(${EXE_NAME} LDL)
endforeach()
