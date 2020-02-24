del game.exe

call "..\mingw\mingwvars.bat"
"..\mingw\bin\g++" -ogame -std=c++98 -Wall -Wformat -Werror -pedantic -O2 -s *.cpp -DLDL_PlatformWindows -DLDL_32bit -Iinclude\ -lgdi32 -luser32 -lmingw32 -Wl,-Bstatic -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread

pause