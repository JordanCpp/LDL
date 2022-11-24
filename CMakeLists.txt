cmake_minimum_required(VERSION 3.8)

project(LibLdl)

set(LDL_GPU_SUPPORT_OPENGL1 true)
add_definitions(-DLDL_GPU_SUPPORT_OPENGL1)

#set(LDL_GPU_SUPPORT_DIRECTX9 true)
#add_definitions(-DLDL_GPU_SUPPORT_DIRECTX9)

#set(LDL_GPU_SUPPORT_DIRECTX5 true)
#add_definitions(-DLDL_GPU_SUPPORT_DIRECTX5)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

include_directories("include")

if (LDL_GPU_SUPPORT_DIRECTX9)
  include_directories("dependencies/dx9sdk/Include")
  link_directories("dependencies/dx9sdk/Lib/x86")
endif() 

if (LDL_GPU_SUPPORT_DIRECTX5)
  include_directories("dependencies/dx5sdk/Include")
  link_directories("dependencies/dx5sdk/Lib")
endif() 

add_library(LDL STATIC
"source/Core/TestEqual.cpp" 
"source/Core/RuntimeError.cpp"
"source/Core/IntegerToString.cpp"
"source/Core/FileInfo.cpp"
"source/Graphics/Base/BaseWindow.cpp"
"source/Graphics/Base/BaseRender.cpp"
"source/Graphics/Cpu/CpuImage.cpp"
"source/Graphics/Cpu/CpuRender.cpp"
"source/Graphics/Primitives/Color.cpp"
"source/Graphics/PixelConverter.cpp"
"source/Graphics/TextRasterizer.cpp"
"source/Graphics/VideoMode.cpp"
"source/Graphics/Base/BaseScreenshoter.cpp"
"source/Events/Eventer.cpp"
"source/Allocators/FixedLinear.cpp"
"source/Loaders/ImageLoader.cpp"
"source/Loaders/FontLoader.cpp"
"source/Time/FpsCounter.cpp"
"source/Time/FpsLimiter.cpp")

if (LDL_GPU_SUPPORT_OPENGL1)
  target_sources(LDL PRIVATE
  "source/Graphics/GL1/GL1Render.cpp"
  "source/Graphics/GL1/GL1Image.cpp"
  "source/Graphics/GL1/GL1Screen.cpp"
  "source/Graphics/GL1/GL1Screenshoter.cpp")
endif() 

if (WIN32 AND LDL_GPU_SUPPORT_OPENGL1)
  target_sources(LDL PRIVATE
  "source/Platforms/Windows/Graphics/GL1Window.cpp")
endif()

if (LDL_GPU_SUPPORT_DIRECTX9)
  target_sources(LDL PRIVATE
  "source/Graphics/DX9/DX9Render.cpp"
  "source/Graphics/DX9/DX9Image.cpp"
  "source/Graphics/DX9/DX9Screenshoter.cpp")
endif() 

if (LDL_GPU_SUPPORT_DIRECTX5)
  target_sources(LDL PRIVATE
  "source/Graphics/DX5/DX5Render.cpp"
  "source/Graphics/DX5/DX5Image.cpp"
  "source/Graphics/DX5/DX5Screenshoter.cpp")
endif() 

if (WIN32 AND LDL_GPU_SUPPORT_DIRECTX9)
  target_sources(LDL PRIVATE
  "source/Platforms/Windows/Graphics/DX9Window.cpp")
endif() 

if (WIN32 AND LDL_GPU_SUPPORT_DIRECTX5)
  target_sources(LDL PRIVATE
  "source/Platforms/Windows/Graphics/DX5Window.cpp")
endif() 

if (WIN32)
  target_sources(LDL PRIVATE
  "source/Platforms/Windows/Graphics/MainWindow.cpp"
  "source/Platforms/Windows/Graphics/CpuWindow.cpp"
  "source/Platforms/Windows/Time/Ticks.cpp"
  "source/Platforms/Windows/Core/Directory.cpp"
  "source/Platforms/Windows/Input/Display.cpp")
elseif(UNIX AND NOT APPLE)
  target_sources(LDL PRIVATE
  "source/Platforms/Linux/Graphics/Window.cpp")
endif() 

if (WIN32)
  target_link_libraries(LDL winmm)
endif() 

if (WIN32 AND LDL_GPU_SUPPORT_OPENGL1)
  target_link_libraries(LDL opengl32)
endif()

if (WIN32 AND LDL_GPU_SUPPORT_DIRECTX9)
  target_link_libraries(LDL d3d9 d3dx9)
endif()

if (WIN32 AND LDL_GPU_SUPPORT_DIRECTX5)
  target_link_libraries(LDL d3drm ddraw)
endif()

add_subdirectory("test")
add_subdirectory("Examples")