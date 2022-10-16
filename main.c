#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>

#include "server.h"

int main() {
    int client;
    char *option;
    char *message = "====== MySecurity ======\n0. Shutdown Computer\n";

    server(&client);

    sendToClient(client, message);
    
    option = receiveFromClient(client);

    close(client);

    return 0;
}