// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE* fptr;
    fptr = fopen("text.txt", "w");

    int rc = fork();
    if (rc < 0)
    {
      fprintf(stderr, "fork failed\n");
      exit(1);
    }
    else if (rc == 0)
    {
      printf("child process (pid: %d)\n", (int) getpid());
      char *child_write = "A string for the child to write!\n";
      fwrite(child_write, sizeof(char), strlen(child_write), fptr);
    }
    else {
      printf("parent process (pid: %d)\n", (int) getpid());
      char *parent_write = "A string for the parent to write!\n";
      fwrite(parent_write, sizeof(char), strlen(parent_write), fptr);
    }
    fclose(fptr);
    return 0;
}
