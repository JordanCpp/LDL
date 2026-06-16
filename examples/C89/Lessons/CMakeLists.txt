
set(LDL_EXAMPLES
    "C89_Lesson_01_Window"
    "C89_Lesson_02_Render"
    "C89_Lesson_03_Clear"
    "C89_Lesson_04_Line"
    "C89_Lesson_05_Fill"
    "C89_Lesson_06_Texture"
    "C89_Lesson_07_InitLegacyGL"
    "C89_Lesson_08_InitModernGL"
)

foreach(EXE_NAME ${LDL_EXAMPLES})
    add_executable(${EXE_NAME} ${EXE_NAME}.c)
    target_link_libraries(${EXE_NAME} LDL)
endforeach()
