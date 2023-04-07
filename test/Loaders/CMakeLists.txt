cmake_minimum_required(VERSION 3.8)

add_executable(ImageLoader "ImageLoader.cpp")
target_link_libraries(ImageLoader LDL)

add_executable(FontLoader "FontLoader.cpp")
target_link_libraries(FontLoader LDL)

add_executable(SoundLoader "SoundLoader.cpp")
target_link_libraries(SoundLoader LDL)