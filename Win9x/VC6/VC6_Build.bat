
call "C:\VC6\Microsoft Visual Studio\VC98\Bin\VCVARS32.BAT"

CL -GX /I..\..\include /DLDL_RENDER_OPENGL1 ..\%2  ^
..\..\source\Allocators\*.cpp ^
..\..\source\Core\*.cpp ^
..\..\source\Events\*.cpp ^
..\..\source\Time\*.cpp ^
..\..\source\Platforms\Windows\Graphics\MainWindow.cpp ^
..\..\source\Platforms\Windows\Graphics\OpenGL1\*.cpp ^
..\..\source\Platforms\Windows\Time\Ticks.cpp ^
..\..\source\Platforms\Windows\Core\*.cpp ^
..\..\source\Graphics\*.cpp ^
..\..\source\Graphics\Base\*.cpp ^
..\..\source\Graphics\Software\Surface.cpp ^
..\..\source\Graphics\OpenGL1\*.cpp ^
..\..\source\Graphics\Primitives\*.cpp ^
..\..\source\Graphics\Utils\*.cpp ^
..\..\source\Loaders\*.cpp  ^
..\..\source\Platforms\Windows\Input\*.cpp  ^
..\..\source\OpenGL\*.cpp  ^
gdi32.lib ^
opengl32.lib ^
winmm.lib   ^
user32.lib

del *.obj