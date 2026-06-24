function(LDL_AddEmscriptenTarget)
    cmake_parse_arguments(
        ARG
        "ASYNCIFY"
        "TARGET;SHELL"
        "SOURCES;FILES;LINK_FLAGS"
        ${ARGN}
    )

    if(NOT ARG_TARGET)
        message(FATAL_ERROR "LDL_AddEmscriptenTarget: TARGET is required")
    endif()

    if(NOT ARG_SOURCES)
        message(FATAL_ERROR "LDL_AddEmscriptenTarget: SOURCES is required")
    endif()

    if(NOT ARG_SHELL)
        set(ARG_SHELL "${CMAKE_CURRENT_LIST_DIR}/shell.html")
    endif()

    add_executable(${ARG_TARGET} ${ARG_SOURCES})

    set_target_properties(${ARG_TARGET} PROPERTIES SUFFIX ".html")

    target_link_libraries(${ARG_TARGET} PRIVATE LDL::Library)

    set(_EM_FLAGS
        # Use our custom HTML shell
        "--shell-file" "${ARG_SHELL}"
        # WebGL 1 + 2
        "-sUSE_WEBGL2=1"
        "-sFULL_ES3=1"
        "-sMIN_WEBGL_VERSION=1"
        "-sMAX_WEBGL_VERSION=2"
        # Memory
        "-sALLOW_MEMORY_GROWTH=1"
        # Export the main() entry point
        "-sEXPORTED_FUNCTIONS=[\"_main\"]"
        "-sEXPORTED_RUNTIME_METHODS=[\"ccall\",\"cwrap\"]"
        # Keep alive for requestAnimationFrame
        "-sNO_EXIT_RUNTIME=1"
        # Runtime assertions: 2 = verbose, shows function signatures in indirect call errors
        # Set to 0 in final production builds to reduce output size
        "-sASSERTIONS=2"
    )

    if(ARG_FILES)
        foreach(_file_dir ${ARG_FILES})
            if(IS_ABSOLUTE "${_file_dir}")
                set(_abs_dir "${_file_dir}")
            else()
                set(_abs_dir "${CMAKE_CURRENT_SOURCE_DIR}/${_file_dir}")
            endif()

            get_filename_component(_dir_name "${_abs_dir}" NAME)
            list(APPEND _EM_FLAGS "--preload-file" "${_abs_dir}@${_dir_name}")

            message(STATUS "LDL Emscripten MEMFS: preloading '${_abs_dir}' -> '/${_dir_name}'")
        endforeach()
    endif()

    if(ARG_ASYNCIFY)
        list(APPEND _EM_FLAGS "-sASYNCIFY=1")
        target_compile_definitions(${ARG_TARGET} PRIVATE ASYNCIFY=1)
    endif()

    if(ARG_LINK_FLAGS)
        list(APPEND _EM_FLAGS ${ARG_LINK_FLAGS})
    endif()

    target_link_options(${ARG_TARGET} PRIVATE ${_EM_FLAGS})

    message(STATUS "LDL Emscripten target: ${ARG_TARGET}")
endfunction()
