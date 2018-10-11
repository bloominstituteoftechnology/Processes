// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    printf("Before fork() pid: %d\n", getpid());

    pid_t pid = fork();

    if (pid == 0) //Child process
    {
        printf("Hello pid: %d\n", getpid());
        exit(0);
    }

    //Wait for child to complete
    wait(NULL);

    printf("Goodbye pid: %d\n", getpid());

    return 0;
}
