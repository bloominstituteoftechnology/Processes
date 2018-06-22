// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

/*
    WAIT - allows the parent process to wait on the child process
        * wait is the system call that goes and cleans up the child process
            * free all memory the child was using
            * removing child's process entry from OS's process table

    What exactly happens with Wait() ?
        * parent process (p1) forks a child process (p2)
        * parent waits until child is finished executing
        * the child will send a signal to the parent indicating it has finished its process
        * once the parent receives the signal, it will terminate the child process and continue to execute its own process
    
    Zombie Process - a process terminates but is never cleaned up
        * when the child finishes executing but never gets cleaned up by the OS
            * OS still has the child process entry listed as active
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int childProcess = fork();

    if (childProcess < 0){
        fprintf(stderr, "FORK FAILED\n");
        exit(1);
    }
    else if (childProcess == 0){
        printf("hello \n");
    }
    else {
        int wait = waitpid(childProcess, NULL, 0);
        printf("goodbye \n");
    }
    
    return 0;
}
