project(LDL)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-DLDL_SHARED_LIBRARY)

include_directories("../../../include")

file(GLOB_RECURSE SOURCE_FILES 
"../../../source/Renders/*.cpp"
"../../../source/Low/*.cpp"
"../../../source/Windows/*.cpp"
"../../../source/OpenGL/*.cpp"
"../../../source/GLU/*.cpp"
"../../../source/WinGL/*.cpp")

add_library(LDL SHARED ${SOURCE_FILES})
target_link_libraries(LDL winmm opengl32)

add_executable(test "../../../test.cpp")
target_link_libraries(test LDL)

add_executable(cpp01 "../../../examples/cpp/cpp01.cpp")
target_link_libraries(cpp01 LDL)

add_executable(cpp02 "../../../examples/cpp/cpp02.cpp")
target_link_libraries(cpp02 LDL)

add_executable(cpp03 "../../../examples/cpp/cpp03.cpp")
target_link_libraries(cpp03 LDL)

add_executable(cpp04 "../../../examples/cpp/cpp04.cpp")
target_link_libraries(cpp04 LDL)

add_executable(cpp98_01 "../../../examples/cpp98/cpp98_01.cpp")
target_link_libraries(cpp98_01 LDL)
