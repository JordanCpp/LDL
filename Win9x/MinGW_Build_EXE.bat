call "C:\Downloads\codeblocks-12.11mingw-setup\MinGW\mingwvars.bat"

g++ -o MinGW_%1.exe -s %2%1.cpp -IC:\Repos\Lib-LDL\include\ -L. -lLDL_MinGW -lglu32 -lopengl32