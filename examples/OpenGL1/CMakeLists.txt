add_executable(Figures "Figures.cpp")
target_link_libraries(Figures LDL)

add_executable(Primitive "Primitive.cpp")
target_link_libraries(Primitive LDL)

add_executable(Triangle "Triangle.cpp")
target_link_libraries(Triangle LDL)

add_executable(Tetrahedron "Tetrahedron.cpp")
target_link_libraries(Tetrahedron LDL)

add_executable(Sierpinski2D "Sierpinski2D.cpp")
target_link_libraries(Sierpinski2D LDL)
