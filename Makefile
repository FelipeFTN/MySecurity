
bin/mySecurity: src/main.o src/socket/socket.o src/handler/handler.o
	mkdir bin
	gcc src/main.o src/socket/socket.o src/handler/handler.o -o bin/mySecurity

main.o: src/main.c
	gcc -c src/main.c -o src/main.o

socket.o: src/socket/socket.c src/socket/socket.h
	gcc -c src/socket/socket.c -o src/socket/socket.o

handler.o: src/handler/handler.c src/handler/handler.h
	gcc -c src/handler/handler.c -o src/handler/handler.o

clean:
	rm src/*.o src/handler/*.o src/socket/*.o
	rm -rf bin/
