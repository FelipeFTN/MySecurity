#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "../services/api.h"
#include "api.h"
#include "libs/socket.h"

// API handler
int handler_api(char *host, int port) {
  char socket_message[64] = {0};
  int error, option;

  // Init socket
  error = init_socket(host, port);
  if (error < 0)
    return -1;

  while (true) {
    // Receive from socket
    error = receive_socket(socket_message);
    if (error < 0)
      return -1;

    // Receive from socket
    error = send_socket(socket_message);
    if (error < 0)
      return -1;

    // Remove '\n' from message
    socket_message[strlen(socket_message) - 1] = 0;

    // API message handler
    option = handler_api_request(socket_message);
    if (option < 0) {
      printf("[%d] handler finished.\n", option);
      break;
    }

    // Clear memory buffer
    memset(socket_message, 0, sizeof socket_message);
  }

  // Close socket
  error = close_socket();
  if (error < 0)
    return -1;

  return 0;
}
