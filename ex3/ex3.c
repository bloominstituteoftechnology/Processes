// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    // Your code here
    
    int rc = fork();

    if (rc == 0) {
        printf("hello ");
        return 0;
    } else if (rc != 0) {
        waitpid(rc, NULL, 0);
        printf("world\n");
        return 0;
    } else {
        printf("Error");
        return 1;
    }


    return 0;
}
