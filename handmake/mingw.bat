
call "C:\Downloads\codeblocks-12.11mingw-setup\MinGW\mingwvars.bat"

g++ -Wall -Wextra -pedantic -O2 -std=c++98 -s -shared -o LDL.dll -DLDL_SHARED_LIBRARY ^
..\source\Renders\*.cpp ^
..\source\Shared\*.cpp ^
..\source\Windows\*.cpp ^
..\source\OpenGL\*.cpp ^
-I..\include\ ^
-lgdi32 ^
-lopengl32 ^
-lwinmm ^
-Wl,--out-implib,LDL.lib 

del *.obj

pause