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
    printf("%d is the current process running\n", (int) getpid());

    if (pipe(p) < 0) {
        fprintf(stderr, "Failed pipe.\n");
        exit(1);
    } else {
        int rc = fork();

        if (rc < 0)
        {
            fprintf(stderr, "Failure to fork.\n");
            exit(1);
        }
        else if (rc == 0)
        {
            printf("%d runs before writing\n", (int) getpid());
            write(p[1], msg1, MSGSIZE);
            write(p[1], msg2, MSGSIZE);
            write(p[1], msg3, MSGSIZE);
            printf("%d runs after writing\n", (int) getpid());
        }
        else {
            waitpid(rc, NULL, 0);
            for (int i = 0; i < 3; i++) {
                read(p[0], inbuf, MSGSIZE);
                printf("%d prints %s\n", (int) getpid(), inbuf);
            }
        }
    }
    return 0;
}
