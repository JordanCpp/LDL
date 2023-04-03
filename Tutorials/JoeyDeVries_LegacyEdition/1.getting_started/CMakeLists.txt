cmake_minimum_required(VERSION 3.8)

add_executable(LegacyEdition1.1.hello_window "LegacyEdition1.1.hello_window.cpp")
target_link_libraries(LegacyEdition1.1.hello_window LDL)

add_executable(LegacyEdition1.2.hello_window_clear "LegacyEdition1.2.hello_window_clear.cpp")
target_link_libraries(LegacyEdition1.2.hello_window_clear LDL)

add_executable(LegacyEdition2.1.hello_triangle "LegacyEdition2.1.hello_triangle.cpp")
target_link_libraries(LegacyEdition2.1.hello_triangle LDL)

add_executable(LegacyEdition2.2.hello_triangle_indexed "LegacyEdition2.2.hello_triangle_indexed.cpp")
target_link_libraries(LegacyEdition2.2.hello_triangle_indexed LDL)

add_executable(LegacyEdition4.1.textures "LegacyEdition4.1.textures.cpp")
target_link_libraries(LegacyEdition4.1.textures LDL)

add_executable(LegacyEdition5.1.transformations "LegacyEdition5.1.transformations.cpp")
target_link_libraries(LegacyEdition5.1.transformations LDL)

add_executable(LegacyEdition6.2.coordinate_systems_depth "LegacyEdition6.2.coordinate_systems_depth.cpp")
target_link_libraries(LegacyEdition6.2.coordinate_systems_depth LDL)

add_executable(LegacyEdition6.3.coordinate_systems_multiple "LegacyEdition6.3.coordinate_systems_multiple.cpp")
target_link_libraries(LegacyEdition6.3.coordinate_systems_multiple LDL)

add_executable(LegacyEdition7.1.camera_circle "LegacyEdition7.1.camera_circle")
target_link_libraries(LegacyEdition7.1.camera_circle LDL)

add_executable(LegacyEdition7.2.camera_keyboard_dt "LegacyEdition7.2.camera_keyboard_dt")
target_link_libraries(LegacyEdition7.2.camera_keyboard_dt LDL)