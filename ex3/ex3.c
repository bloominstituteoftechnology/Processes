// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    printf("Before forking pid: %d\n", (int) getpid());

    pid_t pid = fork();

    if (pid < 0) //fork failed
    {
        exit(1);
    } 
    else if (pid == 0) //child process
    {
        printf("AFTER forking CHILD says Hello pid: %d\n", (int) getpid());

    }
    else {
        //wait for child to complete
        waitpid(pid, NULL, 0); 
        printf("AFTER forking PARENT says Goodbye pid: %d\n", (int) getpid());
    }

    return 0;
}
