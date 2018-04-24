#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys.wait.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Your code here  
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Child process failed.\n");
        exit(1);
    } else if (rc == 0) {
        char *myargs[3];

        myargs[0] = strdup("/bin/ls");
        myargs[1] = strdup("-1");
        myargs[2] = NULL;

        execv(myargs[0], myargs);
        // execl("/bin/ls", "bin", myargs[1], myargs[2]);
        printf("this should not be seen\n");

        /*
            output:
            $ ./ex4
            Makefile
            ex4
            ex4.c
            I am the parent that comes after the child.
        */

    } else {
        int wc = waitpid(rc, NULL, 0);

        printf("I am the parent that comes after the child.\n");
    }

    return 0;
}