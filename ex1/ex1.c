// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    printf(" getpid is %d \n", (int)getpid());
    // printf("  argc is %d \n", argc);
    // for (int i = 0; i < argc; i++)
    // {
    //     printf("  argv[i] is %s \n", argv[i]);
    // }

    int hill = 33;
    printf(" hill#### main process  %d \n", hill);

    ////////////////// let start with fork() ===>> taking running process and and spawns a new process
    int rc = fork();
    printf("*****(rc:%d) \n", rc);
    /////////////////////////////////////////////// ===> child starts here
    if (rc < 0)
    {
        fprintf(stderr, " fork failed \n");
        printf(" hill####error  %d \n", hill);
        exit(1);
    }
    else if (rc == 0)
    {
        //hill = 40;
        printf("=======> child here (pid:%d)\n", (int)getpid());
        printf(" hill####child  %d \n", hill);
    }
    else
    {
        hill = 40;
        printf("========>parent here (pid: %d)  of child  (rc:%d)\n", (int)getpid(), rc);
        printf(" hill####parent  %d \n", hill);
    }
    return 0;
}
