/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSGSIZE 8

char *msg1 = "text no1";
char *msg2 = "text no2";
char *msg3 = "text no3";

int main()
{
    char inbuf[MSGSIZE]; // a buffer that will hold the incoming data that is being written
    int p[2];            // a two-element array to hold the read and write file descriptors that are used by the pipe

    if (pipe(p) < 0)
    {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    int rc = fork();
    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Child here writing\n");
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }
    else
    {
        int wc = waitpid(rc, NULL, 0);
        printf("Parent here reading\n");
        for (int i = 0; i < 3; i++)
        {
            read(p[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
        }
    }
    return 0;
}