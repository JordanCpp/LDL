
for /r ..\%2 %%a in (*.cpp) do (
    call %1 %%~nxa %2%%~nxa
)

pause