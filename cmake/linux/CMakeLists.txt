project(LDL)

find_package(X11 REQUIRED)
link_libraries(${X11_LIBRARIES})
include_directories(${X11_INCLUDE_DIR})

include_directories("../../include")

file(GLOB_RECURSE SOURCE_FILES 
"../../source/Renders/*.cpp"
"../../source/Shared/*.cpp"
"../../source/Linux/*.cpp"
"../../source/OpenGL/*.cpp")

add_library(LDL STATIC ${SOURCE_FILES})
target_link_libraries(LDL GL dl)

add_executable(test "../../test.cpp")
target_link_libraries(test LDL)

add_executable(cpp01 "../../examples/cpp/cpp01.cpp")
target_link_libraries(cpp01 LDL)

add_executable(cpp02 "../../examples/cpp/cpp02.cpp")
target_link_libraries(cpp02 LDL)

add_executable(cpp03 "../../examples/cpp/cpp03.cpp")
target_link_libraries(cpp03 LDL)

add_executable(cpp04 "../../examples/cpp/cpp04.cpp")
target_link_libraries(cpp04 LDL)
