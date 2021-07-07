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

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Child:\n");
        // char *p[] = {"/bin/ls", NULL};
        // execv("/bin/ls", p);

        // execl("/bin/ls", "ls", (char *) NULL);

        execle("/bin/ls", "ls", NULL);
    } else {
        int wc = waitpid(rc, NULL, 0);
        printf("Parent:\n");
    }

    return 0;
}
