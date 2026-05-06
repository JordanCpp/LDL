include(FindPackageHandleStandardArgs)

find_library(OpenGL_LIBRARIES
    NAMES
        GL
)

find_package_handle_standard_args(OpenGL
    REQUIRED_VARS
        OpenGL_LIBRARIES
)

if(OpenGL_FOUND)
    mark_as_advanced(OpenGL_LIBRARIES)
endif()

if(OpenGL_FOUND AND NOT OpenGL::Library)
    add_library(OpenGL::Library UNKNOWN IMPORTED)
    set_target_properties(OpenGL::Library
        PROPERTIES
            IMPORTED_LOCATION ${OpenGL_LIBRARIES}
    )
endif()
