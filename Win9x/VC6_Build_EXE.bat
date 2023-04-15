call "C:\VC6\Microsoft Visual Studio\VC98\Bin\VCVARS32.BAT"

cl /O2 -FeVC6_%1.exe -GX /I..\include %2%1.cpp /link LDL_VC6.lib