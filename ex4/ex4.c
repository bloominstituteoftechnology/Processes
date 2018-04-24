// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

// Reference Material
// https://linux.die.net/man/3/execvp
// https://stackoverflow.com/questions/27541910/how-to-use-execvp?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa

int main(int argc, char* argv[])
{
    int rc = fork();

    if (rc < 0) {
      printf("Fork failed\n");
      exit(1);
    } else if (rc == 0) {
      char *args[] = {"/bin/ls", "-1", NULL};
      execvp(args[0], args);
    } else {
      int wc = waitpid(rc, NULL, 0);
      printf("Parent\n");
    }

    return 0;
}
