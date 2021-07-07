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
    printf("Hello world\n");
    int third = fork();
    if(third < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    if(third == 0) {
        printf("Hello\n");
    }
    else {
        int wc = waitpid(third, NULL, 0);
        printf("Goodbye\n");
    }
    return 0;
}
