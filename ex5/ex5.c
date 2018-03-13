// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 14

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main()
{
    // Your code here

    char inbuf[128];
    int fds[2]; 
    int rc = fork();
    int nbytes;
    pipe(fds);
 
    if (pipe(fds) < 0)
    {
        exit(1);
    }
    /* continued */
    if (rc == 0) {
        write(fds[1], msg1, MSGSIZE);
        write(fds[1], msg2, MSGSIZE);
        write(fds[1], msg3, MSGSIZE);
    }
    else 
    {
        wait(NULL);
        while ((nbytes = read(fds[0], inbuf, 128)) > 0)
        {
            printf("Read from parent: %s\n", inbuf);
        }
            
        if (nbytes != 0)
        {
            exit(2);
        }  
        printf("Finished reading\n");
    }
    
    return 0;
}

/*
        int fds[2];
            char buffer[128];

            pipe(fds);

            write(fds[1], "Hello, world!", 14);
            // write(fds[1], "Hello, world, again!", 21);

            read(fds[0], buffer, 128);

            printf("Read from pipe: %s\n", buffer);    
*/

