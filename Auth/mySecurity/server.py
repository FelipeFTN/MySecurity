import subprocess
import socket

def startServer():
    # Initialize Server
    server = socket.socket()

    REMOTE_HOST = socket.gethostname()
    REMOTE_PORT = 8000 
    LOCAL_HOST = socket.gethostbyname(REMOTE_HOST)

    server.bind((REMOTE_HOST, REMOTE_PORT))
    server.listen()

    # Client Connection
    while True:
        client, client_addr = server.accept()

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