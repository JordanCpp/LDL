call "c:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars32.bat"

"c:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.24.28314\bin\Hostx86\x86\cl" /EHsc /DLDL_PlatformWindows /DLDL_32bit /W4 /Fe"game" /O2 *.cpp /MT /Iinclude\ /link gdi32.lib user32.lib

pause