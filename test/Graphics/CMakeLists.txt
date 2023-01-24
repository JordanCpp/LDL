cmake_minimum_required(VERSION 3.8)

add_subdirectory("Render")

add_executable(Point2u "Point2u.cpp")
target_link_libraries(Point2u LDL)

add_executable(Point2i "Point2i.cpp")
target_link_libraries(Point2i LDL)

add_executable(Rect2u "Rect2u.cpp")
target_link_libraries(Rect2u LDL)

add_executable(Rect2i "Rect2i.cpp")
target_link_libraries(Rect2i LDL)

add_executable(BaseWindow "Base/BaseWindow.cpp")
target_link_libraries(BaseWindow LDL)

add_executable(Window "Window.cpp")
target_link_libraries(Window LDL)

add_executable(Color "Color.cpp")
target_link_libraries(Color LDL)

add_executable(BaseRender "Base/BaseRender.cpp")
target_link_libraries(BaseRender LDL)

add_executable(Surface "Surface.cpp")
target_link_libraries(Surface LDL)

add_executable(Render "Render.cpp")
target_link_libraries(Render LDL)

add_executable(PixelConverter "PixelConverter.cpp")
target_link_libraries(PixelConverter LDL)

add_executable(BaseScreenshoter "Base/BaseScreenshoter.cpp")
target_link_libraries(BaseScreenshoter LDL)

add_executable(VideoMode "VideoMode.cpp")
target_link_libraries(VideoMode LDL)

add_executable(ImageWritter "ImageWritter.cpp")
target_link_libraries(ImageWritter LDL)

add_executable(PixelPainter "PixelPainter.cpp")
target_link_libraries(PixelPainter LDL)

add_executable(Isometric "Isometric.cpp")
target_link_libraries(Isometric LDL)

add_executable(Camera "Camera.cpp")
target_link_libraries(Camera LDL)