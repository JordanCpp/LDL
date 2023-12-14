# Greetings!

# LDL - Little Directmedia Layer
Free cross-platform library.

1. Free for everyone.
2. Consider and accept all ideas.
3. We do not limit the developer.
4. We support old and new platforms.
5. Cross-platform.
6. Static and dynamic link.

# Build for Linux
1. sudo apt-get install libx11-dev
2. sudo apt-get install libgl1-mesa-dev
3. git clone https://github.com/JordanCpp/Lib-LDL.git
4. cd Lib-LDL
5. cmake . or cmake -Bout
6. make

# Build for Windows
1. git clone https://github.com/JordanCpp/Lib-LDL.git
2. cd Lib-LDL

# Add LDL in your project
1. git clone https://github.com/JordanCpp/Lib-LDL.git your_project/dependencies/LDL
- add_subdirectory(dependencies/LDL)
- include_directories(dependencies/LDL/include)
- link_directories   (${CMAKE_CURRENT_BINARY_DIR}/dependencies/LDL)
- target_link_libraries(${PROJECT_NAME} LDL)

# Support platforms.
1. Windows 95 and higher
2. Linux (XLib) Debian 3 and higher
3. Linux Wayland (In the implementation)

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
1. MinGW (gcc 3) and higher
2. GCC 3 and higher
3. Visual C++ 6.0 and higher
4. Open Watcom V2
5. Borland C++ 6.0 and higher

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