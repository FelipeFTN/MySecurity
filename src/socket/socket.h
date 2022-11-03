// Set up socket
int init_socket(int *client);

// End up socket
int close_socket();

// Send message to client
int client_send(int client, char *message);

// Get message from client
char *client_receive(int client);