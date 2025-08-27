call "c:\Downloads\codeblocks-25.03mingw-32bit-setup\MinGW\mingwvars.bat"

g++ -std=c++98 -Wall -Wextra -pedantic -o MinGW_Arcanum.exe -O2 -s -static ^
-I..\include\  ^
-I..\demos\ArcanumWorld\source\  ^
..\demos\ArcanumWorld\source\ArcanumWorld.cpp ^
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
..\demos\ArcanumWorld\source\Arcanum\Writers\*.cpp  ^
-L. -lLDL_MinGW -lglu32 -lopengl32

pause
