cmake_minimum_required(VERSION 3.8)

add_executable(03_Window "03_Window.cpp")
target_link_libraries(03_Window LDL)

add_executable(04_Triangle "04_Triangle.cpp")
target_link_libraries(04_Triangle LDL)

add_executable(05_Shaders "05_Shaders.cpp")
target_link_libraries(05_Shaders LDL)

add_executable(06_Textures "06_Textures.cpp")
target_link_libraries(06_Textures LDL)

add_executable(07_Transformations "07_Transformations.cpp")
target_link_libraries(07_Transformations LDL)

add_executable(08_CoordinateSystems "08_CoordinateSystems.cpp")
target_link_libraries(08_CoordinateSystems LDL)