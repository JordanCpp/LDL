# Greetings!

# LDL - Little Directmedia Layer
Free cross-platform library.

1. Free for everyone.
2. Consider and accept all ideas.
3. We do not limit the developer.
4. We support old and new platforms.
5. Cross-platform.
6. Static link.

# Install Linux
1. git clone https://github.com/JordanCpp/Lib-LDL.git
2. cd Lib-LDL
3. cmake CMakeLists.txt
4. make

# Install for Windows (Static library)
1. git clone https://github.com/JordanCpp/Lib-LDL.git dependencies/LDL 
2. Added to CMake
- set(LDL_STATIC_LIBRARY true)
- add_definitions(-DLDL_STATIC_LIBRARY)
- set(LDL_RENDER_OPENGL3 true)
- add_subdirectory(dependencies/LDL/source)
- include_directories(dependencies/LDL/include)
- link_directories   (${CMAKE_CURRENT_BINARY_DIR}/dependencies/LDL)
- target_link_libraries(${PROJECT_NAME} LDL)

# Install for Windows (Dynamic library 32 bit)
1. git clone https://github.com/JordanCpp/Lib-LDL-WindowsBuilds dependencies/LDL 
2. Added to CMake
- project(MyProject)
- add_definitions(-DLDL_SHARED_LIBRARY)
- include_directories(dependencies/LDL/MSVC2022_x86/include)
- link_directories   (dependencies/LDL/MSVC2022_x86)
- target_link_libraries(${PROJECT_NAME} LDL)

# Install for Windows (Dynamic library 64 bit)
1. git clone https://github.com/JordanCpp/Lib-LDL-WindowsBuilds dependencies/LDL 
2. Added to CMake
- project(MyProject)
- add_definitions(-DLDL_SHARED_LIBRARY)
- include_directories(dependencies/LDL/MSVC2022_x64/include)
- link_directories   (dependencies/LDL/MSVC2022_x64)
- target_link_libraries(MyProject LDL)

# Support platforms.
1. Windows 95
2. Windows 98
3. Windows 98 Me
4. Windows 2000
5. Windows XP
6. Windows Vista
7. Windows 7
8. Windows 8
9. Windows 10
10. Windows 11
11. Linux XLib
12. Linux Wayland (In the implementation)

# Support renders.
1. OpenGL 1.0
2. OpenGL 3.0
3. Software render
4. DirectDraw (In the implementation)
5. DirectX 5 Direct3D (In the implementation)
6. DirectX 9 Direct3D (In the implementation)


# The main idea is to write an analogue of the SDL library. 
Accessible to everyone, without exception. 
Under a free license. Add interesting functionality.

# License.
Boost Software License - Version 1.0 - August 17th, 2003

# Support compillers
1. MinGW
2. Visual C++ 6.0 and higher
3. Open Watcom V2

# Other
I'm glad for everyone. The main language for communication is English. There are no restrictions on ideas or functionality. 
Ready to discuss any questions, ideas, suggestions. There is no bureaucracy.
I'm using the C++98 standard. To support old and new platforms.

# My report on the LDL framework is the C++ Russia 2023 conference.
https://cppconf.ru/talks/16ef41e0e5ec48bfb25b36f8b2a0b540/?referer=/talks/

# Article on habr
https://habr.com/ru/post/700668/

# Communication
https://gamedev.ru/projects/forum/?id=273184
https://www.old-games.ru/forum/threads/pishu-frejmvork-ldl-analog-sdl-no-na-s-i-s-podderzhkoj-staryx-sistem.106435/

# Thanks


# old-games.ru
Tigoro, 
Bobbie,


# gamedev.ru
Vitorio,
Mirrel,
gamedevfor,
vka123,
u960,


# habr
Kotofay

# Screenshots
![0](Screenshots/12_TileMap2.jpg)
![1](Screenshots/10_TileMap.jpg)
![2](Screenshots/1.jpg)
![3](Screenshots/2.jpg)
![4](Screenshots/3.jpg)
![5](Screenshots/4.jpg)
![6](Screenshots/5.jpg)