
set(LDL_EXAMPLES
    "C++98_2DRender_BoidsAlgorithm"
    "C++98_2DRender_CellularAutomata"
    "C++98_2DRender_FogofWar"
    "C++98_2DRender_FractalTree"
    "C++98_2DRender_FractalTree2"
    "C++98_2DRender_Kaleidoscope"
    "C++98_2DRender_ParticleExplosion"
    "C++98_2DRender_ParticleSystem"
    "C++98_2DRender_ProceduralLandscape"
    "C++98_2DRender_RainEffect"
    "C++98_2DRender_Spirograph"
    "C++98_2DRender_Spirograph2"
    "C++98_2DRender_VerletCloth"
)

foreach(EXE_NAME ${LDL_EXAMPLES})
    add_executable(${EXE_NAME} ${EXE_NAME}.cpp)
    target_link_libraries(${EXE_NAME} LDL)
endforeach()
