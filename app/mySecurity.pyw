from threading import Thread
import subprocess
import globals
import time
import os

if __name__ == "__main__":

    serverDir = r"C:\Users\FelipeFTN\Desktop\MySecurity\server"
    subprocess.Popen(os.path.join(serverDir, "mySecurity.exe"))

    import client
    t1 = Thread(target=client.start)
    t1.start()

    import interface
    t2 = Thread(target=interface.main)
    t2.start()

    import request
    req = request.sendRequest()
    while req != 200:
        req = request.sendRequest()
        time.sleep(5)

    import server

