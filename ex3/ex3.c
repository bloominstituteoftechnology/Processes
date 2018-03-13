// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    if(!fork()) {
        //Child
        printf("hello\n");
    } else {
        int stat_loc;
        wait(&stat_loc);
        printf("Child status: %d\n", WEXITSTATUS(stat_loc));
        //Parent
        printf("goodbye\n");
    }
    return 0;
}
