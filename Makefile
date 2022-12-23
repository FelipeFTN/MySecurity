## Compile client & server

CC=gcc

# Uncomment this lines to use compile to windows on an unix based system
# CC=i686-w64-mingw32-gcc
# CFLAGS+= -lws2_32

PROGRAMS=$(SERVER_BINARY) $(CLIENT_BINARY)

# Uncomment this line in case of linker error while building
# CFLAGS+= -fno-use-linker-plugin

ifeq ($(OS),Windows_NT)
	CFLAGS+= -lws2_32
endif

## SERVER
SERVER_BINARY=bin/server 
SERVER_CFILES=server/main.c server/socket/socket.c server/handler/handler.c
SERVER_OBJECTS=server/main.o server/socket/socket.o server/handler/handler.o

## CLIENT
CLIENT_BINARY=bin/client 
CLIENT_CFILES=client/main.c client/socket/socket.c client/handler/handler.c
CLIENT_OBJECTS=client/main.o client/socket/socket.o client/handler/handler.o

all: $(PROGRAMS)

$(SERVER_BINARY): $(SERVER_OBJECTS)
	mkdir -p bin/
	$(CC) $^ -o $@ $(CFLAGS)

$(CLIENT_BINARY): $(CLIENT_OBJECTS)
	mkdir -p bin/
	$(CC) $^ -o $@ $(CFLAGS)

%.o:%.c
	$(CC) -c $^ -o $@ $(CFLAGS)

## Global
clean:
	rm -rf bin/
	rm $(SERVER_OBJECTS)
	rm $(CLIENT_OBJECTS)
