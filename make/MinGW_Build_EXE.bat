call "c:\Downloads\codeblocks-25.03mingw-32bit-setup\MinGW\mingwvars.bat"

g++ -o MinGW_%1.exe -O2 -s -static %2%1.cpp -I..\include\ -L. -lLDL_MinGW -lglu32 -lopengl32