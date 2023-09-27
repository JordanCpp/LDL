
call "C:\Program Files (x86)\DevStudio\VC\bin\VCVARS32.BAT"

CL /O2 /FeLDL.dll -LD -GX /I..\include /DLDL_SHARED_LIBRARY ^
..\source\Renders\*.cpp ^
..\source\Low\*.cpp ^
..\source\Windows\*.cpp ^
..\source\OpenGL\*.cpp ^
..\source\GLU\*.cpp ^
..\source\WinGL\*.cpp   ^
gdi32.lib ^
user32.lib ^
winmm.lib ^
opengl32.lib


del *.obj

pause