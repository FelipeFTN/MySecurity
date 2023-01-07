#include <stdbool.h>
#include <string.h>

#include "../data/api.h"

// API message handler
int api(char *message) {
  int error;

  // Check if message is handshake
  if (strstr(message, "handshake")) {
    struct api_data_struct api_data = { true };

    error = save_api_data(api_data);
    if (error < 0)
      return -1;
    return 0;
  }

  return 0;
}
