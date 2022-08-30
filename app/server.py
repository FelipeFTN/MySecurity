from flask import request
from flask import Flask
import subprocess
import middleware
import globals

app = Flask(__name__)

@app.route('/')
def mySecurity():
    return "MySecurity V1"

@app.route('/shutdown')
def shutdown():
    token = request.headers.get('instance_token')
    err = middleware.tokenMiddleware(token)
    if err: return err[0], err[1]

    subprocess.call(['shutdown', '/s'], shell=True)
    return "Done!"

@app.route('/logout')
def logout():
    token = request.headers.get('instance_token')
    err = middleware.tokenMiddleware(token)
    if err: return err[0], err[1]

    subprocess.call(['shutdown', '/l'], shell=True)
    return "Done!"

@app.route('/message', methods=['POST'])
def message():
    token = request.headers.get('instance_token')
    err = middleware.tokenMiddleware(token)
    if err: return err[0], err[1]

    content_type = request.headers.get('Content-Type')
    if content_type != 'application/json':
        return "Content-Type not Supported!", 400

    json = request.json
    message = json['message']
    subprocess.call(['msg', '*', message])
    return "Done!"

app.run(host='0.0.0.0', port=globals.APP_PORT)