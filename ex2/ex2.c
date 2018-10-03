// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int x = 120;

    printf("hello world (pid: %d)\n", (int) getpid());

    int rc = fork();

    printf("%d\n", rc);

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("child (pid: %d) and x is: %d\n", (int) getpid(), x);
        x = x * 2;
        printf("child x * 2 is now: %d\n", x);
    } else {
        int wc = waitpid(rc, NULL, 0);
        printf("parent of child %d here (pid: %d) and x is: %d\n", rc, (int) getpid(), x);
        x = x / 2;
        printf("parent again, x / 2 is: %d\n", x);
    }
    
    return 0;
}
