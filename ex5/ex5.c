// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
    char readbuffer[MSGSIZE];
    int p[2], pid, nbytes;
    
    pipe(p);

    if ((pid = fork()) > 0){
        close(p[0]);
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
        exit(0);
    } else {
        close(p[1]);
        while (( nbytes = read(p[0], readbuffer, MSGSIZE)) > 0){
            printf("Reading the following strings: %s\n", readbuffer);
        }
        if (nbytes != 0){
            exit(2);
        }
        printf("Finished reading.\n");
    }
    return 0;
}
