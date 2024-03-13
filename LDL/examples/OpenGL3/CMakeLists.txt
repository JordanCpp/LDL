add_definitions(-DLDL_SUPPORT_OPENGL3)

add_executable(01_GL3_Triangle "01_GL3_Triangle.cpp")
target_link_libraries(01_GL3_Triangle LDL)