
call "C:\VC6\Microsoft Visual Studio\VC98\Bin\VCVARS32.BAT"

CL /O2 /FeLDL_VC6.dll -LD -GX /I..\include /DLDL_SHARED_LIBRARY /DLDL_RENDER_OPENGL1 /DLDL_AUDIO_DIRECT_SOUND_8  ^
..\source\Allocators\*.cpp ^
..\source\Core\*.cpp ^
..\source\Events\*.cpp ^
..\source\Time\*.cpp ^
..\source\Audio\*.cpp ^
..\source\DirectX\DirectX9.cpp  ^
..\source\Platforms\Windows\Graphics\*.cpp ^
..\source\Platforms\Windows\Graphics\OpenGL\*.cpp ^
..\source\Platforms\Windows\Graphics\OpenGL1\*.cpp ^
..\source\Platforms\Windows\Graphics\OpenGL3\*.cpp ^
..\source\Platforms\Windows\Graphics\Direct3D9\*.cpp ^
..\source\Platforms\Windows\Graphics\Software\*.cpp ^
..\source\Platforms\Windows\Time\Ticks.cpp ^
..\source\Platforms\Windows\Core\*.cpp ^
..\source\Platforms\Windows\Audio\DirectSound8\*.cpp ^
..\source\Graphics\*.cpp ^
..\source\Graphics\Base\*.cpp ^
..\source\Graphics\Creators\*.cpp ^
..\source\Graphics\Software\*.cpp ^
..\source\Graphics\OpenGL\*.cpp ^
..\source\Graphics\OpenGL1\*.cpp ^
..\source\Graphics\OpenGL3\*.cpp ^
..\source\Graphics\Direct3D9\*.cpp ^
..\source\Graphics\Primitives\*.cpp ^
..\source\Graphics\Utils\*.cpp ^
..\source\Loaders\*.cpp  ^
..\source\Platforms\Windows\Input\*.cpp  ^
..\source\OpenGL\*.cpp  ^
..\source\LDLC\*.cpp  ^
gdi32.lib ^
opengl32.lib ^
winmm.lib   ^
user32.lib

del *.obj