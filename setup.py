#!usr/bin/env python3

import yaml 

username = str(input("My name is: ")).strip()
password = str(input("My authentication password will be: ")).strip()
print("---- Here are some optional settings ------")
print("      -== Just press enter to skip ==-      ")
serverPort = str(input("Server port (8000) > ")).strip()
clientPort = str(input("Client port (3000) > ")).strip()

if serverPort == "": serverPort = "8000"
if clientPort == "": clientPort = "3000"

settings = {
    "user": [{'username': username}, {'authentication': password}],
    "mySecurity": [{'serverPort': serverPort}, {'clientPort': clientPort}]
}

with open('./settings.yaml', 'w') as settingsFile:
    yaml.dump(settings, settingsFile)