// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

/* two choices on wait functions:
1. You can use waitpid() for pid-specific execution OR
2. wait() to just generally wait for child process to terminate first.

Placement of wait is important, since it determines how much of parent can run
before it will wait for child process to complete.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "forkfailed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // grab pid using getpid() and pass it into printf
        printf("hello, child here (pid: %d) \n", (int)getpid());
    }
    else
    {
        // You can use pid-specific wait function:

        /* waitpid(child process of interest, location where waitpid() can store status value, option) */
        // int wc = waitpid(rc, NULL, 0);

        /* OR */

        wait(NULL); // note: any code before wait will be can be iterated before child, depending on environment.

        printf("hello, parent here (pid: %d) of child %d\n", (int)getpid(), rc);
    }
    return 0;
}
