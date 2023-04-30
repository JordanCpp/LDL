cmake_minimum_required(VERSION 3.8)

include_directories("include")

add_library(ArcanumLib STATIC
"source/Game/Engine.cpp" 
"source/Game/Settings.cpp"
"source/Managers/PathManager.cpp"
"source/Formats/Art.cpp"
"source/Graphics/Image.cpp"
"source/Graphics/Sprite.cpp"
"source/Loaders/ArtLoader.cpp"
"source/Managers/SpriteManager.cpp")

add_executable(Arcanum 
"main.cpp")

target_link_libraries(Arcanum ArcanumLib LDL)

add_subdirectory("test")