from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello_world():
    return "MySecurity V1"

@app.route('/authenticate')
def authenticate():
    return "Auth"

app.run()
