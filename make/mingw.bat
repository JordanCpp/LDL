call "C:\Downloads\codeblocks-12.11mingw-setup\MinGW\mingwvars.bat"

g++ -Wall -Wextra -pedantic -o mingw_%1.exe -O2 -s %2%1.cpp -I..\include -lgdi32 -lopengl32 -lwinmm