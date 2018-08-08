// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
    // Your code here
    char inbuf[ MSGSIZE ];
    int fds[2];

    if (pipe(fds) < 0)
    {
        printf("Error establishing a pipe");
        exit(1);
    }

    int child = fork();

    if (child < 0)
    {
        printf("Error creating child process");
        exit(1);
    }
    // when we `fork()` into our `child` process it creates it's own variation of the `pipe` READ=>WRITE system
    // originally the parent holds the READ and the child is the WRITE
    // in our `child` `fork()` the `child` is now the READ and the `parent` is now the WRITE
    else if (child == 0)
    {
        write(fds[1], msg1, MSGSIZE);
        write(fds[1], msg2, MSGSIZE);
        write(fds[1], msg3, MSGSIZE);

        for (int i = 0; i < 3; i++)
        {
            read(fds[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
        }
    }
    else
    {
        waitpid(child, NULL, 0);
        printf("Parent & Child complete\n");
    }
    
    return 0;
}
