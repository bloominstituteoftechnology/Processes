// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

/* pipe is uni-directional, i.e. one way.
One end for granting write access, other end for granting read access.

two-directional read and write would require two pipes.
write to a pipe in FIFO order.

close(deallocate the file indicated)
write(where to write the output, pointer to buffer of nbytes, number of bytes to write) 
read(where to read from, read into the buffer pointed to, number of bytes to read)

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSGSIZE 16 // define a constant message size for each message

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main()
{
    char buffer[MSGSIZE]; // buffer to hold data

    int p[2], nbytes;

    pipe(p);
    int rc = fork();

    if (pipe(p) < 0)
    {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }
    if (rc < 0)
    {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {

        printf("Child here\n");
        close(p[0]);
        // while (read(p[0], &buffer)) {}
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }
    else
    {
        printf("Parent here\n");
        close(p[1]);
        wait(NULL);

        for (int i = 0; i < 3; i++)
        {
            read(p[0], buffer, MSGSIZE);
            printf("Received string: %s\n", buffer);
        }
    }
    return 0;
}