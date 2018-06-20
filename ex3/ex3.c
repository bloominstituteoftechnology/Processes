// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Forking Error\n");
        exit(1);
    } else if (rc == 0) {
        printf("Goodbye(pid: %d)%d\n", (int) getpid(), rc);
    } else {
        printf("Hello (pid: %d) \n", (int) getpid());
    }

    return 0;
}
