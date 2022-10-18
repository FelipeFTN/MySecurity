#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "socket.h"

char *getMessage();
int commandComputer();

int main() {
    int client;
    char *option;

    server(&client);

    sendToClient(client, getMessage());
    
    option = receiveFromClient(client);

    int error = commandComputer(option);
    if (error < 0) {
      printf("Error while commandind computer");
      sendToClient(client, "Error while commanding computer");
      close(client);
      return -1;
    }

    close(client);

    return 0;
}

char *getMessage() {
  char* title = "===== MySecurity =====";
  char* zero = "0.Shutdown Computer";
  char* one = "1.Turn off MySecurity";
  char* two = "2.Exit";

  char message[1024];
  char *message_ptr = message;

  snprintf(message, sizeof(message), "%s%s%s%s", title, zero, one, two);

  return zero;
}

int commandComputer(int option) {
#ifdef __unix__
  if (option == 0) {
    system("sudo shutdown -P now");
    return 0;
  }
#endif
#ifdef _WIN32
  if (option == 0) {
    system("shutdown -s -c 'mySecurity'");
    return 0;
  }
#endif
  return -1;
}
