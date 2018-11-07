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
    int caller = fork();
    if(caller < 0){
        printf("fork failed");
    }else if(caller == 0){
        printf("This is the Parent: Goodbye\n");
    }else{
        printf("This is the Child: Hello\n"); 
    }
    return 0;
}
