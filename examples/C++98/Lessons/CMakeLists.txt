
set(LDL_EXAMPLES
    "C++98_Lesson_01_Window"
    "C++98_Lesson_02_Render"
    "C++98_Lesson_03_Clear"
    "C++98_Lesson_04_Line"
    "C++98_Lesson_05_Fill"
    "C++98_Lesson_06_Texture"
    "C++98_Lesson_07_InitLegacyGL"
    "C++98_Lesson_08_InitModernGL"
    "C++98_Lesson_09_TileMap"
    "C++98_Lesson_10_Font"
    "C++98_Lesson_FontSizeGallery"
    "C++98_Lesson_10_FontStyleMixer"
    "C++98_Lesson_10_FontStyleMixer2"
    "C++98_Lesson_10_FontStyleMixer3"
    "C++98_Lesson_10_FontStyleMixer4"
)

foreach(EXE_NAME ${LDL_EXAMPLES})
    add_executable(${EXE_NAME} ${EXE_NAME}.cpp)
    target_link_libraries(${EXE_NAME} LDL LDL_Image LDL_Ttf)
endforeach()
