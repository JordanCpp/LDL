project(LDL)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

include_directories("../../include")

file(GLOB_RECURSE SOURCE_FILES 
"../../source/Renders/*.cpp"
"../../source/Shared/*.cpp"
"../../source/Linux/*.cpp")

add_library(LDL STATIC ${SOURCE_FILES})

add_executable(test "../../test.cpp")
target_link_libraries(test LDL)
