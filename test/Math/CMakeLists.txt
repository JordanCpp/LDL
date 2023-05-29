cmake_minimum_required(VERSION 3.8)

add_executable(Vec2 "Vec2.cpp")
target_link_libraries(Vec2 LDL)

add_executable(Vec3 "Vec3.cpp")
target_link_libraries(Vec3 LDL)

add_executable(Mat4 "Mat4.cpp")
target_link_libraries(Mat4 LDL)

add_executable(Funcs "Funcs.cpp")
target_link_libraries(Funcs LDL)