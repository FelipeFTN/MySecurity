@echo off

:: Startup directory
set startup=%appdata%\Roaming\Microsoft\Windows\Start Menu\Programs\Startup

:: Build File
make

:: Copy binary to startup folder
copy ./bin/MySecurity.exe "%startup%"
