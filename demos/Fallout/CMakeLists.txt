
add_executable(fallout 
    "Fallout.cpp" 
    "Engine.cpp" 
    "Config.cpp" 
    "SpriteLoader.cpp" 
    "SpriteManager.cpp" 
    "Tile.cpp"
    "Sprite.cpp"
    "Camera.cpp"
    "LocationPainter.cpp"
    "LocationReader.cpp"
    "Location.cpp"
    "Critter.cpp"
    "Math.cpp"

    "Scripts/TestScript.cpp" )

target_link_libraries(fallout LDL LDL_Image)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/data" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/data" DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
