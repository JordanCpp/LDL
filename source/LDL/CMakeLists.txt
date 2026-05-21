project(LDL
    LANGUAGES C OBJC
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
if(WIN32)
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
        ${LDL_ROOT_FOLDER}/source/LDL/macOS/Window.m
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
if(WIN32 AND MSVC)
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
if(WIN32)
    target_include_directories(${PROJECT_NAME} PRIVATE ${LDL_ROOT_FOLDER}/source/LDL/Win9x)
elseif(UNIX AND NOT APPLE)
    target_include_directories(${PROJECT_NAME} PRIVATE ${LDL_ROOT_FOLDER}/source/LDL/Linux)
elseif(APPLE)
    target_include_directories(${PROJECT_NAME} PRIVATE ${LDL_ROOT_FOLDER}/source/LDL/macOS)
endif()

target_compile_options(${PROJECT_NAME} PUBLIC ${LDL_BUILD_FLAGS})
target_compile_definitions(${PROJECT_NAME} PUBLIC ${LDL_BUILD_DEFINES})

if(APPLE)
    target_compile_options(${PROJECT_NAME} PRIVATE -Wno-deprecated-declarations)
endif()

if(WIN32)
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
