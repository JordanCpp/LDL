cmake_minimum_required(VERSION 3.12)

# Fix library and include paths for BSD systems.
if(CMAKE_SYSTEM_NAME MATCHES "BSD")
    list(APPEND CMAKE_PREFIX_PATH "/usr/local")
endif()

project(LDL)

if(MSVC)
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

set(SHARED_SOURCE
    "source/LDL/BaseWin.c"
    "source/LDL/Context.c"
    "source/LDL/EventH.c"
    "source/LDL/EventQ.c"
    "source/LDL/Events.c"
    "source/LDL/Format.c"
    "source/LDL/KeyMap.c"
    "source/LDL/Mapping.c"
    "source/LDL/Result.c"
    "source/LDL/StrSpan.c"
    "source/LDL/Vec2i.c"
)

set(OPENGL_SOURCE 
    "source/LDL/OpenGL/GLLoad.c"
    "source/LDL/OpenGL/GL1_0.c"
    "source/LDL/OpenGL/GL1_1.c"
    "source/LDL/OpenGL/GL1_2.c"
    "source/LDL/OpenGL/GL1_3.c"
    "source/LDL/OpenGL/GL1_4.c"
    "source/LDL/OpenGL/GL1_5.c"
    "source/LDL/OpenGL/GL2_0.c"
    "source/LDL/OpenGL/GL2_1.c"
    "source/LDL/OpenGL/GL3_0.c"
    "source/LDL/OpenGL/GL3_1.c"
    "source/LDL/OpenGL/GL3_2.c"
    "source/LDL/OpenGL/GL3_3.c"
    "source/LDL/OpenGL/GL4_0.c"
    "source/LDL/OpenGL/GL4_1.c"
    "source/LDL/OpenGL/GL4_2.c"
    "source/LDL/OpenGL/GL4_3.c"
    "source/LDL/OpenGL/GL4_4.c"
    "source/LDL/OpenGL/GL4_5.c"
    "source/LDL/OpenGL/GL4_6.c"
)

if(WIN32)
    set(PLATFORM_SOURCE
        "source/LDL/Win9x/GLFuncs.c"
        "source/LDL/Win9x/KMapper.c"
        "source/LDL/Win9x/Library.c"
        "source/LDL/Win9x/MainWin.c"
        "source/LDL/Win9x/Ticks.c"
        "source/LDL/Win9x/Window.c"
        "source/LDL/Win9x/WinError.c"
        "source/LDL/Win9x/WinGL1.c"
        "source/LDL/Win9x/WinGL3.c"
    )
elseif(UNIX AND NOT APPLE)
    set(PLATFORM_SOURCE 
        "source/LDL/Linux/GLFuncs.c"
        "source/LDL/Linux/KMapper.c"
        "source/LDL/Linux/Library.c"
        "source/LDL/Linux/MainWin.c"
        "source/LDL/Linux/Ticks.c"
        "source/LDL/Linux/Window.c"
        "source/LDL/Linux/WinGL.c"
    )
endif()

set(SOURCE
    ${SHARED_SOURCE}
    ${OPENGL_SOURCE}
    ${PLATFORM_SOURCE}
)

add_library(LDL ${SOURCE})

if(WIN32)
    target_link_libraries(LDL winmm opengl32 gdi32 user32)
elseif (UNIX AND NOT APPLE)
    target_link_libraries(LDL X11 GL dl m)
endif()

add_subdirectory("examples")
