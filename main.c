#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>

#include "server.h"

int main() {
    int client;
    char *message = "====== MySecurity ======\n0. Shutdown Computer";

    server(&client);

    sendMessage(client, message);

    close(client);

    return 0;
}