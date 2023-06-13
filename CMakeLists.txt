cmake_minimum_required(VERSION 3.8)

# Uncomment for build shared library 
#set(LDL_SHARED_LIBRARY true)
#add_definitions(-DLDL_SHARED_LIBRARY)

# Default static library
set(LDL_STATIC_LIBRARY true)
add_definitions(-DLDL_STATIC_LIBRARY)

# Render OpenGL 3.3
#set(LDL_RENDER_OPENGL3 true)

# Render OpenGL 1.2
set(LDL_RENDER_OPENGL1 true)

# Render Software
##set(LDL_RENDER_SOFTWARE true)

include_directories("include")

add_subdirectory("source")
add_subdirectory("Examples")

if (LDL_STATIC_LIBRARY)
  add_subdirectory("test")
endif()