project(LDL
    LANGUAGES C
    VERSION ${LDL_VERSION}
)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED 90)

set(LDL_INCLUDES_API
    ${LDL_ROOT_FOLDER}/include/LDL/Config.h
    ${LDL_ROOT_FOLDER}/include/LDL/Context.h
    ${LDL_ROOT_FOLDER}/include/LDL/Enums.h
    ${LDL_ROOT_FOLDER}/include/LDL/Events.h
    ${LDL_ROOT_FOLDER}/include/LDL/Format.h
    ${LDL_ROOT_FOLDER}/include/LDL/LDL.h
    ${LDL_ROOT_FOLDER}/include/LDL/Library.h
    ${LDL_ROOT_FOLDER}/include/LDL/Result.h
    ${LDL_ROOT_FOLDER}/include/LDL/Ticks.h
    ${LDL_ROOT_FOLDER}/include/LDL/Types.h
    ${LDL_ROOT_FOLDER}/include/LDL/Vec2i.h
    ${LDL_ROOT_FOLDER}/include/LDL/Window.h
)
set(LDL_INCLUDES_API_OPENGL
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL1_0.h
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL1_1.h
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL1_2.h
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL1_3.h
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL1_4.h
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL1_5.h
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL2_0.h
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL2_1.h
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL3_0.h
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL3_1.h
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL3_2.h
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL3_3.h
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL4_0.h
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL4_1.h
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL4_2.h
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL4_3.h
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL4_4.h
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL4_5.h
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL4_6.h
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GLConsts.h
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GLLoad.h
    ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GLTypes.h
)

set(LDL_INCLUDES_COMMON
    ${LDL_ROOT_FOLDER}/source/LDL/BaseWin.h
    ${LDL_ROOT_FOLDER}/source/LDL/EventH.h
    ${LDL_ROOT_FOLDER}/source/LDL/EventQ.h
    ${LDL_ROOT_FOLDER}/source/LDL/KeyMap.h
    ${LDL_ROOT_FOLDER}/source/LDL/Mapping.h
    ${LDL_ROOT_FOLDER}/source/LDL/StrSpan.h
)
set(LDL_SOURCES_COMMON
    ${LDL_ROOT_FOLDER}/source/LDL/BaseWin.c
    ${LDL_ROOT_FOLDER}/source/LDL/Context.c
    ${LDL_ROOT_FOLDER}/source/LDL/EventH.c
    ${LDL_ROOT_FOLDER}/source/LDL/EventQ.c
    ${LDL_ROOT_FOLDER}/source/LDL/Events.c
    ${LDL_ROOT_FOLDER}/source/LDL/Format.c
    ${LDL_ROOT_FOLDER}/source/LDL/KeyMap.c
    ${LDL_ROOT_FOLDER}/source/LDL/Mapping.c
    ${LDL_ROOT_FOLDER}/source/LDL/Result.c
    ${LDL_ROOT_FOLDER}/source/LDL/StrSpan.c
    ${LDL_ROOT_FOLDER}/source/LDL/Vec2i.c
)
set(LDL_SOURCES_OPENGL
    ${LDL_ROOT_FOLDER}/source/LDL/OpenGL/GLLoad.c
    ${LDL_ROOT_FOLDER}/source/LDL/OpenGL/GL1_0.c
    ${LDL_ROOT_FOLDER}/source/LDL/OpenGL/GL1_1.c
    ${LDL_ROOT_FOLDER}/source/LDL/OpenGL/GL1_2.c
    ${LDL_ROOT_FOLDER}/source/LDL/OpenGL/GL1_3.c
    ${LDL_ROOT_FOLDER}/source/LDL/OpenGL/GL1_4.c
    ${LDL_ROOT_FOLDER}/source/LDL/OpenGL/GL1_5.c
    ${LDL_ROOT_FOLDER}/source/LDL/OpenGL/GL2_0.c
    ${LDL_ROOT_FOLDER}/source/LDL/OpenGL/GL2_1.c
    ${LDL_ROOT_FOLDER}/source/LDL/OpenGL/GL3_0.c
    ${LDL_ROOT_FOLDER}/source/LDL/OpenGL/GL3_1.c
    ${LDL_ROOT_FOLDER}/source/LDL/OpenGL/GL3_2.c
    ${LDL_ROOT_FOLDER}/source/LDL/OpenGL/GL3_3.c
    ${LDL_ROOT_FOLDER}/source/LDL/OpenGL/GL4_0.c
    ${LDL_ROOT_FOLDER}/source/LDL/OpenGL/GL4_1.c
    ${LDL_ROOT_FOLDER}/source/LDL/OpenGL/GL4_2.c
    ${LDL_ROOT_FOLDER}/source/LDL/OpenGL/GL4_3.c
    ${LDL_ROOT_FOLDER}/source/LDL/OpenGL/GL4_4.c
    ${LDL_ROOT_FOLDER}/source/LDL/OpenGL/GL4_5.c
    ${LDL_ROOT_FOLDER}/source/LDL/OpenGL/GL4_6.c
)

set(LDL_INCLUDES_RENDERS
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/GL/BufferGL.h
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/GL/GLUtils.h
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/GL/TexGL.h
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/GL/2DRGL1.h
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/GL/2DRGL2.h
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/GL/2DRGL3.h
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/GL/3DRGL1.h
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/GL/3DRGL2.h
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/GL/3DRGL3.h
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/Soft/BufSoft.h
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/Soft/PixCopy.h
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/Soft/PixPaint.h
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/Soft/RndrSoft.h
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/Soft/TexSoft.h
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/BaseRndr.h
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/Texture.h
)

set(LDL_SOURCES_RENDERS
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/GL/BufferGL.c
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/GL/GLUtils.c
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/GL/TexGL.c
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/GL/2DRGL1.c
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/GL/2DRGL2.c
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/GL/2DRGL3.c
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/GL/3DRGL1.c
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/GL/3DRGL2.c
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/GL/3DRGL3.c
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/Soft/BufSoft.c
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/Soft/PixCopy.c
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/Soft/PixPaint.c
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/Soft/RndrSoft.c
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/Soft/TexSoft.c
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/BaseRndr.c
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/Color.c
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/Mat4f.c
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/2DRender.c
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/Surface.c
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/Texture.c
    ${LDL_ROOT_FOLDER}/source/LDL/Renders/3DRender.c
)

if(EMSCRIPTEN)
    # IMPORTANT: EMSCRIPTEN must be checked first because emcmake leaves
    # WIN32/APPLE/UNIX set to the host platform values, so checking
    # them first would pick the wrong backend when cross-compiling.
    set(LDL_INCLUDES_PLATFORM
        ${LDL_ROOT_FOLDER}/source/LDL/Emscripten/GLFuncs.h
        ${LDL_ROOT_FOLDER}/source/LDL/Emscripten/KMapper.h
        ${LDL_ROOT_FOLDER}/source/LDL/Emscripten/MainWin.h
        ${LDL_ROOT_FOLDER}/source/LDL/Emscripten/WinGL.h
    )
    set(LDL_SOURCES_PLATFORM
        ${LDL_ROOT_FOLDER}/source/LDL/Emscripten/GLFuncs.c
        ${LDL_ROOT_FOLDER}/source/LDL/Emscripten/KMapper.c
        ${LDL_ROOT_FOLDER}/source/LDL/Emscripten/Library.c
        ${LDL_ROOT_FOLDER}/source/LDL/Emscripten/MainWin.c
        ${LDL_ROOT_FOLDER}/source/LDL/Emscripten/Ticks.c
        ${LDL_ROOT_FOLDER}/source/LDL/Emscripten/Window.c
        ${LDL_ROOT_FOLDER}/source/LDL/Emscripten/WinGL.c
    )
elseif(WIN32)
    set(LDL_INCLUDES_PLATFORM
        ${LDL_ROOT_FOLDER}/source/LDL/Win9x/GLFuncs.h
        ${LDL_ROOT_FOLDER}/source/LDL/Win9x/KMapper.h
        ${LDL_ROOT_FOLDER}/source/LDL/Win9x/MainWin.h
        ${LDL_ROOT_FOLDER}/source/LDL/Win9x/WinError.h
        ${LDL_ROOT_FOLDER}/source/LDL/Win9x/WinGL1.h
        ${LDL_ROOT_FOLDER}/source/LDL/Win9x/WinGL3.h
        ${LDL_ROOT_FOLDER}/source/LDL/Win9x/WinX.h
    )
    set(LDL_SOURCES_PLATFORM
        ${LDL_ROOT_FOLDER}/source/LDL/Win9x/GLFuncs.c
        ${LDL_ROOT_FOLDER}/source/LDL/Win9x/KMapper.c
        ${LDL_ROOT_FOLDER}/source/LDL/Win9x/Library.c
        ${LDL_ROOT_FOLDER}/source/LDL/Win9x/MainWin.c
        ${LDL_ROOT_FOLDER}/source/LDL/Win9x/Ticks.c
        ${LDL_ROOT_FOLDER}/source/LDL/Win9x/Window.c
        ${LDL_ROOT_FOLDER}/source/LDL/Win9x/WinError.c
        ${LDL_ROOT_FOLDER}/source/LDL/Win9x/WinGL1.c
        ${LDL_ROOT_FOLDER}/source/LDL/Win9x/WinGL3.c
    )
elseif(UNIX AND NOT APPLE)
    set(LDL_INCLUDES_PLATFORM
        ${LDL_ROOT_FOLDER}/source/LDL/Linux/GLFuncs.h
        ${LDL_ROOT_FOLDER}/source/LDL/Linux/GLX.h
        ${LDL_ROOT_FOLDER}/source/LDL/Linux/KMapper.h
        ${LDL_ROOT_FOLDER}/source/LDL/Linux/MainWin.h
        ${LDL_ROOT_FOLDER}/source/LDL/Linux/WinGL.h
    )
    set(LDL_SOURCES_PLATFORM
        ${LDL_ROOT_FOLDER}/source/LDL/Linux/GLFuncs.c
        ${LDL_ROOT_FOLDER}/source/LDL/Linux/KMapper.c
        ${LDL_ROOT_FOLDER}/source/LDL/Linux/Library.c
        ${LDL_ROOT_FOLDER}/source/LDL/Linux/MainWin.c
        ${LDL_ROOT_FOLDER}/source/LDL/Linux/Ticks.c
        ${LDL_ROOT_FOLDER}/source/LDL/Linux/Window.c
        ${LDL_ROOT_FOLDER}/source/LDL/Linux/WinGL.c
    )
elseif(APPLE)
    enable_language(OBJC)
    set(LDL_INCLUDES_PLATFORM
        ${LDL_ROOT_FOLDER}/source/LDL/macOS/GLFuncs.h
        ${LDL_ROOT_FOLDER}/source/LDL/macOS/KMapper.h
        ${LDL_ROOT_FOLDER}/source/LDL/macOS/MainWin.h
        ${LDL_ROOT_FOLDER}/source/LDL/macOS/WinGL.h
    )
    set(LDL_SOURCES_PLATFORM
        ${LDL_ROOT_FOLDER}/source/LDL/macOS/GLFuncs.c
        ${LDL_ROOT_FOLDER}/source/LDL/macOS/KMapper.c
        ${LDL_ROOT_FOLDER}/source/LDL/macOS/Library.c
        ${LDL_ROOT_FOLDER}/source/LDL/macOS/MainWin.m
        ${LDL_ROOT_FOLDER}/source/LDL/macOS/Ticks.c
        ${LDL_ROOT_FOLDER}/source/LDL/macOS/Window.c
        ${LDL_ROOT_FOLDER}/source/LDL/macOS/WinGL.m
    )
endif()

source_group("Api" FILES ${LDL_INCLUDES_API})
source_group("Api/OpenGL" FILES ${LDL_INCLUDES_API_OPENGL})
source_group("Core" FILES ${LDL_INCLUDES_COMMON})
source_group("Core" FILES ${LDL_SOURCES_COMMON})
source_group("Core/OpenGL" FILES ${LDL_SOURCES_OPENGL})
source_group("Core/Platform" FILES ${LDL_INCLUDES_PLATFORM})
source_group("Core/Platform" FILES ${LDL_SOURCES_PLATFORM})

if(LDL_BUILD_LIBRARY_STATIC)
    add_library(${PROJECT_NAME} STATIC
        ${LDL_INCLUDES_API}
        ${LDL_INCLUDES_API_OPENGL}
        ${LDL_INCLUDES_COMMON}
        ${LDL_SOURCES_COMMON}
        ${LDL_SOURCES_OPENGL}
        ${LDL_INCLUDES_PLATFORM}
        ${LDL_SOURCES_PLATFORM}
    )
elseif(LDL_BUILD_LIBRARY_SHARED)
    add_library(${PROJECT_NAME} SHARED
        ${LDL_INCLUDES_API}
        ${LDL_INCLUDES_API_OPENGL}
        ${LDL_INCLUDES_COMMON}
        ${LDL_SOURCES_COMMON}
        ${LDL_SOURCES_OPENGL}
        ${LDL_INCLUDES_PLATFORM}
        ${LDL_SOURCES_PLATFORM}
    )
endif()

add_library(LDL::Library ALIAS ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        ENABLE_EXPORTS TRUE
)
if(EMSCRIPTEN)
    set_target_properties(${PROJECT_NAME}
        PROPERTIES
            OUTPUT_NAME LDL
    )
elseif(WIN32 AND MSVC)
    set_target_properties(${PROJECT_NAME}
        PROPERTIES
            OUTPUT_NAME LDL
    )
elseif(UNIX AND NOT APPLE)
    set_target_properties(${PROJECT_NAME}
        PROPERTIES
            OUTPUT_NAME LDL${LDL_VERSION}
            SOVERSION ${LDL_VERSION_PATCH}
            INSTALL_RPATH "$ORIGIN"
            BUILD_WITH_INSTALL_RPATH TRUE
    )
elseif(APPLE)
    set_target_properties(${PROJECT_NAME}
        PROPERTIES
            OUTPUT_NAME LDL${LDL_VERSION}
    )
endif()

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${LDL_ROOT_FOLDER}/include/LDL>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/LDL>
)
target_include_directories(${PROJECT_NAME} PRIVATE ${LDL_ROOT_FOLDER}/source)
target_include_directories(${PROJECT_NAME} PRIVATE ${LDL_ROOT_FOLDER}/source/LDL)
if(EMSCRIPTEN)
    target_include_directories(${PROJECT_NAME} PRIVATE ${LDL_ROOT_FOLDER}/source/LDL/Emscripten)
elseif(WIN32)
    target_include_directories(${PROJECT_NAME} PRIVATE ${LDL_ROOT_FOLDER}/source/LDL/Win9x)
elseif(UNIX AND NOT APPLE)
    target_include_directories(${PROJECT_NAME} PRIVATE ${LDL_ROOT_FOLDER}/source/LDL/Linux)
elseif(APPLE)
    target_include_directories(${PROJECT_NAME} PRIVATE ${LDL_ROOT_FOLDER}/source/LDL/macOS)
endif()

target_compile_options(${PROJECT_NAME} PUBLIC ${LDL_BUILD_FLAGS})
target_compile_definitions(${PROJECT_NAME} PUBLIC ${LDL_BUILD_DEFINES})

if(APPLE AND NOT EMSCRIPTEN)
    # NOTE: AND NOT EMSCRIPTEN - emcmake leaves APPLE=TRUE on macOS hosts
    # when cross-compiling, so this guard prevents a macOS-only warning
    # flag from leaking into the wasm build.
    target_compile_options(${PROJECT_NAME} PRIVATE -Wno-deprecated-declarations)
endif()

if(EMSCRIPTEN)
    # Emscripten links WebGL/HTML5 through compiler/linker flags; GL is
    # the emulated OpenGL ES stub provided by the toolchain.
    #
    # These are PUBLIC, so they propagate as usage requirements to every
    # executable that links LDL::Library (see cmake/emscripten/
    # EmscriptenTarget.cmake, which sets its own copy of the same flags
    # for clarity/standalone use).
    #
    # IMPORTANT: fused "-sNAME=VALUE" form (no space), not "SHELL:-s
    # NAME=VALUE" or separate "-s"/"NAME=VALUE" list elements - either
    # of those produces two independent argv tokens by the time emcc's
    # argument parser sees them, which makes emcc treat the bare
    # "NAME=VALUE" half as a stray input filename and fail with e.g.
    # "emcc: error: FULL_ES3=1: No such file or directory".
    target_link_options(${PROJECT_NAME} PUBLIC
        "-sUSE_WEBGL2=1"
        "-sFULL_ES3=1"
        "-sMIN_WEBGL_VERSION=1"
        "-sMAX_WEBGL_VERSION=2"
        "-sALLOW_MEMORY_GROWTH=1"
    )
    target_link_libraries(${PROJECT_NAME} PUBLIC GL)
elseif(WIN32)
    target_link_libraries(${PROJECT_NAME} PUBLIC winmm gdi32 user32 opengl32)
elseif(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} PUBLIC LibM::Library)
    target_link_libraries(${PROJECT_NAME} PUBLIC LibDl::Library)
    target_link_libraries(${PROJECT_NAME} PUBLIC X11::Library)
    target_link_libraries(${PROJECT_NAME} PUBLIC OpenGL::Library)
elseif(APPLE)
    find_library(COCOA_FRAMEWORK     Cocoa)
    find_library(IOKIT_FRAMEWORK     IOKit)
    find_library(COREVIDEO_FRAMEWORK CoreVideo)
    find_library(OPENGL_FRAMEWORK    OpenGL)

    target_link_libraries(${PROJECT_NAME} PUBLIC ${COCOA_FRAMEWORK})
    target_link_libraries(${PROJECT_NAME} PUBLIC ${IOKIT_FRAMEWORK})
    target_link_libraries(${PROJECT_NAME} PUBLIC ${COREVIDEO_FRAMEWORK})
    target_link_libraries(${PROJECT_NAME} PUBLIC ${OPENGL_FRAMEWORK})
endif()
