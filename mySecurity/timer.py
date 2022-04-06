import subprocess
import time

class Timer:
    def __init__(self, timer, active):
        self.timer = timer
        self.active = active
   
    def startTimer(self):
        while self.active:
            time.sleep(self.timer)
            
            subprocess.call(['shutdown', '/s'], shell=True)
