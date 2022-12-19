## Compile client & server

all: bin/client bin/server

bin/client: client/main.o client/socket/socket.o client/handler/handler.o
	mkdir -p bin/
	winegcc client/main.o client/socket/socket.o client/handler/handler.o -o bin/client

bin/server: server/main.o server/socket/socket.o server/handler/handler.o
	mkdir -p bin/
	winegcc server/main.o server/socket/socket.o server/handler/handler.o -o bin/server

## CLIENT
client/main.o: client/main.c
	winegcc -c client/main.c -o client/main.o

client/socket/socket.o: client/socket/socket.c client/socket/socket.h
	winegcc -c client/socket/socket.c -o client/socket/socket.o

client/handler/handler.o: client/handler/handler.c client/handler/handler.h
	winegcc -c client/handler/handler.c -o client/handler/handler.o

## SERVER
server/main.o: server/main.c
	winegcc -c server/main.c -o server/main.o

server/socket/socket.o: server/socket/socket.c server/socket/socket.h
	winegcc -c server/socket/socket.c -o server/socket/socket.o

server/handler/handler.o: server/handler/handler.c server/handler/handler.h
	winegcc -c server/handler/handler.c -o server/handler/handler.o

clean:
	rm client/*.o client/handler/*.o client/socket/*.o
	rm server/*.o server/handler/*.o server/socket/*.o
	rm -rf client/bin
	rm -rf server/bin
	rm -rf bin/
