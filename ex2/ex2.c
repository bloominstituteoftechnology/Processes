// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    FILE *fp;
    char c;
    fp = fopen("text.txt", "a+");

    pid_t pid;
    pid = fork();
    if (pid < 0) {
      // fork failed; exit
      fprintf(stderr, "fork failed\n");
      exit(1);
    } else if (pid == 0) {
      // fprintf(fp, "%s\n", "Hello!");
      c = fgetc(fp);
      printf("CHILD: %c\n", c);
    } else {
      wait(NULL);
      // fprintf(fp, "%s\n", "Oh hi there!");
      c = fgetc(fp);
      printf("PARENT: %c\n", c);
    }
    return 0;
}
