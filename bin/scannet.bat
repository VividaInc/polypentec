@echo off

@call :initialize
@call :validate 1 8.8.8.8
@call :clean

@pause
@goto :eof

:clean
@cls
@netsh wlan show networks mode=bssid
@sc stop dot3svc >NUL
@exit /b

:initialize
@sc start dot3svc >NUL
@netsh interface set interface "Wi-Fi" disabled
@netsh interface set interface "Wi-Fi" enabled
@exit /b

:validate
@setlocal
@ping -n %~1 %~2 | @find "TTL=" >NUL
@if errorlevel 1 @call :validate %~1 %~2
@endlocal
@exit /b
