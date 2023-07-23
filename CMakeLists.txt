if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

# Uncomment for build shared library 
#set(LDL_SHARED_LIBRARY true)
#add_definitions(-DLDL_SHARED_LIBRARY)

# Default static library
set(LDL_STATIC_LIBRARY true)
add_definitions(-DLDL_STATIC_LIBRARY)

#Install FreeType
add_subdirectory(dependencies/freetype)
include_directories(dependencies/freetype/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/dependencies/freetype)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/dependencies/freetype)

include_directories("include")

add_subdirectory("source")
add_subdirectory("Examples")

if (LDL_STATIC_LIBRARY)
    add_subdirectory("test")
endif()