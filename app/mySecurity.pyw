from threading import Thread
import subprocess
import os

if __name__ == "__main__":
    serverDir = r"C:\Users\FelipeFTN\Desktop\MySecurity\server"
    subprocess.Popen(os.path.join(serverDir, "mySecurity.exe"))

    import interface
    t2 = Thread(target=interface.main)
    t2.start()

    import request
    req = request.sendRequest()
    import server

