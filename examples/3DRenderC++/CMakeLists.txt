
set(LDL_EXAMPLES
    "3DRenderC++_TriangleColor"
    "3DRenderC++_TriangleRotate"
    "3DRenderC++_TriangleVertex"
)

foreach(EXE_NAME ${LDL_EXAMPLES})
    add_executable(${EXE_NAME} ${EXE_NAME}.cpp)
    target_link_libraries(${EXE_NAME} LDL)
endforeach()
