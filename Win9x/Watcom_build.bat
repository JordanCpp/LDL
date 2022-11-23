call C:\WATCOM\owsetenv.bat

del *.obj *.err

wcl386.exe ..\Examples\Graphics\Gpu\05_Gpu_Image\main.cpp -i="C:\WATCOM/h;C:\WATCOM/h/nt;../include;"  /xs -dLDL_GPU_SUPPORT_OPENGL1 ^
..\source\Allocators\*.cpp ^
..\source\Core\*.cpp ^
..\source\Events\*.cpp ^
..\source\Time\*.cpp ^
..\source\Platforms\Windows\Graphics\*.cpp ^
..\source\Platforms\Windows\Time\*.cpp ^
..\source\Graphics\*.cpp ^
..\source\Graphics\Base\*.cpp  ^
..\source\Graphics\Cpu\*.cpp ^
..\source\Graphics\GL1\*.cpp ^
..\source\Graphics\Primitives\*.cpp ^
..\source\Loaders\*.cpp ^
gdi32.lib ^
opengl32.lib ^
winmm.lib

pause