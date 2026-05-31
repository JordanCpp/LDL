
call "C:\VC6\VC98\Bin\VCVARS32.BAT"

cl /O2 -Fe%1.exe -GX /I..\include %2\%1 /link LDL.lib

del *.obj
