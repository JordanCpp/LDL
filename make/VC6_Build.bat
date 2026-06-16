@echo off
setlocal enabledelayedexpansion

:: Список папок для обработки (через пробел)
set "FOLDERS=C++98\Lessons C++98\Points C++98\2DRender C++98\3DRender C++98\OpenGL3"

:: Перебираем каждую папку из списка
for %%d in (%FOLDERS%) do (
    set "TARGET_DIR=..\examples\%%d"

    :: Проверяем существование папки перед поиском
    if exist "!TARGET_DIR!" (
        :: Ищем все файлы .cpp и .c внутри этой папки
        for /f "delims=" %%f in ('dir /b "!TARGET_DIR!\*.cpp" "!TARGET_DIR!\*.c" 2^>nul') do (
            call VC6_EXE %%f !TARGET_DIR!
        )
    )
)

pause
