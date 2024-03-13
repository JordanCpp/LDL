if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)  
endif()

add_subdirectory("LDL")
add_subdirectory("LDL_Image")
