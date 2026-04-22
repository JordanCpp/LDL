
cmake_minimum_required(VERSION 3.12)

project(LDL)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)  
    add_compile_options("/analyze")
endif()

set(LDL_STATIC_LIBRARY true)
add_definitions(-DLDL_STATIC_LIBRARY)

include_directories("include")
include_directories("source")

file(GLOB SOURCE "source/LDL/*.c" "source/LDL/Win9x/*.c" "source/LDL/OpenGL/*.c")
add_library(LDL ${SOURCE})
target_link_libraries(LDL opengl32)

add_executable(main "main.c")
target_link_libraries(main LDL)

add_executable(GLMain "GLMain.c")
target_link_libraries(GLMain LDL)
