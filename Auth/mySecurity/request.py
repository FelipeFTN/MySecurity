import requests
import socket

LOCAL_HOST = socket.gethostname()
LOCAL_HOST_ADDRESS = socket.gethostbyname(LOCAL_HOST)
REMOTE_HOST_ADDRESS = 'http://127.0.0.1:8000/instance'

def sendRequest():
    response = requests.post(
        REMOTE_HOST_ADDRESS,
        json={
            'instance_name': LOCAL_HOST,
            'instance_ip':  LOCAL_HOST_ADDRESS
        }
    )

    return response
