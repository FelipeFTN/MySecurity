#include "../services/api.h"
#include "libs/socket.h"
#include "api.h"

// API handler
int handler_api(char *host, int port) {
  int error, client, sock;
  char message[64];

  error = init_socket(host, port, &client, &sock);
  if (error < 0)
    return -1;

  error = send_socket(sock, "handshake");
  if (error < 0)
    return -1;

  error = close_socket(client);
  if (error < 0)
    return -1;

  return 0;
}
