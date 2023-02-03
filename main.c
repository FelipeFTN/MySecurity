#ifdef _WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <unistd.h>
#endif
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "handler/handler.h"
#include "socket/socket.h"

int main() {
  bool connected;
  char option[8] = {0};
  int client;
  int sock;
  int error;

  // Start socket server at port 8080
  error = init_socket(&client, &sock);
  if (error < 0)
    return -1;
  connected = true;

  // While user does not choose 'Exit'
  while (connected) {
    // Send options to message
    error = send_socket(client, get_commands());
    if (error < 0)
      close_socket(client, sock);

    // Get message sended from client
    error = receive_socket(client, option);
    if (error < 0)
      close_socket(client, sock);

    // Handle user option
    error = run_command(option, &connected);
    if (error < 0) {
      error = send_socket(client, "[!] Invalid option");
      if (error < 0)
        close_socket(client, sock);
    }
  }
  return 0;
}
