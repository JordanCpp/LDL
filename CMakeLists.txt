cmake_minimum_required(VERSION 3.8)

project(LibLdl)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

include_directories("include")

add_library(LDL STATIC
"source/Core/TestEqual.cpp" 
"source/Core/RuntimeError.cpp"
"source/Graphics/Base/BaseWindow.cpp"
"source/Graphics/Base/BaseRender.cpp"
"source/Graphics/CpuImage.cpp"
"source/Graphics/Primitives/Color.cpp"
"source/Events/Eventer.cpp"
"source/Allocators/FixedLinear.cpp"
"source/Loaders/ImageBufferLoader.cpp"
"source/Graphics/GL1Render.cpp")

if (WIN32)
  target_sources(LDL PRIVATE
  "source/Platforms/Windows/Graphics/MainWindow.cpp"
  "source/Platforms/Windows/Graphics/GL1Window.cpp")
elseif(UNIX AND NOT APPLE)
  target_sources(LDL PRIVATE
  "source/Platforms/Linux/Graphics/Window.cpp")
endif() 

if (WIN32)
  target_link_libraries(LDL opengl32)
endif()

add_subdirectory("test")
add_subdirectory("Examples")