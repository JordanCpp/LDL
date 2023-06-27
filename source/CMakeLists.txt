cmake_minimum_required(VERSION 3.8)

project(LDL)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

include_directories("../include")

set(LDL_AUDIO_DIRECT_SOUND_8 true)
add_definitions(-DLDL_AUDIO_DIRECT_SOUND_8)

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
  "Audio/DirectSound8/AudioContextImpl.cpp"
  "DirectX/DirectX9.cpp")
endif() 

set(SOURCE_RENDERS
  "Graphics/OpenGL1/RenderImplOpenGL1.cpp"
  "Graphics/OpenGL1/TextureImplOpenGL1.cpp"
  "Graphics/OpenGL/Util.cpp"
  "Graphics/OpenGL1/ScreenOpenGL1.cpp"
  "Graphics/OpenGL1/ScreenshoterImplOpenGL1.cpp"
  "Graphics/OpenGL1/RenderContextImplOpenGL1.cpp"
  "Graphics/OpenGL1/RenderBufferOpenGL1.cpp"
  "Graphics/OpenGL1/TextureBatcherImplOpenGL1.cpp"
  "Graphics/OpenGL1/CameraImplOpenGL1.cpp"

  "Graphics/Software/RenderImplSoftware.cpp"
  "Graphics/Software/TextureImplSoftware.cpp"
  "Graphics/Software/RenderContextImplSoftware.cpp"
  "Graphics/Software/ScreenshoterImplSoftware.cpp"
  "Graphics/Software/TextureBatcherImplSoftware.cpp"
  "Graphics/Software/CameraImplSoftware.cpp"

  "Graphics/OpenGL3/RenderImplOpenGL3.cpp"
  "Graphics/OpenGL3/TextureImplOpenGL3.cpp"
  "Graphics/OpenGL3/ScreenOpenGL3.cpp"
  "Graphics/OpenGL3/ScreenshoterImplOpenGL3.cpp"
  "Graphics/OpenGL3/RenderContextImplOpenGL3.cpp"
  "Graphics/OpenGL3/ShaderLoaderOpenGL3.cpp"
  "Graphics/OpenGL3/LinePainterOpenGL3.cpp"
  "Graphics/OpenGL3/TexturePainterOpenGL3.cpp"
  "Graphics/OpenGL3/TextureBatcherImplOpenGL3.cpp"
  "Graphics/OpenGL3/CameraImplOpenGL3.cpp"

  "Graphics/Direct3D9/RenderImplDirect3D9.cpp"
  "Graphics/Direct3D9/TextureImplDirect3D9.cpp"
  "Graphics/Direct3D9/ScreenshoterImplDirect3D9.cpp"
  "Graphics/Direct3D9/RenderContextImplDirect3D9.cpp"
  "Graphics/Direct3D9/TextureBatcherImplDirect3D9.cpp"
  "Graphics/Direct3D9/CameraImplDirect3D9.cpp"

  "Graphics/Creators/WindowImplCreator.cpp"
  "Graphics/Creators/RenderImplCreator.cpp"
  "Graphics/Creators/RenderContextImplCreator.cpp"
  "Graphics/Creators/TextureImplCreator.cpp"
  "Graphics/Creators/TextureBatcherImplCreator.cpp"
  ${SOURCE_OPENGL_FILES})

if (WIN32)
set(SOURCE_RENDER_PLATFORM
  "Platforms/Windows/Graphics/OpenGL/FunctionsImpl.cpp"
  "Platforms/Windows/Graphics/Software/WindowImplSoftware.cpp"
  "Platforms/Windows/Graphics/OpenGL1/WindowImplOpenGL1.cpp"
  "Platforms/Windows/Graphics/OpenGL3/WindowImplOpenGL3.cpp"
  "Platforms/Windows/Graphics/Direct3D9/WindowImplDirect3D9.cpp"
)
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

set(SOURCE_ALL ${SOURCE_FILES} ${SOURCE_RENDERS} ${SOURCE_RENDER_PLATFORM} ${SOURCE_PLATFORM} ${SOURCE_AUDIO})

if (LDL_SHARED_LIBRARY)
  add_library(${PROJECT_NAME} SHARED  ${SOURCE_ALL})		
elseif (LDL_STATIC_LIBRARY)
  add_library(${PROJECT_NAME} STATIC  ${SOURCE_ALL})		
endif() 

if (WIN32)
  target_link_libraries(${PROJECT_NAME} winmm opengl32)
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