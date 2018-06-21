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
    char inbuf[MSGSIZE];
    // int rc = fork();
    int p[2], pid, nbytes;
    if(pipe(p) < 0) {
       fprintf(stderr, "pipe failed\n");
        exit(1); 
    }
    if((pid = fork()) > 0) {
        printf("CHILE WRITN\n");
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }
    else{
        close(p[1]);
         printf("PAP REED\n");
        while((nbytes = read(p[0], inbuf, MSGSIZE)) > 0) {
            printf("%s\n", inbuf);
        }
        if(nbytes != 0) {
            exit(2);
        }
       
        //  waitpid(rc, NULL, 0);
        // for(i = 0; i < 3; i++) {
        //     read(p[i], inbuf, MSGSIZE);
        //     printf("%s\n", inbuf);
        // }
    }
    return 0;
}
