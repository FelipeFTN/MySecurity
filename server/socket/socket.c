#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

// Set up socket
int init_socket(int *client, int *sock)
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
    if ((*sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("[x] Error while creating the socket.\n");
        return -1;
    }

    // Set address for reuse
    if (setsockopt(*sock, SOL_SOCKET, SO_REUSEADDR, &opt, (socklen_t)sizeof(opt)) < 0)
    {
        printf("[x] Error while setting address for reuse\n");
        return -1;
    }

    // Bind address and port to socket
    if (bind(*sock, (struct sockaddr *)&address, (socklen_t)addrlen) < 0)
    {
        printf("[x] Error while binding the socket.\n");
        return -1;
    }

    // Listen to socket for connections
    if (listen(*sock, 3) < 0)
    {
        printf("[x] Error while listening the socket.\n");
        return -1;
    }

    // Accept client connection
    if ((*client = accept(*sock, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        printf("[x] Error while accepting the client.\n");
        return -1;
    }
	printf("[+] Client Connected!\n");

    return 0;
}

// End up socket
int close_socket(int client, int sock)
{
	printf("[+] Close socket\n");
	// Closing the connected socket
	close(client);
	// Closing the listening socket
    int error = shutdown(sock, SHUT_RDWR);
    if (error)
	{
		printf("[x] Error while turning off the socket\n");
        return -1;
	}

    return 0;
}

// Send message to client 
int send_socket(int client, char *buffer)
{
	int error;

	error = send(client, buffer, strlen(buffer), 0);
	if (error < 0)
	{
		printf("[x] Error while sending to client\n");
		return -1;
	}

	return 0;
}

// Get message from client 
int receive_socket(int client, char *buffer)
{
	int error;

	error = read(client, buffer, 1024);
	if (error < 0)
	{
		printf("[x] Error while receiving from client\n");
		return -1;
	}

	printf("< %s\n", buffer);
	return 0;
}
