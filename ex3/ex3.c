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
    int pid = fork();

    if (pid < 0) {
        printf("Error\n");
        exit(1);
    } else if (pid == 0) {
        printf("Inside child process\n");
        exit(0);
    } else {
        wait(NULL);
        printf("Inside parent process\n");
        exit(0);
    }
    return 0;
}
