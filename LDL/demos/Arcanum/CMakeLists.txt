
file(GLOB ARCANUM_FILES "*.cpp")
add_executable(Arcanum ${ARCANUM_FILES})
target_link_libraries(Arcanum LDL)