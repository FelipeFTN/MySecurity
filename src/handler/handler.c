#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <netdb.h>

// Get command options
char *get_commands()
{
    char *message = "\n\n===== MySecurity =====\n\n0.Shutdown Computer\n1.Turn off MySecurity\n2.Exit\n";
    char *message_ptr = message;

    return message_ptr;
}

// Get instance info
int get_instance_info(char* name, char* ip)
{
	char host[256];
	struct hostent *host_entry;
	int hostname;

	// Find the host name
	hostname = gethostname(host, sizeof(host));
	if (hostname < 0)
		return -1;

	// Find host information
	host_entry = gethostbyname(host);
	if (host_entry == NULL)
		return -1;

	// Convert into IP string
	ip = inet_ntoa(*((struct in_addr*) host_entry->h_addr_list[0]));

	name = host;

	return 0;
}

// Get option and execute a command
int run_command(char *option, int client, bool *mysecurity)
{
    printf("[+] Client: %s\n", option);
    if (option[0] == '1') { *mysecurity = false; return -1; }
    if (option[0] == '2') { close(client); return -1; }
#ifdef __unix__
    if (option[0] == '0') { system("sudo shutdown -P now"); return 0; }
#endif
#ifdef _WIN32
    if (option[0] == '0') { system("shutdown -s -c 'mySecurity'"); return 0; }
#endif
    return -1;
}
