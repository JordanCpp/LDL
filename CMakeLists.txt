cmake_minimum_required(VERSION 3.8)

project(LibLdl)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

include_directories("include")

add_library(LDL STATIC
"source/Core/TestEqual.cpp" 
"source/Core/RuntimeError.cpp"
"source/Graphics/BaseWindow.cpp"
"source/Events/Eventer.cpp"
"source/Allocators/FixedLinear.cpp")

if (WIN32)
  target_sources(LDL PRIVATE
  "source/Platforms/Windows/Graphics/Window.cpp")
elseif(UNIX AND NOT APPLE)
  target_sources(LDL PRIVATE
  "source/Platforms/Linux/Graphics/Window.cpp")
endif() 

add_subdirectory("test")