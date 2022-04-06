from threading import Thread

if __name__ == "__main__":
    # Start Shutdown Timer
    import timer
    shutdown = timer.Timer(120, True)
    t1 = Thread(target=shutdown.startTimer)
    t1.start()

    # Add Interface Kivy

    # Start Server
    import server
    auth = server.startServer()
    if auth:
        shutdown.active = False