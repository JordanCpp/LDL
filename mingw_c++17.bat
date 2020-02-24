del game.exe

call "..\mingw\mingwvars.bat"
"..\mingw\bin\g++" -ogame -std=c++17 -Wall -Wformat -Werror *.cpp -DLDL_PlatformWindows -DLDL_32bit -Iinclude\  -lgdi32 -luser32 -lmingw32 -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic

pause