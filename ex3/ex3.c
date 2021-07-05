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
    int rc = fork();
    if (rc < 0) 
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("hello\n");
    }
    else
    {
        wait(NULL);       
        printf("goodbye\n");
    }
    
        
    return 0;
    return 0;
}
