project(LDL)

if(UNIX AND NOT APPLE)
    find_package(X11 REQUIRED)
    link_libraries(${X11_LIBRARIES})
    include_directories(${X11_INCLUDE_DIR})
endif()

include_directories("../include")

file(GLOB_RECURSE SHARED_FILES "Shared/*.cpp")

if (WIN32)
  file(GLOB_RECURSE SOURCE_PLATFORM "Platforms/Windows/*.cpp")
elseif(UNIX AND NOT APPLE)
  file(GLOB_RECURSE SOURCE_PLATFORM "Platforms/Linux/*.cpp")
endif() 

set(SOURCE_ALL ${SHARED_FILES} ${SOURCE_PLATFORM})

if (LDL_SHARED_LIBRARY)
  add_library(${PROJECT_NAME} SHARED  ${SOURCE_ALL})		
elseif (LDL_STATIC_LIBRARY)
  add_library(${PROJECT_NAME} STATIC  ${SOURCE_ALL})		
endif() 

if (WIN32)
    target_link_libraries(${PROJECT_NAME} winmm opengl32 freetype)
elseif (UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} X11 GL dl freetype)
endif()