cmake_minimum_required(VERSION 3.8)

add_executable(01_Context "01_Context.cpp")
target_link_libraries(01_Context LDL)

add_executable(02_Triangle "02_Triangle.cpp")
target_link_libraries(02_Triangle LDL)