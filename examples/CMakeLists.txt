
if(LDL_BUILD_EXAMPLES AND LDL_BUILD_EXAMPLES_CPP11)
    enable_language(CXX)
    add_subdirectory("C++11")
endif()

if(LDL_BUILD_EXAMPLES AND LDL_BUILD_EXAMPLES_CPP98)
    enable_language(CXX)
    add_subdirectory("C++98")
endif()

if(LDL_BUILD_EXAMPLES AND LDL_BUILD_EXAMPLES_CPP98_GL3)
    enable_language(CXX)
    add_subdirectory("C++98_GL3")
endif()

if(LDL_BUILD_EXAMPLES AND LDL_BUILD_EXAMPLES_C89)
    add_subdirectory("C89")
endif()

if(LDL_BUILD_EXAMPLES AND LDL_BUILD_EXAMPLES_OPENGL1)
    add_subdirectory("OpenGL1")
endif()

if(LDL_BUILD_EXAMPLES AND LDL_BUILD_EXAMPLES_OPENGL2)
    add_subdirectory("OpenGL2")
endif()

if(LDL_BUILD_EXAMPLES AND LDL_BUILD_EXAMPLES_OPENGL3)
    add_subdirectory("OpenGL3")
endif()
