#include <stdio.h>

// Handler API command
int api_handler(char *command) {
  printf("[+] Received from API %s", command);
  return 0;
}
