
set(LDL_EXAMPLES
    "C89_OpenGL2_AnimatedWater"
    "C89_OpenGL2_LightingShaderCube"
    "C89_OpenGL2_ShaderCube"
    "C89_OpenGL2_SolarSystem"
    "C89_OpenGL2_TexturedTerrain"
)

foreach(EXE_NAME ${LDL_EXAMPLES})
    add_executable(${EXE_NAME} ${EXE_NAME}.c)
    target_link_libraries(${EXE_NAME} LDL)
endforeach()
