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

    server(&client);

    sendToClient(client, getMessage());
    
    char *option = receiveFromClient(client);

    int error = commandComputer(option);
    if (error < 0) {
      printf("[%d] Error while commanding computer\n", error);
      sendToClient(client, "Error while commanding computer\n");
      close(client);
      return -1;
    }

    close(client);

    return 0;
}

char *getMessage() {
  char* message = "===== MySecurity =====\n0.Shutdown Computer\n1.Turn off MySecurity\n2.Exit";

  char *message_ptr = message;

  return message_ptr;
}

int commandComputer(char *option) {
  printf("\noption: %s\n", option);
  if (option[0] == '1') {
    return 0;
  }
  if (option[0] == '2') {
    return 0;
  }
#ifdef __unix__
  if (option[0] == '0') {
    system("sudo shutdown -P now");
    return 0;
  }
#endif
#ifdef _WIN32
  if (option[0] == '0') {
    system("shutdown -s -c 'mySecurity'");
    return 0;
  }
#endif
  return -1;
}
