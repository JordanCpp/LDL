
add_subdirectory("Graphics")
add_subdirectory("Loaders")
add_subdirectory("Core")
add_subdirectory("Input")
add_subdirectory("Performance")
add_subdirectory("Math")

add_executable(SDL1Test "SDL1Test.cpp")
target_link_libraries(SDL1Test LDL_SDL)
