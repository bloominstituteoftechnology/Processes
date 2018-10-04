// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    

    printf("hello world (pid: %d)\n", (int) getpid());

    int rc = fork();

    printf("%d\n", rc);

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("child (pid:%d)\n", (int) getpid());
        printf("hello\n");

    } else {
        int wc = waitpid(rc, NULL, 0);
        printf("parent of child %d here (pid:%d)\n", rc, (int) getpid());
        printf("goodbye\n");
    }
    

    return 0;
}
