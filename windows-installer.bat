@ECHO off

echo Welcome to MySecurity Installer!
echo:
echo Disclaimer:
echo Make sure you have the latest version of python, golang, pip and npm installed in your computer.
pause

:installPythonRequirements
echo Installing Python Requirements
start python.exe -m pip install -r ./app/requirements.txt

:startGo
echo Installing Goland Server
cd ./server/
start go build 

pause