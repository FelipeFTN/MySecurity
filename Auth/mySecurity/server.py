import socket

def startServer():
    # Initialize Server
    server = socket.socket()

    REMOTE_HOST = socket.gethostname()
    REMOTE_PORT = 1001

    print("[+] Server Initialized!")

    server.bind((REMOTE_HOST, REMOTE_PORT))
    server.listen()

    # Connection Loop
    while True:
        client, client_addr = server.accept()
        client.send("[+] User Authenticated!".encode())
        client.close()
        return True