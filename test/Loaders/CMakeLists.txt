cmake_minimum_required(VERSION 3.8)

add_executable(ImageBufferLoader "ImageBufferLoader.cpp")
target_link_libraries(ImageBufferLoader LDL)

add_executable(FontBufferLoader "FontBufferLoader.cpp")
target_link_libraries(FontBufferLoader LDL)