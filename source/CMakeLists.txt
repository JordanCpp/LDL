cmake_minimum_required(VERSION 3.8)

project(LDL)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

include_directories("../include")

if (LDL_RENDER_SOFTWARE)
  add_definitions(-DLDL_RENDER_SOFTWARE)
endif()

if (LDL_RENDER_GDI)
  add_definitions(-DLDL_RENDER_GDI)
endif()

if (LDL_RENDER_OPENGL1)
  add_definitions(-DLDL_RENDER_OPENGL1)
endif() 

if (LDL_RENDER_OPENGL3)
  add_definitions(-DLDL_RENDER_OPENGL3)
endif()

if (LDL_RENDER_DIRECT_DRAW)
  add_definitions(-DLDL_RENDER_DIRECT_DRAW)
endif()

if (LDL_RENDER_DIRECTX5)
  add_definitions(-DLDL_RENDER_DIRECTX5)
endif()

if (LDL_RENDER_DIRECTX9)
  add_definitions(-DLDL_RENDER_DIRECTX9)
endif()

if (LDL_RENDER_DIRECTX10)
  add_definitions(-DLDL_RENDER_DIRECTX10)
endif()

set(LDL_AUDIO_DIRECT_SOUND_8 true)
add_definitions(-DLDL_AUDIO_DIRECT_SOUND_8)

if (LDL_RENDER_DIRECTX10)
  include_directories("../dependencies/dx10sdk/Include")
  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    link_directories("../ddependencies/dx10sdk/Lib/x64")
  elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    link_directories("../ddependencies/dx10sdk/Lib/x86")
  endif()
endif() 

if (LDL_RENDER_DIRECTX9 OR LDL_AUDIO_DIRECT_SOUND_8)
  include_directories("../ddependencies/dx9sdk/Include")
  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    link_directories("../ddependencies/dx9sdk/Lib/x64")
  elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    link_directories("../ddependencies/dx9sdk/Lib/x86")
  endif()
endif() 

if (LDL_RENDER_DIRECTX5)
  include_directories("../ddependencies/dx5sdk/Include")
  link_directories("../ddependencies/dx5sdk/Lib")
endif() 

if (LDL_RENDER_DIRECT_DRAW)
  include_directories("../ddependencies/dx1sdk/Include")
  link_directories("../ddependencies/dx1sdk/Lib")
endif()

set(SOURCE_FILES
"Core/TestEqual.cpp" 
"Core/RuntimeError.cpp"
"Core/NumberToString.cpp"
"Core/FileInfo.cpp"
"Core/Directory.cpp"
"Core/FastPimpl.cpp"
"Core/Library.cpp"

"Graphics/Base/BaseWindow.cpp"
"Graphics/Base/BaseRender.cpp"
"Graphics/Software/Surface.cpp"
"Graphics/Software/PixelPainter.cpp"
"Graphics/Software/PixelCopier.cpp"
"Graphics/Primitives/Color.cpp"
"Graphics/PixelConverter.cpp"
"Graphics/TextRasterizer.cpp"
"Graphics/VideoMode.cpp"
"Graphics/Window.cpp"
"Graphics/Base/BaseScreenshoter.cpp"
"Graphics/Render.cpp"
"Graphics/RenderContext.cpp"
"Graphics/Texture.cpp"
"Graphics/Screenshoter.cpp"
"Graphics/ImageWritter.cpp"
"Graphics/ImageResizer.cpp"
"Graphics/Isometric.cpp"
"Graphics/Camera.cpp"
"Graphics/TextureBatcher.cpp"
"Graphics/Utils/PotTextureSizer.cpp"

"Audio/Mixer.cpp"
"Audio/Sound.cpp"
"Audio/AudioContext.cpp"

"Events/Eventer.cpp"

"Allocators/FixedLinear.cpp"
"Allocators/SmallAllocator.cpp"

"Loaders/ImageLoader.cpp"
"Loaders/FontLoader.cpp"
"Loaders/SoundLoader.cpp"

"Time/FpsCounter.cpp"
"Time/FpsLimiter.cpp"

"LDLC/LDL_Window.cpp"
"LDLC/LDL_RenderContext.cpp"
"LDLC/LDL_Render.cpp"
"LDLC/LDL_Surface.cpp"
"LDLC/LDL_Texture.cpp"
"LDLC/LDL_FpsCounter.cpp"
"LDLC/LDL_FpsLimiter.cpp"
"LDLC/LDL_NumberToString.cpp"
"LDLC/LDL_Library.cpp"
"LDLC/LDL_Ticks.cpp"
"LDLC/LDL_FixedLinear.cpp"
"LDLC/LDL_ImageLoader.cpp")

set(SOURCE_OPENGL_FILES
"Graphics/OpenGL/Functions.cpp"
"OpenGL/OpenGLLoader.cpp"
"OpenGL/OpenGL1_0.cpp"
"OpenGL/OpenGL1_1.cpp"
"OpenGL/OpenGL1_2.cpp"
"OpenGL/OpenGL1_3.cpp"
"OpenGL/OpenGL1_4.cpp"
"OpenGL/OpenGL1_5.cpp"
"OpenGL/OpenGL2_0.cpp"
"OpenGL/OpenGL2_1.cpp"
"OpenGL/OpenGL3_0.cpp"
"OpenGL/OpenGL3_1.cpp"
"OpenGL/OpenGL3_2.cpp"
"OpenGL/OpenGL3_3.cpp"
"OpenGL/OpenGL4_0.cpp"
"OpenGL/OpenGL4_1.cpp"
"OpenGL/OpenGL4_2.cpp"
"OpenGL/OpenGL4_3.cpp"
"OpenGL/OpenGL4_4.cpp"
"OpenGL/OpenGL4_5.cpp"
"OpenGL/OpenGL4_6.cpp"
"OpenGL/OpenGLUtility.cpp"
"LDLC/LDL_OpenGLLoader.cpp")

if (LDL_AUDIO_DIRECT_SOUND_8)
  set(SOURCE_AUDIO
  "Audio/DirectSound8/MixerImpl.cpp"
  "Audio/DirectSound8/SoundImpl.cpp"
  "Audio/DirectSound8/AudioContextImpl.cpp")
endif() 

#
# OpenGL1
#
if (LDL_RENDER_OPENGL1)
  set(SOURCE_RENDER
  "Graphics/OpenGL1/RenderImpl.cpp"
  "Graphics/OpenGL1/TextureImpl.cpp"
  "Graphics/OpenGL/Util.cpp"
  "Graphics/OpenGL1/Screen.cpp"
  "Graphics/OpenGL1/ScreenshoterImpl.cpp"
  "Graphics/OpenGL1/RenderContextImpl.cpp"
  "Graphics/OpenGL1/RenderBuffer.cpp"
  "Graphics/OpenGL1/TextureBatcherImpl.cpp"
  "Graphics/OpenGL1/CameraImpl.cpp"
  ${SOURCE_OPENGL_FILES})
endif() 

if (WIN32 AND LDL_RENDER_OPENGL1)
set(SOURCE_RENDER_PLATFORM
  "Platforms/Windows/Graphics/OpenGL/FunctionsImpl.cpp"
  "Platforms/Windows/Graphics/OpenGL1/WindowImpl.cpp")
endif()

#
# OpenGL3
#
if (LDL_RENDER_OPENGL3)
  set(SOURCE_RENDER
  "Graphics/OpenGL3/RenderImpl.cpp"
  "Graphics/OpenGL3/TextureImpl.cpp"
  "Graphics/OpenGL3/Util.cpp"
  "Graphics/OpenGL3/Screen.cpp"
  "Graphics/OpenGL3/ScreenshoterImpl.cpp"
  "Graphics/OpenGL3/RenderContextImpl.cpp"
  "Graphics/OpenGL3/ShaderLoader.cpp"
  "Graphics/OpenGL3/LinePainter.cpp"
  "Graphics/OpenGL3/TexturePainter.cpp"
  "Graphics/OpenGL3/TextureBatcherImpl.cpp"
  "Graphics/OpenGL3/CameraImpl.cpp"
  ${SOURCE_OPENGL_FILES})
endif() 

if (WIN32 AND LDL_RENDER_OPENGL3)
  set(SOURCE_RENDER_PLATFORM
  "Platforms/Windows/Graphics/OpenGL/FunctionsImpl.cpp"
  "Platforms/Windows/Graphics/OpenGL3/WindowImpl.cpp")
endif()

#
# Software
#
if (LDL_RENDER_SOFTWARE)
  set(SOURCE_RENDER
  "Graphics/Software/RenderImpl.cpp"
  "Graphics/Software/TextureImpl.cpp"
  "Graphics/Software/RenderContextImpl.cpp"
  "Graphics/Software/ScreenshoterImpl.cpp"
  "Graphics/Software/TextureBatcherImpl.cpp"
  "Graphics/Software/CameraImpl.cpp")
endif() 

if (WIN32 AND LDL_RENDER_SOFTWARE)
  set(SOURCE_RENDER_PLATFORM
  "Platforms/Windows/Graphics/Software/WindowImpl.cpp")
endif()

#
# GDI
#
if (LDL_RENDER_GDI)
  set(SOURCE_RENDER
  "Graphics/GDI/RenderImpl.cpp"
  "Graphics/GDI/TextureImpl.cpp"
  "Graphics/GDI/Util.cpp"
  "Graphics/GDI/Screen.cpp"
  "Graphics/GDI/ScreenshoterImpl.cpp")
endif() 

if (WIN32 AND LDL_RENDER_GDI)
  set(SOURCE_RENDER_PLATFORM
  "Platforms/Windows/Graphics/GDI/WindowImpl.cpp")
endif()

#
# DirectDraw
#
if (LDL_RENDER_DIRECT_DRAW)
  set(SOURCE_RENDER
  "Graphics/DirectDraw/RenderImpl.cpp"
  "Graphics/DirectDraw/TextureImpl.cpp"
  "Graphics/DirectDraw/ScreenshoterImpl.cpp"
  "Graphics/DirectDraw/RenderContextImpl.cpp"
  "Graphics/DirectDraw/TextureBatcherImpl.cpp"
  "Graphics/DirectDraw/CameraImpl.cpp")
endif()

if (WIN32 AND LDL_RENDER_DIRECT_DRAW)
  set(SOURCE_RENDER_PLATFORM
  "Platforms/Windows/Graphics/DirectDraw/WindowImpl.cpp")
endif() 

#
# DirectX9
#
if (LDL_RENDER_DIRECTX9)
  set(SOURCE_RENDER
  "Graphics/DirectX9/Direct3D/RenderImpl.cpp"
  "Graphics/DirectX9/Direct3D/TextureImpl.cpp"
  "Graphics/DirectX9/Direct3D/ScreenshoterImpl.cpp"
  "Graphics/DirectX9/Direct3D/RenderContextImpl.cpp")
endif() 

if (WIN32 AND LDL_RENDER_DIRECTX9)
  set(SOURCE_RENDER_PLATFORM
  "Platforms/Windows/Graphics/DirectX9/Direct3D/WindowImpl.cpp")
endif() 

#
# DirectX10
#
if (LDL_RENDER_DIRECTX10)
  set(SOURCE_RENDER
  "Graphics/DirectX10/Direct3D/RenderImpl.cpp"
  "Graphics/DirectX10/Direct3D/TextureImpl.cpp"
  "Graphics/DirectX10/Direct3D/ScreenshoterImpl.cpp"
  "Graphics/DirectX10/Direct3D/RenderContextImpl.cpp")
endif() 

if (WIN32 AND LDL_RENDER_DIRECTX10)
  set(SOURCE_RENDER_PLATFORM
  "Platforms/Windows/Graphics/DirectX10/Direct3D/WindowImpl.cpp")
endif() 

#
# DirectX5
#
if (LDL_RENDER_DIRECTX5)
  set(SOURCE_RENDER
  "Graphics/DirectX5/Direct3D/RenderImpl.cpp"
  "Graphics/DirectX5/Direct3D/TextureImpl.cpp"
  "Graphics/DirectX5/Direct3D/ScreenshoterImpl.cpp")
endif() 

if (WIN32 AND LDL_RENDER_DIRECTX5)
  set(SOURCE_RENDER_PLATFORM
  "Platforms/Windows/Graphics/DirectX5/Direct3D/WindowImpl.cpp")
endif() 

#
# Platform
#
if (WIN32)
  set(SOURCE_PLATFORM
  "Platforms/Windows/Graphics/MainWindow.cpp"
  "Platforms/Windows/Time/Ticks.cpp"
  "Platforms/Windows/Core/DirectoryImpl.cpp"
  "Platforms/Windows/Core/LibraryImpl.cpp"
  "Platforms/Windows/Input/Display.cpp"
  "Platforms/Windows/Input/Mouse.cpp")
elseif(UNIX AND NOT APPLE)
  set(SOURCE_PLATFORM
  "Platforms/Linux/Graphics/Window.cpp")
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

if (WIN32 AND LDL_RENDER_DIRECT_DRAW)
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