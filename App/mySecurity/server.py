from flask import request
from flask import Flask
import subprocess
import middleware

app = Flask(__name__)

@app.route('/')
def mySecurity():
    return "MySecurity V1"

@app.route('/shutdown')
def shutdown():
    secret = request.headers.get('instance_secret')
    err = middleware.secretMiddleware(secret)
    if err: return err[0], err[1]

    subprocess.call(['shutdown', '/s'], shell=True)
    return "Done!"

@app.route('/logout')
def logout():
    secret = request.headers.get('instance_secret')
    err = middleware.secretMiddleware(secret)
    if err: return err[0], err[1]

    subprocess.call(['shutdown', '/l'], shell=True)
    return "Done"

app.run(host='0.0.0.0')