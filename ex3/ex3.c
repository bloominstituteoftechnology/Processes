// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    // Your code here
    pid_t process = fork();
    if (process < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (process == 0)
    {
        printf("hello");
    }
    else
    {
        int wa = waitpid(process, NULL, 0);
        printf("goodbye");
    }

    return 0;
}
