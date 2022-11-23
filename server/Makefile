
bin/mySecurity: main.o socket/socket.o handler/handler.o
	mkdir -p bin/
	gcc main.o socket/socket.o handler/handler.o -o bin/mySecurity

main.o: main.c
	gcc -c main.c -o main.o

socket.o: socket/socket.c socket/socket.h
	gcc -c socket/socket.c -o socket/socket.o

handler.o: handler/handler.c handler/handler.h
	gcc -c handler/handler.c -o handler/handler.o

clean:
	rm *.o handler/*.o socket/*.o
	rm -rf bin/
