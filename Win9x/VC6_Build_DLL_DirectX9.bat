
call "C:\VC6\Microsoft Visual Studio\VC98\Bin\VCVARS32.BAT"

CL /FeLDL.dll -LD -GX /DLDL_SHARED_LIBRARY  /DLDL_RENDER_DIRECTX9 ^
/I..\dependencies\dx9sdk\include        ^
/I..\include ^
..\source\Allocators\*.cpp ^
..\source\Core\*.cpp ^
..\source\Events\*.cpp ^
..\source\Time\*.cpp ^
..\source\Platforms\Windows\Graphics\*.cpp ^
..\source\Platforms\Windows\Graphics\DirectX9\Direct3D\*.cpp ^
..\source\Platforms\Windows\Time\Ticks.cpp ^
..\source\Platforms\Windows\Core\*.cpp ^
..\source\Graphics\*.cpp ^
..\source\Graphics\Base\*.cpp ^
..\source\Graphics\Software\Surface.cpp ^
..\source\Graphics\DirectX9\Direct3D\*.cpp ^
..\source\Graphics\Primitives\*.cpp ^
..\source\Graphics\Utils\*.cpp ^
..\source\Loaders\*.cpp  ^
..\source\Platforms\Windows\Input\*.cpp  ^
gdi32.lib ^
..\dependencies\dx9sdk\lib\x86\d3d9.lib  ^
..\dependencies\dx9sdk\lib\x86\d3dx9.lib ^
winmm.lib   ^
user32.lib

del *.obj