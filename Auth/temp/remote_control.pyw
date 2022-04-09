import subprocess
import socket
import time

server = socket.socket()

REMOTE_HOST = socket.gethostname()
REMOTE_PORT = 1002

print("[+] Server Initialized...")

server.bind((REMOTE_HOST, REMOTE_PORT))
server.listen(5)

while True:
    client, client_addr = server.accept()
    print(client_addr)
    print("[+] Client Connected!")

    time.sleep(2)

    message = "0. Shutdown Now!\n1. No Authorization\n2. Log Out!\n3. Send Message"
    message = message.encode()
    client.send(message)

    print("[+] Message Sended to Client")

    print("")
    
    option = client.recv(1024)
    option = option.decode()
    if option == "0":
        subprocess.call(['shutdown', '/p'], shell=True)
        print("[+] Command Receved!")
    elif option == "1":
        subprocess.call(['shutdown', '/s', '/c', "'ERRO: VOCÊ NÃO TEM AUTORIZAÇÃO PARA UTILIZAR ESTE COMPUTADOR!'"], shell=True)
        print("[+] Command Receved!")
    elif option == "2":
        subprocess.call(['shutdown', '/l'], shell=True)
        print("[+] Command Receved!")
    elif option == "3":
        client.send("Type the Message: ".encode())
        clientMessage = client.recv(1024)
        clientMessage = clientMessage.decode()
        subprocess.call(['msg', '*', f'{clientMessage}'], shell=True)
        client.send("[+] Command Receved!".encode())

