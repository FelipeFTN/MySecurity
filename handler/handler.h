#include <stdbool.h>

// Get command options
char *get_commands();

// Get instance info
int get_instance_info(char *name, char* ip);

// Get option and execute a command
int run_command(char *option, bool *connected);
