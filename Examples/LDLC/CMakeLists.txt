cmake_minimum_required(VERSION 3.8)

add_executable(LDLC_01_WindowAndRender "LDLC_01_WindowAndRender.c")
target_link_libraries(LDLC_01_WindowAndRender LDL)

add_executable(LDLC_02_Color "LDLC_02_Color.c")
target_link_libraries(LDLC_02_Color LDL)

add_executable(LDLC_03_Line "LDLC_03_Line.c")
target_link_libraries(LDLC_03_Line LDL)

add_executable(LDLC_04_Rect "LDLC_04_Rect.c")
target_link_libraries(LDLC_04_Rect LDL)

add_executable(LDLC_05_Texture "LDLC_05_Texture.c")
target_link_libraries(LDLC_05_Texture LDL)