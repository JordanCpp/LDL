call "C:\Downloads\codeblocks-12.11mingw-setup\MinGW\mingwvars.bat"

g++ -Wall -Wextra -pedantic -O2 -std=c++98 -s -shared -o LDL_MinGW.dll -DLDL_SHARED_LIBRARY ^
..\source\Shared\Allocators\*.cpp ^
..\source\Shared\Core\*.cpp ^
..\source\Shared\Events\*.cpp ^
..\source\Shared\Time\*.cpp ^
..\source\Shared\Audio\*.cpp ^
..\source\Shared\Graphics\*.cpp ^
..\source\Shared\Graphics\Base\*.cpp ^
..\source\Shared\Graphics\Creators\*.cpp ^
..\source\Shared\Graphics\Software\*.cpp ^
..\source\Shared\Graphics\OpenGL\*.cpp ^
..\source\Shared\Graphics\OpenGL1\*.cpp ^
..\source\Shared\Graphics\OpenGL3\*.cpp ^
..\source\Shared\Graphics\Primitives\*.cpp ^
..\source\Shared\Graphics\Utils\*.cpp ^
..\source\Shared\Loaders\*.cpp ^
..\source\Shared\OpenGL\*.cpp ^
..\source\Shared\LDLC\*.cpp ^
..\source\Platforms\Windows\DirectX\*.cpp ^
..\source\Platforms\Windows\Graphics\*.cpp ^
..\source\Platforms\Windows\Graphics\OpenGL\*.cpp ^
..\source\Platforms\Windows\Graphics\OpenGL1\*.cpp ^
..\source\Platforms\Windows\Graphics\OpenGL3\*.cpp ^
..\source\Platforms\Windows\Graphics\Software\*.cpp ^
..\source\Platforms\Windows\Time\Ticks.cpp ^
..\source\Platforms\Windows\Core\*.cpp ^
..\source\Platforms\Windows\Input\*.cpp ^
..\source\Platforms\Windows\Audio\DirectSound8\*.cpp ^
-I..\include\ ^
-I..\dependencies\dx9sdk\Include ^
-lgdi32 ^
-lopengl32 ^
-lwinmm ^
-Wl,--out-implib,LDL_MinGW.lib