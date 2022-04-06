import threading

if __name__ == "__main__":
    # Start Shutdown Timer
    import timer
    shutdown = timer(120, True)

    # ToDo: Apply Threads Here

    # Start Server
    import server
    auth = server.startServer()