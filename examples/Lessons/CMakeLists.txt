
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

add_executable(01_WindowAndRender "01_WindowAndRender.cpp")
target_link_libraries(01_WindowAndRender LDL)

add_executable(02_Color "02_Color.cpp")
target_link_libraries(02_Color LDL)

add_executable(03_Line "03_Line.cpp")
target_link_libraries(03_Line LDL)

add_executable(04_Rect "04_Rect.cpp")
target_link_libraries(04_Rect LDL)

add_executable(05_Surface "05_Surface.cpp")
target_link_libraries(05_Surface LDL)

add_executable(06_Texture "06_Texture.cpp")
target_link_libraries(06_Texture LDL)

add_executable(07_TileMapRandom "07_TileMapRandom.cpp")
target_link_libraries(07_TileMapRandom LDL)

add_executable(08_Memory "08_Memory.cpp")
target_link_libraries(08_Memory LDL)

add_executable(09_Software "09_Software.cpp")
target_link_libraries(09_Software LDL)
