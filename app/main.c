#include <stdio.h>

#include "handler/api.h"

int main() {
  char *HOST = "127.0.0.1";
  int PORT = 8079;

  // API Connection
  api_handler(HOST, PORT);

  return 0;
}
