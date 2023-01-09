// Set up socket
int init_socket(char *host, int port, int *client, int *sock);

// Close socket connection
int close_socket(int client);

// Send message to server 
int send_socket(int sock, char *buffer);

// Get a message from server
int receive_socket(int sock, char *buffer);
