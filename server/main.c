#ifdef _WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <unistd.h>
#endif
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "handler/handler.h"
#include "socket/socket.h"

int main()
{
    bool connected, handshaked;
    char option[8] = { 0 };
    bool mysecurity = true;
    char handshake[16];
    int client;
    int sock;
    int error;

    while (mysecurity)
    {
        // Start socket server at port 8080
        error = init_socket(&client, &sock);
        if (error < 0)
            return -1;
        connected = true;

		// Receive client's handshake 
		error = receive_socket(client, handshake);
		if (error < 0)
			close_socket(client, sock);

		handshaked = strstr(handshake, "Handshake");

		if (!handshaked)
		{
			printf("[x] Could not handshake - `%s`\n", handshake);
			close_socket(client, sock);
			return -1;
		}
		printf("[+] Handshaked!\n");

		// While user does not choose 'Exit'
		while (connected)
		{
			// Send options to message
			error = send_socket(client, get_commands());
			if (error < 0)
				close_socket(client, sock);

			// Get message sended from client
			error = receive_socket(client, option);
			if (error < 0)
				close_socket(client, sock);

			// Handle user option
			error = run_command(option, &mysecurity, &connected);
			if (error < 0)
			{
				error = send_socket(client, "[!] Invalid option");
				if (error < 0)
					close_socket(client, sock);
			}
		}
    }
    return 0;
}
