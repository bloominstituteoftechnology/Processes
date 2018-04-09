#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int x = 100;

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        x = 500;
        printf("Child pid: %d, x: %d\n", (int) getpid(), x);
    } else {
        waitpid(rc, NULL, 0); // unclear which process runs first so wait is used to have child run first and child to terminate properly preventing zombie
        x = 31;
        printf("Parent pid: %d of child %d, x: %d\n", (int) getpid(), rc, x);
    }
    return 0;
}
