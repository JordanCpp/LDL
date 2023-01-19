cmake_minimum_required(VERSION 3.8)

add_executable(PerfPixelPainter "PixelPainter.cpp")
target_link_libraries(PerfPixelPainter LDL)