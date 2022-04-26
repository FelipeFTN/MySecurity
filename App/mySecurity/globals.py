import socket
import base64

global LOCAL_HOST
global LOCAL_HOST_ADDRESS
global REMOTE_HOST_ADDRESS
global SECRET

LOCAL_HOST = socket.gethostname()
LOCAL_HOST_ADDRESS = socket.gethostbyname(LOCAL_HOST)
REMOTE_HOST_ADDRESS = 'http://127.0.0.1:8000/instance'
# ToDo: Change Secret to JWT Token
SECRET = LOCAL_HOST + LOCAL_HOST_ADDRESS
SECRET = base64.b64encode(SECRET.encode("utf-8"))
SECRET = str(SECRET, "utf-8")