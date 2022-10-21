cmake_minimum_required(VERSION 3.8)

add_executable(Allocator "Allocator.cpp")
target_link_libraries(Allocator LDL)