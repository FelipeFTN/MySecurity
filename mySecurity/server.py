import socket

def startServer():
    # Initialize Server
    server = socket.socket()

    REMOTE_HOST = socket.gethostname()
    REMOTE_PORT = 1001

    print("[+] Server Initialized!")

    server.bind((REMOTE_HOST, REMOTE_PORT))
    server.listen()

    while True:
        try:
            client, client_addr = server.accept()
            client.send("[+] User Authenticated!")
            client.close()
            return True
        except Exception as e:
            return e