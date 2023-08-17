
include_directories(../include)
file(GLOB_RECURSE SOURCE_GORDON_LIB "*.cpp")
add_library(GordonLib STATIC ${SOURCE_GORDON_LIB})
target_link_libraries(GordonLib LDL)