add_subdirectory("Utils")

add_executable(Rectu "Rectu.cpp")
target_link_libraries(Rectu LDL)

add_executable(Window "Window.cpp")
target_link_libraries(Window LDL)

add_executable(Color "Color.cpp")
target_link_libraries(Color LDL)

add_executable(Surface "Surface.cpp")
target_link_libraries(Surface LDL)

add_executable(Render "Render.cpp")
target_link_libraries(Render LDL)

add_executable(PixelConverter "PixelConverter.cpp")
target_link_libraries(PixelConverter LDL)

add_executable(VideoMode "VideoMode.cpp")
target_link_libraries(VideoMode LDL)

add_executable(ImageWritter "ImageWritter.cpp")
target_link_libraries(ImageWritter LDL)

add_executable(PixelPainter "PixelPainter.cpp")
target_link_libraries(PixelPainter LDL)

add_executable(Isometric "Isometric.cpp")
target_link_libraries(Isometric LDL)

add_executable(ImageResizer "ImageResizer.cpp")
target_link_libraries(ImageResizer LDL)