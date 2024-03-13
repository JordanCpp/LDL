call "C:\VC6\Microsoft Visual Studio\VC98\Bin\VCVARS32.BAT"

cl /O2 -Fevc6_gl1_%1.exe ..\source\*.cpp ..\source\OpenGL\*.cpp ..\source\Renders\*.cpp ..\source\Platform\Windows\*.cpp %2%1.cpp /I..\include /DLDL_SUPPORT_OPENGL1 /link gdi32.lib winmm.lib user32.lib opengl32.lib

del *.obj