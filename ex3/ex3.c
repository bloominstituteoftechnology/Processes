// Write another program using `fork()`. The child process should print "Hello"
// while the parent process should print "Goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    int rc = fork();

    if (rc < 0)
    {
        // "Formatted print"
        fprintf(stderr, "Fork unsuccessful!\n");
        exit(1);
    }

    else if (rc == 0)
    {
        // This is the child process
        printf("Child process: 'Hello!'\n");
    }

    else
    {
        int wc = waitpid(rc, NULL, 0);
        // This is the parent process
        printf("Parent process: 'Goodbye!'\n");
    }

    return 0;
}
