project(LDL_Proj)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)  
endif()

include_directories("include")

add_executable(test "test.cpp")
target_link_libraries(test winmm opengl32)

add_subdirectory("OpenGL1")
