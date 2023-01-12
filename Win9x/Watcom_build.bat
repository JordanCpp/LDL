call C:\WATCOM\owsetenv.bat

del *.obj *.err

wcl386.exe ..\Examples\Graphics\05_Image\main.cpp -i="C:\WATCOM/h;C:\WATCOM/h/nt;../include;"  /xs -dLDL_GPU_SUPPORT_OPENGL1 ^
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
..\source\Graphics\Gpu\*.cpp ^
..\source\Graphics\Primitives\*.cpp ^
..\source\Loaders\*.cpp  ^
..\source\Platforms\Windows\Input\*.cpp  ^
gdi32.lib ^
opengl32.lib ^
winmm.lib

pause