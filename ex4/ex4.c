#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        char *myargs[3];
        myargs[0] = strdup("ws");
        myargs[1] = strdup("/bin/ls");
        execv(myargs[0], myargs);
    } else {
        waitpid(rc, NULL, 0);
        printf("Parent pid: %d of child %d\n", (int) getpid(), rc);
    }

    return 0;
}
