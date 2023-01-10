#include "../services/api.h"
#include "libs/socket.h"
#include "api.h"

// API handler
int handler_api(char *host, int port) {
  char message[64] = "handshake";
  int error;

  error = init_socket(host, port);
  if (error < 0)
    return -1;

  error = send_socket(message);
  if (error < 0)
    return -1;

  error = close_socket();
  if (error < 0)
    return -1;

  return 0;
}
