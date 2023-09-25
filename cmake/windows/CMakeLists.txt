project(LDL)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-D_LDL_STATIC_LIBRARY)

include_directories("../../include")

file(GLOB_RECURSE SOURCE_FILES 
"../../source/Renders/*.cpp"
"../../source/Shared/*.cpp"
"../../source/Windows/*.cpp"
"../../source/OpenGL/*.cpp"
"../../source/WinGL/*.cpp")

add_library(LDL STATIC ${SOURCE_FILES})
target_link_libraries(LDL winmm opengl32)

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
