// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

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
            wait(NULL);
            fprintf(fp, "Goodbye\n", PID, PPID, FPID);
            fclose(fp);
        }
        if (FPID == 0)
        {
            fprintf(fp, "Hello\n", PID, PPID, FPID);
            fclose(fp);
        }
    }

    return 0;
}
