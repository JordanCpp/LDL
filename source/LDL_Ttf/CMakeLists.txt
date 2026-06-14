
project(LDL_Ttf LANGUAGES C VERSION ${LDL_VERSION})

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED 99)

if(LDL_BUILD_LIBRARY_STATIC)
    add_library(LDL_Ttf STATIC "Ttf.c")
elseif(LDL_BUILD_LIBRARY_SHARED)
    add_library(LDL_Ttf SHARED "Ttf.c")
endif()

target_link_libraries(LDL_Ttf LDL freetype)
