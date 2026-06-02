
call "C:\VC6\VC98\Bin\VCVARS32.BAT"

CL /O2 /FeLDL.dll -LD -GX /DLDL_SHARED_LIBRARY ^
..\source\LDL\*.c ^
..\source\LDL\OpenGL\*.c ^
..\source\LDL\Renders\*.c ^
..\source\LDL\Renders\GL\*.c ^
..\source\LDL\Win9x\*.c ^
/I..\include\ ^
/I..\source\ ^
gdi32.lib ^
opengl32.lib ^
winmm.lib   ^
user32.lib

del *.obj

pause
