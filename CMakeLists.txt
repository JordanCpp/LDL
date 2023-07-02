cmake_minimum_required(VERSION 2.8)

# Uncomment for build shared library 
#set(LDL_SHARED_LIBRARY true)
#add_definitions(-DLDL_SHARED_LIBRARY)

# Default static library
set(LDL_STATIC_LIBRARY true)
add_definitions(-DLDL_STATIC_LIBRARY)

include_directories("include")

add_subdirectory("source")
add_subdirectory("Examples")

if (LDL_STATIC_LIBRARY)
  #add_subdirectory("test")
endif()