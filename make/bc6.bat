bcc32 -w-8027 -O2 -I..\include -DLDL_SUPPORT_OPENGL1 -ebc6_%1.exe ..\source\*.cpp ..\source\OpenGL\*.cpp ..\source\Renders\*.cpp ..\source\Platform\Windows\*.cpp %2%1.cpp

del *.obj
del *.tds