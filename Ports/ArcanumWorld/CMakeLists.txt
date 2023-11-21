
set(CMAKE_CXX_STANDARD 11)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

#Install zlib
include_directories(dependencies/zlib)
file(GLOB_RECURSE SOURCE_ZLIB 
"dependencies/zlib/adler32.c"
"dependencies/zlib/compress.c"
"dependencies/zlib/crc32.c"
"dependencies/zlib/deflate.c"
"dependencies/zlib/gzclose.c"
"dependencies/zlib/gzlib.c"
"dependencies/zlib/gzread.c"
"dependencies/zlib/gzwrite.c"
"dependencies/zlib/infback.c"
"dependencies/zlib/inffast.c"
"dependencies/zlib/inflate.c"
"dependencies/zlib/inftrees.c"
"dependencies/zlib/trees.c"
"dependencies/zlib/uncompr.c"
"dependencies/zlib/zutil.c")
add_library(Zlib STATIC ${SOURCE_ZLIB})

include_directories("source/Shared")

file(GLOB_RECURSE SOURCE_FILES "source/Shared/*.cpp")

add_library(ArcanumLib STATIC ${SOURCE_FILES})

target_link_libraries(ArcanumLib LDL Zlib)

add_executable(ArcanumWorld "source/ArcanumWorld.cpp")
target_link_libraries(ArcanumWorld ArcanumLib)

add_executable(GenMap "source/GenMap.cpp")
target_link_libraries(GenMap ArcanumLib)