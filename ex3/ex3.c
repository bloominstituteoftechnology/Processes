// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.
//https://stackoverflow.com/questions/11733481/can-anyone-explain-a-simple-description-regarding-file-descriptor-after-fork
//In "Advanced Programming in the Unix Environment", 2nd edition,
//By W. Richard Stevens.
//
//Section 8.3 fork function.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    // Your code here

    printf("here is the output \n");
    printf("Before fork is called : ( pid: %d)\n", (int)getpid());
    // printf("######################################################");
    // fork the child process
    int rc = fork();

    if (rc < 0)
    { // fork failed; exit
        printf("fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("######################################################\n");
        printf("Child process first to print out: child (pid : %d ) \n", (int)getpid());
        printf("######################################################\n");
        printf("hello \n");
        _exit(0);
    }
    else
    {
        int status;

        wait(&status);
        // printf("###############################################\n");
        printf("goodbye \n");
        printf("######################################################\n");
        printf("Parent process last wait child to print: Parent (pid : %d )\n", (int)getpid());
    }
    return 0;
}
