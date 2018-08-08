// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int x = 100;
    printf("first(pid: %d)\n", (int) getpid());
    int rc = fork();
    // ------------------------------------------------ child process starts executing here
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        printf("second, hello, child here (pid: %d) value of x = %d \n", (int) getpid(), x);
        x++;
        printf("Third, hello, child here (pid: %d) value of x = %d \n", (int) getpid(), x);
    } else {
        int wc = waitpid(rc, NULL, 0);
        printf("Forth, hello, parent here (pid: %d) of child %d, value of x = %d\n", (int) getpid(), rc, x);
        x++;
        printf("Fifth, hello, parent here (pid: %d) of child %d, value of x = %d\n", (int) getpid(), rc, x);
    }

    return 0;
}
