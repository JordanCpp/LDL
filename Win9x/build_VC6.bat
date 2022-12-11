
call "C:\VC6\Microsoft Visual Studio\VC98\Bin\VCVARS32.BAT"

CL -GX /I..\include /DLDL_GPU_SUPPORT_OPENGL1 ..\%2  ^
..\source\Allocators\*.cpp ^
..\source\Core\*.cpp ^
..\source\Events\*.cpp ^
..\source\Time\*.cpp ^
..\source\Platforms\Windows\Graphics\MainWindow.cpp ^
..\source\Platforms\Windows\Graphics\Cpu\CpuWindowImpl.cpp ^
..\source\Platforms\Windows\Graphics\Gl1\GpuWindowImpl.cpp ^
..\source\Platforms\Windows\Time\Ticks.cpp ^
..\source\Platforms\Windows\Core\*.cpp ^
..\source\Graphics\*.cpp ^
..\source\Graphics\Base\*.cpp ^
..\source\Graphics\Cpu\*.cpp ^
..\source\Graphics\GL1\*.cpp ^
..\source\Graphics\Primitives\*.cpp ^
..\source\Loaders\*.cpp  ^
..\source\Creators\*.cpp  ^
..\source\Platforms\Windows\Input\*.cpp  ^
gdi32.lib ^
opengl32.lib ^
winmm.lib   ^
user32.lib

rename main.exe  %1

del *.obj