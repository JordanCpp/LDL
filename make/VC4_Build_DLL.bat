
call "C:\MSDEV\BIN\VCVARS32.BAT"

CL /O2 /FeLDL_VC5.dll -LD -GX /DLDL_SHARED_LIBRARY ^
..\source\LDL\Shared\APIs\OpenGL\*.cpp ^
..\source\LDL\Shared\APIs\SDL3\*.cpp ^
..\source\LDL\Shared\Core\*.cpp ^
..\source\LDL\Shared\Events\*.cpp ^
..\source\LDL\Shared\Graphics\*.cpp ^
..\source\LDL\Shared\Loaders\*.cpp ^
..\source\LDL\Shared\Input\*.cpp ^
..\source\LDL\Shared\Math\*.cpp ^
..\source\LDL\Shared\std\*.cpp ^
..\source\LDL\Shared\Time\*.cpp ^
..\source\LDL\Shared\Graphics\Base\*.cpp ^
..\source\LDL\Shared\Graphics\Creators\*.cpp ^
..\source\LDL\Shared\Graphics\Renders\Software\*.cpp ^
..\source\LDL\Shared\Graphics\Renders\OpenGL\*.cpp ^
..\source\LDL\Shared\Graphics\Renders\OpenGL1\*.cpp ^
..\source\LDL\Shared\Graphics\Renders\OpenGL3\*.cpp ^
..\source\LDL\Shared\Graphics\Utils\*.cpp ^
..\source\LDL\Platforms\Windows\*.cpp ^
..\source\LDL\Platforms\Windows\Core\*.cpp ^
..\source\LDL\Platforms\Windows\Graphics\*.cpp ^
..\source\LDL\Platforms\Windows\Input\*.cpp ^
..\source\LDL\Platforms\Windows\Time\Ticks.cpp ^
/I..\include\ ^
/I..\source\ ^
gdi32.lib ^
opengl32.lib ^
winmm.lib   ^
user32.lib

del *.obj

pause
