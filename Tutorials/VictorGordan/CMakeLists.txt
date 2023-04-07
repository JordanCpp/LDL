cmake_minimum_required(VERSION 3.8)

include_directories("GordonLib/include")

add_library(GordonLib STATIC
"GordonLib/source/EBO.cpp"
"GordonLib/source/shaderClass.cpp"
"GordonLib/source/Texture2D.cpp"
"GordonLib/source/VAO.cpp"
"GordonLib/source/VBO.cpp")	

add_subdirectory("YoutubeOpenGL 6 - Textures")
add_subdirectory("YoutubeOpenGL 7 - Going 3D")