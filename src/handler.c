#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// Get command options
char *get_commands()
{
    char *message = "\n\n===== MySecurity =====\n\n0.Shutdown Computer\n1.Turn off MySecurity\n2.Exit\n";
    char *message_ptr = message;

    return message_ptr;
}

// Get option and execute a command
int run_command(char *option, int client, bool *mysecurity)
{
    printf("[+] Client: %s\n", option);
    if (option[0] == '1')
    {
        *mysecurity = false;
        return -1;
    }
    if (option[0] == '2')
    {
        close(client);
        return -1;
    }
#ifdef __unix__
    if (option[0] == '0')
    {
        system("sudo shutdown -P now");
        return 0;
    }
#endif
#ifdef _WIN32
    if (option[0] == '0')
    {
        system("shutdown -s -c 'mySecurity'");
        return 0;
    }
#endif
    return -1;
}