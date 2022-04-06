import subprocess
import time

class Timer:
    def __init__(self, timer, active):
        self.active = active
        self.timer = timer
   
    def startTimer(self):
        time.sleep(self.timer)
        
        if self.active == False: return

        print("[!] Shutdown Called!")
        # subprocess.call(['shutdown', '/s'], shell=True)
