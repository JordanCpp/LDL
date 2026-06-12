
set(LDL_EXAMPLES
    "C++98_01_Window"
    "C++98_02_Render"
    "C++98_03_Clear"
    "C++98_04_Line"
    "C++98_05_Fill"
    "C++98_06_Texture"
    "C++98_07_InitLegacyGL"
    "C++98_08_InitModernGL"
    "C++98_09_TileMap"
)

foreach(EXE_NAME ${LDL_EXAMPLES})
    add_executable(${EXE_NAME} ${EXE_NAME}.cpp)
    target_link_libraries(${EXE_NAME} LDL)
endforeach()
