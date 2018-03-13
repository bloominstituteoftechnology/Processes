// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t FPID = fork();
    pid_t PID = getpid();
    printf("Starting... %d", PID);
    pid_t PPID = getppid();

    if (FPID != 0)
    {
        wait(NULL);
        printf("\n<PARENT>  PID:%d  PPID:%d  FPID:%d  </PARENT>\n", PID, PPID, FPID);
    }

    if (FPID == 0)
    {
        printf("\n<CHILD>  PID:%d  PPID:%d  FPID:%d  </CHILD>\n", PID, PPID, FPID);
    }
    return 0;
}