// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  // Your code here
  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed \n");
    exit(1);
  } else if (rc == 0) {
    printf("child process hereeee\n");

    //execl("/bin/ls", "ls", "-l", (char *)NULL);

    char *args[] = {"ls", "-l", NULL};
    //execv("/bin/ls" , args);
    
    // Don't understand
    execlp("l", "ls", "-l", (char *)NULL);
    // Dont' understand
    execvp("ls", args);
  } else {
    wait(NULL);
  }
  return 0;
}
