#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "../data/api.h"
#include "../handler/libs/socket.h"

// API message handler
int api_response_handler(char *socket_message) {
  int error;

  printf("[+] Handler %s\n", socket_message);

  if (strstr(socket_message, "0")) {
    // Quit application
    socket_message = "quit";
    return -1;
  }
  return 0;
}

int api_handshake() {
  char socket_handshake[12] = {0};
  int error;

  // Receive from socket
  error = receive_socket(socket_handshake);
  if (error < 0)
    return -1;

  // Send to socket
  error = send_socket(socket_handshake);
  if (error < 0)
    return -1;

  if (!strcmp(socket_handshake, "handshake"))
    return -1;

  printf("[+] handshaked\n");

  return 0;
}

int parse_message(char *socket_message, char* parsed_message) {
  // Remove '\n' byte from message
  if (socket_message[strlen(socket_message) - 1] == '\n')
    socket_message[strlen(socket_message) - 1] = 0;

  strcpy(parsed_message, socket_message);

  return 0;
}
