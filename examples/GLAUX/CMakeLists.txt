
add_executable(glxHello "glxHello.c")
target_link_libraries(glxHello LDL_GLAUX)

add_executable(glxTrngl "glxTrngl.c")
target_link_libraries(glxTrngl LDL_GLAUX)

add_executable(BEZMESH "BEZMESH.C")
target_link_libraries(BEZMESH LDL_GLAUX)

add_executable(BEZSURF "BEZSURF.C")
target_link_libraries(BEZSURF LDL_GLAUX)

add_executable(FONT "FONT.C")
target_link_libraries(FONT LDL_GLAUX)
