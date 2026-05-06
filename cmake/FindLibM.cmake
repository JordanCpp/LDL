include(FindPackageHandleStandardArgs)

find_library(LibM_LIBRARIES
    NAMES
        m
)

find_package_handle_standard_args(LibM
    REQUIRED_VARS
        LibM_LIBRARIES
)

if(LibM_FOUND)
    mark_as_advanced(LibM_LIBRARIES)
endif()

if(LibM_FOUND AND NOT LibM::Library)
    add_library(LibM::Library UNKNOWN IMPORTED)
    set_target_properties(LibM::Library
        PROPERTIES
            IMPORTED_LOCATION ${LibM_LIBRARIES}
    )
else()
    add_library(LibM::Library INTERFACE)
    target_compile_options(LibM::Library INTERFACE -lm)
endif()
