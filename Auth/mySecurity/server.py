import socket

def startServer():
    # Initialize Server
    server = socket.socket()

    REMOTE_HOST = socket.gethostname()
    REMOTE_PORT = 8000 
    LOCAL_HOST = socket.gethostbyname(REMOTE_HOST)

    server.connect((REMOTE_HOST, REMOTE_PORT))
    server.send(LOCAL_HOST.encode())