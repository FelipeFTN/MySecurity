import requests
import globals

def sendRequest():
    response = requests.post(
        globals.REMOTE_HOST_ADDRESS,
        json={
            'instance_name': globals.LOCAL_HOST,
            'instance_ip':  globals.LOCAL_HOST_ADDRESS,
            'instance_secret': globals.SECRET
        }
    )

    return response
