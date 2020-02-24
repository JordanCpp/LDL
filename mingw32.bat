
"d:\mingw-w64\i686-8.1.0-win32-dwarf-rt_v6-rev0\mingw32\bin\g++" -ogame -std=c++11 -Wall -Wextra -Wformat -Werror -pedantic -O2 -s -flto *.cpp -DLDL_PlatformWindows -DLDL_32bit -Iinclude\ -lgdi32 -luser32 -lmingw32 -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic

pause