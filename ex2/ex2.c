// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Your code here
FILE *fp = fopen("text.txt", "w");
  int rc = fork();
   if (rc < 0)
  {
    fprintf(stderr, "fork failed \n ");
    exit(1);
  }
  else if (rc == 0)
  {
    printf("Child process here (pid: %d) \n", (int)getpid());
    char *child = "Here you go, child\n";
    fwrite(child, 1, strlen(child), fp);
  }
  else
  {
    printf("Parent process here (pid:%d)\n", (int)getpid());
    char *parent = "Here you go, parent \n";
    fwrite(parent, 1, strlen(parent), fp);
  }
  fclose(fp);
    return 0;
}

//parent's string was written first, followed by child's string
// Here you go, parent 
// Parent process here (pid:5142)
// Here you go, child
// Child process here (pid: 5143)