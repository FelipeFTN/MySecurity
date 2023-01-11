#include <stdbool.h>
#include <string.h>

#include "../data/api.h"

// API message handler
int handler_api_request(char *socket_message) {
  int error;

  if (strstr(socket_message, "0")) {
    // Quit application
    return -1;
    
  } else if (strstr(socket_message, "handshake")) {
    // Handshaked - Connected
    struct api_data_struct api_data = { true };

    error = save_api_data(api_data);
    if (error < 0)
      return -1;
    return 0;
  }

  return -1;
}
