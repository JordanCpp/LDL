
add_executable(01_API_Window "01_API_Window.c")
target_link_libraries(01_API_Window LDL)

add_executable(02_API_Render "02_API_Render.c")
target_link_libraries(02_API_Render LDL)

add_executable(03_API_Clear "03_API_Clear.c")
target_link_libraries(03_API_Clear LDL)

add_executable(04_API_Line "04_API_Line.c")
target_link_libraries(04_API_Line LDL)

add_executable(05_API_Fill "05_API_Fill.c")
target_link_libraries(05_API_Fill LDL)

add_executable(06_API_Texture "06_API_Texture.c")
target_link_libraries(06_API_Texture LDL)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/LDL_24_256.bmp" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/LDL_24_256.bmp" DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
