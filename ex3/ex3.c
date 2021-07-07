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
    int r = fork();

    if (rc < 0) {    // fork failed; exit
      printf(stderr, "fork failed\n");
      exit(1);
    
    }

    else if (r == 0) 
    {
        printf("hello from child!\n");
    }

    else 
    {
        wait(NULL);
        printf("goodbye from parent!\n");
    }

    return 0;
}
