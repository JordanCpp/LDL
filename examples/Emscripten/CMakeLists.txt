if(EMSCRIPTEN)
    include("${LDL_ROOT_FOLDER}/cmake/emscripten/EmscriptenTarget.cmake")

    # FILES: embed the Files/ directory into Emscripten's MEMFS so that
    # fopen("Files/LDL_24_256.bmp", "rb") works in the browser exactly
    # as it does on the desktop. Emscripten packs the directory into a
    # .data file at link time (served alongside the .wasm/.js).
    LDL_AddEmscriptenTarget(
        TARGET   Emscripten_Triangle
        SOURCES  Emscripten_Triangle.c
        FILES    Files
    )
endif()
