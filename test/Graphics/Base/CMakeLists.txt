cmake_minimum_required(VERSION 3.8)

add_executable(BaseWindow "BaseWindow.cpp")
target_link_libraries(BaseWindow LDL)

add_executable(BaseRender "BaseRender.cpp")
target_link_libraries(BaseRender LDL)

add_executable(BaseScreenshoter "BaseScreenshoter.cpp")
target_link_libraries(BaseScreenshoter LDL)