#ifdef _WIN32
#include <winsock2.h>
#else
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <unistd.h>
#endif

#include <stdio.h>
#include <string.h>

// Set up socket
int init_socket(int *client, int *sock, int port) {
#ifdef _WIN32
  WSADATA wsa;

  if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
    printf("Failed. Error Code : %d", WSAGetLastError());
    return -1;
  }
#endif

  struct sockaddr_in address;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);
  address.sin_family = AF_INET;

  int addrlen = sizeof(address);
  int opt = 1;

  printf("MySecurity PORT: %d\n", port);

  // Open socket
  if ((*sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("[x] Error while creating the socket.\n");
    return -1;
  }

#ifdef _WIN32
  // Set address for reuse
  if (setsockopt(*sock, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) <
      0) {
    printf("[x] Error while setting address for reuse\n");
    return -1;
  }
#else
  // Set address for reuse
  if (setsockopt(*sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
    printf("[x] Error while setting address for reuse\n");
    return -1;
  }
#endif

  // Bind address and port to socket
  if (bind(*sock, (struct sockaddr *)&address, addrlen) < 0) {
    printf("[x] Error while binding the socket.\n");
    return -1;
  }

  // Listen to socket for connections
  if (listen(*sock, 3) < 0) {
    printf("[x] Error while listening the socket.\n");
    return -1;
  }

#ifdef _WIN32
  // Accept client connection
  if ((*client = accept(*sock, (struct sockaddr *)&address, &addrlen)) < 0) {
    printf("[x] Error while accepting the client.\n");
    return -1;
  }
#else
  // Accept client connection
  if ((*client = accept(*sock, (struct sockaddr *)&address,
                        (socklen_t *)&addrlen)) < 0) {
    printf("[x] Error while accepting the client.\n");
    return -1;
  }
#endif

  printf("[+] Client Connected!\n");

  return 0;
}

// End up socket
int close_socket(int client, int sock) {
  printf("[+] Close socket\n");
  // Closing the connected socket
#ifdef _WIN32
  closesocket(client);
  WSACleanup();
#else
  close(client);
  shutdown(client, SHUT_RDWR);
#endif

  return 0;
}

// Send message to client
int send_socket(int client, char *buffer) {
  int error;

  error = send(client, buffer, strlen(buffer), 0);
  if (error < 0) {
    printf("[x] Error while sending to client\n");
    return -1;
  }

  return 0;
}

// Get message from client
int receive_socket(int client, char *buffer) {
  int error;

#ifdef _WIN32
  error = recv(client, buffer, 1024, 0);
  if (error < 0) {
    printf("[x] Error while receiving from client\n");
    return -1;
  }
#else
  error = read(client, buffer, 1024);
  if (error < 0) {
    printf("[x] Error while receiving from client\n");
    return -1;
  }
#endif

  printf("< %s\n", buffer);
  return 0;
}
