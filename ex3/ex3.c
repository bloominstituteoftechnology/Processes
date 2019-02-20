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
    if (new_process){
        printf("hello from child\n");
    } else {
        printf("goodbye from main\n");
    }
    
    return 0;
}
