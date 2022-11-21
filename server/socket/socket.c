#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int server_socket;

// Set up socket
int init_socket(int *client)
{
    struct sockaddr_in address;
    const int port = 8080;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    address.sin_family = AF_INET;

    int addrlen = sizeof(address);
    int opt = 1;

    printf("MySecurity PORT: %d\n", port);

    // Open socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("[x] Error while creating the socket.\n");
        return -1;
    }

    // Set address for reuse
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, (socklen_t)sizeof(opt)) < 0)
    {
        printf("[x] Error while setting address for reuse\n");
        return -1;
    }

    // Bind address and port to socket
    if (bind(server_socket, (struct sockaddr *)&address, (socklen_t)addrlen) < 0)
    {
        printf("[x] Error while binding the socket.\n");
        return -1;
    }

    // Listen to socket for connections
    if (listen(server_socket, 3) < 0)
    {
        printf("[x] Error while listening the socket.\n");
        return -1;
    }

    // Accept client connection
    if ((*client = accept(server_socket, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        printf("[x] Error while accepting the client.\n");
        return -1;
    }
	printf("[+] Client Connected!\n");

    return 0;
}

// End up socket
int close_socket()
{
	printf("[+] Close socket");
    int error = shutdown(server_socket, SHUT_RDWR);
    if (error)
        return -1;
    return 0;
}

// Send a message to client
int client_send(int client, char *buffer)
{
    if (send(client, buffer, strlen(buffer), 0) < 0)
    {
        printf("[x] Error while sending message.\n");
        return -1;
    }
    return 0;
}

// Get a message from client
int client_receive(int client, char *buffer)
{
	printf("client message: %s", buffer);

	char new_buffer[1024] = { 0 };
    int readValue;

    readValue = recv(client, new_buffer, 1024);
    if (readValue < 0)
    {
        printf("[%d] Error while receiving message.\n", readValue);
		return 1;
    }
	buffer = new_buffer;
	printf("> %s\n", new_buffer);

	printf("client message: %s", buffer);

    return 0;
}
