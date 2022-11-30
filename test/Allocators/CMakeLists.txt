cmake_minimum_required(VERSION 3.8)

add_executable(Allocator "Allocator.cpp")
target_link_libraries(Allocator LDL)

add_executable(FixedLinear "FixedLinear.cpp")
target_link_libraries(FixedLinear LDL)

add_executable(ObjectPool "ObjectPool.cpp")
target_link_libraries(ObjectPool LDL)