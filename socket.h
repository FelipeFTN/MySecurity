int server(int *client);

int sendToClient(int client, char *message);

char *receiveFromClient(int client);