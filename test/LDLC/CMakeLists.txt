cmake_minimum_required(VERSION 3.8)

add_executable(LDL_WindowTest "LDL_WindowTest.cpp")
target_link_libraries(LDL_WindowTest LDL)

add_executable(LDL_RenderTest "LDL_RenderTest.cpp")
target_link_libraries(LDL_RenderTest LDL)