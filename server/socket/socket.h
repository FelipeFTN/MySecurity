// Set up socket
int init_socket(int *client);

// End up socket
int close_socket();

// Send message to client
int client_send(int client, char *buffer);

// Get message from client
int client_receive(int client, char *buffer);
