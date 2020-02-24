
"d:\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\g++" -ogame -std=c++11 -Wall -Wextra -Wformat -Werror -pedantic -O2 -s *.cpp -DLDL_PlatformWindows -DLDL_64bit -Iinclude\ -lgdi32 -luser32 -lmingw32 -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic

pause