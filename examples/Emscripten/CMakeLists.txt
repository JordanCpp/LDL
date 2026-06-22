if(EMSCRIPTEN)
    include("${LDL_ROOT_FOLDER}/cmake/emscripten/EmscriptenTarget.cmake")

    LDL_AddEmscriptenTarget(
        TARGET   Emscripten_Triangle
        SOURCES  Emscripten_Triangle.c
    )
endif()
