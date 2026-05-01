
add_executable(OpenGL2_ShaderCube "OpenGL2_ShaderCube.c")
target_link_libraries(OpenGL2_ShaderCube LDL)

add_executable(OpenGL2_LightingShaderCube "OpenGL2_LightingShaderCube.c")
target_link_libraries(OpenGL2_LightingShaderCube LDL)

add_executable(OpenGL2_TexturedTerrain "OpenGL2_TexturedTerrain.c")
target_link_libraries(OpenGL2_TexturedTerrain LDL)

add_executable(OpenGL2_SolarSystem "OpenGL2_SolarSystem.c")
target_link_libraries(OpenGL2_SolarSystem LDL)

add_executable(OpenGL2_AnimatedWater "OpenGL2_AnimatedWater.c")
target_link_libraries(OpenGL2_AnimatedWater LDL)
