
set(LDL_EXAMPLES
    "C89_3DRender_Triangle"
)

foreach(EXE_NAME ${LDL_EXAMPLES})
    add_executable(${EXE_NAME} ${EXE_NAME}.c)
    target_link_libraries(${EXE_NAME} LDL)
endforeach()
