#include <stdbool.h>
#include <stdio.h>

#include "socket/socket.h"

int main() {
  char *handshake = "Handshake";
  int client, error, sock = 0;
  char message[256] = {0};
  char command[16] = {0};
  bool connected;

  while (true) {
    // Start Client
    error = init_socket(&client, &sock);
    if (error < 0)
      return -1;
    connected = true;

    // Send Handshake to server
    error = send_socket(sock, handshake);
    if (error < 0)
      return -1;

    while (connected) {
      // Receive from server
      error = receive_socket(sock, message);
      if (error < 0)
        return -1;

      // Send to server
      printf("> ");
      scanf("%[^\n]", command);
      error = send_socket(sock, command);
      if (error < 0)
        return -1;
    }
  }

  return 0;
}
