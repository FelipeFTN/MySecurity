#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "socket.h"

char *getMessage();
int commandComputer();

int main() {
    char *option;
    int client;
    int error;

    error = server(&client);
    if (error < 0) return -1;

    while(option[0] != '1') {
      error = sendToClient(client, getMessage());
      if (error < 0) close(client);
      
      option = receiveFromClient(client);

      error = commandComputer(option);
      if (error < 0) { printf("[x] Command Error!\n"); }
    }

    return 0;
}

char *getMessage() {
  char* message = "\n\n===== MySecurity =====\n\n0.Shutdown Computer\n1.Turn off MySecurity\n2.Exit\n";

  char *message_ptr = message;

  return message_ptr;
}

int commandComputer(char *option) {
  printf("\n[+] Client: %s\n", option);
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
