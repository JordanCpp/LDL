if(NOT LDL_ENABLE_INSTALL)
    return()
endif()

install(
    TARGETS LDL
    EXPORT LDLTargets
    RUNTIME
        COMPONENT Library
        DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY
        COMPONENT Library
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE
        COMPONENT Library
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PERMISSIONS
        OWNER_READ OWNER_WRITE
        GROUP_READ
        WORLD_READ
)

install(
    FILES
        ${LDL_ROOT_FOLDER}/include/LDL/Config.h
        ${LDL_ROOT_FOLDER}/include/LDL/Context.h
        ${LDL_ROOT_FOLDER}/include/LDL/Enums.h
        ${LDL_ROOT_FOLDER}/include/LDL/Events.h
        ${LDL_ROOT_FOLDER}/include/LDL/Format.h
        ${LDL_ROOT_FOLDER}/include/LDL/LDL.h
        ${LDL_ROOT_FOLDER}/include/LDL/Library.h
        ${LDL_ROOT_FOLDER}/include/LDL/Result.h
        ${LDL_ROOT_FOLDER}/include/LDL/Ticks.h
        ${LDL_ROOT_FOLDER}/include/LDL/Types.h
        ${LDL_ROOT_FOLDER}/include/LDL/Vec2i.h
        ${LDL_ROOT_FOLDER}/include/LDL/Window.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/LDL
    COMPONENT Library
)
install(
    FILES
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL1_0.h
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL1_1.h
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL1_2.h
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL1_3.h
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL1_4.h
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL1_5.h
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL2_0.h
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL2_1.h
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL3_0.h
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL3_1.h
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL3_2.h
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL3_3.h
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL4_0.h
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL4_1.h
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL4_2.h
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL4_3.h
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL4_4.h
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL4_5.h
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GL4_6.h
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GLConsts.h
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GLLoad.h
        ${LDL_ROOT_FOLDER}/include/LDL/OpenGL/GLTypes.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/LDL/OpenGL
    COMPONENT Library
)

configure_file(
    ${LDL_ROOT_FOLDER}/cmake/ldl.pc.in
    ${LDL_BUILD_FOLDER}/pkgconfig/ldl-${LDL_VERSION}.pc
    @ONLY
)
install(
    FILES ${LDL_BUILD_FOLDER}/pkgconfig/ldl-${LDL_VERSION}.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
    COMPONENT Library
)

install(
    EXPORT LDLTargets
    FILE LDLTargets.cmake
    NAMESPACE LDL::
    DESTINATION ${LDL_BUILD_FOLDER}/cmake
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
    ${LDL_ROOT_FOLDER}/cmake/LDLConfig.cmake.in
    ${LDL_BUILD_FOLDER}/cmake/LDLConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/ldl-${LDL_VERSION}
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)
write_basic_package_version_file(
    ${LDL_BUILD_FOLDER}/cmake/LDLConfigVersion.cmake
    VERSION ${LDL_VERSION}
    COMPATIBILITY AnyNewerVersion
)
install(
    FILES
        ${LDL_BUILD_FOLDER}/cmake/LDLConfig.cmake
        ${LDL_BUILD_FOLDER}/cmake/LDLConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/ldl-${LDL_VERSION}
)
install(
    DIRECTORY ${LDL_BUILD_FOLDER}/cmake/
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/ldl-${LDL_VERSION}
    FILES_MATCHING PATTERN "LDLTargets*.cmake"
)

configure_file(
    ${LDL_ROOT_FOLDER}/cmake/ReplacePrefix.cmake.in
    ${LDL_BUILD_FOLDER}/ReplacePrefix.cmake
    @ONLY
)
install(SCRIPT ${LDL_BUILD_FOLDER}/ReplacePrefix.cmake)
