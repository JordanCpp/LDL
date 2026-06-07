
set(LDL_EXAMPLES
    "Render2D_BoidsAlgorithm"
    "Render2D_CellularAutomata"
    "Render2D_FogofWar"
    "Render2D_FractalTree"
    "Render2D_FractalTree2"
    "Render2D_Kaleidoscope"
    "Render2D_ParticleExplosion"
    "Render2D_ParticleSystem"
    "Render2D_ProceduralLandscape"
    "Render2D_RainEffect"
    "Render2D_Spirograph"
    "Render2D_Spirograph2"
    "Render2D_VerletCloth"
)

foreach(EXE_NAME ${LDL_EXAMPLES})
    add_executable(${EXE_NAME} ${EXE_NAME}.cpp)
    target_link_libraries(${EXE_NAME} LDL)
endforeach()
