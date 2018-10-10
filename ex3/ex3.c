// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    int dip = fork();
    if (dip < 0)
    {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (dip == 0)
    {
        printf("hello\n");
    }
    else
    {
        wait(NULL);
        printf("Goodbye!\n");
    }

    return 0;
}

// solution
// int main(void)
// {
//     int rc = fork();

//     if (rc < 0) {
//         fprintf(stderr, "fork failed\n");
//         exit(1);
//     } else if (rc == 0) {
//         printf("hello\n");
//     } else {
//         int wait = waitpid(rc, NULL, 0);
//         printf("Goodbye\n");
//     }

//     return 0;
// }