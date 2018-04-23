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
    int new_fork = fork();
    if (new_fork < 0) {
        printf("Your fork failed!\n");
    } else if (new_fork == 0) {
        printf("Hello!\n");
    } else {
        waitpid(new_fork, NULL, 0);
        printf("Goodbye!\n");
    }

    return 0;
}
