
set(LDL_EXAMPLES
    "C89_01_Window"
    "C89_02_Render"
    "C89_03_Clear"
    "C89_04_Line"
    "C89_05_Fill"
    "C89_06_Texture"
    "C89_07_InitLegacyGL"
    "C89_08_InitModernGL"
)

foreach(EXE_NAME ${LDL_EXAMPLES})
    add_executable(${EXE_NAME} ${EXE_NAME}.c)
    target_link_libraries(${EXE_NAME} LDL)
endforeach()
