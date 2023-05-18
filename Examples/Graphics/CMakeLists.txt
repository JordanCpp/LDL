cmake_minimum_required(VERSION 3.8)

add_executable(01_WindowAndRender "01_WindowAndRender.cpp")
target_link_libraries(01_WindowAndRender LDL)

add_executable(02_Color "02_Color.cpp")
target_link_libraries(02_Color LDL)

add_executable(03_Line "03_Line.cpp")
target_link_libraries(03_Line LDL)

add_executable(04_Rect "04_Rect.cpp")
target_link_libraries(04_Rect LDL)

add_executable(05_Texture "05_Texture.cpp")
target_link_libraries(05_Texture LDL)

add_executable(06_Click "06_Click.cpp")
target_link_libraries(06_Click LDL)

add_executable(07_Motion "07_Motion.cpp")
target_link_libraries(07_Motion LDL)

add_executable(08_Surface "08_Surface.cpp")
target_link_libraries(08_Surface LDL)

add_executable(09_ColorKey "09_ColorKey.cpp")
target_link_libraries(09_ColorKey LDL)

add_executable(10_TileMap "10_TileMap.cpp")
target_link_libraries(10_TileMap LDL)

add_executable(11_Resize "11_Resize.cpp")
target_link_libraries(11_Resize LDL)

add_executable(12_TileMap2 "12_TileMap2.cpp")
target_link_libraries(12_TileMap2 LDL)

add_executable(13_TileMapBatcher "13_TileMapBatcher.cpp")
target_link_libraries(13_TileMapBatcher LDL)