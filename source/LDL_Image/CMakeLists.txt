
project(LDL_Image LANGUAGES C VERSION ${LDL_VERSION})

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED 99)

if(LDL_BUILD_LIBRARY_STATIC)
    add_library(LDL_Image STATIC "Image.c")
elseif(LDL_BUILD_LIBRARY_SHARED)
    add_library(LDL_Image SHARED "Image.c")
endif()

target_link_libraries(LDL_Image LDL)
