from threading import Thread

if __name__ == "__main__":
    # Interface Kivy
    # import interface
    # mySecurity = interface.Application()
    # t2 = Thread(target=mySecurity.run)
    # t2.start()

    # Request Back-end
    import request
    req = request.sendRequest()
    if req.status_code == 200:

        # Start Server
        import server
        server.startServer()

