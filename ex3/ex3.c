// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <strings.h>

int main(void)
{
    int new_process = fork();

    // Return value of fork()
    // On success, the PID of the child process is returned in the parent, and 0 is returned in the child. 

    if (new_process){
        printf("hello from child\n");
    } else {
        printf("goodbye from main\n");
    }
    
    return 0;
}
