// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    char *hello = "hello";
    char *goodbye = "goodbye";

    int pid = (int)getpid();
    printf("pid BEFORE: (pid: %d)\n\n", pid);

    int rc = fork();

    if (rc < 0)
    {
        printf("Child forked unsuccessfully");
    }
    else if (rc == 0)
    {
        printf("pid in child: (pid: %d)\n", (int)getpid());
        printf("Test: (pid: %d)\n", pid);
        printf("Child forked, %s\n", hello);
    }
    else
    {
        printf("Test: (pid: %d)\n", pid);
        printf("Parent forked, %s\n", goodbye);
    }

    return 0;
}
