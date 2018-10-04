// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    printf("Before forking pid: %d\n", getpid());

    pid_t pid = fork();

    if (pid == 0) {
        printf("Child says hello: %d\n", getpid());
    }
    else {
        waitpid(pid, NULL, 0);
        printf("Parent says goodbye: %d\n", getpid());
    }
    return 0;
}
