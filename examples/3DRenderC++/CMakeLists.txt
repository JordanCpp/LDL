
set(LDL_EXAMPLES
    "3DRenderC++_TriangleVertex"
    "3DRenderC++_TriangleColor"
)

foreach(EXE_NAME ${LDL_EXAMPLES})
    add_executable(${EXE_NAME} ${EXE_NAME}.cpp)
    target_link_libraries(${EXE_NAME} LDL)
endforeach()
