#include <stdio.h>

#include "handler/api.h"

int main() {
  char *ip = "127.0.0.1";
  int port = 8079;

  // API Connection
  handler_api(ip, port);

  return 0;
}
