
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data       DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Config.xml DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

include_directories("source")

file(GLOB_RECURSE SOURCE_FILES "source/Arcanum/*.cpp")

add_library(Arcanum STATIC ${SOURCE_FILES})

target_link_libraries(Arcanum LDL)

add_executable(ArcanumWorld "source/ArcanumWorld.cpp")
target_link_libraries(ArcanumWorld Arcanum)

add_executable(GenMap "source/GenMap.cpp")
target_link_libraries(GenMap Arcanum)
