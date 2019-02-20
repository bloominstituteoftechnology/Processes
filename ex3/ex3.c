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
    waitpid(pid, NULL, 0); /* if I'm understanding this right, the wait(NULL) here ensures the child is printed first */

    if(pid == 0) {
        printf("%s", "hello\n");
    }
    else {
        printf("%s", "goodbye\n");
    }
    
    return 0;
}
