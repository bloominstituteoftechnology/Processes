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

    //printf("..%d \n", (int)getpid());

    int s = fork();

    if(s == 0){
         printf("hello   %d \n", (int)getpid());
    } else{
         wait(NULL);
         printf("goodbye  %d \n", (int)getpid());
    }


    return 0;
}
    
    
    
