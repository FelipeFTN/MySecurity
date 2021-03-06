import requests
import globals

def sendRequest():
    try:
        response = requests.post(
            globals.REMOTE_HOST_ADDRESS,
            json={
                'instance_name': globals.LOCAL_HOST,
                'instance_ip':  globals.LOCAL_HOST_ADDRESS,
                'instance_token': globals.TOKEN
            }
        )
    except:
        return "Error: No Connection was stablished!"

    return response
