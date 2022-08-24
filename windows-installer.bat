@ECHO off

:installPythonRequirements
python.exe -m pip install -r ./app/python/requirements.txt

:startGo
cd ./api/
go run ./main.go

:startPython

:startReact

pause