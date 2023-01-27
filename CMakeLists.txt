cmake_minimum_required(VERSION 3.8)

project(LibLDL)

#set(LDL_RENDER_SOFTWARE true)
#add_definitions(-DLDL_RENDER_SOFTWARE)

set(LDL_RENDER_OPENGL1 true)
add_definitions(-DLDL_RENDER_OPENGL1)

#set(LDL_GPU_SUPPORT_DIRECTX9 true)
#add_definitions(-DLDL_GPU_SUPPORT_DIRECTX9)

#set(LDL_GPU_SUPPORT_DIRECTX5 true)
#add_definitions(-DLDL_GPU_SUPPORT_DIRECTX5)

#set(LDL_GPU_SUPPORT_DIRECTX1 true)
#add_definitions(-DLDL_GPU_SUPPORT_DIRECTX1)

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

if (LDL_GPU_SUPPORT_DIRECTX1)
  include_directories("dependencies/dx1sdk/Include")
  link_directories("dependencies/dx1sdk/Lib")
endif()

add_library(LDL STATIC
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
"source/Graphics/Functions.cpp"
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
"source/OpenGL/OpenGLLoader.cpp"
"source/Time/FpsCounter.cpp"
"source/Time/FpsLimiter.cpp"
"source/OpenGL/OpenGL1_0.cpp"
"source/OpenGL/OpenGL1_1.cpp"
"source/OpenGL/OpenGL_Matrix4.cpp")

if (LDL_RENDER_SOFTWARE)
  target_sources(LDL PRIVATE
  "source/Graphics/Software/RenderImpl.cpp"
  "source/Graphics/Software/TextureImpl.cpp")
endif() 

if (WIN32 AND LDL_RENDER_SOFTWARE)
  target_sources(LDL PRIVATE
  "source/Platforms/Windows/Graphics/Software/WindowImpl.cpp")
endif()

if (LDL_RENDER_OPENGL1)
  target_sources(LDL PRIVATE
  "source/Graphics/OpenGL1/RenderImpl.cpp"
  "source/Graphics/OpenGL1/TextureImpl.cpp"
  "source/Graphics/OpenGL1/Util.cpp"
  "source/Graphics/OpenGL1/Screen.cpp"
  "source/Graphics/OpenGL1/ScreenshoterImpl.cpp")
endif() 

if (WIN32 AND LDL_RENDER_OPENGL1)
  target_sources(LDL PRIVATE
  "source/Platforms/Windows/Graphics/OpenGL1/WindowImpl.cpp"
  "source/Platforms/Windows/Graphics/OpenGL1/ContextImpl.cpp"
  "source/Platforms/Windows/Graphics/OpenGL1/FunctionsImpl.cpp")
endif()

if (LDL_GPU_SUPPORT_DIRECTX1)
  target_sources(LDL PRIVATE
  "source/Platforms/Windows/Graphics/DirectDraw/WindowImpl.cpp"
  "source/Graphics/DirectDraw/RenderImpl.cpp"
  "source/Graphics/DirectDraw/TextureImpl.cpp"
  "source/Graphics/DirectDraw/ScreenshoterImpl.cpp")
endif()

if (LDL_GPU_SUPPORT_DIRECTX9)
  target_sources(LDL PRIVATE
  "source/Graphics/DirectX9/Direct3D/RenderImpl.cpp"
  "source/Graphics/DirectX9/Direct3D/TextureImpl.cpp"
  "source/Graphics/DirectX9/Direct3D/ScreenshoterImpl.cpp")
endif() 

if (LDL_GPU_SUPPORT_DIRECTX5)
  target_sources(LDL PRIVATE
  "source/Graphics/DirectX5/Direct3D/RenderImpl.cpp"
  "source/Graphics/DirectX5/Direct3D/TextureImpl.cpp"
  "source/Graphics/DirectX5/Direct3D/ScreenshoterImpl.cpp")
endif() 

if (WIN32 AND LDL_GPU_SUPPORT_DIRECTX9)
  target_sources(LDL PRIVATE
  "source/Platforms/Windows/Graphics/DirectX9/Direct3D/WindowImpl.cpp")
endif() 

if (WIN32 AND LDL_GPU_SUPPORT_DIRECTX5)
  target_sources(LDL PRIVATE
  "source/Platforms/Windows/Graphics/DirectX5/Direct3D/WindowImpl.cpp")
endif() 

if (WIN32)
  target_sources(LDL PRIVATE
  "source/Platforms/Windows/Graphics/MainWindow.cpp"
  "source/Platforms/Windows/Time/Ticks.cpp"
  "source/Platforms/Windows/Core/DirectoryImpl.cpp"
  "source/Platforms/Windows/Core/LibraryImpl.cpp"
  "source/Platforms/Windows/Input/Display.cpp"
  "source/Platforms/Windows/Input/Mouse.cpp")
elseif(UNIX AND NOT APPLE)
  target_sources(LDL PRIVATE
  "source/Platforms/Linux/Graphics/Window.cpp")
endif() 

if (WIN32)
  target_link_libraries(LDL winmm)
endif() 

if (WIN32 AND LDL_RENDER_OPENGL1)
  target_link_libraries(LDL opengl32)
endif()

if (WIN32 AND LDL_GPU_SUPPORT_DIRECTX9)
  target_link_libraries(LDL d3d9 d3dx9)
endif()

if (WIN32 AND LDL_GPU_SUPPORT_DIRECTX5)
  target_link_libraries(LDL d3drm ddraw)
endif()

if (WIN32 AND LDL_GPU_SUPPORT_DIRECTX1)
  target_link_libraries(LDL ddraw)
endif()

add_subdirectory("test")
add_subdirectory("Examples")
add_subdirectory("Tutorials")