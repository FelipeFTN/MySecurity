@ECHO off

goto :main

:mySecurity
echo ===== Welcome to MySecurity Installer! =====
echo:
echo Quick Disclaimer:
echo Make sure you have the latest version of
echo python, golang, pip and npm installed in your computer.
echo:
echo Press enter to start...
PAUSE >nul
goto :eof

:installPythonRequirements
echo Installing Python Requirements...
echo:
start python.exe -m pip install -r ./app/requirements.txt
goto :eof

:mySecuritySetup
python.exe ./setup.py
echo:
goto :eof

:buildGo
echo Installing Goland Server...
cd ./server/
start go build 
cd ..
echo:
echo Press enter to continue... 
PAUSE >nul
goto :eof

:buildReact
echo Building React...
cd ./client/
npm run build
EXIT /B %ERRORLEVEL%

:main
CALL :mySecurity
CALL :installPythonRequirements
CALL :mySecuritySetup
CALL :buildGo
GOTO :buildReact