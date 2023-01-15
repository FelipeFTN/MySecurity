#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "../data/api.h"
#include "../libs/socket.h"

int parse_message(char *socket_message, char *parsed_message);

// API message handler
int api_response_handler(char *socket_message) {
  char parsed_message[64] = {0};
  int error;

  // API message formatter
  error = parse_message(socket_message, parsed_message);
  if (error < 0) {
    printf("[x] Parsing error");
  }

  printf("[+] Handler %s\n", parsed_message);

  if (strstr(parsed_message, "quit")) {
    // Quit application
    socket_message = "quit\n";
    return -1;
  }
  return 0;
}

int parse_message(char *socket_message, char* parsed_message) {
  // Copy variable bytes
  strcpy(parsed_message, socket_message);

  // Remove '\n' byte from message
  if (parsed_message[strlen(parsed_message) - 1] == '\n')
    parsed_message[strlen(parsed_message) - 1] = 0;

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
