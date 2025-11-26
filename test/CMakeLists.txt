
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/TestFiles DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

add_executable(SDL1Test "SDL1Test.cpp")
target_link_libraries(SDL1Test LDL_SDL)

add_executable(LDLTest "LDLTest.cpp")
target_link_libraries(LDLTest LDL)
