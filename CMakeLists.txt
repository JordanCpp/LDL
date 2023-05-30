cmake_minimum_required(VERSION 3.8)

project(LDL)

#
# Library type
#

#set(LDL_SHARED_LIBRARY true)
#add_definitions(-DLDL_SHARED_LIBRARY)

set(LDL_STATIC_LIBRARY true)
add_definitions(-DLDL_STATIC_LIBRARY)

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

#set(LDL_RENDER_DIRECTX10 true)
#add_definitions(-DLDL_RENDER_DIRECTX10)

set(LDL_AUDIO_DIRECT_SOUND_8 true)
add_definitions(-DLDL_AUDIO_DIRECT_SOUND_8)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

include_directories("include")

if (LDL_RENDER_DIRECTX10)
  include_directories("dependencies/dx10sdk/Include")
  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    link_directories("dependencies/dx10sdk/Lib/x64")
  elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    link_directories("dependencies/dx10sdk/Lib/x86")
  endif()
endif() 

if (LDL_RENDER_DIRECTX9 OR LDL_AUDIO_DIRECT_SOUND_8)
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
"source/Core/NumberToString.cpp"
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
"source/Graphics/RenderContext.cpp"
"source/Graphics/Texture.cpp"
"source/Graphics/Screenshoter.cpp"
"source/Graphics/ImageWritter.cpp"
"source/Graphics/ImageResizer.cpp"
"source/Graphics/Isometric.cpp"
"source/Graphics/Camera.cpp"
"source/Graphics/TextureBatcher.cpp"
"source/Graphics/Utils/PotTextureSizer.cpp"

"source/Audio/Mixer.cpp"

"source/Events/Eventer.cpp"

"source/Allocators/FixedLinear.cpp"
"source/Allocators/SmallAllocator.cpp"

"source/Loaders/ImageLoader.cpp"
"source/Loaders/FontLoader.cpp"
"source/Loaders/SoundLoader.cpp"

"source/Time/FpsCounter.cpp"
"source/Time/FpsLimiter.cpp"

"source/LDLC/LDL_Window.cpp"
"source/LDLC/LDL_RenderContext.cpp"
"source/LDLC/LDL_Render.cpp"
"source/LDLC/LDL_Surface.cpp"
"source/LDLC/LDL_Texture.cpp"
"source/LDLC/LDL_FpsCounter.cpp"
"source/LDLC/LDL_FpsLimiter.cpp"
"source/LDLC/LDL_NumberToString.cpp"
"source/LDLC/LDL_Library.cpp"
"source/LDLC/LDL_Ticks.cpp"
"source/LDLC/LDL_FixedLinear.cpp"
"source/LDLC/LDL_ImageLoader.cpp")

set(SOURCE_OPENGL_FILES
"source/Graphics/OpenGL/Functions.cpp"
"source/OpenGL/OpenGLLoader.cpp"
"source/OpenGL/OpenGL1_0.cpp"
"source/OpenGL/OpenGL1_1.cpp"
"source/OpenGL/OpenGL1_2.cpp"
"source/OpenGL/OpenGL1_3.cpp"
"source/OpenGL/OpenGL1_4.cpp"
"source/OpenGL/OpenGL1_5.cpp"
"source/OpenGL/OpenGL2_0.cpp"
"source/OpenGL/OpenGL2_1.cpp"
"source/OpenGL/OpenGL3_0.cpp"
"source/OpenGL/OpenGL3_1.cpp"
"source/OpenGL/OpenGL3_2.cpp"
"source/OpenGL/OpenGL3_3.cpp"
"source/OpenGL/OpenGL4_0.cpp"
"source/OpenGL/OpenGL4_1.cpp"
"source/OpenGL/OpenGL4_2.cpp"
"source/OpenGL/OpenGL4_3.cpp"
"source/OpenGL/OpenGL4_4.cpp"
"source/OpenGL/OpenGL4_5.cpp"
"source/OpenGL/OpenGL4_6.cpp"
"source/OpenGL/OpenGLUtility.cpp"
"source/LDLC/LDL_OpenGLLoader.cpp")

if (LDL_AUDIO_DIRECT_SOUND_8)
  set(SOURCE_AUDIO
  "source/Audio/DirectSound8/MixerImpl.cpp")
endif() 

#
# OpenGL1
#
if (LDL_RENDER_OPENGL1)
  set(SOURCE_RENDER
  "source/Graphics/OpenGL1/RenderImpl.cpp"
  "source/Graphics/OpenGL1/TextureImpl.cpp"
  "source/Graphics/OpenGL/Util.cpp"
  "source/Graphics/OpenGL1/Screen.cpp"
  "source/Graphics/OpenGL1/ScreenshoterImpl.cpp"
  "source/Graphics/OpenGL1/RenderContextImpl.cpp"
  "source/Graphics/OpenGL1/RenderBuffer.cpp"
  "source/Graphics/OpenGL1/TextureBatcherImpl.cpp"
  "source/Graphics/OpenGL1/CameraImpl.cpp"
  ${SOURCE_OPENGL_FILES})
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
  "source/Graphics/OpenGL3/ScreenshoterImpl.cpp"
  "source/Graphics/OpenGL3/RenderContextImpl.cpp"
  "source/Graphics/OpenGL3/ShaderLoader.cpp"
  "source/Graphics/OpenGL3/LinePainter.cpp"
  "source/Graphics/OpenGL3/TexturePainter.cpp"
  "source/Graphics/OpenGL3/TextureBatcherImpl.cpp"
  "source/Graphics/OpenGL3/CameraImpl.cpp"
  ${SOURCE_OPENGL_FILES})
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
  "source/Graphics/Software/TextureImpl.cpp"
  "source/Graphics/Software/RenderContextImpl.cpp"
  "source/Graphics/Software/ScreenshoterImpl.cpp"
  "source/Graphics/Software/TextureBatcherImpl.cpp"
  "source/Graphics/Software/CameraImpl.cpp")
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
  "source/Graphics/DirectX9/Direct3D/ScreenshoterImpl.cpp"
  "source/Graphics/DirectX9/Direct3D/RenderContextImpl.cpp")
endif() 

if (WIN32 AND LDL_RENDER_DIRECTX9)
  set(SOURCE_RENDER_PLATFORM
  "source/Platforms/Windows/Graphics/DirectX9/Direct3D/WindowImpl.cpp")
endif() 

#
# DirectX10
#
if (LDL_RENDER_DIRECTX10)
  set(SOURCE_RENDER
  "source/Graphics/DirectX10/Direct3D/RenderImpl.cpp"
  "source/Graphics/DirectX10/Direct3D/TextureImpl.cpp"
  "source/Graphics/DirectX10/Direct3D/ScreenshoterImpl.cpp"
  "source/Graphics/DirectX10/Direct3D/RenderContextImpl.cpp")
endif() 

if (WIN32 AND LDL_RENDER_DIRECTX10)
  set(SOURCE_RENDER_PLATFORM
  "source/Platforms/Windows/Graphics/DirectX10/Direct3D/WindowImpl.cpp")
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

set(SOURCE_ALL ${SOURCE_FILES} ${SOURCE_RENDER} ${SOURCE_RENDER_PLATFORM} ${SOURCE_PLATFORM} ${SOURCE_AUDIO})

if (LDL_SHARED_LIBRARY)
  add_library(${PROJECT_NAME} SHARED  ${SOURCE_ALL})		
elseif (LDL_STATIC_LIBRARY)
  add_library(${PROJECT_NAME} STATIC  ${SOURCE_ALL})		
endif() 

if (WIN32)
  target_link_libraries(${PROJECT_NAME} winmm)
endif() 

if (WIN32 AND (LDL_RENDER_OPENGL1 OR LDL_RENDER_OPENGL3))
  target_link_libraries(${PROJECT_NAME} opengl32)
endif()

if (WIN32 AND LDL_RENDER_DIRECTX1)
  target_link_libraries(${PROJECT_NAME} ddraw)
endif()

if (WIN32 AND LDL_RENDER_DIRECTX5)
  target_link_libraries(${PROJECT_NAME} d3drm ddraw)
endif()

if (WIN32 AND LDL_RENDER_DIRECTX9)
  target_link_libraries(${PROJECT_NAME} d3d9 d3dx9)
endif()

if (WIN32 AND LDL_AUDIO_DIRECT_SOUND_8)
  target_link_libraries(${PROJECT_NAME} dsound dxguid)
endif()

add_subdirectory("Examples")

if (LDL_STATIC_LIBRARY)
  add_subdirectory("test")
endif()