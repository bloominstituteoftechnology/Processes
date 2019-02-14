// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    printf("In the parent process, pid: %d \n", (int) getpid());

    int child_process = fork();
    if (child_process < 0)
    {
        // Failure to fork
        fprintf(stderr, "Failure to fork!\n");
        exit(1);
    }
    else if (child_process == 0)
    {
        // Fork succeeded
        printf("Hello from child.\n");
    }
    else
    {
        int wc = waitpid(child_process, NULL, 0); // Make our parent wait on PID of the child_process
        printf("Goodbye from parent.\n");
    }
    return 0;
}
