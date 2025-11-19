
call "C:\iso\mingw\codeblocks-8.02mingw-setup\MinGW\mingwvars.bat"

g++ -fno-rtti -fno-exceptions -Wall -Wextra -pedantic -O2 -s -static -shared -o LDL_MinGW.dll -DLDL_WINDOWS_NT -DLDL_SHARED_LIBRARY ^
..\source\LDL\OpenGL\*.cpp ^
..\source\LDL\WinNT\*.cpp ^
..\source\LDL\*.cpp ^
..\source\LDL\Renders\Soft\*.cpp ^
..\source\LDL\Renders\GL\*.cpp ^
..\source\LDL\Renders\GL1\*.cpp ^
..\source\LDL\Renders\GL3\*.cpp ^
-I..\include\ ^
-I..\source\ ^
-lgdi32 ^
-lopengl32 ^
-lwinmm ^
-Wl,--out-implib,LDL_MinGW.lib

pause
