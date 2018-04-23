// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory

// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor

// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Your code here
    printf("--beginning of program\n");

    FILE *fp;

    pid_t process = fork();

    if (process == 0)
    {
        sleep(5);
        fp = fopen("text.txt", "r");
        fprintf(fp, "%s %s %s %s", "My", "name", "is", "Dixie");
        //printf("Child process PID - (pid: %d) \n", (int)getpid());
    }

    else if (process > 0)
    {
        fp = fopen("text.txt", "w+");
        fprintf(fp, "%s %s %s %s", "My", "name", "is", "Dixie");
        // printf("Parent process PID - (pid: %d) \n", (int)getpid());
    }

    else
    {
        fprintf(stderr, "fork failed \n");
        fclose(fp);
        exit(1);
    }

    printf("--end of program\n");

    return 0;
}