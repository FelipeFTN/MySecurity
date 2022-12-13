#include <stdbool.h>
#include <stdio.h>

#include "socket/socket.h"

int main() {
	char *handshake = "MySecurity - HandShake";
	char message[1024] = { 0 };
	int client, error, sock = 0;
	bool connected;
	char *command;

	// Start Client
	error = init_socket(&client, &sock);
	if (error < 0)
		return -1;
	connected = true;
	
	// Send Handshake to server
	error = send_socket(sock, handshake);
	if (error < 0)
		return -1;

	while (connected)
	{
		// Receive from server
		error = receive_socket(sock, message);
		if (error < 0)
			return -1;

		// Send to server
		printf("< ");
		scanf("%s", command);
		error = send_socket(sock, command);
		if (error < 0)
			return -1;
	}

	return 0;
}
