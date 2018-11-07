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
    int process = getpid();
    printf("process %d\n", process);
    int parent = getppid();
    printf("parent %d\n", parent);
    char * hello = "hello";
    int rc = fork();
    int wc = waitpid(rc, NULL, 0); //waits for fork on line 15
    if(rc < 0){
        printf("fork failed\n");
    } else if(rc == 0){
        printf("%s\n", hello);
    } else {
        printf("goodbye\n");
    }

    return 0;
}
