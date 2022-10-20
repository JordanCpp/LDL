cmake_minimum_required(VERSION 3.8)

add_executable(Point2u "Point2u.cpp")
target_link_libraries(Point2u LDL)

add_executable(Point2i "Point2i.cpp")
target_link_libraries(Point2i LDL)