// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

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

    FILE *fp;
    char file[] = "text.txt";
    fp = fopen(file, "a");

    if (fp != NULL)
    {
        if (FPID != 0)
        {
            fprintf(fp, "<PARENT>  PID:%d  PPID:%d  FPID:%d  </PARENT>\n", PID, PPID, FPID);
            fclose(fp);
        }
        if (FPID == 0)
        {
            fprintf(fp, "<CHILD>  PID:%d  PPID:%d  FPID:%d  </CHILD>\n", PID, PPID, FPID);
            fclose(fp);
        }
    }

    return 0;
}
