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
    printf("Hello Lambda (pid: %d)\n", (int) getpid());

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Process Failed\n");
        exit(1);
    } else if (rc == 0) {
        execl("/bin/ls", "ls", "-la", NULL);
        printf("Accessing secret library.");
    } else {
        int tc = wait(NULL);
        printf("Parent (pid: %d) of child %d\n", (int) getpid(), rc);
    }

    return 0;
}
