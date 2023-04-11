cmake_minimum_required(VERSION 3.8)

add_executable(NumberToString "NumberToString.cpp")
target_link_libraries(NumberToString LDL)

add_executable(Directory "Directory.cpp")
target_link_libraries(Directory LDL)