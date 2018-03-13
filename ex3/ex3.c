// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int a = 100;
    int rc = fork();

    if (rc == 0)
    {
        a = a + 128;
        printf("In CHILD a = %d\n", a);
    }
    else
    {
        int wc = waitpid(rc, NULL, 0);
        printf("In PARENT a = %d\n", a);
    }

    return 0;
}
