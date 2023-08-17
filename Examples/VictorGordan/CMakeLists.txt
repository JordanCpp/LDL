add_subdirectory("GordanLib")

include_directories(include)

add_executable(01_CreateWindow "01_CreateWindow.cpp")
target_link_libraries(01_CreateWindow LDL)

add_executable(02_Triangle "02_Triangle.cpp")
target_link_libraries(02_Triangle LDL)

add_executable(03_Indices "03_Indices.cpp")
target_link_libraries(03_Indices LDL)

add_executable(05_Shaders "05_Shaders.cpp")
target_link_libraries(05_Shaders LDL GordonLib)

add_executable(06_Textures "06_Textures.cpp")
target_link_libraries(06_Textures LDL GordonLib)

add_executable(07_Going3D "07_Going3D.cpp")
target_link_libraries(07_Going3D LDL GordonLib)

add_executable(08_Camera "08_Camera.cpp")
target_link_libraries(08_Camera LDL GordonLib)

add_executable(09_Lighting "09_Lighting.cpp")
target_link_libraries(09_Lighting LDL GordonLib)