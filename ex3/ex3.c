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
    int fork_process = fork();

    if (fork_process < 0)
    {
        fprintf(stderr, "Something went wronk forking %d process\n", (int)getpid());
    }
    else if (fork_process == 0)
    {
        printf("=== CHILD_1 ===\n");
        printf("hello\n");
        printf("=== CHILD_2 ===\n");
    }
    else
    {
        printf("=== PARENT_1 ===\n");
        waitpid(fork_process, NULL, 0);
        printf("goodbye\n");
        printf("=== PARENT_2 ===\n");
    }

    return 0;
}

/*
*********  OUTPUT  *********
TERMINAL
=== PARENT_1 ===
=== CHILD_1 ===
hello
=== CHILD_2 ===
goodbye
=== PARENT_2 ===
*/
