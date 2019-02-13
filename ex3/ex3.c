// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int test = fork();
    wait(NULL);
    if(test == 0) {
        printf("Hello");
    } else {
        
        printf("Goodbye");
    }
    

    return 0;
}
