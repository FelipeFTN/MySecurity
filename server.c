#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int server(int *client) {
    struct sockaddr_in address;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    address.sin_family = AF_INET;

    char buffer[1024];
    int addrlen = sizeof(address);
    int server_socket;
    int opt = 1;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("[%d] Error while creating the socket.");
        return -1;
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, (socklen_t) sizeof(opt)) < 0) {
        printf("[x] Error while setting address for reuse\n");
        return -1;
    }

    if (bind(server_socket, (struct sockaddr*) &address, (socklen_t) addrlen) < 0) {
        printf("[%d] Error while binding the socket.");
        return -1;
    }

    if (listen(server_socket, 3) < 0) {
        printf("[%d] Error while listening the socket.");
        return -1;
    }

    if ((*client = accept(server_socket, (struct sockaddr*) &address, (socklen_t*) &addrlen)) < 0) {
        printf("[%d] Error while accepting the client.", *client);
        return -1;
    }

    printf("[%d] Client Connected!\n", *client);

    return 0;
}

int sendMessage(int client, char* message) {

    printf("client: %d\n", client);
    if (send(client, message, strlen(message), 0) < 0) {
        printf("[x] Error while sending message.\n");
        return -1;
    }

    printf("%s\n", message);

    return 0;
}