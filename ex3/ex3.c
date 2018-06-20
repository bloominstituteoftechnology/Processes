// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    // Your code here
if (fork()== 0) {
    printf("Hello\n");
    exit(2);
    } else {
        sleep(30);
        int stat_loc;
        wait(&stat_loc);
        printf("Child status: %d\n", WEXITSTATUS(stat_loc));

        printf("Goodbye\n");
    }
    return 0;
}
