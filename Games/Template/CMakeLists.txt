cmake_minimum_required(VERSION 3.8)

include_directories("include")

add_library(DisLib STATIC
"source/Game/Engine.cpp" 
"source/Game/Settings.cpp")

add_executable(Disciples 
"main.cpp")

target_link_libraries(Disciples DisLib LDL)

add_subdirectory("test")