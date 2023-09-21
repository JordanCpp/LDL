
call "C:\Program Files (x86)\DevStudio\VC\bin\VCVARS32.BAT"

CL /O2 /FeLDL.dll -LD -GX /I..\include ^
..\source\Renders\*.cpp ^
..\source\Shared\*.cpp ^
..\source\Windows\*.cpp ^
gdi32.lib ^
user32.lib ^
winmm.lib


del *.obj

pause