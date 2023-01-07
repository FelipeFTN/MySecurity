#include "../services/api.h"
#include "libs/socket.h"

// API handler
int handler_api() {
  int error, client, sock;
  char message[64];

  error = init_socket(&client, &sock);
  if (error < 0)
    return -1;

  error = receive_socket(sock, message);
  if (error < 0)
    return -1;

  error = api(message);
  if (error < 0)
    return -1;

  error = close_socket(client);
  if (error < 0)
    return -1;

  return 0;
}
