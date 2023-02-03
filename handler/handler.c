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
  char *message = "===== MySecurity =====\n\n[0] Shutdown Computer\n[1] Turn "
                  "off MySecurity\n[2] Exit\n";
  char *message_ptr = message;

  return message_ptr;
}

// Get instance info
int get_instance_info(char *name, char *ip) {
  char host[256];
  struct hostent *host_entry;
  int hostname;

  // Find the host name
  hostname = gethostname(host, sizeof(host));
  if (hostname < 0)
    return -1;

  // Find host information
  host_entry = gethostbyname(host);
  if (host_entry == NULL)
    return -1;

  // Convert into IP string
  ip = inet_ntoa(*((struct in_addr *)host_entry->h_addr_list[0]));

  name = host;

  return 0;
}

// Get option and execute a command
int run_command(char *option, bool *connected) {
  printf("[!] run command: %s\n", option);
  if (option[0] == '0') {
    printf("shutting down computer");
#ifdef _WIN32
    system("shutdown -s");
#else
    system("sudo shutdown -P");
#endif
    return 0;

  } else if (option[0] == '1') {
    *connected = false;
    return 0;
  } else if (option[0] == '2') {
    *connected = false;
    return 0;
  }

  return -1;
}