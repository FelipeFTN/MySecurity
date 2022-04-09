from tkinter import *
import subprocess
import threading
import socket
import time

connectionFinished = False

def server():
    # Iniciar Servidor
    server = socket.socket()

    REMOTE_HOST = socket.gethostname()
    REMOTE_PORT = 1001

    print("[+] Server Initialized...")

    server.bind((REMOTE_HOST, REMOTE_PORT))
    server.listen(5)

    while True:
        try:
            client, client_addr = server.accept()
            subprocess.call(['shutdown', '/a'], shell=True)
            client.send("Usuário autenticado!".encode())
            client.close()
            break
        except:
            print("ERROR")
    connectionFinished = True
        
class Application:
    def __init__(self, master=None):
        self.timerCountdown = 120

        subprocess.call(['shutdown', '/s', '/t', f'{self.timerCountdown}'], shell=True)

        self.container = Frame(master)
        self.container["padx"] = 30
        self.container.pack()

        self.title = Label(self.container, text="MySecurity")
        self.title["font"] = ("Verdana", "10", "bold")
        self.title.pack()

        self.question = Label(self.container, text="Quem está utilizando o computador?")
        self.question["font"] = ("Verdana", "8")
        self.question["pady"] = 10
        self.question.pack()

        self.name = Entry(self.container)
        self.name["width"] = 18
        self.name["font"] = ("Verdana", "10", "italic")
        self.name.pack(side=LEFT)

        self.submit = Button(self.container)
        self.submit["text"] = "Autenticar"
        self.submit["font"] = ("Verdana", "7")
        self.submit["width"] = 10
        self.submit.bind("<Button-1>", self.changeText)
        self.submit.pack(side=RIGHT)

        self.container1 = Frame(master)
        self.container1["padx"] = 30
        self.container1["pady"] = 20
        self.container1.pack()

        self.response = Label(self.container1, text="")
        self.response["font"] = ("Verdana", "10", "bold")
        self.response.pack()

        if connectionFinished:
            self.response["text"] = "Usuário Autenticado!"
            time.sleep(2)
            root.quit()

    def changeText(self, event):
        if self.name.get().strip() == "Felipe Tenorio":
            self.response["text"] = "Bem-vindo!\n \nPor favor faça a verificaçao de duplo fator"
            startServer = threading.Thread(target=server)
            startServer.start()
        else:
            self.response["text"] = "Desculpe, voce nao esta autorizado a utilizar este computador."


root = Tk()
Application(root)
root.mainloop()
