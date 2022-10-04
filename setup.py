#!usr/bin/env python3

import getpass
import yaml 
import os

username = ""
password = ""

while username == "":
    username = str(input("User Name: ")).strip()
while password == "":
    password = str(input("Auth Password: ")).strip()

print("\n\n---- Here are some optional settings ------")
print("      -== Just press enter to skip ==-      \n")

serverPort = str(input("Server port (8000) > ")).strip()
clientPort = str(input("Client port (80) > ")).strip()
appPort = str(input("App port (5000) > ")).strip()

if serverPort == "": serverPort = "8000"
if clientPort == "": clientPort = "80"
if appPort == "": appPort = "5000"

settings = {
    "user": [{'username': username, 'authentication': password}],
    "mySecurity": [{'serverPort': serverPort, 'clientPort': clientPort, 'appPort': appPort}]
}

with open('./settings.yaml', 'w') as settingsFile:
    yaml.dump(settings, settingsFile)