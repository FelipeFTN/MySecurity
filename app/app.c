#include <stdio.h>

#include "handler/api.h"

int app(char *command) {
  int error;

  error = api_handler(command);
  if (error < 0)
    return -1;

  return 0;
}
