
set(LDL_EXAMPLES
    "OpenGL2_AnimatedWater"
    "OpenGL2_LightingShaderCube"
    "OpenGL2_ShaderCube"
    "OpenGL2_SolarSystem"
    "OpenGL2_TexturedTerrain"
)

foreach(EXE_NAME ${LDL_EXAMPLES})
    add_executable(${EXE_NAME} ${EXE_NAME}.c)
    target_link_libraries(${EXE_NAME} LDL)
endforeach()
