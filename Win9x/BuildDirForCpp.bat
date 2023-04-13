
for /r ..\%2 %%a in (*.cpp *.c) do (
    call %1 %%~nxa %2%%~nxa
)