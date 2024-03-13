project(LDL_Image)

add_definitions(-DLDL_IMAGE_SHARED)

include_directories("include")
add_library(LDL_Image STATIC "source/LDL_Image.cpp")

add_executable(test "test.cpp")
target_link_libraries(test LDL_Image)
