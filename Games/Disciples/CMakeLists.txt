cmake_minimum_required(VERSION 3.8)

include_directories("include")

add_executable(Disciples 
"main.cpp" 
"source/Game/Engine.cpp" 
"source/Game/Settings.cpp")

target_link_libraries(Disciples LDL)