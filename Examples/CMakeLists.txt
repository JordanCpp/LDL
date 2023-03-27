cmake_minimum_required(VERSION 3.8)

add_subdirectory("Graphics")
add_subdirectory("LDLC")

if (LDL_RENDER_DIRECTX9)
  add_subdirectory("DirectX9")
endif()