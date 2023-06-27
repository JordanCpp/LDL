cmake_minimum_required(VERSION 3.8)

project(LDL)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

include_directories("../include")

set(LDL_AUDIO_DIRECT_SOUND_8 true)
add_definitions(-DLDL_AUDIO_DIRECT_SOUND_8)

file(GLOB SOURCE_FILES
    "Core/*.cpp"
    "Graphics/*.cpp"
    "Graphics/Base/*.cpp"
    "Graphics/Software/*.cpp"
    "Graphics/OpenGL/*.cpp"
    "OpenGL/*.cpp"
    "Graphics/Primitives/*.cpp"
    "Graphics/Utils/*.cpp"
    "Audio/*.cpp"
    "Events/*.cpp"
    "Allocators/*.cpp"
    "Loaders/*.cpp"
    "Time/*.cpp"
    "LDLC/*.cpp")

file(GLOB SOURCE_RENDERS
    "Graphics/OpenGL/*.cpp"
    "Graphics/OpenGL1/*.cpp"
    "Graphics/Software/*.cpp"
    "Graphics/OpenGL3/*.cpp"
    "Graphics/Direct3D9/*.cpp"
    "Graphics/Creators/*.cpp")

if (LDL_AUDIO_DIRECT_SOUND_8)
  set(SOURCE_AUDIO
  "Audio/DirectSound8/MixerImpl.cpp"
  "Audio/DirectSound8/SoundImpl.cpp"
  "Audio/DirectSound8/AudioContextImpl.cpp"
  "DirectX/DirectX9.cpp")
endif() 

if (WIN32)
set(SOURCE_RENDER_PLATFORM
  "Platforms/Windows/Graphics/OpenGL/FunctionsImpl.cpp"
  "Platforms/Windows/Graphics/Software/WindowImplSoftware.cpp"
  "Platforms/Windows/Graphics/OpenGL1/WindowImplOpenGL1.cpp"
  "Platforms/Windows/Graphics/OpenGL3/WindowImplOpenGL3.cpp"
  "Platforms/Windows/Graphics/Direct3D9/WindowImplDirect3D9.cpp")
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