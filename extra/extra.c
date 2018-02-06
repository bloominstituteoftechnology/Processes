// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define LMSGSIZE 7 // define a constant message size for each message
#define bufSize 512
int main(int argc, char *argv[])
{
    char inbuf[LMSGSIZE]; // a buffer that will hold the incoming data that is being written
    int pcp[2];           // a two-element array to hold the read and write file descriptors that are used by the child write parent read pipe
    int ppc[2];           // a two-element array to hold the read and write file descriptors that are used by the child read parent write pipe
    // establish our pipe, passing it the p array so that it gets populated by the read and write file descriptors
    if (pipe(pcp) < 0)
    {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }
    if (pipe(ppc) < 0)
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
    { // child
        printf("enter a string\n");
        char buf[bufSize];
        fgets(buf, bufSize, stdin);
        char lbuf[LMSGSIZE];
        sprintf(lbuf, "%6.6d", (int)strlen(buf));
        write(pcp[1], lbuf, LMSGSIZE);
        write(pcp[1], buf, strlen(buf));
        // printf("child buf write: %s  lbuf: %s\n", buf, lbuf);
        read(ppc[0], lbuf, LMSGSIZE);
        int L = atoi(lbuf);
        // printf("Child read L: %i, lbuf: %s\n", L, lbuf);
        char *ibuf = (char *)malloc(L + 1);
        ibuf[L] = 0;
        read(ppc[0], ibuf, L);
        // printf("Child read L: %i, ibuf: %s\n", L, ibuf);
        puts(ibuf);
        free(ibuf);
        exit(0);
    }
    else
    { // parent
        int rcp = fork();
        if (rcp < 0)
        { // fork failed; exit
            fprintf(stderr, "fork failed\n");
            exit(1);
        }
        if (rcp == 0)
        // for (int i = 0; i < 3; i++)
        {
            // read 16 bytes of data from the read file descriptor
            read(pcp[0], inbuf, LMSGSIZE);
            const int L = atoi(inbuf);
            const char *received = "Recieved ";
            const int rL = strlen(received);
            char *ibuf = (char *)malloc(L + rL + 1);
            ibuf[L + rL] = 0;
            read(pcp[0], ibuf + rL, L);
            memcpy(ibuf, received, rL);
            // printf("parent ibuf read: %s inbuf: %s\n", ibuf, inbuf);
            char lbuf[LMSGSIZE];
            // printf("parent write L: %d  rL: %d\n", L, rL);
            sprintf(lbuf, "%6.6d", L + rL + 1);
            // printf("parent L: %i  lbuf: %s\n", L, lbuf);
            write(ppc[1], lbuf, LMSGSIZE);
            write(ppc[1], ibuf, L + rL + 1);
            // printf("parent L: %i  ibuf: %s\n", L, ibuf);
            free(ibuf);
            exit(0);
        }
        else
        {
            int wc = waitpid(rc, NULL, 0);
            int wcp = waitpid(rcp, NULL, 0);
            puts("parent goodbye");
        }
        exit(0);
    }
}