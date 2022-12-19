cmake_minimum_required(VERSION 3.8)

add_executable(GpuRenderScreen "GpuRenderScreen.cpp")
target_link_libraries(GpuRenderScreen LDL)