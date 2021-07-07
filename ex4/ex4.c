// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    int rc = fork();

    if (rc < 0) {   // fork failed; exit
      fprintf(stderr, "fork failed, exiting\n");
      exit(1);
    } else if (rc == 0) {
      printf("child here\n");
      // char *args[] = {"ls", "-l", NULL};
      // execvp(args[0], args);
      // execl("/bin/ls", "ls", "-l", NULL);
      execlp("ls", "ls", "-l", NULL);
    } else {
      int wc = waitpid(rc, NULL, 0);
      printf("parent here\n");
    }

    return 0;
}
