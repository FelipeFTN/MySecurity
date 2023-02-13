#ifdef _WIN32
#include <winsock2.h>
#else
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#endif

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

// Get command options
char *get_commands() {
  char *message = "===== MySecurity =====\n\n[1] Shutdown Computer\n[2] Reboot"
                  "Computer\n[0] Exit";
  char *message_ptr = message;

  return message_ptr;
}

// Get option and execute a command
int run_command(char *option) {
#ifdef _WIN32 // Windows based operating system 
  switch (atoi(option)) {
  case 0:
    return 1;
    break;

  case 1:
    system("shutdown -s now");
    break;

  case 2:
    system("shutdown -r");
    break;

  default:
    return -1;
  }
#else // Unix based operating system 
  switch (atoi(option)) {
  case 0:
    return 1;
    break;

  case 1:
    system("sudo shutdown -P now");
    break;

  case 2:
    system("sudo reboot");
    break;

  default:
    return -1;
  }
#endif
  return 0;
}
