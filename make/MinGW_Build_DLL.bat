
call "C:\iso\mingw\codeblocks-8.02mingw-setup\MinGW\mingwvars.bat"

g++ -fno-rtti -fno-exceptions -Wall -Wextra -pedantic -O2 -s -static -shared -o LDL_MinGW.dll -DLDL_WINDOWS_NT -DLDL_SHARED_LIBRARY ^
..\src\LDL\OpenGL\*.cpp ^
..\src\LDL\WinNT\*.cpp ^
..\src\LDL\*.cpp ^
..\src\LDL\Renders\Soft\*.cpp ^
..\src\LDL\Renders\GL\*.cpp ^
..\src\LDL\Renders\GL1\*.cpp ^
..\src\LDL\Renders\GL3\*.cpp ^
-I..\include\ ^
-I..\src\ ^
-lgdi32 ^
-lopengl32 ^
-lwinmm ^
-Wl,--out-implib,LDL_MinGW.lib

pause
