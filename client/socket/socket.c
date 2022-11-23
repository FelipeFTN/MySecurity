#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

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
int close_socket(int client)
{
	close(client);
	return 0;
}

// Send message to server
int send_socket(int sock, char *buffer)
{
	int error;

	error = send(sock, buffer, strlen(buffer), 0);
	if (error < 0)
		return -1;

	printf("> %s\n", buffer);
	return 0;
}

// Get a message from server
int receive_socket(int sock, char *buffer)
{
	int error;
	
	error = read(sock, buffer, 1024);
	if (error < 0)
		return -1;

	printf("< %s\n", buffer);
	return 0;
}
