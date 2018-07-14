@echo off
setlocal
set command="start /B ^"zmem^" ^".ecce/bin/zmem.exe^""
cd "%GOPATH%/src/zmem"
cmd /C %command%
endlocal
