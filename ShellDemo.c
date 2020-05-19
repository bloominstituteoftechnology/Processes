#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


#define MAX_COMMANDLINE_LEN 8192 // constant variable in global scope
#define MAX_COMMANDLINE_ARGS 128 // constant variable in global scope

/* PROTOTYPE */
void parse_commandline(char *commandline, char *exec_commands[], int max_count);
// pointers





int main(void) {
  char commandline[MAX_COMMANDLINE_LEN];
  // char **exec_commands
  char *exec_commands[MAX_COMMANDLINE_ARGS]
  return 0;
}