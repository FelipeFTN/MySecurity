import requests
import globals

def sendRequest():
    try:
        response = requests.post(
            f"{globals.SERVER_HOST_ADDRESS}/instance",
            json={
                'instance_name': globals.LOCAL_HOST_NAME,
                'instance_ip':  globals.LOCAL_HOST_ADDRESS,
                'instance_token': globals.TOKEN
            }
        )
        return response.status_code
    except:
        return {"status_code": 500, "Error":"No Connection was stablished!"}['status_code']

def sendAuthorization():
    try:
        headers = {'Authorization': globals.TOKEN}
        response = requests.get(
            f"{globals.SERVER_HOST_ADDRESS}/auth",
            headers=headers
        )
        return response.status_code
    except:
        return {"status_code": 401, "Error":"Authorization failed!"}['status_code']