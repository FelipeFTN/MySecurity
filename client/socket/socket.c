#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int client_socket;

// Set up socket
int init_socket(int *client, int *sock)
{
	int valread;
	int port = 8080;
	char buffer[1024] = { 0 };
	struct sockaddr_in serv_addr;
	if ((*sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("[x] Error while creating the socket.\n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);

	// Convert IP address from text to binary
	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
	{
		printf("[x] Error while converting IP.\n");
		return -1;
	}

	// Connect client to server
	if((*client = connect(*sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0)
	{
		printf("[x] Error while connecting to server.\n");
		return -1;
	}
	printf("[+] Server Connected!\n");

	return 0;
}

// End up socket
int close_socket(int* client)
{
	close(*client);
	return 0;
}

// Send a message to server
int server_send(int sock, char *buffer)
{
	// client or sock
	if (send(sock, buffer, strlen(buffer), 0) < 0)
	{
		printf("[x] Error while sending message.\n");
		return -1;
	}
	return 0;
}

// Get a message from server
int server_receive(int sock, char *buffer)
{
    char new_buffer[1024] = {0};
    int readValue;

    readValue = recv(sock, new_buffer, 1024);
    if (readValue < 0)
    {
        printf("[%d] Error while receiving message.\n", readValue);
		return 1;
    }
	buffer = new_buffer;
	printf("> %s\n", buffer);

    return 0;
}
