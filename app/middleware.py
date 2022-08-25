import globals

def tokenMiddleware(token):
    if token:
        if token == globals.TOKEN:
            return
        return "Error: Instance Token May be Incorrect", 406
    return "Error: No Instance Token Found", 400