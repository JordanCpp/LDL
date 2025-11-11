
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

add_executable(SDL3_01_Window "SDL3_01_Window.c")
target_link_libraries(SDL3_01_Window LDL_SDL3)

add_executable(SDL3_02_Renderer "SDL3_02_Renderer.c")
target_link_libraries(SDL3_02_Renderer LDL_SDL3)

add_executable(SDL3_03_Clear "SDL3_03_Clear.c")
target_link_libraries(SDL3_03_Clear LDL_SDL3)

add_executable(SDL3_04_Surface "SDL3_04_Surface.c")
target_link_libraries(SDL3_04_Surface LDL_SDL3)

add_executable(SDL3_05_Texture "SDL3_05_Texture.c")
target_link_libraries(SDL3_05_Texture LDL_SDL3)
