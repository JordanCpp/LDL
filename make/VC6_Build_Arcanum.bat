
call "C:\VC6\Microsoft Visual Studio\VC98\Bin\VCVARS32.BAT"

cl /O2 -FeVC6_Arcanum.exe -GX /I..\include\ /I..\demos\ArcanumWorld\source\ ..\demos\ArcanumWorld\source\ArcanumWorld.cpp  ^
..\demos\ArcanumWorld\source\Arcanum\Allocators\*.cpp  ^
..\demos\ArcanumWorld\source\Arcanum\Core\*.cpp  ^
..\demos\ArcanumWorld\source\Arcanum\Formats\*.cpp  ^
..\demos\ArcanumWorld\source\Arcanum\Forms\*.cpp  ^
..\demos\ArcanumWorld\source\Arcanum\Game\*.cpp  ^
..\demos\ArcanumWorld\source\Arcanum\Gameplay\*.cpp  ^
..\demos\ArcanumWorld\source\Arcanum\Graphics\*.cpp  ^
..\demos\ArcanumWorld\source\Arcanum\Loaders\*.cpp  ^
..\demos\ArcanumWorld\source\Arcanum\Managers\*.cpp  ^
..\demos\ArcanumWorld\source\Arcanum\Objects\*.cpp  ^
..\demos\ArcanumWorld\source\Arcanum\Painters\*.cpp  ^
..\demos\ArcanumWorld\source\Arcanum\Readers\*.cpp  ^
..\demos\ArcanumWorld\source\Arcanum\Savers\*.cpp ^
..\demos\ArcanumWorld\source\Arcanum\Scripts\*.cpp ^
..\demos\ArcanumWorld\source\Arcanum\Widgets\*.cpp ^
..\demos\ArcanumWorld\source\Arcanum\Writers\*.cpp ^
/link LDL_VC6.lib glu32.lib opengl32.lib

del *.obj

pause
