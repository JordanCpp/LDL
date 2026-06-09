
set(LDL_EXAMPLES
    "2DRenderC++_BoidsAlgorithm"
    "2DRenderC++_CellularAutomata"
    "2DRenderC++_FogofWar"
    "2DRenderC++_FractalTree"
    "2DRenderC++_FractalTree2"
    "2DRenderC++_Kaleidoscope"
    "2DRenderC++_ParticleExplosion"
    "2DRenderC++_ParticleSystem"
    "2DRenderC++_ProceduralLandscape"
    "2DRenderC++_RainEffect"
    "2DRenderC++_Spirograph"
    "2DRenderC++_Spirograph2"
    "2DRenderC++_VerletCloth"
)

foreach(EXE_NAME ${LDL_EXAMPLES})
    add_executable(${EXE_NAME} ${EXE_NAME}.cpp)
    target_link_libraries(${EXE_NAME} LDL)
endforeach()
