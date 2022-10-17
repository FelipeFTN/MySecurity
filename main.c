#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include "socket.h"

char *getMessage();

int main() {
    int client;
    char *option;

    server(&client);

    sendToClient(client, getMessage());
    
    option = receiveFromClient(client);

    close(client);

    return 0;
}

char *getMessage() {
  char* title = "===== MySecurity =====\n";
  char* zero = "0.Shutdown Computer\n";
  char* one = "1.Turn off MySecurity\n";
  char* two = "2.Exit\n";

  char message[1024];
  char *message_ptr = message;

  snprintf(message, sizeof(message), "%s%s%s%s", title, zero, one, two);

  return message_ptr;
}
