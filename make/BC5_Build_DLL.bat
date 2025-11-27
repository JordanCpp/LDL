
bcc32 -w- -O2 -tWD -e"LDL_BC5.dll" -I..\include\ -I..\src\ /DLDL_SHARED_LIBRARY /DLDL_WINDOWS_9X ^
..\src\LDL\OpenGL\*.cpp ^
..\src\LDL\Win9X\*.cpp ^
..\src\LDL\*.cpp ^
..\src\LDL\Renders\Soft\*.cpp ^
..\src\LDL\Renders\GL\*.cpp ^
..\src\LDL\Renders\GL1\*.cpp ^
..\src\LDL\Renders\GL3\*.cpp 


implib LDL_BC5.lib LDL_BC5.dll

del *.obj *.tds

pause