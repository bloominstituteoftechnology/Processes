// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int x = 100;
    printf("Hello from Main (pid: %d)\n", (int) getpid());
    printf("Main says: x = %d \n", x);

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        x -= 50;
        printf("Hello from Child (pid: %d)\n", (int) getpid());
        printf("Child says: x = %d \n", x);
    } else {
        // waitpid(-1, &rc, 0); //=> same as below
        wait(&rc);
        
        x += 25;
        printf("Goodbye from Parent (pid: %d)\n", (int) getpid());
        printf("Parent Process says: x = %d \n", x);
    }
    printf("Final check says: x = %d \n", x);
    return 0;
}
