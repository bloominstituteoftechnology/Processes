// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main(void)
{
    // Your code here
    char buffer[MSGSIZE];
    int wire[2];

    if (pipe(wire) < 0)
    {
        fprintf(stderr, "pipe failed\n");
    }

    int fork_process = fork();

    if (fork_process < 0)
    {
        fprintf(stderr, "Something went wronk forking %d process\n", (int)getpid());
    }
    else if (fork_process == 0)
    {
        printf("=== %d CHILD_START ===\n", (int)getpid());

        write(wire[1], msg1, MSGSIZE);
        write(wire[1], msg2, MSGSIZE);
        write(wire[1], msg3, MSGSIZE);

        printf("=== CHILD_END ===\n");
    }
    else
    {
        printf("=== %d PARENT_START ===\n", (int)getpid());

        waitpid(fork_process, NULL, 0);

        for (int i = 0; i < 3; i++)
        {
            read(wire[0], buffer, MSGSIZE);
            printf("Message %d %s\n", i, buffer);
        }

        printf("=== PARENT_END ===\n");
    }
    printf(" %d END\n", (int)getpid());

    return 0;
}

/*
*********  OUTPUT  *********
TERMINAL
=== 9059 PARENT_START ===
=== 9060 CHILD_START ===
=== CHILD_END ===
 9060 END
Message 0 hello world #1
Message 1 hello world #2
Message 2 hello world #3
=== PARENT_END ===
 9059 END
*/