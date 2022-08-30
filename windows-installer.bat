@ECHO off

echo ===== Welcome to MySecurity Installer! =====
echo:
echo Quick Disclaimer:
echo Make sure you have the latest version of
echo python, golang, pip and npm installed in your computer.
echo:
pause

:installPythonRequirements
echo Installing Python Requirements...
echo:
start python.exe -m pip install -r ./app/requirements.txt

:mySecurityConfiguration
python.exe ./setup.py
echo:

:buildGo
echo Installing Goland Server
cd ./server/
start go build 
echo:

:buildReact
echo Building React
cd ../client/
start npm run build
echo:

echo Congratulation! MySecurity Successfully installed.
echo:
pause