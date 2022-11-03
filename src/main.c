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
    char *option;
    int client;
    int error;

    while (mysecurity)
    {
        // Start socket server at port 8080
        error = init_socket(&client);
        if (error < 0)
            return -1;
        connected = true;

        // While user does not choose 'Exit'
        while (connected)
        {
            // Send options to message
            error = client_send(client, get_commands());
            if (error < 0)
                close(client);

            // Get message sended from client
            option = client_receive(client);

            // Handle user option
            error = run_command(option, client, &mysecurity);
            if (error < 0)
                connected = false;
        }
        // Close socket server
        error = close_socket();
        if (error < 0)
            return -1;
    }
    return 0;
}
