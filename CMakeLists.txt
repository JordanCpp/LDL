project(LDL_Proj)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)  
endif()

if (WIN32)
    set(libs gdi32 user32 winmm opengl32)
elseif (UNIX AND NOT APPLE)
    set(libs X11 GL dl)
endif()

add_executable(test "test.cpp")
target_link_libraries(test ${libs})

add_subdirectory("examples")