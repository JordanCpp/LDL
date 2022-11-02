cmake_minimum_required(VERSION 3.8)

add_executable(Game 
"main.cpp" 
"Engine.cpp")

target_link_libraries(Game LDL)