// API message handler
int api_response_handler(char *message);

// API handshake
int api_handshake();
//
// API message formatter
int parse_message(char *socket_message, char* parsed_message);
