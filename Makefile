## Compile MySecurity

CC=gcc

# Uncomment this lines to use compile to windows on an unix based system
# You will need 'mingw-w64' to be installed in your machine.
#
# CC=i686-w64-mingw32-gcc
# CFLAGS+= -lws2_32

PROGRAMS=$(BINARY)

# Uncomment this line in case of linker error while building
#
# CFLAGS+= -fno-use-linker-plugin

ifeq ($(OS),Windows_NT)
	CFLAGS+= -lws2_32
endif

BINARY=bin/mySecurity
CFILES=main.c libs/socket/socket.c handler/handler.c
OBJECTS=main.o libs/socket/socket.o handler/handler.o

all: $(PROGRAMS)

$(BINARY): $(OBJECTS)
	mkdir -p bin/
	$(CC) $^ -o $@ $(CFLAGS)

%.o:%.c
	$(CC) -c $^ -o $@ $(CFLAGS)

## Clear all binaries & objects 
clean:
	rm -rf bin/
	rm $(OBJECTS)
