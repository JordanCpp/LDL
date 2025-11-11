
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

add_executable(SDL1_01_Window "SDL1_01_Window.c")
target_link_libraries(SDL1_01_Window LDL_SDL)

add_executable(SDL1_02_LoadBmp "SDL1_02_LoadBmp.c")
target_link_libraries(SDL1_02_LoadBmp LDL_SDL)

add_executable(SDL1_03_ColorScreen "SDL1_03_ColorScreen.c")
target_link_libraries(SDL1_03_ColorScreen LDL_SDL)
