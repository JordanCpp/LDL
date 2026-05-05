include(FindPackageHandleStandardArgs)

find_path(X11_INCLUDE_DIRS
    NAMES
        X11/Xlib.h
)

find_library(X11_LIBRARIES
    NAMES
        X11
)

find_package_handle_standard_args(X11
    REQUIRED_VARS
        X11_INCLUDE_DIRS
        X11_LIBRARIES
)

if(X11_FOUND)
    mark_as_advanced(X11_INCLUDE_DIRS X11_LIBRARIES)
endif()

if(X11_FOUND AND NOT TARGET X11::Library)
    add_library(X11::Library UNKNOWN IMPORTED)
    set_target_properties(X11::Library
        PROPERTIES
            IMPORTED_LOCATION ${X11_LIBRARIES}
            INTERFACE_INCLUDE_DIRECTORIES ${X11_INCLUDE_DIRS}
    )
endif()
