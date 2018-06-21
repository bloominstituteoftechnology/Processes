// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ronaldo = 7;

int main(int argc, char *argv[])
{
    printf("====>ronaldo : %d \n", ronaldo);
    //////////////////////////////////////////////
    // for (int i = 0; i < argc; i++)
    // {

    //     printf(" %s \n", argv[i]);
    // }

    printf(" .......hello exec......... \n");
    printf(" process runing: %d \n", (int)getpid());
    // //////////////////////////
    //int rc = fork();
    //printf("*****(rc:%d) \n", rc);
    // ///////////////////////////////
    // if (rc < 0)
    // {
    //     fprintf(stderr, " fork failed \n");
    //     exit(1);
    // }
    // else if (rc == 0)
    // {

    //     printf("=======> child here (pid:%d)\n", (int)getpid());
    // }
    // else
    // {

    //     printf("========>parent here (pid: %d)  of child  (rc:%d)\n", (int)getpid(), rc);
    // }

    return 0;
}
