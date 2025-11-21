
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
include_directories("src")

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
    "src/LDL/Cpp98/*.cpp"
    "src/LDL/Renders/GL/*.cpp" 
    "src/LDL/Renders/GL1/*.cpp" 
    "src/LDL/Renders/GL3/*.cpp" 
    "src/LDL/Renders/Soft/*.cpp"
    "src/LDL/*.cpp" 
    "src/LDL/OpenGL/*.cpp" 
    "src/LDL/${LDL_WINDOWS_NAME}/*.cpp")
elseif(UNIX AND NOT APPLE)
    file(GLOB_RECURSE SOURCE 
    "src/LDL/Shared/*.cpp" 
    "src/LDL/APIs/OpenGL/*.cpp" 
    "src/LDL/Linux/*.cpp")
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

file(GLOB LDL_SDL_SOURCE "src/LDL/SDL/*.cpp")
if (LDL_SHARED_LIBRARY)
    add_library(LDL_SDL SHARED ${LDL_SDL_SOURCE})		
elseif (LDL_STATIC_LIBRARY)
    add_library(LDL_SDL STATIC ${LDL_SDL_SOURCE})		
endif()
target_link_libraries(LDL_SDL LDL)

if (LDL_SHARED_LIBRARY)
    add_library(LDL_SDL_image SHARED "src/LDL/SDL_image/SDL_image.cpp")		
elseif (LDL_STATIC_LIBRARY)
    add_library(LDL_SDL_image STATIC "src/LDL/SDL_image/SDL_image.cpp")		
endif()
target_link_libraries(LDL_SDL_image LDL_SDL)

file(GLOB LDL_SDL2_SOURCE "src/LDL/SDL2/*.cpp")
if (LDL_SHARED_LIBRARY)
    add_library(LDL_SDL2 SHARED ${LDL_SDL2_SOURCE})		
elseif (LDL_STATIC_LIBRARY)
    add_library(LDL_SDL2 STATIC ${LDL_SDL2_SOURCE})		
endif()
target_link_libraries(LDL_SDL2 LDL)

file(GLOB LDL_SDL3_SOURCE "src/LDL/SDL3/*.cpp")
if (LDL_SHARED_LIBRARY)
    add_library(LDL_SDL3 SHARED ${LDL_SDL3_SOURCE})		
elseif (LDL_STATIC_LIBRARY)
    add_library(LDL_SDL3 STATIC ${LDL_SDL3_SOURCE})		
endif()
target_link_libraries(LDL_SDL3 LDL)

file(GLOB LDL_GLUT_SOURCE "src/LDL/GLUT/*.cpp")
if (LDL_SHARED_LIBRARY)
    add_library(LDL_GLUT SHARED ${LDL_GLUT_SOURCE})		
elseif (LDL_STATIC_LIBRARY)
    add_library(LDL_GLUT STATIC ${LDL_GLUT_SOURCE})		
endif()
target_link_libraries(LDL_GLUT LDL)

add_subdirectory("test")
add_subdirectory("examples")
add_subdirectory("demos")
