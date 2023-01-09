# C Compiler
CC=gcc

BINARY=bin/MySecurity
OBJECTS=main.o handler/api.o handler/libs/socket.o services/api.o data/api.o

$(BINARY): $(OBJECTS)
	mkdir -p bin/
	$(CC) $^ -o $@

%.o:%.c
	$(CC) -c $^ -o $@

## Global
clean:
	rm -rf bin/
	rm $(OBJECTS)
