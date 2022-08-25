from threading import Thread

if __name__ == "__main__":
    import interface
    t2 = Thread(target=interface.main)
    t2.start()

    import request
    req = request.sendRequest()
    import server

