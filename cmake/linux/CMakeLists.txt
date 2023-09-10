project(LDL)

find_package(X11 REQUIRED)
link_libraries(${X11_LIBRARIES})
include_directories(${X11_INCLUDE_DIR})

include_directories("../../include")

file(GLOB_RECURSE SOURCE_FILES 
"../../source/Renders/*.cpp"
"../../source/Shared/*.cpp"
"../../source/Linux/*.cpp")

add_library(LDL STATIC ${SOURCE_FILES})

add_executable(test "../../test.cpp")
target_link_libraries(test LDL)
