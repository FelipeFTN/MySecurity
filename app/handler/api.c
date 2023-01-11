#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "../services/api.h"
#include "libs/socket.h"
#include "api.h"

// API handler
int handler_api(char *host, int port) {
  char socket_message[64] = { 0 };
  int error;

  error = init_socket(host, port);
  if (error < 0)
    return -1;

  while (true) {

    error = receive_socket(socket_message);
    if (error < 0)
      return -1;

    if (strstr(socket_message, "exit")) break;

    error = send_socket(socket_message);
    if (error < 0)
      return -1;

    // Clear memory buffer
    memset(socket_message, 0, sizeof socket_message);

  }

  error = close_socket();
  if (error < 0)
    return -1;

  return 0;
}
