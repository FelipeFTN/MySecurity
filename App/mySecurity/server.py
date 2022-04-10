import subprocess
import socket
import json

def startServer():
    # Initialize Server
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    REMOTE_HOST = socket.gethostname()
    REMOTE_PORT = 9000 
    LOCAL_HOST = socket.gethostbyname(REMOTE_HOST)

    server.bind((REMOTE_HOST, REMOTE_PORT))
    server.listen()

    # Client Connection
    while True:
        client, client_addr = server.accept()
        print(client_addr)
        message = {
            "0": "Shutdown Now",
            "1": "No Authorization",
            "2": "Log Out",
            "3": "Send Message"
        }

        message = json.dumps(message, indent=2).encode("utf-8")
        client.send(message)

        request = client.recv(1024)
        request = request.decode()
        if request == "0":
            subprocess.call(['shutdown', '/p'], shell=True)
            print("[+] Command Receved!")
        elif request == "1":
            subprocess.call(['shutdown', '/s', '/c', "'ERROR: YOU DO NOT HAVE PERMISSION TO USE THIS COMPUTER!'"], shell=True)
            print("[+] Command Receved!")
        elif request == "2":
            subprocess.call(['shutdown', '/l'], shell=True)
            print("[+] Command Receved!")
        elif request == "3":
            client.send("Type the Message: ".encode())
            clientMessage = client.recv(1024)
            clientMessage = clientMessage.decode()
            subprocess.call(['msg', '*', f'{clientMessage}'], shell=True)
            client.send("[+] Command Receved!".encode())