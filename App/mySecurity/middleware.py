import globals

def secretMiddleware(secret):
    if secret:
        if secret == globals.SECRET:
            return
        return "Error: Instance Secret May be Incorrect", 406
    return "Error: No Instance Secret Found", 400