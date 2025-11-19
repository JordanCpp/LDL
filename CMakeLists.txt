
cmake_minimum_required(VERSION 3.12)

project(LDL)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)  
    add_compile_options("/analyze")
endif()

if(UNIX AND NOT APPLE)
    find_package(X11 REQUIRED)
    link_libraries(${X11_LIBRARIES})
    include_directories(${X11_INCLUDE_DIR})
endif()

set(LDL_STATIC_LIBRARY true)
add_definitions(-DLDL_STATIC_LIBRARY)

include_directories("deps")
include_directories("include")
include_directories("source")

if (WIN32)
    #set(LDL_WINDOWS_9X true)
    #add_definitions(-DLDL_WINDOWS_9X)

    set(LDL_WINDOWS_NT true)
    add_definitions(-DLDL_WINDOWS_NT)

    if (LDL_WINDOWS_NT)
        set(LDL_WINDOWS_NAME "WinNT")
    elseif (LDL_WINDOWS_9X)
        set(LDL_WINDOWS_NAME "Win9X")
    endif()
endif()

if (WIN32)
    file(GLOB SOURCE 
    "source/LDL/Renders/OpenGL/*.cpp" 
    "source/LDL/Renders/OpenGL1/*.cpp" 
    "source/LDL/Renders/OpenGL3/*.cpp" 
    "source/LDL/Renders/Software/*.cpp"
    "source/LDL/Shared/*.cpp" 
    "source/LDL/OpenGL/*.cpp" 
    "source/LDL/${LDL_WINDOWS_NAME}/*.cpp"
    "source/LDL/Eventer.cpp"
    "source/LDL/FpsCount.cpp"
    "source/LDL/FpsLimit.cpp"
    "source/LDL/Random.cpp"
    "source/LDL/BmpLoad.cpp"
    "source/LDL/KeyMap.cpp"
    "source/LDL/Mapping.cpp"
    "source/LDL/Assert.cpp"
    "source/LDL/Convert.cpp"
    "source/LDL/Format.cpp"
    "source/LDL/MemMngr.cpp"
    "source/LDL/Result.cpp"
    "source/LDL/StdFuncs.cpp"
    "source/LDL/Stream.cpp"
    "source/LDL/TestEq.cpp"
    "source/LDL/UtfConv.cpp"
    "source/LDL/BaseRndr.cpp"
    "source/LDL/BaseWin.cpp"
    "source/LDL/Batcher.cpp"
    "source/LDL/Color.cpp"
    "source/LDL/Context.cpp"
    "source/LDL/Palette.cpp"
    "source/LDL/PixConv.cpp"
    "source/LDL/PixFrmt.cpp"
    "source/LDL/PixRszr.cpp"
    "source/LDL/PixWrtr.cpp"
    "source/LDL/Render.cpp"
    "source/LDL/TexSizer.cpp"
    "source/LDL/Texture.cpp"
    "source/LDL/Video.cpp"
    "source/LDL/Window.cpp")
elseif(UNIX AND NOT APPLE)
    file(GLOB_RECURSE SOURCE 
    "source/LDL/Shared/*.cpp" 
    "source/LDL/APIs/OpenGL/*.cpp" 
    "source/LDL/Linux/*.cpp")
endif()

if (LDL_SHARED_LIBRARY)
    add_library(LDL SHARED ${SOURCE})		
elseif (LDL_STATIC_LIBRARY)
    add_library(LDL STATIC ${SOURCE})		
endif()

if (WIN32)
    target_link_libraries(LDL winmm opengl32)
elseif (UNIX AND NOT APPLE)
    target_link_libraries(LDL X11 GL dl)
endif()

file(GLOB LDL_SDL_SOURCE "source/LDL/SDL/*.cpp")
if (LDL_SHARED_LIBRARY)
    add_library(LDL_SDL SHARED ${LDL_SDL_SOURCE})		
elseif (LDL_STATIC_LIBRARY)
    add_library(LDL_SDL STATIC ${LDL_SDL_SOURCE})		
endif()
target_link_libraries(LDL_SDL LDL)

if (LDL_SHARED_LIBRARY)
    add_library(LDL_SDL_image SHARED "source/LDL/SDL_image/SDL_image.cpp")		
elseif (LDL_STATIC_LIBRARY)
    add_library(LDL_SDL_image STATIC "source/LDL/SDL_image/SDL_image.cpp")		
endif()
target_link_libraries(LDL_SDL_image LDL_SDL)

file(GLOB LDL_SDL2_SOURCE "source/LDL/SDL2/*.cpp")
if (LDL_SHARED_LIBRARY)
    add_library(LDL_SDL2 SHARED ${LDL_SDL2_SOURCE})		
elseif (LDL_STATIC_LIBRARY)
    add_library(LDL_SDL2 STATIC ${LDL_SDL2_SOURCE})		
endif()
target_link_libraries(LDL_SDL2 LDL)

file(GLOB LDL_SDL3_SOURCE "source/LDL/SDL3/*.cpp")
if (LDL_SHARED_LIBRARY)
    add_library(LDL_SDL3 SHARED ${LDL_SDL3_SOURCE})		
elseif (LDL_STATIC_LIBRARY)
    add_library(LDL_SDL3 STATIC ${LDL_SDL3_SOURCE})		
endif()
target_link_libraries(LDL_SDL3 LDL)

file(GLOB LDL_GLUT_SOURCE "source/LDL/GLUT/*.cpp")
if (LDL_SHARED_LIBRARY)
    add_library(LDL_GLUT SHARED ${LDL_GLUT_SOURCE})		
elseif (LDL_STATIC_LIBRARY)
    add_library(LDL_GLUT STATIC ${LDL_GLUT_SOURCE})		
endif()
target_link_libraries(LDL_GLUT LDL)

add_subdirectory("test")
add_subdirectory("examples")
add_subdirectory("demos")
