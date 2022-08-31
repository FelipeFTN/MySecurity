import subprocess
import globals

def start():
    cmd = f"serve -l {globals.CLIENT_PORT} -s build"
    cmd = cmd.split(" ")
    dir = r"C:\Users\FelipeFTN\Desktop\MySecurity\client"
    subprocess.call(cmd, cwd=dir, shell=True)
