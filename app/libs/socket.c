#ifdef _WIN32
#include <Ws2tcpip.h>
#include <winsock2.h>
#else
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <unistd.h>
#endif

#include <stdio.h>
#include <string.h>

int sock;
int client;

// Set up socket
int init_socket(char* HOST, int PORT) {
#ifdef _WIN32
  WSADATA wsa;

  if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
    printf("Failed. Error Code : %d", WSAGetLastError());
    return -1;
  }
#endif

  struct sockaddr_in serv_addr;
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("[x] Error while creating the socket.\n");
    return -1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

#ifdef _WIN32
  // Convert IP address from text to binary
  if (InetPtonW(AF_INET, HOST, &serv_addr.sin_addr) <= 0) {
    printf("[x] Error while converting IP.\n");
    return -1;
  }

#else
  // Convert IP address from text to binary
  if (inet_pton(AF_INET, HOST, &serv_addr.sin_addr) <= 0) {
    printf("[x] Error while converting IP.\n");
    return -1;
  }
#endif

  // Connect client to server
  if ((client = connect(sock, (struct sockaddr *)&serv_addr,
                         sizeof(serv_addr))) < 0) {
    printf("[x] Error while connecting to server.\n");
    return -1;
  }
  printf("[+] Server Connected!\n");

  return 0;
}

// End up socket
int close_socket() {
  printf("[+] Close socket");
  // Closing the connected socket
#ifdef _WIN32
  closesocket(client);
  WSACleanup();
#else
  close(client);
#endif
  return 0;
}

// Send message to server
int send_socket(char *buffer) {
  int error;

  error = send(sock, buffer, strlen(buffer), 0);
  if (error < 0) {
    printf("[x] Error while sending to server\n");
    return -1;
  }

  return 0;
}

// Get a message from server
int receive_socket(char *buffer) {
  int error;

#ifdef _WIN32
  error = recv(sock, buffer, 1024, 0);
  if (error < 0) {
    printf("[x] Error while receiving from server\n");
    return -1;
  }
#else
  error = recv(sock, buffer, 1024, 0);
  if (error < 0) {
    printf("[x] Error while receiving from server\n");
    return -1;
  }
#endif

  return 0;
}
