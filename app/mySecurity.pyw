from threading import Thread
import subprocess
import globals
import os

if __name__ == "__main__":
    serverDir = r"C:\Users\FelipeFTN\Desktop\MySecurity\server"
    subprocess.Popen(os.path.join(serverDir, "mySecurity.exe"))

    subprocess.call([f'serve -l {globals.CLIENT_PORT} -s build'], shell=True)

    import interface
    t2 = Thread(target=interface.main)
    t2.start()

    import request
    req = request.sendRequest()
    import server

