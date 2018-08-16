// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // needed for use with waitpid()

int main(void)
{
    // Your code here
    int rc = fork(); // call fork to create a child process
    if (rc < 0)      // if fork failed print out a standard error message and exit
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) // represents child process
    {
        printf("Hello! \n");
    }
    else // represents parent process
    {
        int wc = waitpid(rc, NULL, 0); // waitpid() suspends the parent process until the child process pointed at by rc terminates.
        printf("Goodbye!\n");
    }
    return 0;
}
