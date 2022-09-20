import socket
import base64
import yaml

global LOCAL_HOST_ADDRESS
global SERVER_HOST_ADDRESS
global LOCAL_HOST_NAME
global AUTH_PASSWORD
global SERVER_PORT
global CLIENT_PORT
global LOCAL_HOST
global APP_PORT
global TOKEN

try:
    with open('./settings.yaml', 'r') as settings:
        settingsYaml = yaml.safe_load(settings)
except:
    with open('../settings.yaml', 'r') as settings:
        settingsYaml = yaml.safe_load(settings)

LOCAL_HOST = socket.gethostname() 
LOCAL_HOST_NAME = settingsYaml['user'][0]['username']
AUTH_PASSWORD = settingsYaml['user'][0]['authentication']
SERVER_PORT = settingsYaml['mySecurity'][0]['serverPort']
CLIENT_PORT = settingsYaml['mySecurity'][0]['clientPort']
APP_PORT = settingsYaml['mySecurity'][0]['appPort']
LOCAL_HOST_ADDRESS = socket.gethostbyname(LOCAL_HOST)
SERVER_HOST_ADDRESS = f'http://127.0.0.1:{SERVER_PORT}'
# ToDo: Change Token with Bcrypt 
TOKEN = LOCAL_HOST_NAME + " " + LOCAL_HOST_ADDRESS
TOKEN = base64.b64encode(TOKEN.encode("utf-8"))
TOKEN = str(TOKEN, "utf-8")
