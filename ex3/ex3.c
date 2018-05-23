// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    // Your code here
    printf("Hello World (pid: %d)\n", (int)getpid());

    int rc = fork();

    if (rc < 0)
    {
        printf("Fork failed");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Child is first (pid: %d)\n", (int)getpid());
    }
    else
    {
        int wc = waitpid(rc, NULL, 0);
        printf("Parent is last (pid: %d)\n", (int)getpid());
    }
    return 0;
}
