call "C:\Downloads\codeblocks-12.11mingw-setup\MinGW\mingwvars.bat"

g++ -Wall -Wextra -pedantic -o mingw_test.exe -O2 -s ..\test.cpp -I..\include -lgdi32 -lopengl32 -lwinmm

pause