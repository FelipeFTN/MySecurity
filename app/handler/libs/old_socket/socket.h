// Set up socket
int init_socket(char *host, int port);

// Close socket connection
int close_socket();

// Send message to server 
int send_socket(char *buffer);

// Get a message from server
int receive_socket(char *buffer);
