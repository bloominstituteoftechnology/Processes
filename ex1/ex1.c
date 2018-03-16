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
    int val = 5;
    pid_t FPID = fork();
    pid_t PID = getpid();
    printf("Starting... %d", PID);
    pid_t PPID = getppid();

    if (FPID != 0)
    {
        val = 10;
        wait(NULL);
        printf("\n<PARENT>  PID:%d  PPID:%d  FPID:%d  VAL:%i  </PARENT>\n", PID, PPID, FPID, val);
    }

    if (FPID == 0)
    {
        // val = 11;
        printf("\n<CHILD>  PID:%d  PPID:%d  FPID:%d  VAL:%i  </CHILD>\n", PID, PPID, FPID, val);
    }
    return 0;
}

// Because each initialized value prior to fork is copied by value, there are safe of conflict. See pipes to introduce side effects.