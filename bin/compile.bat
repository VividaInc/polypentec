@echo off
setlocal
set EXE="bin/a.exe"
set INCLUDE="C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include"
set LIBRARY="C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/lib"
set LOCALLIBRARY="include"

gcc -c -I%LOCALLIBRARY% src/init.c
gcc -c -I%LOCALLIBRARY% src/window.c
gcc -c -I%LOCALLIBRARY% src/render.c
gcc -c -I%LOCALLIBRARY% src/textbox.c
gcc -c -I%LOCALLIBRARY% src/button.c
gcc -c -I%LOCALLIBRARY% src/main.c

gcc -o %EXE% -I%INCLUDE% -L%LIBRARY% init.o window.o render.o textbox.o button.o main.o -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
