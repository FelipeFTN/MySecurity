#ifdef _WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#endif

#include <sys/types.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

// Get command options
char *get_commands()
{
    char *message = "===== MySecurity =====\n\n[0] Shutdown Computer\n[1] Turn off MySecurity\n[2] Exit\n";
    char *message_ptr = message;

    return message_ptr;
}

// Get instance info
/*
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
*/

// Get option and execute a command
int run_command(char *option, bool *mysecurity, bool *connected)
{
	printf("[!] run command: %s\n", option);
	if (option[0] == '0')
	{
		printf("shutting down computer");
		system("sudo shutdown -P");
		return 0;
		
	} else if (option[0] == '1')
	{
		*connected = false;
		*mysecurity = false;
		return 0;
	}

	return -1;
}
