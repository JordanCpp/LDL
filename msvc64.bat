call "c:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"

"c:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.24.28314\bin\Hostx64\x64\cl" /EHsc /DLDL_PlatformWindows /DLDL_64bit /W4 /Fe"game" /O2 *.cpp /MT /Iinclude\ /link gdi32.lib user32.lib

pause