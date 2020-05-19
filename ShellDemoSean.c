#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define MAX_TOKENS 100

char **parse_commandline(char *str, int *argc, char **args)
{
  char *token;
  *argc = 0;

  // Break the given str down into tokens using a delimiter
  // More specifically, we'll split on tabs, newlines, and carriage returns 
  token = strtok(str, " \t\n\r");

  // Add this token to the args array
  while (token != NULL && *argc < MAX_TOKENS) {
    // Index into args array using the value in argc
    // Then increment *argc
    args[(*argc)++] = token;

    // Fetch the next token
    token = strtok(NULL, " \t\n\r");
  }

  // Lastly, add a NULL as the last element in args
  args[*argc] = NULL;  

  return args;
}

int main(void)
{
  // Holds the entire command line input all at once
  char commandline[1024];
  // Holds individual parsed tokens 
  char *args[MAX_TOKENS];
  // Number of args stored in the args array
  int argc;

  // In a continuous loop
  while (1) {
    // Receive input from stdin
    // shell should print a prompt for the user
    printf("lambda-shell$");

    // Read input from stdin
    fgets(commandline, sizeof(commandline), stdin);

    // Parse that input into tokens 
    // Parse the commandline buffer into individual args
    parse_commandline(commandline, &argc, args);

    // Check for some specific commands 
      // Like an exit command or other such commands 
    if (argc == 0) {
      continue;
    }

    // Check for an "exit" command
    if (argc == 1 && strcmp(args[0], "exit") == 0) {
      break;
    }

    // Check for "cd" command
    if (strcmp(args[0], "cd") == 0) {
      if (argc != 2) {
        printf("usage: cd dirname\n");
        continue;
      }

      // Change to the specified directory
      if (chdir(args[1]) < 0) {
        fprintf(stderr, "chdir failed");
        continue;
      }

      // If we successfully changed directories, continue our shell loop
      continue;
    }

    // To allow us to execute arbitrary programs, 
    // use fork and exec in concert
    // Fork this process
    // In the child context, exec with the specified program name

    pid_t child_pid = fork();

    if (child_pid < 0) {
      fprintf(stderr, "fork failed");
      continue;
    }

    // In the child context
    if (child_pid == 0) {
      // Exec the child program, transforming it in the specified command
      execvp(args[0], args);

      // If we get here, that means the exec call failed
      fprintf(stderr, "exec failed");
      exit(1);
    } else {
      // In the parent context
      // Wait for the child to complete
      waitpid(child_pid, NULL, 0);
    }
  }

  return 0;
}