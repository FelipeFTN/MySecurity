from flask import request
from flask import Flask
import subprocess
import globals

app = Flask(__name__)

@app.route('/')
def mySecurity():
    return "MySecurity V1"

@app.route('/shutdown')
def shutdown():
    secret = request.headers.get('instance_secret')
    if secret:
        if secret == globals.SECRET:
            subprocess.call(['shutdown', '/s'], shell=True) 
            return "Done!"
        return "Error: Instance Secret May be Incorrect", 406
    return "Error: No Instance Secret Found", 400

app.run()