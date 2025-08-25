bcc32 -eBC6_%1.exe -I..\include %2%1.cpp /link LDL_BC6.lib glu32.lib opengl32.lib

del %1.obj
del BC6_%1.tds