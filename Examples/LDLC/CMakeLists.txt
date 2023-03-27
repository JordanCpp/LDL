cmake_minimum_required(VERSION 3.8)

add_executable(LDLC_01_WindowAndRender "LDLC_01_WindowAndRender.c")
target_link_libraries(LDLC_01_WindowAndRender LDL)

add_executable(LDLC_02_Color "LDLC_02_Color.c")
target_link_libraries(LDLC_02_Color LDL)