import socket
import base64

global LOCAL_HOST
global LOCAL_HOST_ADDRESS
global REMOTE_HOST_ADDRESS
global TOKEN

LOCAL_HOST = socket.gethostname()
LOCAL_HOST_ADDRESS = socket.gethostbyname(LOCAL_HOST)
REMOTE_HOST_ADDRESS = 'http://127.0.0.1:8000/instance'
# ToDo: Change Token with JWT Token
TOKEN = LOCAL_HOST + " " + LOCAL_HOST_ADDRESS
TOKEN = base64.b64encode(TOKEN.encode("utf-8"))
TOKEN = str(TOKEN, "utf-8")