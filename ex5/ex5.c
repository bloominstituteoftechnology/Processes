// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main()
{
    char buffer[MSGSIZE];
    int p[2], nBytes, childProcess;

    if (pipe(p) < 0){
        printf("PIPE FAILED.\n");
        exit(1);
    }

    if ((childProcess = fork()) > 0){
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);

        close(p[1]);
    }

    else {
        close(p[1]);

        while ((nBytes = read(p[0], buffer, MSGSIZE)) > 0){
            printf("%s \n", buffer);
        }

        if (nBytes != 0) exit(2);

        printf("\n~ Finished reading. ~\n");
    }
    
    return 0;
}
