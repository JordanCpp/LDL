project(LDL_Proj)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)  
endif()

include_directories("include")

set(libs winmm opengl32)

add_executable(test "test.cpp")
target_link_libraries(test ${libs})

add_subdirectory("examples")
add_subdirectory("OpenGL1")
add_subdirectory("OpenGL3")
