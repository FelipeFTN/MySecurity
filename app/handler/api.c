#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "../services/api.h"
#include "../libs/socket.h"

// API handler
int api_handler(char *HOST, int PORT) {
  char socket_message[64] = {0};
  int error, option;

  // Init socket
  error = init_socket(HOST, PORT);
  if (error < 0)
    return -1;

  while (true) {
    // Receive from socket
    error = receive_socket(socket_message);
    if (error < 0)
      return -1;
    
    // API message handler
    option = api_response_handler(socket_message);

    error = send_socket(socket_message);
    if (error < 0)
      return -1;

    // Clear memory buffer
    memset(socket_message, 0, sizeof socket_message);

    if (option < 0) {
      printf("[+] Handler finished\n");
      break;
    }
  }

  // Close socket
  error = close_socket();
  if (error < 0)
    return -1;

  return 0;
}
