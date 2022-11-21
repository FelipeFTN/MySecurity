// Set up socket
int init_socket(int *client, int *sock);

// Close socket connection
int close_socket(int *client);

// Send message to server 
int server_send(int sock, char *buffer);

// Get a message from server
int server_receive(int sock, char *buffer);
