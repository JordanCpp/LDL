cmake_minimum_required(VERSION 3.12)

project(LDL)

option(LDL_BUILD_LIBRARY_STATIC "Enable building static library" ON)
option(LDL_BUILD_LIBRARY_SHARED "Enable building shared library" OFF)

option(LDL_BUILD_EXAMPLES "Enable building examples" OFF)
option(LDL_BUILD_EXAMPLES_C89 "Enable building examples for С89" ON)
option(LDL_BUILD_EXAMPLES_CPP98 "Enable building examples for С++ 98" ON)
option(LDL_BUILD_EXAMPLES_CPP98_GL3 "Enable building examples for С++ 98 OpenGl 3.x" ON)
option(LDL_BUILD_EXAMPLES_CPP11 "Enable building examples for С++ 11" ON)
option(LDL_BUILD_EXAMPLES_OPENGL2 "Enable building examples for OpenGL 2" ON)
option(LDL_BUILD_EXAMPLES_OPENGL1 "Enable building examples for OpenGL 1" ON)
option(LDL_BUILD_EXAMPLES_OPENGL2 "Enable building examples for OpenGL 2" ON)
option(LDL_BUILD_EXAMPLES_OPENGL3 "Enable building examples for OpenGL 3" ON)
option(LDL_BUILD_EXAMPLES_2D_RENDER_CPP "Enable building examples for 2D render for C++" ON)
option(LDL_BUILD_EXAMPLES_3D_RENDER_CPP "Enable building examples for 3D render for C++" ON)
option(LDL_BUILD_EXAMPLES_3D_RENDER_C89 "Enable building examples for 3D render for C89" ON)
option(LDL_BUILD_DEMO_FALLOUT "Enable building demo fallout" ON)

option(LDL_ENABLE_INSTALL "Enable install target for library" OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)

set(CMAKE_SKIP_RPATH FALSE)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

include(GNUInstallDirs)

set(LDL_VERSION_MAJOR 0)
set(LDL_VERSION_MINOR 1)
set(LDL_VERSION_PATCH 0)
set(LDL_VERSION "${LDL_VERSION_MAJOR}.${LDL_VERSION_MINOR}.${LDL_VERSION_PATCH}")
set(LDL_VERSION_SHORT "${LDL_VERSION_MAJOR}.${LDL_VERSION_MINOR}")

set(LDL_ROOT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})
set(LDL_BUILD_FOLDER ${CMAKE_CURRENT_BINARY_DIR})

if(LDL_BUILD_LIBRARY_STATIC)
    set(LDL_BUILD_DEFINES -DLDL_STATIC_LIBRARY)
elseif(LDL_BUILD_LIBRARY_SHARED)
    set(LDL_BUILD_DEFINES -DLDL_SHARED_LIBRARY)
endif()
if(WIN32 AND MSVC)
    set(LDL_BUILD_FLAGS /analyze)
    set(LDL_BUILD_DEFINES ${LDL_BUILD_DEFINES} -D_CRT_SECURE_NO_WARNINGS -D_CRT_NONSTDC_NO_DEPRECATE)
endif()

if(UNIX AND NOT APPLE)
    find_package(LibM REQUIRED)
    find_package(LibDl REQUIRED)
    find_package(X11 REQUIRED)
    find_package(OpenGL REQUIRED)
elseif(APPLE)
    find_package(OpenGL)
    find_library(COCOA_FRAMEWORK Cocoa REQUIRED)
    find_library(IOKIT_FRAMEWORK IOKit REQUIRED)
    find_library(COREVIDEO_FRAMEWORK CoreVideo REQUIRED)
endif()

include_directories(${LDL_ROOT_FOLDER}/include)

add_subdirectory("source")
add_subdirectory("examples")
add_subdirectory("demos")

add_executable(tests test/tests.c)
target_link_libraries(tests LDL)

include(InstallLdl)
