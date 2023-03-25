cmake_minimum_required(VERSION 3.8)

project(LDL)
#
# Library type
#

#set(LDL_CONFIG_SHARED_LIBRARY true)
#add_definitions(-DLDL_CONFIG_SHARED_LIBRARY)

set(LDL_CONFIG_STATIC_LIBRARY true)
add_definitions(-DLDL_CONFIG_STATIC_LIBRARY)

#
# Render type
#

#set(LDL_RENDER_SOFTWARE true)
#add_definitions(-DLDL_RENDER_SOFTWARE)

#set(LDL_RENDER_GDI true)
#add_definitions(-DLDL_RENDER_GDI)

set(LDL_RENDER_OPENGL1 true)
add_definitions(-DLDL_RENDER_OPENGL1)

#set(LDL_RENDER_OPENGL3 true)
#add_definitions(-DLDL_RENDER_OPENGL3)

#set(LDL_RENDER_DIRECTX1 true)
#add_definitions(-DLDL_RENDER_DIRECTX1)

#set(LDL_RENDER_DIRECTX5 true)
#add_definitions(-DLDL_RENDER_DIRECTX5)

#set(LDL_RENDER_DIRECTX9 true)
#add_definitions(-DLDL_RENDER_DIRECTX9)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

include_directories("include")

if (LDL_RENDER_DIRECTX9)
  include_directories("dependencies/dx9sdk/Include")
  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    link_directories("dependencies/dx9sdk/Lib/x64")
  elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    link_directories("dependencies/dx9sdk/Lib/x86")
  endif()
endif() 

if (LDL_RENDER_DIRECTX5)
  include_directories("dependencies/dx5sdk/Include")
  link_directories("dependencies/dx5sdk/Lib")
endif() 

if (LDL_RENDER_DIRECTX1)
  include_directories("dependencies/dx1sdk/Include")
  link_directories("dependencies/dx1sdk/Lib")
endif()

set(SOURCE_FILES
"source/Core/TestEqual.cpp" 
"source/Core/RuntimeError.cpp"
"source/Core/IntegerToString.cpp"
"source/Core/FileInfo.cpp"
"source/Core/Directory.cpp"
"source/Core/FastPimpl.cpp"
"source/Core/Library.cpp"
"source/Graphics/Base/BaseWindow.cpp"
"source/Graphics/Base/BaseRender.cpp"
"source/Graphics/Software/Surface.cpp"
"source/Graphics/Software/PixelPainter.cpp"
"source/Graphics/Software/PixelCopier.cpp"
"source/Graphics/Primitives/Color.cpp"
"source/Graphics/PixelConverter.cpp"
"source/Graphics/TextRasterizer.cpp"
"source/Graphics/VideoMode.cpp"
"source/Graphics/Window.cpp"
"source/Graphics/Base/BaseScreenshoter.cpp"
"source/Graphics/Render.cpp"
"source/Graphics/Texture.cpp"
"source/Graphics/Screenshoter.cpp"
"source/Graphics/ImageWritter.cpp"
"source/Graphics/ImageResizer.cpp"
"source/Graphics/Isometric.cpp"
"source/Graphics/Camera.cpp"
"source/Graphics/Utils/PotTextureSizer.cpp"
"source/Events/Eventer.cpp"
"source/Allocators/FixedLinear.cpp"
"source/Allocators/SmallAllocator.cpp"
"source/Loaders/ImageLoader.cpp"
"source/Loaders/FontLoader.cpp"
"source/Time/FpsCounter.cpp"
"source/Time/FpsLimiter.cpp"
"source/Graphics/OpenGL/Functions.cpp"
"source/OpenGL/OpenGLLoader.cpp"
"source/OpenGL/OpenGL1_0.cpp"
"source/OpenGL/OpenGL1_1.cpp"
"source/OpenGL/OpenGL3_3.cpp"
"source/LDLC/LDL_Window.cpp")

#
# OpenGL1
#
if (LDL_RENDER_OPENGL1)
  set(SOURCE_RENDER
  "source/Graphics/OpenGL1/RenderImpl.cpp"
  "source/Graphics/OpenGL1/TextureImpl.cpp"
  "source/Graphics/OpenGL1/Util.cpp"
  "source/Graphics/OpenGL1/Screen.cpp"
  "source/Graphics/OpenGL1/ScreenshoterImpl.cpp")
endif() 

if (WIN32 AND LDL_RENDER_OPENGL1)
set(SOURCE_RENDER_PLATFORM
  "source/Platforms/Windows/Graphics/OpenGL/FunctionsImpl.cpp"
  "source/Platforms/Windows/Graphics/OpenGL1/WindowImpl.cpp")
endif()

#
# OpenGL3
#
if (LDL_RENDER_OPENGL3)
  set(SOURCE_RENDER
  "source/Graphics/OpenGL3/RenderImpl.cpp"
  "source/Graphics/OpenGL3/TextureImpl.cpp"
  "source/Graphics/OpenGL3/Util.cpp"
  "source/Graphics/OpenGL3/Screen.cpp"
  "source/Graphics/OpenGL3/ScreenshoterImpl.cpp")
endif() 

if (WIN32 AND LDL_RENDER_OPENGL3)
  set(SOURCE_RENDER_PLATFORM
  "source/Platforms/Windows/Graphics/OpenGL/FunctionsImpl.cpp"
  "source/Platforms/Windows/Graphics/OpenGL3/WindowImpl.cpp")
endif()

#
# Software
#
if (LDL_RENDER_SOFTWARE)
  set(SOURCE_RENDER
  "source/Graphics/Software/RenderImpl.cpp"
  "source/Graphics/Software/TextureImpl.cpp")
endif() 

if (WIN32 AND LDL_RENDER_SOFTWARE)
  set(SOURCE_RENDER_PLATFORM
  "source/Platforms/Windows/Graphics/Software/WindowImpl.cpp")
endif()

#
# GDI
#
if (LDL_RENDER_GDI)
  set(SOURCE_RENDER
  "source/Graphics/GDI/RenderImpl.cpp"
  "source/Graphics/GDI/TextureImpl.cpp"
  "source/Graphics/GDI/Util.cpp"
  "source/Graphics/GDI/Screen.cpp"
  "source/Graphics/GDI/ScreenshoterImpl.cpp")
endif() 

if (WIN32 AND LDL_RENDER_GDI)
  set(SOURCE_RENDER_PLATFORM
  "source/Platforms/Windows/Graphics/GDI/WindowImpl.cpp")
endif()

#
# DirectX1
#
if (LDL_RENDER_DIRECTX1)
  set(SOURCE_RENDER
  "source/Graphics/DirectDraw/RenderImpl.cpp"
  "source/Graphics/DirectDraw/TextureImpl.cpp"
  "source/Graphics/DirectDraw/ScreenshoterImpl.cpp")
endif()

if (WIN32 AND LDL_RENDER_DIRECTX1)
  set(SOURCE_RENDER_PLATFORM
  "source/Platforms/Windows/Graphics/DirectDraw/WindowImpl.cpp")
endif() 

#
# DirectX9
#
if (LDL_RENDER_DIRECTX9)
  set(SOURCE_RENDER
  "source/Graphics/DirectX9/Direct3D/RenderImpl.cpp"
  "source/Graphics/DirectX9/Direct3D/TextureImpl.cpp"
  "source/Graphics/DirectX9/Direct3D/ScreenshoterImpl.cpp")
endif() 

if (WIN32 AND LDL_RENDER_DIRECTX9)
  set(SOURCE_RENDER_PLATFORM
  "source/Platforms/Windows/Graphics/DirectX9/Direct3D/WindowImpl.cpp")
endif() 

#
# DirectX5
#
if (LDL_RENDER_DIRECTX5)
  set(SOURCE_RENDER
  "source/Graphics/DirectX5/Direct3D/RenderImpl.cpp"
  "source/Graphics/DirectX5/Direct3D/TextureImpl.cpp"
  "source/Graphics/DirectX5/Direct3D/ScreenshoterImpl.cpp")
endif() 

if (WIN32 AND LDL_RENDER_DIRECTX5)
  set(SOURCE_RENDER_PLATFORM
  "source/Platforms/Windows/Graphics/DirectX5/Direct3D/WindowImpl.cpp")
endif() 

#
# Platform
#
if (WIN32)
  set(SOURCE_PLATFORM
  "source/Platforms/Windows/Graphics/MainWindow.cpp"
  "source/Platforms/Windows/Time/Ticks.cpp"
  "source/Platforms/Windows/Core/DirectoryImpl.cpp"
  "source/Platforms/Windows/Core/LibraryImpl.cpp"
  "source/Platforms/Windows/Input/Display.cpp"
  "source/Platforms/Windows/Input/Mouse.cpp")
elseif(UNIX AND NOT APPLE)
  set(SOURCE_PLATFORM
  "source/Platforms/Linux/Graphics/Window.cpp")
endif() 

set(SOURCE_ALL ${SOURCE_FILES} ${SOURCE_RENDER} ${SOURCE_RENDER_PLATFORM} ${SOURCE_PLATFORM})

if (LDL_CONFIG_SHARED_LIBRARY)
  add_library(${CMAKE_PROJECT_NAME} SHARED  ${SOURCE_ALL})		
elseif (LDL_CONFIG_STATIC_LIBRARY)
  add_library(${CMAKE_PROJECT_NAME} STATIC  ${SOURCE_ALL})		
endif() 

if (WIN32)
  target_link_libraries(${CMAKE_PROJECT_NAME} winmm)
endif() 

if (WIN32 AND (LDL_RENDER_OPENGL1 OR LDL_RENDER_OPENGL3))
  target_link_libraries(${CMAKE_PROJECT_NAME} opengl32)
endif()

if (WIN32 AND LDL_RENDER_DIRECTX1)
  target_link_libraries(${CMAKE_PROJECT_NAME} ddraw)
endif()

if (WIN32 AND LDL_RENDER_DIRECTX5)
  target_link_libraries(${CMAKE_PROJECT_NAME} d3drm ddraw)
endif()

if (WIN32 AND LDL_RENDER_DIRECTX9)
  target_link_libraries(${CMAKE_PROJECT_NAME} d3d9 d3dx9)
endif()

add_subdirectory("Examples")
add_subdirectory("Games")
add_subdirectory("Experiments")

if (LDL_CONFIG_STATIC_LIBRARY)
  add_subdirectory("test")
  add_subdirectory("Tutorials")
endif()