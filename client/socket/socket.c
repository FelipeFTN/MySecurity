#ifdef _WIN32
#include <winsock2.h>
#include <Ws2tcpip.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

#include <string.h>
#include <stdio.h>

// Set up socket
int init_socket(int *client, int *sock)
{
#ifdef _WIN32
	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		printf("Failed. Error Code : %d",WSAGetLastError());
		return -1;
	}
#endif

	int port = 8080;
	struct sockaddr_in serv_addr;
	if ((*sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("[x] Error while creating the socket.\n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);

#ifdef _WIN32
	// Convert IP address from text to binary
	if (InetPtonW(AF_INET, L"127.0.0.1", &serv_addr.sin_addr) <= 0)
	{
		printf("[x] Error while converting IP.\n");
		return -1;
	}

#else
	// Convert IP address from text to binary
	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
	{
		printf("[x] Error while converting IP.\n");
		return -1;
	}
#endif

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
	printf("[+] Close socket");
	//Closing the connected socket
#ifdef _WIN32
	closesocket(client);
	WSACleanup();
#else
	close(client);
#endif
	return 0;
}

// Send message to server
int send_socket(int sock, char *buffer)
{
	int error;

	error = send(sock, buffer, strlen(buffer), 0);
	if (error < 0)
	{
		printf("[x] Error while sending to server\n");
		return -1;
	}

	return 0;
}

// Get a message from server
int receive_socket(int sock, char *buffer)
{
	int error;
	
#ifdef _WIN32
	error = recv(sock, buffer, 1024, 0);
	if (error < 0)
	{
		printf("[x] Error while receiving from server\n");
		return -1;
	}	
#else
	error = read(sock, buffer, 1024);
	if (error < 0)
	{
		printf("[x] Error while receiving from server\n");
		return -1;
	}
#endif

	printf("< %s\n", buffer);
	return 0;
}
