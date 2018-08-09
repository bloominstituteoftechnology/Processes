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
    char inbuf[MSGSIZE];
    int p[2];

    if (pipe(p) < 0) {
        fprintf(stderr, "Call a plumber because this pipe is blocked.\n");
        exit(1);
    }

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "There is no fork.\nOnly spoon.\n");
        exit(1);
    }
    else if (rc == 0) {
        printf("I'm just a child.\n");
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }
    else {
        printf("Parental unit activate.\n");
        /*
        I think it's best to put a wait in here, but it's not necessary because:

        > Additionally, if the process with read access tries to read from the pipe before anything has been written to it, the reading process is suspended until there is some data to read.

        Thus, even though the parent process happens first on my computer, the read operation is suspended until the child process has written data to the pipe.
        */
        for (int i = 0; i < 3; i++) {
            read(p[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
        }
    }

    return 0;
}
