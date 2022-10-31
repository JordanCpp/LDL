call "C:\Downloads\codeblocks-12.11mingw-setup\MinGW\mingwvars.bat"

cd ../
g++ -Wall -Wextra -pedantic -O2 -std=c++11 -o Win9x\%1 -DLDL_GPU_SUPPORT_OPENGL1 %2 ^
source\Allocators\*.cpp ^
source\Core\*.cpp ^
source\Events\*.cpp ^
source\Time\*.cpp ^
source\Platforms\Windows\Graphics\MainWindow.cpp   ^
source\Platforms\Windows\Graphics\CpuWindow.cpp   ^
source\Platforms\Windows\Graphics\GL1Window.cpp    ^
source\Graphics\*.cpp   ^
source\Graphics\Base\*.cpp ^
source\Graphics\GL1\*.cpp   ^
source\Graphics\Primitives\*.cpp ^
source\Loaders\*.cpp ^
-Iinclude\    ^
-lgdi32 ^
-lopengl32  ^
-static

cd Win9x