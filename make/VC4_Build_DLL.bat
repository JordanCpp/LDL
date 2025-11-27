
call "C:\MSDEV\BIN\VCVARS32.BAT"

CL /O2 /FeLDL_VC4.dll -LD -GX /DLDL_SHARED_LIBRARY /DLDL_WINDOWS_9X ^
..\src\LDL\OpenGL\*.cpp ^
..\src\LDL\Win9X\*.cpp ^
..\src\LDL\*.cpp ^
..\src\LDL\Renders\Soft\*.cpp ^
..\src\LDL\Renders\GL\*.cpp ^
..\src\LDL\Renders\GL1\*.cpp ^
..\src\LDL\Renders\GL3\*.cpp ^
-I..\include\ ^
-I..\src\ ^
gdi32.lib ^
opengl32.lib ^
winmm.lib   ^
user32.lib

del *.obj

pause
