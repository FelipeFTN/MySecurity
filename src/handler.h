#include <stdbool.h>

// Get command options
char *get_commands();

// Get option and execute a command
int run_command(char *option, int client, bool *mysecurity);