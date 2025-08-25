project(LDL)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)  
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
    "source/LDL/Platforms/Utils/*.cpp" 
    "source/LDL/Platforms/Windows/*.cpp")
elseif(UNIX AND NOT APPLE)
    file(GLOB_RECURSE SOURCE 
    "source/LDL/Shared/*.cpp" 
    "source/LDL/Platforms/Utils/*.cpp" 
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

#add_subdirectory("test")
add_subdirectory("examples")
add_subdirectory("ports")
