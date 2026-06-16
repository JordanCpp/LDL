
call "C:\VC6\VC98\Bin\VCVARS32.BAT"

CL /O2 /FeLDL_Image.dll -LD -GX /DLDL_SHARED_LIBRARY ^
..\source\LDL_Image\*.c ^
/I..\include\ ^
/I..\source\ ^
LDL.lib

del *.obj

pause
