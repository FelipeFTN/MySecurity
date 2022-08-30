import socket
import base64
import yaml

global LOCAL_HOST
global LOCAL_HOST_ADDRESS
global SERVER_HOST_ADDRESS
global TOKEN
global AUTH_PASSWORD

with open('./settings.yaml', 'r') as settings:
    settingsYaml = yaml.safe_load(settings)

LOCAL_HOST = settingsYaml['user'][0]['username']
AUTH_PASSWORD = settingsYaml['user'][0]['authentication']
SERVER_PORT = settingsYaml['mySecurity'][0]['serverPort']
APP_PORT = settingsYaml['mySecurity'][0]['appPort']
LOCAL_HOST_ADDRESS = socket.gethostbyname(socket.gethostname())
SERVER_HOST_ADDRESS = f'http://127.0.0.1:{SERVER_PORT}/instance'
# ToDo: Change Token with Bcrypt 
TOKEN = LOCAL_HOST + " " + LOCAL_HOST_ADDRESS
TOKEN = base64.b64encode(TOKEN.encode("utf-8"))
TOKEN = str(TOKEN, "utf-8")
