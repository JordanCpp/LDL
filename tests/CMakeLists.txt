add_definitions(-DLDL_SUPPORT_OPENGL1)

add_executable(TestAll "TestAll.cpp")
target_link_libraries(TestAll LDLGL1)