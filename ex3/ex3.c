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
    pid_t pid = fork();

    if(pid == 0) {
        printf("%s", "hello\n");
        wait(NULL);
    }
    else {
        printf("%s", "goodbye\n");
        waitpid(pid, NULL, 1);
    }

    return 0;
}
