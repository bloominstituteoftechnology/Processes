// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

/*
    Pipes provide a unidirectional interprocess communication channel.
        * a black of memory is allocated that each end of the pipe has access to

    A pipe has a READ and WRITE end.
        * data written to the WRITE end can be read from the READ end
    
    pipe(x) - where x is an array with two elements (read and write) - x[2]
      * creates a new pipe
      * returns two file descriptors
        * pipefd[0] referring to the READ pipe
        * pipefd[1] referring to the WRITE pipe
      * data written to WRITE is buffered by the kernel until it is read by READ
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main()
{
    char buffer[MSGSIZE]; // holds the message on the read end of the pipe
    int pipefd[2], childProcess, nBytes;

    if (pipe(pipefd) < 0){
        printf("PIPE FAILED.\n");
        exit(1);
    }

    if ((childProcess = fork()) > 0){
        write(pipefd[1], msg1, MSGSIZE);
        write(pipefd[1], msg2, MSGSIZE);
        write(pipefd[1], msg3, MSGSIZE);
    }

    else {
        close(pipefd[1]); // close the WRITE pipe

        while ((nBytes = read(pipefd[0], buffer, MSGSIZE)) > 0){
            printf("%s \n", buffer);
        }

        if (nBytes != 0) exit(2);

        printf("\nFinished reading.\n");
    }
    
    return 0;
}
