cmake_minimum_required(VERSION 3.8)

add_executable(01_SettingUpAnOpenGLWindow "01_SettingUpAnOpenGLWindow.cpp")
target_link_libraries(01_SettingUpAnOpenGLWindow LDL)

add_executable(02_YourFirstPolygon "02_YourFirstPolygon.cpp")
target_link_libraries(02_YourFirstPolygon LDL)

add_executable(03_AddingColor "03_AddingColor.cpp")
target_link_libraries(03_AddingColor LDL)

add_executable(04_Rotation "04_Rotation.cpp")
target_link_libraries(04_Rotation LDL)

add_executable(05_3DShapes "05_3DShapes.cpp")
target_link_libraries(05_3DShapes LDL)

add_executable(06_TextureMapping "06_TextureMapping.cpp")
target_link_libraries(06_TextureMapping LDL)