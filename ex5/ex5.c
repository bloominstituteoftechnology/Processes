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

int main()
{
    int p[2];
    int inbuf[MSGSIZE];
    int nbytes;
    if (pipe(p) < 0)
        exit(1);

    int rc = fork();

    if (rc < 0)
        printf("Fork failed");
    else if (rc == 0) {
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);

        close(p[1]);
    }
    else{
        int wc = waitpid(rc, NULL, 0);
        // while ((nbytes = read(p[0], inbuf, MSGSIZE)) > 0) {
        //     printf("% s\n",inbuf);
        //     printf("%d\n", nbytes);        
        // }
        nbytes = read(p[0], inbuf, MSGSIZE);
        printf("%s\n", inbuf);
        nbytes = read(p[0], inbuf, MSGSIZE);
        printf("%s\n", inbuf);
        nbytes = read(p[0], inbuf, MSGSIZE);
        printf("%s\n", inbuf);
        close(p[0]);
        if (nbytes != 0)
            exit(2);
        printf("Finished reading\n");
        
    }
    return 0;
}
