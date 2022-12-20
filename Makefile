## Compile client & server
CC=gcc
PROGRAMS=bin/server bin/client
ifeq ($(OS),Windows_NT)
	CFLAGS+= -l ws2_32
endif

## SERVER
BINARY=bin/server 
CFILES=server/main.c server/socket/socket.c server/handler/handler.c 
OBJECTS=server/main.o server/socket/socket.o server/handler/handler.o 

all: $(PROGRAMS)

$(BINARY): $(OBJECTS)
	mkdir -p bin/
	$(CC) $^ -o $@

%.o:%.c
	$(CC) -c $^ -o $@ $(CFLAGS)

## CLIENT
BINARY=bin/client 
CFILES=client/main.c client/socket/socket.c client/handler/handler.c 
OBJECTS=client/main.o client/socket/socket.o client/handler/handler.o 

$(BINARY): $(OBJECTS)
	mkdir -p bin/
	$(CC) $^ -o $@

%.o:%.c
	$(CC) -c $^ -o $@ $(CFLAGS)

## Global
clean:
	rm -rf bin/
	rm server/*.o server/handler/*.o server/socket/*.o
	rm client/*.o client/handler/*.o client/socket/*.o
