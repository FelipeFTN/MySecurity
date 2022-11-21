#include <stdbool.h>
#include <stdio.h>

#include "socket/socket.h"

int main() {
	char *message = "MySecurity - HandShake";
	int client, error, sock = 0;
	bool mysecurity, connected;
	char *command;

	// Start Client
	error = init_socket(&client, &sock);
	if (error < 0)
		return -1;
	connected = true;
	
	// Send Handshake to server
	error = server_send(sock, message);
	if (error < 0)
		return -1;

	// Receive from server
	error = server_receive(sock, message);
	if (error < 0)
		return -1;

	printf("< ");
	scanf("%s", command);
	error = server_send(sock, command);
	if (error < 0)
		return -1;

	return 0;
}
