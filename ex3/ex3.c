// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    printf("Parent %d\n", (int) getpid());
    
    int rc = fork();
    
    if (rc < 0) {
        fprintf(stderr, "Fork failed!\n");
        exit(1);
    } else if (rc == 0) {
        printf("Child %d says Hello\n", (int) getpid());
    } else {
        int wc = waitpid(rc, NULL, 0);
        printf("Parent %d of child %d says Goodbye\n", (int) getpid(), rc);
    } 

    return 0;
}
