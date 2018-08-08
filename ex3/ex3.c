// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int pid = fork();
    if (pid) {
        printf("hello\n");
    } else{
        waitpid(pid, NULL, 0);
        printf("goodbye\n");
    }
    return 0;
}
