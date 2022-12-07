#include <sys/socket.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "handler/handler.h"
#include "socket/socket.h"

int main()
{
    bool mysecurity = true;
    bool connected;
	char handshake[64];
    char *option;
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

        // While user does not choose 'Exit'
        while (connected)
        {
			// Receive client's handshake 
			error = receive_socket(client, handshake);
            if (error < 0)
                close_socket(client, sock);
			if (handshake != "MySecurity - HandShake")
			{
				printf("[x] Could not handshake - `%s`\n", handshake);
				close_socket(client, sock);
				return -1;
			}

            // Send options to message
            error = send_socket(client, get_commands());
            if (error < 0)
                close_socket(client, sock);

            // Get message sended from client
            error = receive_socket(client, option);
            if (error < 0)
                close_socket(client, sock);

            // Handle user option
            error = run_command(option, client, &mysecurity);
            if (error < 0)
			{
				error = send_socket(client, "[!] Invalid option");
				if (error < 0)
					close_socket(client, sock);
			}
        }

        // Close socket server
        error = close_socket(client, sock);
        if (error < 0)
            return -1;
    }
    return 0;
}
