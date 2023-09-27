
set path=C:\Program Files (x86)\Borland\CBuilder5\Bin\

bcc32.exe -tWD -e"LDL.dll" -I..\include -DLDL_SHARED_LIBRARY  ^
..\source\Renders\*.cpp ^
..\source\Shared\*.cpp ^
..\source\Windows\*.cpp ^
..\source\OpenGL\*.cpp ^
..\source\GLU\*.cpp ^
..\source\WinGL\*.cpp

del *.obj

pause