call "C:\VC6\Microsoft Visual Studio\VC98\Bin\VCVARS32.BAT"

cl /O2 -Fevc6_test.exe -GX ..\test.cpp /I..\include /link gdi32.lib winmm.lib user32.lib opengl32.lib

del *.obj

pause