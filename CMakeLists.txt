project(LDL_Proj)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)  
endif()

include_directories("include")

if (WIN32)
    set(libs gdi32 user32 winmm opengl32)
elseif (UNIX AND NOT APPLE)
    set(libs X11 GL dl)
endif()

file(GLOB SHARED_FILES  "source/*.cpp")
file(GLOB OPENGL_FILES  "source/OpenGL/*.cpp")

if (WIN32)
file(GLOB WINDOWS_FILES          "source/windows/*.cpp")
file(GLOB WINDOWS_OPENGL1_FILES  "source/windows/OpenGL1/*.cpp" "source/Renders/GL1Rndr.cpp")
file(GLOB WINDOWS_OPENGL3_FILES  "source/windows/OpenGL3/*.cpp")
file(GLOB WINDOWS_SOFTWARE_FILES "source/windows/Software/*.cpp")
endif()

add_library(LDLGL1 ${SHARED_FILES} ${WINDOWS_FILES} ${OPENGL_FILES} ${WINDOWS_OPENGL1_FILES})
target_compile_definitions(LDLGL1 PUBLIC -DLDL_SUPPORT_OPENGL1)
target_link_libraries(LDLGL1 ${libs})	

add_library(LDLGL3 ${SHARED_FILES} ${WINDOWS_FILES} ${OPENGL_FILES} ${WINDOWS_OPENGL3_FILES})
target_compile_definitions(LDLGL3 PUBLIC -DLDL_SUPPORT_OPENGL3)
target_link_libraries(LDLGL3 ${libs})

add_library(LDLSoft ${SHARED_FILES} ${WINDOWS_FILES} ${WINDOWS_SOFTWARE_FILES})
target_compile_definitions(LDLGL3 PUBLIC -DLDL_SUPPORT_SOFTWARE)
target_link_libraries(LDLSoft ${libs})

add_subdirectory("examples")
add_subdirectory("tests")
