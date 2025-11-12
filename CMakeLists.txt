
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

include_directories("include")
include_directories("source")

if (WIN32)
    file(GLOB_RECURSE SOURCE 
    "source/LDL/Shared/*.cpp" 
    "source/LDL/APIs/OpenGL/*.cpp" 
    "source/LDL/Platforms/Windows/*.cpp")
elseif(UNIX AND NOT APPLE)
    file(GLOB_RECURSE SOURCE 
    "source/LDL/Shared/*.cpp" 
    "source/LDL/APIs/OpenGL/*.cpp" 
    "source/LDL/Platforms/Linux/*.cpp")
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

file(GLOB LDL_SDL_SOURCE "source/LDL/APIs/SDL/*.cpp")
add_library(LDL_SDL STATIC ${LDL_SDL_SOURCE})	
target_link_libraries(LDL_SDL LDL)

file(GLOB LDL_SDL2_SOURCE "source/LDL/APIs/SDL2/*.cpp")
add_library(LDL_SDL2 STATIC ${LDL_SDL2_SOURCE})	
target_link_libraries(LDL_SDL2 LDL)

file(GLOB LDL_SDL3_SOURCE "source/LDL/APIs/SDL3/*.cpp")
add_library(LDL_SDL3 STATIC ${LDL_SDL3_SOURCE})	
target_link_libraries(LDL_SDL3 LDL)

file(GLOB LDL_GLUT_SOURCE "source/LDL/APIs/GLUT/*.cpp")
add_library(LDL_GLUT STATIC ${LDL_GLUT_SOURCE})	
target_link_libraries(LDL_GLUT LDL)

add_subdirectory("test")
add_subdirectory("examples")
add_subdirectory("demos")
