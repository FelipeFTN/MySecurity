// Client side C/C++ program to demonstrate Socket
// programming
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int sock = 0;
int client_fd;

int init_socket(char *host, int port) {
  char *hello = "Hello from client";
  char buffer[1024] = {0};

  struct sockaddr_in serv_addr;

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("\n Socket creation error \n");
    return -1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);

  if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0) {
    printf("\nInvalid address/ Address not supported \n");
    return -1;
  }

  if ((client_fd = connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))) < 0) {
    printf("\nConnection Failed \n");
    return -1;
  }

  return 0;
}

int send_socket(char *buffer) {
  int error;

  error = send(sock, buffer, strlen(buffer), 0);
  if (error < 0)
    return -1;

  return 0;
}

int receive_socket(char *buffer) {
  int error;

  error = read(sock, buffer, 2048);
  if (error < 0)
    return -1;

  printf("< %s <\n", buffer);

  return 0;
}

int close_socket() {
  int error;

  error = close(client_fd);
  if (error < 0)
    return -1;

  return 0;
}
