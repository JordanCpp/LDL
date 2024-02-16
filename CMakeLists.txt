project(LDL_Proj)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)  
endif()

include_directories("include")

if (UNIX AND NOT APPLE)
    find_package(X11 REQUIRED)
    link_libraries(${X11_LIBRARIES})
    include_directories(${X11_INCLUDE_DIR})
endif()

if (WIN32)
    set(libs gdi32 user32 winmm opengl32)
elseif (UNIX AND NOT APPLE)
    set(libs X11 GL dl)
endif()

if (WIN32)
    file(GLOB SRC_FILES 
    "source/*.cpp" 
    "source/OpenGL/*.cpp" 
    "source/Renders/*.cpp" 
    "source/Platform/Windows/*.cpp")
elseif (UNIX AND NOT APPLE)
    file(GLOB SRC_FILES 
    "source/*.cpp" 
    "source/OpenGL/*.cpp" 
    "source/Renders/GL1Rndr.cpp" 
    "source/Platform/UNIX/*.cpp")
endif()

add_library(LDL STATIC ${SRC_FILES})
target_link_libraries(LDL ${libs})	

#add_definitions(-DLDL_SUPPORT_SOFTWARE)
add_definitions(-DLDL_SUPPORT_OPENGL1)

add_subdirectory("examples")
add_subdirectory("tests")
add_subdirectory("Arcanum")
