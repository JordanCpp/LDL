call "C:\Downloads\codeblocks-12.11mingw-setup\MinGW\mingwvars.bat"

g++ -Wall -Wextra -pedantic -o mingw_%1.exe -O2 -s ..\source\*.cpp ..\source\OpenGL\*.cpp ..\source\Renders\*.cpp ..\source\Platform\Windows\*.cpp %2%1.cpp -I..\include -DLDL_SUPPORT_OPENGL1 -lgdi32 -lopengl32 -lwinmm