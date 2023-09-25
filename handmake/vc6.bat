
call "C:\VC6\Microsoft Visual Studio\VC98\Bin\VCVARS32.BAT"

CL /O2 /FeLDL.dll -LD -GX /I..\include /DLDL_SHARED_LIBRARY ^
..\source\Renders\*.cpp ^
..\source\Shared\*.cpp ^
..\source\Windows\*.cpp ^
..\source\OpenGL\*.cpp ^
..\source\WinGL\*.cpp  ^
gdi32.lib ^
user32.lib ^
winmm.lib  ^
opengl32.lib

del *.obj

pause