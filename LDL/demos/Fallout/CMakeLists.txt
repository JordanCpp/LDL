
file(GLOB SOURCE_FILES "*.cpp")
add_executable(Fallout ${SOURCE_FILES})
target_link_libraries(Fallout LDL)