@echo off

:: Verify Make
make >nil 2>&1 && (
  echo Initiating MySecurity build
) || (
  echo error: cmake is not installed!
  exit /b
)

:: Startup directory
set startup=%appdata%\Roaming\Microsoft\Windows\Start Menu\Programs\Startup

:: Build File
make

:: Copy binary to startup folder
copy ./bin/MySecurity.exe "%startup%"
