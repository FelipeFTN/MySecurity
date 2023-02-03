// Set up socket
int init_socket(int *client, int *sock);

// End up socket
int close_socket(int client, int sock);

// Send message to client
int send_socket(int client, char *buffer);

// Get message from client
int receive_socket(int client, char *buffer);
